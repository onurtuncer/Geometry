/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef MASTER_H__
#define MASTER_H__

#include <memory>
#include <vector>
#include <chrono>
#include <ctime>

#include "ParametricDevice.h"
/* #include "MasterConfiguration.h" */
#include "UpdateMode.h"
#include "BusBase.h"
#include "Core/Parameter/ParameterManager.h"

namespace Controller::Ethercat {

/*!
 * Ethercat Master Class.
 * Offers a simple API to:
 * - Attach devices of type EthercatDevice that shall be managed.
 * - Startup the EtherCAT communication and configure the attached devices
 * - Update the communication at a constant rate if desired
 * - Shutdown the communication
 */

class Master {

  public:
    Master(const std::string& configPath, std::shared_ptr<ParameterManager> pm)
      : m_ConfigPath(configPath), m_ParameterManagerPtr(pm){/*empty*/};
    
    void Initialize();
    void CreateEthercatBus();
    bool AttachDevice(std::shared_ptr<ParametricDevice> device);
    bool Startup();

    std::string GetNetworkInterface() const;

  /*!
   * Update the PDO communication.
   * Propagate the EtherCAT frame(s) through the network.
   * This function needs to be called at a constant rate.
   * There are three options:
   *   1. use updateMode = UpdateMode::NonStandalone if the timing is handled externally.
   *   2. use updateMode = UpdateMode::StandaloneEnforceRate if the call shall
   *      create the necessary timeout such that the average update rate corresponds
   *      to the configured timestep.
   *   3. use updateMode == UpdateMode::StandaloneEnforceStep if the call shall
   *      create the necessary timeout such that the update time step corresponds
   *      to the configured time step.
   * @param[in] updateMode select the update mode.
   */
  void Update(UpdateMode updateMode);
  void Shutdown();

  /*!
   * Pre shutdown communication.
   * Call preShutdown() of every attached device.
   * This function needs to be executed outside of the communicatino update thread.
   * PDO communication needs to continue until this funtion returns. */
  void PreShutdown();
  BusBase* GetBusPtr() { return m_Bus.get(); }

// Configuration
public:

  // /*!
  //  * Load a configuration.
  //  * @param[in] configuration EthercatMasterConfiguration.
  //  */
  // void LoadMasterConfiguration(const MasterConfiguration& configuration);

  // /*!
  //  * Return the active configuration.
  //  * @return configuration_
  //  */
  // MasterConfiguration GetConfiguration();

  /*!
   * Set the priority of the calling thread.
   * The following pthread parameters are set (man pthread_setschedparam):
   * - SCHED_FIFO
   * - Priority: priority (higher number means higher priority);
   *   Check `chrt -m` to see the max number for your system.
   *   Default: 90, works good on most modern machines
   * @warning This function needs to be called from within the thread executing
   * the communication update. If handle threads externally then a call to this
   * function can be omitted.
   * @note This requires pthreads and will thus only work on POSIX compliant
   * systems (e.g. linux)
   * @note Check that the user owning this process has the capabilities to change
   * scheduling parameters (/etc/security/limits.conf, man limits.conf)
   * @param[in] priority Prioirity of the calling thread.
   * Default: 99, Range on most systems: 1 - 99
   * @param[in] cpu_core. Allows locking the thread to a certain cpu core to avoid the thread hopping
   * from core to core. Default -1: Dont attach to any core. Has to be < than number of avaible cores
   * @return True if successful
   */
  bool SetRealtimePriority(int priority = 99, int cpu_core = -1) const;

  /*!
   * Resets the update rate scheduler (heartbeat reset).
   * Call this RIGHT BEFORE restarting PDO communication after an
   * interruption, i.e. right before the newly first call to update().
   * The calling thread shall be the same running the update loop.
   * @note Does not have to be called on the FIRST startup of the communication
   * (if update() is not called outsied of the update loop before, which it
   * shouldn't be anyway).
   */
  void ResetUpdateScheduler() { m_FirstUpdate = true; }

protected:
  std::unique_ptr<BusBase> m_Bus{nullptr};
  std::vector<std::shared_ptr<Device>> m_Devices;
/*   MasterConfiguration m_Configuration; */
  unsigned int m_RateTooLowCounter{0};

  timespec m_SleepEnd{0, 0};
  timespec m_LastWakeup{0, 0};
  long int m_TimestepNs{0};
  bool m_FirstUpdate{true};

protected:
  bool DeviceExists(const std::string& name);

  /*!
   * Let the update thread sleep such that the desired update rate is created.
   * - If enforceRate is true:
   *   Compensate for update cycles that took to long by sleeping for a shorter time period.
   *   The average rate will correspond to the desired rate (if possible).
   * - If enforceRate is false:
   *   Do not compensate for update cycles that took too long.
   *   Every timestep is kept as close to the desired value as possible.
   */
  void CreateUpdateHeartbeat(bool enforceRate);

  private:
    std::string m_ConfigPath;
    std::shared_ptr<ParameterManager> m_ParameterManagerPtr;
  };

} // namespace Controller::Ethercat

#endif // MASTER_H__
