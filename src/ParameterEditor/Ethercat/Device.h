/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef DEVICE_H_
#define DEVICE_H_

#include <string>
#include <cstdint>
#include <memory>
#include <thread>
#include <chrono>
#include "BusBase.h"
#include "ISlave.h"

#define IO_CONFIG 0

namespace Controller::Ethercat {

  class Device : public ISlave {

    public:
      typedef std::shared_ptr<Device> SharedPtr;

  public:

    /*!
     * Set the update time step.
     * This value needs to correspond to the target time step used in the update
     * of the EtherCAT communication.
     * You don't have to update this value in the communication update loop.
     * This function does not have to be called manually when using the EthercatMaster.
     * @param[in] timeStep communication update time step.
     */
    virtual void SetTimeStep(double timeStep);

    /*!
     * PDO preparation for communication shutdown.
     * Things that need to be done before the PDO communication stops.
     * This function must be called in a thread separated from the communication
     * update thread!
     * The PDO communication will continue during the execution of this function.
     * Pay attention to not block updateRead or updateWrite with mutexes and don't
     * create data races.
     * This function should only return once the desired state of the drive has been reached.
     */
    virtual void PreShutdown() {};
    virtual std::string GetName() const override {return m_Name;}
    virtual void SetName(const std::string& name) {m_Name = name;}

  public:

    /*!
     * Send a write SDO of type Value to the device and confirm by reading
     * the same value afterwards.
     * @note Using SDO and PDO communication simultaneously is usually a bad idea.
     * @param[in] index index of the SDO (16 bit).
     * @param[in] subindex sub index of the SDO (8 bit).
     * @param[in] completeAcces]ns true if all subindices are read.
     * @param[in] value Value which is read from the device.
     * @param[in] delay Delay between the writing and reading SDO calls (in microseconds).
     * @return true if the read value corresponds to the written value.
     */
    template <typename Value>
    bool SdoVerifyWrite(const uint16_t index, const uint8_t subindex, const bool completeAccess, Value value, float delay = 0) {

      Value testVal;
      bool success = true;
      success &= SendSdoWrite(index, subindex, completeAccess, value);
      std::this_thread::sleep_for(std::chrono::microseconds(static_cast<unsigned int>(delay)));
      success &= SendSdoRead(index, subindex, completeAccess, testVal);
      return (success & (value == testVal));
    }

  protected:
    std::string m_Name;
    double m_TimeStep{0.0};
  };

} // namespace Controller::Ethercat

#endif // DEVICE_H_
