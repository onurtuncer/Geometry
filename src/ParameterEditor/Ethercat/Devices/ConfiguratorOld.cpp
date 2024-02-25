/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <filesystem>
#include <yaml-cpp/yaml.h>
#include "Core/Log/Log.h"
#include "ConfiguratorOld.h"

namespace Controller::Ethercat::Devices {

  static bool PathExists(std::string& path) {

    return std::filesystem::exists(path);
  }

  Configurator::Configurator(std::string path, bool startup):
      m_SetupFilePath(path) {

      ParseFile(m_SetupFilePath);
      Setup(startup);
      CONTROLLER_CORE_TRACE("[EthercatDeviceConfigurator] Parsing and setup finished");
  }

  std::vector<std::shared_ptr<Controller::Ethercat::Master>> Configurator::GetMasters() {

      return m_Masters;
  }

  std::vector<std::shared_ptr<Controller::Ethercat::Device>> Configurator::GetSlaves() {
    
      return m_Slaves;
  }

  std::shared_ptr<Controller::Ethercat::Device> Configurator::GetSlave(std::string name) {

      for(auto& slave : m_Slaves) {
          if(slave->GetName() == name)
              return slave;
      }
      throw std::runtime_error("[EthercatDeviceConfigurator] Slave: " + name + " not found");
  }

  const Configurator::SlaveEntry& Configurator::GetInfoForSlave(const std::shared_ptr<Controller::Ethercat::Device>& slave) {

      return m_SlaveToEntryMap[slave];
  }

  std::shared_ptr<Controller::Ethercat::Master> Configurator::GetMaster() {

      if(m_Masters.size() > 1)
          throw std::runtime_error("[EthercatDeviceConfigurator] More than one master configured, use getMasters instead of master");

      if(m_Masters.empty())
          throw std::out_of_range("[EthercatDeviceConfigurator] No master configured");

      return m_Masters[0];
  }

  const std::string& Configurator::GetSetupFilePath() {

      return m_SetupFilePath;
  }

  void Configurator::ParseFile(std::string path)  {

      //Check if file exists
      if(!PathExists(path))
          throw std::runtime_error("[EthercatDeviceConfigurator] File not found: "+path);
      //Load into yaml
      YAML::Node node = YAML::LoadFile(path);

      //Ethercat master configuration
      if(node["ethercat_master"]) {

          const auto ecat_master_node = node["ethercat_master"];

          if(ecat_master_node["time_step"]) {
              m_MasterConfiguration.timeStep = ecat_master_node["time_step"].as<double>();
          }
          else {
              throw std::runtime_error("[EthercatDeviceConfigurator] Node time_step missing in ethercat_master");
          }
          if(ecat_master_node["update_rate_too_low_warn_threshold"]) {
              m_MasterConfiguration.updateRateTooLowWarnThreshold = ecat_master_node["update_rate_too_low_warn_threshold"].as<int>();
          }
          else {
              throw std::runtime_error("[EthercatDeviceConfigurator] Node update_rate_too_low_warn_threshold missing in ethercat_master");
          }
      }
      else {
          throw std::runtime_error("[EthercatDeviceConfigurator] Node ethercat_master is missing in yaml");
      }

      //Check if node is ethercat_devices
      if(node["ethercat_devices"]) {
          //Get all children
          const YAML::Node& nodes = node["ethercat_devices"];
          if(nodes.size() == 0)
          CONTROLLER_CORE_TRACE("[EthercatDeviceConfigurator] No devices defined in yaml");
            //   throw std::runtime_error("[EthercatDeviceConfigurator] No devices defined in yaml");

          //Iterate through child nodes
          for(YAML::const_iterator it = nodes.begin(); it != nodes.end(); ++it) {
              const YAML::Node& child = *it;
              SlaveEntry entry;
              //type - entry
              if(child["type"]) {

                  auto typeString = child["type"].as<std::string>();

                  if(typeString == "XMC") {
                      entry.type = SlaveType::XMC;
                  }
                  else if(typeString == "DeltaIO")  {
                      entry.type = SlaveType::DeltaIO;
                  }
                  else if(typeString == "SMB")  {
                      entry.type = SlaveType::SMB;
                  }
                  else if(typeString == "Yaskawa") {
                      entry.type = SlaveType::Yaskawa;
                  }
                  else if(typeString == "Beckhoff")  {
                      entry.type = SlaveType::Beckhoff;
                  }
                  else {
                      throw std::runtime_error("[EthercatDeviceConfigurator] " + typeString + " is an undefined type of ethercat device");
                  }
              }
              else {
                  throw std::runtime_error("[EthercatDeviceConfigurator] Node: " + child.Tag() + " has no entry type");
              }

              //name - entry
              if(child["name"])  {

                  entry.name = child["name"].as<std::string>();
              }
              else  {
                  throw std::runtime_error("[EthercatDeviceConfigurator] Node: " + child.Tag() + " has no entry name");
              }

              //configuration_file - entry
              if(child["configuration_file"]) {
                  entry.config_file_path = child["configuration_file"].as<std::string>();
              }
              else  {
                  throw std::runtime_error("[EthercatDeviceConfigurator] Node: " + child.Tag() + " has no entry configuration_file");
              }

              //ethercat_bus_address - entry
              if(child["ethercat_address"])  {
                  entry.ethercat_address = child["ethercat_address"].as<int>();
              }
              else  {
                  throw std::runtime_error("[EthercatDeviceConfigurator] Node: " + child.Tag() + " has no entry ethercat_bus_address");
              }

              //ethercat_bus - entry
              if(child["ethercat_bus"]) {
                  entry.ethercat_bus = child["ethercat_bus"].as<std::string>();
              }
              else {
                  throw std::runtime_error("[EthercatDeviceConfigurator] Node: " + child.Tag() + " has no entry ethercat_bus");
              }

              //ethercat_pdo_type - entry
            //   if(entry.type == SlaveType::? || entry.type == SlaveType::?)
            //   {
            //       if(child["ethercat_pdo_type"]) {
            //           entry.ethercat_pdo_type = child["ethercat_pdo_type"].as<std::string>();
            //       }
            //       else {
            //           throw std::runtime_error("[EthercatDeviceConfigurator] Node: " + child.Tag() + " has no entry ethercat_pdo_type");
            //       }
            //   }

              m_SlaveEntries.push_back(entry);
          }
      }
      else {
          throw std::runtime_error("[EthercatDeviceConfigurator] Node ethercat devices missing in yaml");
      }
       
 
}

  void Configurator::Setup(bool startup)  {

        m_Slaves.resize(m_SlaveEntries.size());
      for(auto& entry : m_SlaveEntries) {

         std::stringstream ss;

          ss << "[EthercatDeviceConfigurator] Creating slave: " << entry.name << std::endl;
          CONTROLLER_CORE_INFO(ss.str());

          std::shared_ptr<Controller::Ethercat::Device> slave = nullptr;

          switch (entry.type) {

            case SlaveType::XMC: {

                std::string configuration_file_path = HandleFilePath(entry.config_file_path,m_SetupFilePath);
                slave = XMC::DeviceFromFile(configuration_file_path, entry.name, entry.ethercat_address);
            }
            break;
            case SlaveType::DeltaIO: {

                std::string configuration_file_path = HandleFilePath(entry.config_file_path,m_SetupFilePath);
                slave = DeltaIO::DeviceFromFile(configuration_file_path, entry.name, entry.ethercat_address);
            }
            break;
            case SlaveType::SMB: {

                std::string configuration_file_path = HandleFilePath(entry.config_file_path, m_SetupFilePath);
                std::cout << "SMB configuration file path: " << m_SetupFilePath << std::endl;
                std::cout << "SMB name: " << entry.config_file_path << std::endl;
                std::cout << "SMB ethercat_address: " << configuration_file_path << std::endl;
                slave = SMB::DeviceFromFile(configuration_file_path, entry.name, entry.ethercat_address);
            }
            break;
            case SlaveType::Yaskawa: {

                std::string configuration_file_path = HandleFilePath(entry.config_file_path, m_SetupFilePath);
                std::cout << "Yaskawa configuration file path: " << m_SetupFilePath << std::endl;
                std::cout << "Yaskawa name: " << entry.config_file_path << std::endl;
                std::cout << "Yaskawa ethercat_address: " << configuration_file_path << std::endl;
                slave = Yaskawa::DeviceFromFile(configuration_file_path, entry.name, entry.ethercat_address);
            }
            break;

            default:
                throw std::runtime_error("[EthercatDeviceConfigurator] Not existing EthercatSlaveType passed");
            break;
          } // switch

          m_Slaves.at(entry.ethercat_address-1) = slave;
          m_SlaveToEntryMap.insert({m_Slaves.at(entry.ethercat_address-1), entry});
      }

      //Create master for each bus needed

      for(auto& slave : m_Slaves) {
          //Find entry object for each slave because the slave base class does not provide info about the interface name
          SlaveEntry entry = m_SlaveToEntryMap[slave];

          //See if we already have a master for that interface
          bool masterFound = false;

          for(auto& master : m_Masters) {
            
              if(master->GetConfiguration().networkInterface == entry.ethercat_bus) {
                  masterFound = true;

                  if(!master->AttachDevice(slave)) {
                      throw std::runtime_error("[EthercatDeviceConfigurator] could not attach slave: " + slave->GetName() + " to master on interface: " + master->GetConfiguration().networkInterface);
                  }
                  break;
              }
          }

          if(!masterFound) {

              auto master = std::make_shared<Controller::Ethercat::Master>();
              m_MasterConfiguration.networkInterface = entry.ethercat_bus;
              master->LoadMasterConfiguration(m_MasterConfiguration);

              m_Masters.push_back(master);

              //And attach the slave
              if(!master->AttachDevice(slave)) {
                  throw std::runtime_error("[EthercatDeviceConfigurator] could not attach slave: "
                    + slave->GetName() + " to master on interface: " + master->GetConfiguration().networkInterface);
              }
          }

      }

      if(startup) {

          for(auto& master : m_Masters) {

              CONTROLLER_CORE_INFO("Starting master on: " + master->GetConfiguration().networkInterface);

              if(!master->Startup()) {
                  throw std::runtime_error("[EthercatDeviceConfigurator] could not start master on interface: "
                     + master->GetConfiguration().networkInterface);
              }
          }
      }
  }
   void Configurator::parseSlaves()
    {
        for (auto &slave : m_Slaves)
        {
            SlaveEntry entry = m_SlaveToEntryMap[slave];
            if (entry.type == SlaveType::XMC)
            {
                std::string configuration_file_path = HandleFilePath(entry.config_file_path, m_SetupFilePath);
            }
            else if (entry.type == SlaveType::DeltaIO)
            {
                std::string configuration_file_path = HandleFilePath(entry.config_file_path, m_SetupFilePath);
                auto deltaio = std::dynamic_pointer_cast<DeltaIO>(slave);
                if (deltaio)
                {
                    deltaio->LoadConfigFile(configuration_file_path);
                }
            }
            else if (entry.type == SlaveType::SMB)
            {
                std::string configuration_file_path = HandleFilePath(entry.config_file_path, m_SetupFilePath);
                auto smb = std::dynamic_pointer_cast<SMB>(slave);
                if (smb)
                {
                    smb->LoadConfigFile(configuration_file_path);
                }
            }
            else if (entry.type == SlaveType::Yaskawa)
            {
                std::string configuration_file_path = HandleFilePath(entry.config_file_path, m_SetupFilePath);
                auto yaskawa = std::dynamic_pointer_cast<Yaskawa>(slave);
                if (yaskawa)
                {
                    yaskawa->LoadConfigFile(configuration_file_path);
                }
            }
            else
            {
                throw std::runtime_error("[EthercatDeviceConfigurator] Not existing EthercatSlaveType passed");
            } // switch
        }
    }


  std::string Configurator::HandleFilePath(const std::string &path, const std::string &setup_file_path) const {

      std::string resultPath = "";
      if (path.front() == '/') {
          resultPath = path;
          // Path to the configuration file is absolute, use it as is.
      }
      else if (path.front() == '~') {
          // Path to the configuration file is absolute, need to replace '~' with the home directory.
          const char* homeDirectory = getenv("HOME");
          if (homeDirectory == nullptr)
              throw std::runtime_error("[EthercatDeviceConfigurator] Environment variable 'HOME' could not be evaluated.");
          resultPath = path;
          resultPath.erase(resultPath.begin());
          resultPath = homeDirectory + resultPath;
      }
      else {
          // Path to the configuration file is relative, need to append it to the path of the setup file.
          resultPath = setup_file_path.substr(0, setup_file_path.find_last_of("/")+1) + path;
      }
      if(!PathExists(resultPath))
          throw std::runtime_error("Path: " + resultPath + " does not exist");
      return  resultPath;
  }

} // namespace Controller::Ethercat::Devices