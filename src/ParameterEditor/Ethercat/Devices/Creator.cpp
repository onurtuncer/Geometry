/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include "Core/Log/Log.h"
#include "Creator.h"

namespace Controller::Ethercat::Devices {

  Creator::Creator(std::shared_ptr<ParameterManager> param, bool startup):

      pm(param) {

      ReadFromManager();
      Create(startup);
      CONTROLLER_CORE_TRACE("[EthercatDeviceConfigurator] Read parameters from manager and setup finished");
  }


  std::vector<std::shared_ptr<Ethercat::ParametricDevice>> Creator::GetSlaves() {
    
      return m_Slaves;
  }

  std::shared_ptr<Ethercat::ParametricDevice> Creator::GetSlave(std::string name) {

      for(auto& slave : m_Slaves) {
          if(slave->GetName() == name)
              return slave;
      }
      throw std::runtime_error("[EthercatDeviceConfigurator] Slave: " + name + " not found");
  }

  const Creator::SlaveInfo& Creator::GetInfoForSlave(const std::shared_ptr<Ethercat::ParametricDevice>& slave) {

      return m_SlavePtrToInfoMap[slave];
  }

  std::shared_ptr<Ethercat::Master> Creator::GetMaster() {
      
      return m_MasterPtr;
  }

  void Creator::ReadFromManager()  {

    // Get master configuration

/*     m_MasterConfiguration.networkInterface = pm->GetParameter<std::string>("bus.name").getValue();
    m_MasterConfiguration.timeStep = pm->GetParameter<double>("bus.timeStep").getValue();
    m_MasterConfiguration.updateRateTooLowWarnThreshold = pm->GetParameter<unsigned int>("bus.updateRateTooLowWarnThreshold").getValue();
    m_MasterConfiguration.rateCompensationCoefficient = pm->GetParameter<double>("bus.rateCompensationCoefficient").getValue(); */

    //   pm1.AddParameter("channels.01.type", Parameter<int>(0)); // 0: milling, 1: turning

    // pm1.AddParameter("channels.01.number_of_axes",       Parameter<int>(3));
    // pm1.AddParameter("channels.01.kinematics_type",      Parameter<int>(0)); 

    std::string path = "channels.01.trajectory";

    m_TrajectoryGeneratorSettings.m_JerkLimit = pm->GetParameter<double>(path + ".jerklimit").getValue();
    m_TrajectoryGeneratorSettings.m_IsContouringEnabled = pm->GetParameter<bool>(path + ".contouring_enabled").getValue();
    m_TrajectoryGeneratorSettings.m_CorneringTolerance = pm->GetParameter<double>(path + ".cornering_tolerance").getValue();
    m_TrajectoryGeneratorSettings.m_SampleTime = pm->GetParameter<double>(path + ".sample_time").getValue();
    m_TrajectoryGeneratorSettings.m_AccelerationLimit = pm->GetParameter<double>(path + ".acceleration_limit").getValue();
    m_TrajectoryGeneratorSettings.m_DecelerationLimit = pm->GetParameter<double>(path + ".deceleration_limit").getValue();

    // Get servo entries 

    path = "channels.01";

    std::vector<std::string> servoNames = pm->GetParameter< std::vector<std::string>>(path + ".servo_names").getValue();
   
    std::string servoName;
    std::string ioName;

    for (const std::string& name : servoNames) {

        SlaveInfo info{};
     
        servoName = path + '.' + name;

        std::stringstream ss;
        ss << "Processing servo: " << servoName << std::endl;

        CONTROLLER_CORE_TRACE(ss.str());

        info.name = name;
        info.type = pm->GetParameter<Devices::SlaveType>(path + ".deviceType").getValue();
        info.ethercat_address = pm->GetParameter<uint32_t>(path + ".deviceType").getValue();
        info.config_path = path;
        info.ethercat_bus = pm->GetParameter<std::string>("bus.name").getValue();
        m_SlaveInfos.push_back(info);
    }   

    path = "bus.io";

    std::vector<std::string> ioNames = pm->GetParameter< std::vector<std::string>>(path + ".io_names").getValue();   


     for (const std::string& name : servoNames) {

        SlaveInfo info{};
     
        ioName = path + '.' + name;

        std::stringstream ss;

        ss << "Processing IO device: " << ioName << std::endl;

        info.name = name;
        info.type = pm->GetParameter<Devices::SlaveType>(path + ".deviceType").getValue();
        info.ethercat_address = pm->GetParameter<uint32_t>(path + ".deviceType").getValue();
        info.config_path = path;
        info.ethercat_bus = pm->GetParameter<std::string>("bus.name").getValue();
        m_SlaveInfos.push_back(info);
    }       
 
}

void Creator::Create(bool startup)  {

    m_Slaves.resize(m_SlaveInfos.size()); 

    for(auto& entry : m_SlaveInfos) {

         std::stringstream ss;

          ss << "[EthercatDeviceConfigurator] Creating slave: " << entry.name << std::endl;
          CONTROLLER_CORE_INFO(ss.str());

          std::shared_ptr<Ethercat::ParametricDevice> slave = nullptr;

          switch (entry.type) {

          /*   case SlaveType::XMC: {

                slave = XMC::DeviceFromParameterManager(entry.config_path, entry.name, entry.ethercat_address);
            }
            break; */
            case SlaveType::DeltaIO: {
      
                slave = DeltaIO::DeviceFromParameterManager(pm, entry.config_path, entry.name, entry.ethercat_address);
            }
            break;
            case SlaveType::SMB: {

                slave = SMB::DeviceFromParameterManager(pm, entry.config_path, entry.name, entry.ethercat_address);
            }
            break;
            case SlaveType::Yaskawa: {
    
                slave = Yaskawa::DeviceFromParameterManager(pm, entry.config_path, entry.name, entry.ethercat_address);
            }
            break;

            default:
                throw std::runtime_error("[EthercatDeviceConfigurator] Not existing EthercatSlaveType passed");
            break;
          } // switch

          m_Slaves.at(entry.ethercat_address-1) = slave;
          m_SlavePtrToInfoMap.insert({m_Slaves.at(entry.ethercat_address-1), entry});
      } 

//       //Create master for each bus needed

       auto m_MasterPtr = std::make_shared<Ethercat::Master>("bus", pm);
        //   m_MasterConfiguration.networkInterface = entry.ethercat_bus;
        m_MasterPtr->Initialize();

        //   m_Master = master;

       for(auto& slave : m_Slaves) {
          //Find entry object for each slave because the slave base class does not provide info about the interface name
          SlaveInfo info = m_SlavePtrToInfoMap[slave];

          //See if we already have a master for that interface

          //And attach the slave
          if(!m_MasterPtr->AttachDevice(slave)) {
                  throw std::runtime_error("[EthercatDeviceConfigurator] could not attach slave: "
                    + slave->GetName() + " to master on interface: " + m_MasterPtr->GetNetworkInterface());
          }
          
      } 

      if(startup) {

              CONTROLLER_CORE_INFO("Starting master on: " + m_MasterPtr->GetNetworkInterface());

              if(!m_MasterPtr->Startup()) {
                  throw std::runtime_error("[EthercatDeviceConfigurator] could not start master on interface: "
                     + m_MasterPtr->GetNetworkInterface());
              }       
      }
  }


} // namespace Controller::Ethercat::Devices