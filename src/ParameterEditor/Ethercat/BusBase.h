/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN
  Provides context to visitor pattern implementation such that variable/function
  names and values can be passed alongside within the correct scope

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
-------------------------------------------------------------------------------*/

#ifndef BUS_BASE_H
#define BUS_BASE_H

#include <cassert>
#include <atomic>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <chrono>
#include <mutex>
#include <memory>
#include <iomanip>
#include <cstring> /* memcopy */
#include "ethercat.h"
#include "Core/Log/Log.h"

namespace Controller::Ethercat {

// forward declaration for ISlave
class ISlave;
using ISlavePtr = std::shared_ptr<ISlave>;

/**
 * @brief      Class for managing an ethercat bus containing one or multpile
 *             slaves
 */
class BusBase {
 public:
  using PdoSizePair = std::pair<uint16_t, uint16_t>;
  using PdoSizeMap = std::unordered_map<std::string, PdoSizePair>;

  BusBase() = delete;  // Delete default constructor
  explicit BusBase(const std::string& name);
  virtual ~BusBase() = default;

  auto GetName() const -> const std::string& { return m_Name; }
  auto GetUpdateReadStamp() const -> const std::chrono::time_point<std::chrono::high_resolution_clock>& { return m_UpdateReadStamp; }
  auto GetUpdateWriteStamp() const -> const std::chrono::time_point<std::chrono::high_resolution_clock>& { return m_UpdateWriteStamp; }

  static auto IsAvailable(const std::string& name) -> bool;
  static auto PrintAvailableBusses() -> void;

  auto IsAvailable() const -> bool;
  auto GetNumberOfSlaves() const -> int;
  auto AddSlave(const ISlavePtr& slave) -> bool;
  auto Startup(const bool sizeCheck = true) -> bool;
  auto UpdateRead() -> void;
  auto UpdateWrite() -> void;
  auto Shutdown() -> void;

  void reloadODList(const uint16_t slaveAddress, ec_ODlistt& odList, ec_OElistt& oeList);

  
  /*!
   * Set the desired EtherCAT state machine state.
   * @param state Desired state.
   * @param slave Address of the slave, 0 for all slaves.
   */
  auto SetState(const uint16_t state, const uint16_t slave = 0) -> void;

  /*!
   * Wait for an EtherCAT state machine state to be reached.
   * @param state      Desired state.
   * @param slave      Address of the slave, 0 for all slaves.
   * @param maxRetries Maximum number of retries.
   * @param retrySleep Duration to sleep between the retries.
   * @return True if the state has been reached within the timeout.
   */
  auto WaitForState(const uint16_t state, const uint16_t slave = 0, const unsigned int maxRetries = 40, const double retrySleep = 0.001) -> bool;

  auto GetEcState(const uint16_t slave = 0) -> uint16_t;

  auto GetErrorString(ec_errort error) -> std::string;

  /**
   * @brief      Prints application layer status
   * @param[in]  slave  Address of the slave, 0 for all slaves.
   */
  auto PrintALStatus(const uint16_t slave = 0) -> void;

  /*!
   * Check if an error for the SDO index of the slave exists.
   * @param slave   Address of the slave.
   * @param index   Index of the SDO.
   * @return True if an error for the index exists.
   */
  auto CheckForSdoErrors(const uint16_t slave, const uint16_t index) -> bool;

  /*!
   * Synchronize the distributed clocks.
   * @param      slave     Address of the slave.
   * @param      activate  True to activate the distr. clock, false to deactivate.
   * @param[in]  timeStep  The time step
   */
  auto SyncDistributedClock0(const uint16_t slave, const bool activate, const double cycleTime, const double cycleShift) -> void;

  /*!
   * Returns a map of the actually requested PDO sizes (Rx & Tx) This is useful
   * for slaves where the PDO size at startup is unknown This method shall be
   * used after adding the slaves and after executing the "startup" method
   * @return     std::unordered_map with the addresses and the corresponding Pdo sizes
   */
  auto GetHardwarePdoSizes() -> PdoSizeMap;

  /*!
   * Returns a pair with the TxPdo and RxPdo sizes for the requested address
   * Overloads the "PdoSizeMap getHardwarePdoSizes()" method.
   * @param      slave  Address of the slave
   * @return     std::pair with the rx (first) and tx (second) Pdo sizes
   */
  auto GetHardwarePdoSizes(const uint16_t slave) -> PdoSizePair;

  /*!
   * Send a writing SDO.
   * @param slave          Address of the slave.
   * @param index          Index of the SDO.
   * @param subindex       Sub-index of the SDO.
   * @param completeAccess Access all sub-indices at once.
   * @param value          Value to write.
   * @return True if successful.
   */
  template <typename Value>
  auto SendSdoWrite(const uint16_t slave, const uint16_t index, const uint8_t subindex, const bool completeAccess, const Value value) -> bool{
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    const int size = sizeof(Value);
    Value valueCopy = value;  // copy value to make it modifiable
    int wkc = 0;
    {
      std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
      wkc = ecx_SDOwrite(&m_Context, slave, index, subindex, static_cast<boolean>(completeAccess), size, &valueCopy, EC_TIMEOUTRXM);
    }
    if (wkc <= 0) {
      std::stringstream ss;
      ss << "Slave " << slave << ": Working counter too low (" << wkc << ") for writing SDO (ID: 0x" << std::setfill('0')
                                 << std::setw(4) << std::hex << index << ", SID 0x" << std::setfill('0') << std::setw(2) << std::hex
                                 << static_cast<uint16_t>(subindex) << ")."  << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return false;
    }
    return true;
  }

  /*!
   * Send a reading SDO.
   * @param slave          Address of the slave.
   * @param index          Index of the SDO.
   * @param subindex       Sub-index of the SDO.
   * @param completeAccess Access all sub-indices at once.
   * @param value          Return argument, will contain the value which was read.
   * @return True if successful.
   */
  template <typename Value>
  auto SendSdoRead(const uint16_t slave, const uint16_t index, const uint8_t subindex, const bool completeAccess, Value& value) -> bool {
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    int size = sizeof(Value);
    int wkc = 0;
    {
      std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
      wkc = ecx_SDOread(&m_Context, slave, index, subindex, static_cast<boolean>(completeAccess), &size, &value, EC_TIMEOUTRXM);
    }
    std::stringstream ss;
    if (wkc <= 0) {
      ss << "Slave " << slave << ": Working counter too low (" << wkc << ") for reading SDO (ID: 0x" << std::setfill('0')
                                 << std::setw(4) << std::hex << index << ", SID 0x" << std::setfill('0') << std::setw(2) << std::hex
                                 << static_cast<uint16_t>(subindex) << ")." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str()); // TODO flush ss
      return false;
    }
    if (size != sizeof(Value)) {
      ss << "Slave " << slave << ": Size mismatch (expected " << sizeof(Value) << " bytes, read " << size
                                 << " bytes) for reading SDO (ID: 0x" << std::setfill('0') << std::setw(4) << std::hex << index
                                 << ", SID 0x" << std::setfill('0') << std::setw(2) << std::hex << static_cast<uint16_t>(subindex) << ")." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return false;
    }
    return true;
  }

  /**
   * Send a special reading SDO to read SDOs of type visible string.
   * @param slave          Address of the slave.
   * @param index          Index of the SDO.
   * @param subindex       Sub-index of the SDO.
   * @param value          Return argument, will contain the value which was read.
   * @return True if successful.
   */
  auto SendSdoReadVisibleString(const uint16_t slave, const uint16_t index, const uint8_t subindex, std::string& value) -> bool {
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    char buffer[128];
    int length = sizeof(buffer) - 1;
    int wkc = 0;
    {
      std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
      wkc = ecx_SDOread(&m_Context, slave, index, subindex, static_cast<boolean>(false), &length, &buffer, EC_TIMEOUTRXM);
    }
    std::stringstream ss;
    if (wkc <= 0) {
      ss << "Slave " << slave << ": Working counter too low (" << wkc << ") for reading SDO (ID: 0x" << std::setfill('0')
                                 << std::setw(4) << std::hex << index << ", SID 0x" << std::setfill('0') << std::setw(2) << std::hex
                                 << static_cast<uint16_t>(subindex) << ")." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str()); // TODO flush ss
      return false;
    }
    value.clear();
    for (int i = 0; i < length; ++i) {
      ss << "Char      : " << buffer[i] << std::endl;
      ss << "Char (int): " << static_cast<unsigned int>(buffer[i]) << std::endl;
      if (buffer[i] != 0x0) {
        value += buffer[i];
      } else {
        break;
      }
    }
    CONTROLLER_CORE_TRACE(ss.str());
    return true;
  }

  auto GetExpectedWorkingCounter(const uint16_t slave = 0) const -> int;
  auto WorkingCounterIsOk() const -> bool;
  auto IsOk() const -> bool;

  /*!
   * Read a TxPDO from the buffer.
   * @param slave Address of the slave.
   * @param txPdo Return argument, TxPDO container.
   */
  template <typename TxPdo>
  auto ReadTxPdo(const uint16_t slave, TxPdo& txPdo) const -> void {
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    assert(sizeof(TxPdo) == m_Context.slavelist[slave].Ibytes);
    memcpy(&txPdo, m_Context.slavelist[slave].inputs, sizeof(TxPdo));
  }

  /*!
   * Write an RxPDO to the buffer.
   * @param slave Address of the slave.
   * @param rxPdo RxPDO container.
   */
  template <typename RxPdo>
  auto WriteRxPdo(const uint16_t slave, const RxPdo& rxPdo) -> void {
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    
    assert(sizeof(RxPdo) == m_Context.slavelist[slave].Obytes);
    memcpy(m_Context.slavelist[slave].outputs, &rxPdo, sizeof(RxPdo));
  }

 // auto SetOutputUint16(const uint16_t slave, const uint16_t moduleIndex, const uint16_t value) -> void;

//TODO template these!!!
  auto SetOutputUint8(const uint16_t slave, const uint16_t moduleIndex, const uint8_t value) -> void;
  auto SetOutputUint16(const uint16_t slave, const uint16_t moduleIndex, const uint16_t value) -> void;
  auto SetOutputUint32(const uint16_t slave, const uint16_t moduleIndex, const uint32_t value) -> void;
  auto SetOutputInt8(const uint16_t slave, const uint16_t moduleIndex, const int8_t value) -> void;
  auto SetOutputInt16(const uint16_t slave, const uint16_t moduleIndex, const int16_t value) -> void;
  auto SetOutputInt32(const uint16_t slave, const uint16_t moduleIndex, const int32_t value) -> void;

 protected:
  std::string m_Name;   //! Name of the bus
  bool m_Initialized{false}; //! Whether the bus has been initialized successfully //TODO fix typo!
  std::vector<ISlavePtr> m_Slaves; //! List of slaves.
  bool m_SentProcessData{false}; //! Bool indicating whether PDO data has been sent and not read yet.
  std::atomic<int> m_Wkc;   //! Working counter of the most recent PDO.
  std::chrono::time_point<std::chrono::high_resolution_clock> m_UpdateReadStamp;   //! Time of the last successful PDO reading.
  std::chrono::time_point<std::chrono::high_resolution_clock> m_UpdateWriteStamp;   //! Time of the last successful PDO writing.
  const unsigned int  m_ConfigMaxRetries{5};   //! Maximal number of retries to configure the EtherCAT bus.
  const double        m_ConfigRetrySleep{1.0}; //! Time to sleep between the retries.
  unsigned int        m_WorkingCounterTooLowCounter{0}; //! Count working counter too low in a row.
  const unsigned int  m_MaxWorkingCounterTooLow{100}; //! Maximal number of working counter to low.
  char m_IOMap[4096]; // EtherCAT input/output mapping of the slaves within the datagrams.

  // EtherCAT context data elements:
  ecx_portt       m_Port;   // Port reference.
  ec_slavet       m_SlaveList[EC_MAXSLAVE]; // List of slave data. Index 0 is reserved for the master, higher indices for the slaves.
  int             m_SlaveCount{0};   // Number of slaves found in the network.
  ec_groupt       m_GroupList[EC_MAXGROUP]; // Slave group structure.
  uint8           m_EsiBuf[EC_MAXEEPBUF]; // Internal, reference to EEPROM cache buffer.
  uint32          m_EsiMap[EC_MAXEEPBITMAP]; // Internal, reference to EEPROM cache map.
  ec_eringt       m_EList;   // Internal, reference to error list.
  ec_idxstackT    m_IdxStack; // Internal, reference to processdata stack buffer info.
  boolean         m_Error{FALSE};   // Boolean indicating if an error is available in error stack.
  int64           m_DcTime{0};   // Reference to last DC time from slaves.
  ec_SMcommtypet  m_SmCommtype[EC_MAX_MAPT];   // Internal, SM buffer.
  ec_PDOassignt   m_PdoAssign[EC_MAX_MAPT];   // Internal, PDO assign list.
  ec_PDOdesct     m_PdoDesc[EC_MAX_MAPT]; // Internal, PDO description list.
  ec_eepromSMt    m_Sm;   // Internal, SM list from EEPROM.
  ec_eepromFMMUt  m_Fmmu;   // Internal, FMMU list from EEPROM.

  mutable std::recursive_mutex m_ContextMutex;
  // EtherCAT context data.
  // Note: SOEM does not use dynamic memory allocation (new/delete). Therefore
  // all context pointers must be null or point to an existing member.
  ecx_contextt m_Context = {&m_Port,
                            &m_SlaveList[0],
                            &m_SlaveCount,
                            EC_MAXSLAVE,
                            &m_GroupList[0],
                            EC_MAXGROUP,
                            &m_EsiBuf[0],
                            &m_EsiMap[0],
                            0,
                            &m_EList,
                            &m_IdxStack,
                            &m_Error,
                            &m_DcTime,
                            &m_SmCommtype[0],
                            &m_PdoAssign[0],
                            &m_PdoDesc[0],
                            &m_Sm,
                            &m_Fmmu,
                            nullptr,
                            nullptr,
                            0,
                            nullptr
                            };
};

using BusBasePtr = std::shared_ptr<BusBase>;

/*!
 * Send a reading SDO - specialization for strings
 * @param slave          Address of the slave.
 * @param index          Index of the SDO.
 * @param subindex       Sub-index of the SDO.
 * @param completeAccess Access all sub-indices at once.
 * @param value          Return argument, will contain the value which was read. The string needs to be preallocated to the correct size!
 * @return True if successful.
 */
template<>
bool BusBase::SendSdoRead<std::string>(const uint16_t slave, const uint16_t index, const uint8_t subindex, const bool completeAccess, std::string& value);

/*!
   * Send a writing SDO - specialization for strings
   * @param slave          Address of the slave.
   * @param index          Index of the SDO.
   * @param subindex       Sub-index of the SDO.
   * @param completeAccess Access all sub-indices at once.
   * @param value          Value to write.
   * @return True if successful.
   */
template<>
bool BusBase::SendSdoWrite<std::string>(const uint16_t slave, const uint16_t index, const uint8_t subindex, const bool completeAccess, const std::string value);

}  // namespace Controller::Ethercat

#endif // BUS_BASE_H
