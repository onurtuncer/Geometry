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

#include <cstring>  /* memset */
#include "BusBase.h"
#include "ISlave.h"
#include "Core/ThreadSleep.h"

namespace Controller::Ethercat {

  BusBase::BusBase(const std::string& name) : m_Name(name), m_Wkc(0) {
    // Initialize all SOEM context data pointers that are not used with null.
    m_Context.elist->head = 0;
    m_Context.elist->tail = 0;
    m_Context.port->stack.sock = nullptr;
    m_Context.port->stack.txbuf = nullptr;
    m_Context.port->stack.txbuflength = nullptr;
    m_Context.port->stack.tempbuf = nullptr;
    m_Context.port->stack.rxbuf = nullptr;
    m_Context.port->stack.rxbufstat = nullptr;
    m_Context.port->stack.rxsa = nullptr;
    m_Context.port->redport = nullptr;
    //  m_Context.idxstack->data = nullptr; // This does not compile since SOEM uses a fixed size array of void pointers.
    m_Context.FOEhook = nullptr;
  }

  auto BusBase::IsAvailable(const std::string& name) -> bool {
    ec_adaptert* adapter = ec_find_adapters();
    while (adapter != nullptr) {
      if (name == std::string(adapter->name)) {
        return true;
      }
      adapter = adapter->next;
    }
    return false;
  }

  void BusBase::PrintAvailableBusses() {
    std::stringstream ss;
    ss << "Available adapters:" << std::endl;
    ec_adaptert* adapter = ec_find_adapters();
    while (adapter != nullptr) {
      ss << "- Name: '" << adapter->name << "', description: '" << adapter->desc << "'" << std::endl;
      adapter = adapter->next;
    }
    CONTROLLER_CORE_INFO(ss.str());
  }

  auto BusBase::IsAvailable() const -> bool { return IsAvailable(m_Name); }

  auto BusBase::GetNumberOfSlaves() const -> int {
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    return *m_Context.slavecount;
  }

  auto BusBase::AddSlave(const ISlavePtr& slave) -> bool {
    std::stringstream ss;
    for (const auto& existingSlave : m_Slaves) {
      if (slave->GetAddress() == existingSlave->GetAddress()) {
        ss << "[" << GetName() << "] "
           << "Slave '" << existingSlave->GetName() << "' and slave '" << slave->GetName()
           << "' have identical addresses (" << slave->GetAddress() << ")." << std::endl;
        return false;
      }
    }

    CONTROLLER_CORE_ERROR(ss.str());

    m_Slaves.push_back(slave);
    return true;
  }

  auto BusBase::Startup(const bool sizeCheck) -> bool {

    std::stringstream ss;
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    /*
   * Followed by start of the application we need to set up the NIC to be used as
   * EtherCAT Ethernet interface. In a simple setup we call ec_init(ifname) and if
   * SOEM comes with support for cable redundancy we call ec_init_redundant that
   * will open a second port as backup. You can send NULL as ifname if you have a
   * dedicated NIC selected in the nicdrv.c. It returns >0 if succeeded.
   */
    if (!IsAvailable()) {
      ss << "[" << GetName() << "] "
         << "Bus is not available." << std::endl;
      PrintAvailableBusses();
      return false;
    }
    if (ecx_init(&m_Context, m_Name.c_str()) <= 0) {
      ss << "[" << GetName() << "] "
         << "No socket connection. Execute as root." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return false;
    }

    // Initialize SOEM.
    // Note: ecx_config_init(..) requests the slaves to go to PRE-OP.
    for (unsigned int retry = 0; retry <= m_ConfigMaxRetries; retry++) {
      if (ecx_config_init(&m_Context, FALSE) > 0) {
        // Successful initialization.
        break;
      } else if (retry == m_ConfigMaxRetries) {
        // Too many failed attempts.
        ss << "[" << GetName() << "] "
           << "No slaves have been found." << std::endl;
        CONTROLLER_CORE_ERROR(ss.str());
        return false;
      }
      // Sleep and retry.
      Controller::ThreadSleep(m_ConfigRetrySleep);
      ss << "No slaves have been found, retrying " << retry + 1 << "/" << m_ConfigMaxRetries << " ..." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
    }

    // Print the slaves which have been detected.
    ss << "The following " << GetNumberOfSlaves() << " slaves have been found and configured:" << std::endl;
    for (int slave = 1; slave <= GetNumberOfSlaves(); slave++) {
      ss << "Address: " << slave << " - Name: '" << std::string(m_Context.slavelist[slave].name) << "'" << std::endl;
    }

    // Check if the given slave addresses are valid.
    bool slaveAddressesAreOk = true;
    for (const auto& slave : m_Slaves) {
      auto address = static_cast<int>(slave->GetAddress());
      if (address == 0) {
        ss << "[" << GetName() << "] "
           << "Slave '" << slave->GetName() << "': Invalid address " << address << "." << std::endl;
        slaveAddressesAreOk = false;
      }
      if (address > GetNumberOfSlaves()) {
        ss << "[" << GetName() << "] "
           << "Slave '" << slave->GetName() << "': Invalid address " << address << ", "
           << "only " << GetNumberOfSlaves() << " slave(s) found." << std::endl;
        slaveAddressesAreOk = false;
      }
    }

   CONTROLLER_CORE_INFO(ss.str()); //TODO need to flush contents of stringstream

    if (!slaveAddressesAreOk) {
      return false;
    }

    // Disable symmetrical transfers.
    m_Context.grouplist[0].blockLRW = 1;

    // Initialize the communication interfaces of all slaves.
    for (auto& slave : m_Slaves) {
      if (!slave->Startup()) {
        ss << "[" << GetName() << "] "
           << "Slave '" << slave->GetName() << "' was not initialized successfully." << std::endl;
        CONTROLLER_CORE_ERROR(ss.str()); // TODO need to flush again
        return false;
      }
    }

    // Set up the communication IO mapping.
    // Note: ecx_config_map_group(..) requests the slaves to go to SAFE-OP.
    ecx_config_map_group(&m_Context, &m_IOMap, 0);

    // Check if the size of the IO mapping fits our slaves.
    bool ioMapIsOk = true;
    // do this check only if 'sizeCheck' is true
    if (sizeCheck) {
      for (const auto& slave : m_Slaves) {
        const ISlave::PdoInfo pdoInfo = slave->GetCurrentPdoInfo();
        if (pdoInfo.rxPdoSize != m_Context.slavelist[slave->GetAddress()].Obytes) {
          ss << "[" << GetName() << "] "
             << "RxPDO size mismatch: The slave '" << slave->GetName() << "' expects a size of " << pdoInfo.rxPdoSize
             << " bytes but the slave found at its address " << slave->GetAddress() << " requests "
             << m_Context.slavelist[slave->GetAddress()].Obytes << " bytes)." << std::endl;
          ioMapIsOk = false;
        }
        if (pdoInfo.txPdoSize != m_Context.slavelist[slave->GetAddress()].Ibytes) {
          ss << "[" << GetName() << "] "
             << "TxPDO size mismatch: The slave '" << slave->GetName() << "' expects a size of " << pdoInfo.txPdoSize
             << " bytes but the slave found at its address " << slave->GetAddress() << " requests "
             << m_Context.slavelist[slave->GetAddress()].Ibytes << " bytes)." << std::endl;
          ioMapIsOk = false;
        }
      }
    }

    CONTROLLER_CORE_ERROR(ss.str());

    if (!ioMapIsOk) {
      return false;
    }

    // Initialize the memory with zeroes.
    for (int slave = 1; slave <= GetNumberOfSlaves(); slave++) {
      memset(m_Context.slavelist[slave].inputs, 0, m_Context.slavelist[slave].Ibytes);
      memset(m_Context.slavelist[slave].outputs, 0, m_Context.slavelist[slave].Obytes);
    }

    m_WorkingCounterTooLowCounter = 0;
    m_Initialized = true;

    return true;
  }

  auto BusBase::UpdateRead() -> void {

    std::stringstream ss;
    if (!m_SentProcessData) {
      ss << "No process data to read." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return;
    }

    //! Receive the EtherCAT data.
    m_UpdateReadStamp = std::chrono::high_resolution_clock::now();
    {
      std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
      m_Wkc = ecx_receive_processdata(&m_Context, EC_TIMEOUTRET);
    }
    m_SentProcessData = false;

    //! Check the working counter.
    if (!WorkingCounterIsOk()) {
      ++m_WorkingCounterTooLowCounter;
      if (!IsOk()) {
      ss << 1.0 << "Bus is not ok. Too many working counter too low in a row: " << m_WorkingCounterTooLowCounter << std::endl;
      }    
      ss << "Working counter too low counter: " << m_WorkingCounterTooLowCounter << std::endl;
      ss << 1.0 << "Update Read:" << this << std::endl;
      ss << 1.0 << "Working counter is too low: " << m_Wkc.load() << " < " << GetExpectedWorkingCounter() << std::endl;
      // CONTROLLER_CORE_WARN(ss.str());
      return;
    }
    // Reset working counter too low counter.
    m_WorkingCounterTooLowCounter = 0;

    //! Each slave attached to this bus reads its data to the buffer.
    for (auto& slave : m_Slaves) {
      slave->UpdateRead();
    }
  }

  auto BusBase::UpdateWrite() -> void {
    std::stringstream ss;
    if (m_SentProcessData) {
      ss << "Sending new process data without reading the previous one." << std::endl;
      CONTROLLER_CORE_WARN(ss.str());
    }

    //! Each slave attached to this bus write its data to the buffer.
    for (auto& slave : m_Slaves) {
      slave->UpdateWrite();
    }

    //! Send the EtherCAT data.
    m_UpdateWriteStamp = std::chrono::high_resolution_clock::now();
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    ecx_send_processdata(&m_Context);
    m_SentProcessData = true;
  }

  void BusBase::Shutdown() {

    std::stringstream ss;
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    // Set the slaves to state Init.
    if (GetNumberOfSlaves() > 0) {
      SetState(EC_STATE_INIT);
    }

    for (auto& slave : m_Slaves) {
      slave->Shutdown();
    }

    // Close the port.
    if (m_Context.port != nullptr) {
      ss << "Closing socket ..." << std::endl;
      CONTROLLER_CORE_INFO(ss.str());
      ecx_close(&m_Context);
      // Sleep to make sure the socket is closed, because ecx_close is non-blocking.
      Controller::ThreadSleep(0.5);
    }

    m_Initialized = false;
  }

  auto BusBase::SetState(const uint16_t state, const uint16_t slave) -> void {
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
  if(!m_Initialized) {
      std::stringstream ss;
      ss << "Bus " << m_Name << " was not successfully initialized, skipping operation" << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return;
    }
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    m_Context.slavelist[slave].state = state;
    ecx_writestate(&m_Context, slave);
    std::stringstream ss;
    ss << "Slave " << slave << ": State " << state << " has been set." << std::endl;
    CONTROLLER_CORE_INFO(ss.str());
  }

  auto BusBase::WaitForState(const uint16_t state,
                                 const uint16_t slave,
                                 const unsigned int maxRetries,
                                 const double retrySleep) -> bool {

    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    std::stringstream ss;
    for (unsigned int retry = 0; retry <= maxRetries; retry++) {
      m_Context.slavelist[slave].state = state;
      ecx_writestate(&m_Context, slave);
      ecx_statecheck(&m_Context, slave, state, static_cast<int>(1e6 * retrySleep));
      if (ecx_statecheck(&m_Context, slave, state, static_cast<int>(1e6 * retrySleep)) == state) {
        ss << "Slave " << slave << ": State " << state << " has been reached." << std::endl;
        CONTROLLER_CORE_INFO(ss.str());
        return true;
      }
      ecx_readstate(&m_Context);

      // TODO: Do this for all states?
      ecx_send_processdata(&m_Context);
      m_Wkc = ecx_receive_processdata(&m_Context, EC_TIMEOUTRET);
    }

    ss << "Slave " << slave << ": State " << state << " has not been reached." << std::endl;
    CONTROLLER_CORE_WARN(ss.str());
    return false;
  }

  auto BusBase::GetEcState(const uint16_t slave) -> uint16_t {
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    ecx_readstate(&m_Context);
    return m_Context.slavelist[slave].state;
  }

  auto BusBase::GetExpectedWorkingCounter(const uint16_t slave) const -> int {

    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    return m_Context.grouplist[slave].outputsWKC * 2 + m_Context.grouplist[slave].inputsWKC;
  }

auto BusBase::GetErrorString(ec_errort error) -> std::string  {
    std::stringstream stream;
    stream << "Time: " << (static_cast<double>(error.Time.sec) + (static_cast<double>(error.Time.usec) / 1000000.0));

    switch (error.Etype) {
      case EC_ERR_TYPE_SDO_ERROR:
      stream << " SDO slave: " << error.Slave << " index: 0x" << std::setfill('0') << std::setw(4) << std::hex << error.Index << "."
             << std::setfill('0') << std::setw(2) << std::hex << static_cast<uint16_t>(error.SubIdx) << " error: 0x" << std::setfill('0')
             << std::setw(8) << std::hex << static_cast<unsigned>(error.AbortCode) << " " << ec_sdoerror2string(error.AbortCode);
        break;
      case EC_ERR_TYPE_EMERGENCY:
      stream << " EMERGENCY slave: " << error.Slave << " error: 0x" << std::setfill('0') << std::setw(4) << std::hex << error.ErrorCode;
        break;
      case EC_ERR_TYPE_PACKET_ERROR:
      stream << " PACKET slave: " << error.Slave << " index: 0x" << std::setfill('0') << std::setw(4) << std::hex << error.Index << "."
             << std::setfill('0') << std::setw(2) << std::hex << static_cast<uint16_t>(error.SubIdx) << " error: 0x" << std::setfill('0')
             << std::setw(8) << std::hex << error.ErrorCode;
        break;
      case EC_ERR_TYPE_SDOINFO_ERROR:
      stream << " SDO slave: " << error.Slave << " index: 0x" << std::setfill('0') << std::setw(4) << std::hex << error.Index << "."
             << std::setfill('0') << std::setw(2) << std::hex << static_cast<uint16_t>(error.SubIdx) << " error: 0x" << std::setfill('0')
             << std::setw(8) << std::hex << static_cast<unsigned>(error.AbortCode) << " " << ec_sdoerror2string(error.AbortCode);
        break;
      case EC_ERR_TYPE_SOE_ERROR:
      stream << " SoE slave: " << error.Slave << " index: 0x" << std::setfill('0') << std::setw(4) << std::hex << error.Index
             << " error: 0x" << std::setfill('0') << std::setw(8) << std::hex << static_cast<unsigned>(error.AbortCode) << " "
             << ec_soeerror2string(error.ErrorCode);
        break;
      case EC_ERR_TYPE_MBX_ERROR:
      stream << " MBX slave: " << error.Slave << " error: 0x" << std::setfill('0') << std::setw(8) << std::hex << error.ErrorCode << " "
             << ec_mbxerror2string(error.ErrorCode);
        break;
      default:
        stream << " MBX slave: " << error.Slave << " error: 0x" << std::setfill('0') << std::setw(8) << std::hex
               << static_cast<unsigned>(error.AbortCode);
        break;
    }
    return stream.str();
  }

  auto BusBase::PrintALStatus(const uint16_t slave) -> void {

    std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    std::stringstream ss;

    ss <<" slave: " << slave << " alStatusCode: 0x" << std::setfill('0') <<
                   std::setw(8) << std::hex << m_Context.slavelist[slave].ALstatuscode <<
                   " " << ec_ALstatuscode2string(m_Context.slavelist[slave].ALstatuscode) << std::endl;
    CONTROLLER_CORE_INFO(ss.str());
  }

  auto BusBase::CheckForSdoErrors(const uint16_t slave, const uint16_t index) -> bool {

    std::stringstream ss;
    while (ecx_iserror(&m_Context)) {
      ec_errort error;
      if (ecx_poperror(&m_Context, &error)) {
        std::string errorStr = GetErrorString(error);
        ss << errorStr << std::endl;
        if (error.Slave == slave && error.Index == index) {
          CONTROLLER_CORE_ERROR(ss.str());
          return true;
        }
      }
    }
    return false;
  }

  auto BusBase::WorkingCounterIsOk() const -> bool { return m_Wkc >= GetExpectedWorkingCounter(); }

  auto BusBase::IsOk() const -> bool { return m_WorkingCounterTooLowCounter < m_MaxWorkingCounterTooLow; }

  auto BusBase::SyncDistributedClock0(const uint16_t slave, const bool activate, const double cycleTime, const double cycleShift) -> void {
    std::stringstream ss;
    ss << "Bus '" << m_Name << "', slave " << slave << ":  " << (activate ? "Activating" : "Deactivating")
       << " distributed clock synchronization..." << std::endl;

    ecx_dcsync0(&m_Context, slave, static_cast<uint8_t>(activate), static_cast<uint32_t>(cycleTime * 1e9),
                static_cast<int32_t>(1e9 * cycleShift));

    ss << "Bus '" << m_Name << "', slave " << slave << ":  " << (activate ? "Activated" : "Deactivated")
       << " distributed clock synchronization." << std::endl;
    CONTROLLER_CORE_INFO(ss.str());
  }

auto BusBase::GetHardwarePdoSizes() -> BusBase::PdoSizeMap  {
    PdoSizeMap pdoMap;

    for (const auto& slave : m_Slaves) {
      pdoMap.insert(std::make_pair(slave->GetName(), GetHardwarePdoSizes(slave->GetAddress())));
    }

    return pdoMap;
  }

  auto BusBase::GetHardwarePdoSizes(const uint16_t slave) -> BusBase::PdoSizePair {
    return std::make_pair(m_Context.slavelist[slave].Obytes, m_Context.slavelist[slave].Ibytes);
  }

template<>
auto BusBase::SendSdoRead<std::string>(const uint16_t slave, const uint16_t index, const uint8_t subindex, const bool completeAccess, std::string& value) -> bool {
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    //Expected length of the string. String needs to be preallocated
    int size = value.length();
    //Store for check at the end
    int expected_size = size;
    //Create buffer with the length of the string
    char buffer[size];
    int wkc = 0;
    {
      std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
      wkc = ecx_SDOread(&m_Context, slave, index, subindex, static_cast<boolean>(completeAccess), &size, buffer, EC_TIMEOUTRXM);
      //Convert read data to a std::string
      value = std::string(buffer,size);
    }
    std::stringstream ss;
    if (wkc <= 0) {
      ss << "Slave " << slave << ": Working counter too low (" << wkc << ") for reading SDO (ID: 0x" << std::setfill('0')
                                 << std::setw(4) << std::hex << index << ", SID 0x" << std::setfill('0') << std::setw(2) << std::hex
                                 << static_cast<uint16_t>(subindex) << ")." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str()); // TODO flush ss
      return false;
    }

    if (size != (int)expected_size) {
      ss << "Slave " << slave << ": Size mismatch (expected " << expected_size << " bytes, read " << size
                                 << " bytes) for reading SDO (ID: 0x" << std::setfill('0') << std::setw(4) << std::hex << index
                                 << ", SID 0x" << std::setfill('0') << std::setw(2) << std::hex << static_cast<uint16_t>(subindex) << ")." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return false;
    }
    return true;
  }

template<>
auto BusBase::SendSdoWrite<std::string>(const uint16_t slave, const uint16_t index, const uint8_t subindex, const bool completeAccess, const std::string value) -> bool {
    assert(static_cast<int>(slave) <= GetNumberOfSlaves());
    const int size = value.length();
    const char* dataPtr = value.data();
    int wkc = 0;
    {
      std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
        wkc = ecx_SDOwrite(&m_Context, slave, index, subindex, static_cast<boolean>(completeAccess), size, &dataPtr, EC_TIMEOUTRXM);
    }
    std::stringstream ss;
    if (wkc <= 0) {
        ss << "Slave " << slave << ": Working counter too low (" << wkc << ") for writing SDO (ID: 0x" << std::setfill('0')
                                   << std::setw(4) << std::hex << index << ", SID 0x" << std::setfill('0') << std::setw(2) << std::hex
                                   << static_cast<uint16_t>(subindex) << ")." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return false;
    }
    return true;
  }

/*   auto BusBase::SetOutputUint16(const uint16_t slave, const uint16_t moduleIndex, uint16_t value) -> void {
  uint8_t *dataPtr;
  // std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
  dataPtr = m_Context.slavelist[slave].outputs;
  dataPtr += moduleIndex;
  *dataPtr++ = value & 0xFF;
  *dataPtr++ = (value >> 8) & 0xFF;
} */

auto BusBase::SetOutputUint8(const uint16_t slave, const uint16_t moduleIndex, uint8_t value) -> void {
    uint8_t *dataPtr;
    // std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    dataPtr = m_Context.slavelist[slave].outputs;
    dataPtr += moduleIndex;
    *dataPtr = value;
  }

  auto BusBase::SetOutputUint16(const uint16_t slave, const uint16_t moduleIndex, uint16_t value) -> void {
    uint8_t *dataPtr;
    // std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    dataPtr = m_Context.slavelist[slave].outputs;
    dataPtr += moduleIndex;
    *dataPtr++ = value & 0xFF;
    *dataPtr++ = (value >> 8) & 0xFF;
  }

  auto BusBase::SetOutputUint32(const uint16_t slave, const uint16_t moduleIndex, uint32_t value) -> void {
    uint8_t *dataPtr;
    // std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    dataPtr = m_Context.slavelist[slave].outputs;
    dataPtr += moduleIndex;
    *dataPtr++ = value & 0xFF;
    *dataPtr++ = (value >> 8) & 0xFF;
    *dataPtr++ = (value >> 16) & 0xFF;
    *dataPtr++ = (value >> 24) & 0xFF;
  }

  auto BusBase::SetOutputInt8(const uint16_t slave, const uint16_t moduleIndex, int8_t value) -> void {
    uint8_t *dataPtr;
    // std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    dataPtr = m_Context.slavelist[slave].outputs;
    dataPtr += moduleIndex;
    *dataPtr = value;
  }

  auto BusBase::SetOutputInt16(const uint16_t slave, const uint16_t moduleIndex, int16_t value) -> void {
    uint8_t *dataPtr;
    // std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    dataPtr = m_Context.slavelist[slave].outputs;
    dataPtr += moduleIndex;
    *dataPtr++ = value & 0xFF;
    *dataPtr++ = (value >> 8) & 0xFF;
  }

  auto BusBase::SetOutputInt32(const uint16_t slave, const uint16_t moduleIndex, int32_t value) -> void {
    uint8_t *dataPtr;
    // std::lock_guard<std::recursive_mutex> guard(m_ContextMutex);
    dataPtr = m_Context.slavelist[slave].outputs;
    dataPtr += moduleIndex;
    *dataPtr++ = value & 0xFF;
    *dataPtr++ = (value >> 8) & 0xFF;
    *dataPtr++ = (value >> 16) & 0xFF;
    *dataPtr++ = (value >> 24) & 0xFF;
  }

  #define OTYPE_VAR               0x0007
  #define OTYPE_ARRAY             0x0008
  #define OTYPE_RECORD            0x0009

char* otype2string(uint16 otype)
{
    static char str[32] = { 0 };

    switch(otype)
    {
        case OTYPE_VAR:
            sprintf(str, "VAR");
            break;
        case OTYPE_ARRAY:
            sprintf(str, "ARRAY");
            break;
        case OTYPE_RECORD:
            sprintf(str, "RECORD");
            break;
        default:
            sprintf(str, "ot:0x%4.4X", otype);
    }
    return str;
}


  void BusBase::reloadODList(const uint16_t slaveAddress, ec_ODlistt& odList, ec_OElistt& oeList) {

     int i, j;

    odList.Entries = 0;
    memset(&odList, 0, sizeof(odList));
    if( ecx_readODlist(&m_Context, slaveAddress, &odList))
    {
        printf(" CoE Object Description found, %d entries.\n",odList.Entries);
        for( i = 0 ; i < odList.Entries ; i++)
        {
            uint8_t max_sub;
            char name[128] = { 0 };

            ecx_readODdescription(&m_Context, i, &odList);
            while(EcatError) printf(" - %s\n", ecx_elist2string(&m_Context));
            snprintf(name, sizeof(name) - 1, "\"%s\"", odList.Name[i]);
            // if (odList.ObjectCode[i] == OTYPE_VAR)
            // {
            //     printf("0x%04x      %-40s      [%s]\n", odList.Index[i], name,
            //            otype2string(odList.ObjectCode[i]));
            // }
            // else
            // {
            //     printf("0x%04x      %-40s      [%s  maxsub(0x%02x / %d)]\n",
            //            odList.Index[i], name, otype2string(odList.ObjectCode[i]),
            //            odList.MaxSub[i], odList.MaxSub[i]);
            // }
            memset(&oeList, 0, sizeof(oeList));
            ecx_readOE(&m_Context, i, &odList, &oeList);
            while(EcatError) printf("- %s\n", ec_elist2string());

            if(odList.ObjectCode[i] != OTYPE_VAR)
            {
                int l = sizeof(max_sub);
                ecx_SDOread(&m_Context, slaveAddress, odList.Index[i], 0, FALSE, &l, &max_sub, EC_TIMEOUTRXM);
            }
            else {
                max_sub = odList.MaxSub[i];
            }

            // for( j = 0 ; j < max_sub+1 ; j++)
            // {
            //     if ((oeList.DataType[j] > 0) && (oeList.BitLength[j] > 0))
            //     {
            //         snprintf(name, sizeof(name) - 1, "\"%s\"", oeList.Name[j]);
            //         printf("    0x%02x      %-40s      [%-16s %6s]      ", j, name,
            //                dtype2string(oeList.DataType[j], oeList.BitLength[j]),
            //                access2string(oeList.ObjAccess[j]));
            //         if ((oeList.ObjAccess[j] & 0x0007))
            //         {
            //             printf("%s", SDO2string(slaveAddress, odList.Index[i], j, oeList.DataType[j]));
            //         }
            //         printf("\n");
            //     }
            // }
        }
    }
    else
    {
        while(EcatError) printf("%s", ec_elist2string());
    }
  }

}  // namespace Controller::Ethercat
