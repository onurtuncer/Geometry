/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN
  Provides context to visitor pattern implementation such that variable/function
  names and values can be passed alongside within the correct scope

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef ISLAVE_H
#define ISLAVE_H

#include <iostream>
#include <cstdint>
#include <memory>
#include <mutex>
#include <typeinfo>
#include "BusBase.h"

namespace Controller::Ethercat {

  /**
   * @brief      Base class for generic ethercat slaves using soem
   */
  class ISlave {
   public:
    /**
     * @brief      Struct defining the Pdo characteristic
     */
    struct PdoInfo {

      uint16_t rxPdoId = 0; // The id of the rx pdo
      uint16_t txPdoId = 0; // The id of the tx pdo
      uint16_t rxPdoSize = 0; // The size of the rx pdo
      uint16_t txPdoSize = 0;   // The size of the tx pdo
      uint32_t moduleId = 0;   // The value referencing the current pdo type on slave side
    };

    ISlave(BusBase* bus, const uint32_t address);
    ISlave();
    virtual ~ISlave() = default;

    /**
     * @brief      Returns the name of the slave.
     * @return     Name of the ethercat bus
     */
    virtual std::string GetName() const = 0;
    virtual bool Startup() = 0;
    virtual void UpdateRead() = 0;
    virtual void UpdateWrite() = 0;
    virtual void Shutdown() = 0;
    virtual PdoInfo GetCurrentPdoInfo() const = 0;

    void reloadODList();

    ec_ODlistt m_ODlist; // Object description list
    ec_OElistt m_OElist; // Object entry list

    /**
     * @brief      Set BusBase pointer
     */
    auto SetBusBasePointer(BusBase* bus) -> void {m_Bus = bus;}


    /**
     * @brief      Set physical EtherCAT address
     */
    auto SetAddress(uint32_t address) -> void {m_Address = address;}

    /**
     * @brief      Returns the bus address of the slave
     * @return     Bus address.
     */
    auto GetAddress() const -> uint32_t { return m_Address; }

    /*!
     * Send a writing SDO.
     * @param index          Index of the SDO.
     * @param subindex       Sub-index of the SDO.
     * @param completeAccess Access all sub-inidices at once.
     * @param value          Value to write.
     * @return True if successful.
     */
    template <typename Value>
    auto SendSdoWrite(const uint16_t index, const uint8_t subindex, const bool completeAccess, const Value value) -> bool {
      std::lock_guard<std::recursive_mutex> lock(m_Mutex);
      const bool success =  m_Bus->SendSdoWrite(m_Address, index, subindex, completeAccess, value);
      if(!success) {
        std::cout << "Error writing SDO.\tAddress: " << m_Address << "Index: " << (int)index
                          << "\nSubindex: " << (int)subindex << "\n Complete Access: "
                          << (int)completeAccess << "\nType: " << typeid(value).name() << std::endl;
      }
      return success;
    }

    /*!
     * Send a reading SDO.
     * @param index          Index of the SDO.
     * @param subindex       Sub-index of the SDO.
     * @param completeAccess Access all sub-inidices at once.
     * @param value          Return argument, will contain the value which was read.
     * @return True if successful.
     */
    template <typename Value>
    auto SendSdoRead(const uint16_t index, const uint8_t subindex, const bool completeAccess, Value& value) -> bool {
      std::lock_guard<std::recursive_mutex> lock(m_Mutex);
      const bool success = m_Bus->SendSdoRead(m_Address, index, subindex, completeAccess, value);
      if(!success) {
        std::stringstream ss;
        ss << "Error reading SDO.\tAddress: " << m_Address << "Index: " << (int)index
                          << "\nSubindex: " << (int)subindex << "\n Complete Access: "
                          << (int)completeAccess << "\nType: " << typeid(value).name() << std::endl;
        std::cout << ss.str();
      }
      return success;
    }

    /**
     * Send a generic reading SDO.
     * @warning Not implemented!
     */
    virtual bool SendSdoReadGeneric(const std::string& indexString, const std::string& subindexString, const std::string& valueTypeString,
                                    std::string& valueString);
    /**
     * Send a generic writing SDO.
     * @warning Not implemented!
     */
    virtual bool SendSdoWriteGeneric(const std::string& indexString, const std::string& subindexString, const std::string& valueTypeString,
                                     const std::string& valueString);

    /**
     * Send a special reading SDO to read SDOs of type visible string.
     * @param index          Index of the SDO.
     * @param subindex       Sub-index of the SDO.
     * @param value          Return argument, will contain the value which was read.
     * @return True if successful.
     */
    virtual bool SendSdoReadVisibleString(const uint16_t index, const uint8_t subindex, std::string& value);

    

   protected:
    /**
     * @brief      Prints a warning. Use this method to suppress compiler warnings
     */
    auto PrintWarnNotImplemented() -> void {
      std::cout << "Functionality is not implemented." << std::endl;
    }

    mutable std::recursive_mutex m_Mutex; // Mutex prohibiting simultaneous access to EtherCAT slave.
    BusBase* m_Bus{nullptr}; // Non owning pointer to the ethercat bus  //TODO make this a shared pointer
    uint32_t m_Address{0}; // The bus address
  };

  using ISlavePtr = std::shared_ptr<ISlave>;

}  // namespace Controller::Ethercat

#endif // ISLAVE_H
