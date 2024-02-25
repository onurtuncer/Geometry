/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <thread>
#include <pthread.h>
#include <cmath>
#include "Master.h"

#define SLEEP_EARLY_STOP_NS (50000) // less than 1e9 - 1!!
#define BILLION (1000000000)

namespace Controller::Ethercat {

  std::string Master::GetNetworkInterface() const{

    auto name = m_ParameterManagerPtr->GetParameter<std::string>(m_ConfigPath + ".name").getValue();
    return name;
  }

  void Master::Initialize() {

    using namespace std::chrono_literals;
    m_Devices.clear();
    // m_Configuration = configuration;

    m_TimestepNs = floor(m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".timeStep").getValue() * 1e9);
    CreateEthercatBus();
  }

/*   MasterConfiguration Master::GetConfiguration() {
      return m_Configuration;
  } */

  void Master::CreateEthercatBus(){
      m_Bus.reset(new BusBase(GetNetworkInterface()));
  }

  bool Master::AttachDevice(std::shared_ptr<ParametricDevice> device){

    std::stringstream ss;

    if (DeviceExists(device->GetName())){
      ss << "Cannot attach device with name '" << device->GetName()
         << "' because it already exists." << std::endl;
      CONTROLLER_CORE_WARN(ss.str());
      return false;
    }

    m_Bus->AddSlave(device);
    device->SetBusBasePointer(m_Bus.get());
    device->SetTimeStep(m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".timeStep").getValue());
    m_Devices.push_back(device);

    ss << "Attached device '"
                      << device->GetName()
                      << "' to address "
                      << device->GetAddress();
    CONTROLLER_CORE_INFO(ss.str());

    return true;
  }

  bool Master::Startup(){

    bool success = true;

    success &= m_Bus->Startup(false);

    // for(const auto & device : m_Devices) {

    //   if(!m_Bus->WaitForState(EC_STATE_SAFE_OP, device->GetAddress(), 50, 0.05))
    //     CONTROLLER_CORE_ERROR("Not in safe op mode after startup!");
    //   m_Bus->SetState(EC_STATE_OPERATIONAL, device->GetAddress());
    //   // success &= m_Bus->WaitForState(EC_STATE_OPERATIONAL, device->GetAddress(), 50, 0.05);
    // }

    m_Bus->SetState(EC_STATE_OPERATIONAL);
    m_Bus->WaitForState(EC_STATE_OPERATIONAL);

    if(!success)
      CONTROLLER_CORE_ERROR("[EthercatMaster:] Startup not successful.");
    return success;
  }

  void Master::Update(UpdateMode updateMode){

    if(m_FirstUpdate){
      clock_gettime(CLOCK_MONOTONIC, &m_LastWakeup);
      m_SleepEnd = m_LastWakeup;
      m_FirstUpdate = false;
    }

    m_Bus->UpdateWrite();
    
    m_Bus->UpdateRead();

    // create update heartbeat if in standalone mode
    switch(updateMode){

      case UpdateMode::StandaloneEnforceRate:
        CreateUpdateHeartbeat(true);
        break;
      case UpdateMode::StandaloneEnforceStep:
        CreateUpdateHeartbeat(false);
        break;
      case UpdateMode::NonStandalone:
        break;
    } // switch
  }

  void Master::Shutdown(){

    m_Bus->SetState(EC_STATE_INIT);
    m_Bus->Shutdown();
  }

  void Master::PreShutdown() {

     for(auto & device : m_Devices)
        device->PreShutdown();
  }

  bool Master::DeviceExists(const std::string& name){

    for (const auto& device : m_Devices) {
      if (device->GetName() == name) {
        return true;
      }
    }
    return false;
  }

  bool Master::SetRealtimePriority(int priority, int cpuCore) const {

    bool success = true;
    //Handle to our thread
    pthread_t thread = pthread_self();
    //First set the priority of the thread in the scheduler to the passed priority (99 is max)
    sched_param param;
    param.sched_priority = priority;
    int errorFlag = pthread_setschedparam(thread, SCHED_FIFO, &param);

    std::stringstream ss;

    if(errorFlag != 0){
      ss << "[EthercatMaster::SetRealtimePriority]"
                        << " Could not set thread priority. Check limits.conf or"
                        << " execute as root";
      CONTROLLER_CORE_ERROR(ss.str());
      success &= false;
    }

    //Allow attaching the thread to a certain cpu core
    //Create an empty cpu set for the scheduler
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    //Obtain amount of cpus
    int numberOfCPUs = sysconf(_SC_NPROCESSORS_ONLN);

    //In case the user passed a core value > 0
    if(cpuCore > 0 ) {
        //check if the core is < than the number of available cpus
        if(cpuCore >= numberOfCPUs) {
            ss << "[EthercatMaster::SetRealtimePriority]" <<
                  "Tried to attach thread to core: " << cpuCore << " even though the computer only has: " << numberOfCPUs  << " core(s)!";
            CONTROLLER_CORE_ERROR(ss.str());
            return false;
        }
        //Set the core
        CPU_SET(cpuCore, &cpuset);
        //Tell the scheduler our preferences
        errorFlag = pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset);
        if(errorFlag != 0) {
            ss << "EthercatMaster::setRealtimePriority]" <<
                            "Could not assign ethercat thread to single cpu core: "
                              << errorFlag;
            CONTROLLER_CORE_ERROR(ss.str());
            success &= false;
        }

    }
    return success;
  }


  ////////////////////////////
  // Timing functionalities //
  ////////////////////////////

  // true if ts1 < ts2
  inline bool TimespecSmallerThan(timespec* ts1, timespec* ts2){

    return (ts1->tv_sec < ts2->tv_sec || (ts1->tv_sec == ts2->tv_sec && ts1->tv_nsec < ts2->tv_nsec));
  }

  inline void HighPrecisionSleep(timespec ts){

    if(ts.tv_nsec >= SLEEP_EARLY_STOP_NS){
      ts.tv_nsec -= SLEEP_EARLY_STOP_NS;
    } else {
      ts.tv_nsec += BILLION - SLEEP_EARLY_STOP_NS;
      ts.tv_sec -= 1;
    }
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ts, nullptr);

    // busy waiting for the remaining time
    timespec now;
    do {
      clock_gettime(CLOCK_MONOTONIC, &now);
    } while(TimespecSmallerThan(&now, &ts));
  }


  inline void AddNsecsToTimespec(timespec *ts, long int ns){

    if(ts->tv_nsec < BILLION - (ns % BILLION)){
      ts->tv_nsec += ns % BILLION;
      ts->tv_sec += ns / BILLION;
    } else {
      ts->tv_nsec += (ns % BILLION) - BILLION;
      ts->tv_sec += ns / BILLION + 1;
    }
  }

  inline long int GetTimeDiffNs(timespec t_end, timespec t_start){

    return BILLION*(t_end.tv_sec - t_start.tv_sec) + t_end.tv_nsec - t_start.tv_nsec;
  }

  void Master::CreateUpdateHeartbeat(bool enforceRate){

    if(enforceRate){
      // since we do sleep in absolute times keeping the rate constant is trivial:
      // we simply increment the target sleep wakeup time by the timestep in every
      // iteration.
      AddNsecsToTimespec(&m_SleepEnd, m_TimestepNs);
    } else {
      // sleep until m_TimeStepNs nanoseconds from last wakeup time
      m_SleepEnd = m_LastWakeup;
      AddNsecsToTimespec(&m_SleepEnd, m_TimestepNs);
    }

    timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);

    // we are late.
    if(TimespecSmallerThan(&m_SleepEnd, &now)){

        ++m_RateTooLowCounter;

      // prevent the creation of a too low update step
      auto rateCompensationCoefficient = m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".rateCompensationCoefficient").getValue();
      auto updateRateTooLowWarnThreshold = m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".updateRateTooLowWarnThreshold").getValue();

      AddNsecsToTimespec(&m_LastWakeup, static_cast<long int>(rateCompensationCoefficient * m_TimestepNs));
      // need to sleep a bit
      if(TimespecSmallerThan(&now, &m_LastWakeup)){
        if(m_RateTooLowCounter >= updateRateTooLowWarnThreshold){
          // CONTROLLER_CORE_WARN("[EthercatMaster::CreateUpdateHeartbeat]: update rate too low.");
        }

        HighPrecisionSleep(m_LastWakeup);
        clock_gettime(CLOCK_MONOTONIC, &m_LastWakeup);

      // do not violate the minimum time step
      } else {
        if(m_RateTooLowCounter >= updateRateTooLowWarnThreshold){
          // CONTROLLER_CORE_WARN("[EthercatMaster::CreateUpdateHeartbeat]: update rate too low.");
        }
        clock_gettime(CLOCK_MONOTONIC, &m_LastWakeup);
      }
      return;

    // on time
    } else {
      m_RateTooLowCounter = 0;
      HighPrecisionSleep(m_SleepEnd);
      clock_gettime(CLOCK_MONOTONIC, &m_LastWakeup);
    }
  }

} // namespace Controller::Ethercat
