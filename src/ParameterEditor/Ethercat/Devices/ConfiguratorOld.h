/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef DEVICE_CONFIGURATOR_H__
#define DEVICE_CONFIGURATOR_H__

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <type_traits>
#include "DeviceTypes.h"
#include "Ethercat/Master.h"
#include "Ethercat/Devices/XMC.h"
#include "Ethercat/Devices/DeltaIO.h"
#include "Ethercat/Devices/SMB.h"
#include "Ethercat/Devices/Yaskawa.h"

#include "../../Motion/TrajectoryGeneratorSettings.h"

namespace Controller::Ethercat::Devices {

  class Configurator {

    public:

    
      struct SlaveEntry {

          SlaveType type;
          std::string name;
          std::string config_path;

          uint32_t ethercat_address;
          std::string ethercat_bus;
          std::string ethercat_pdo_type;
      };

      explicit Configurator(std::string path, bool startup = false);
      virtual ~Configurator() = default;

      std::vector<std::shared_ptr<Controller::Ethercat::Master>> GetMasters();
      std::vector<std::shared_ptr<Controller::Ethercat::Device>> GetSlaves();
      std::shared_ptr<Controller::Ethercat::Device> GetSlave(std::string name);

      const Controller::Ethercat::MasterConfiguration &GetMasterConfiguration() const {
        return m_MasterConfiguration;
      }

      const Controller::Motion::TrajectoryGeneratorSettings &GetTrajectoryGeneratorSettings() const {
        return m_TrajectoryGeneratorSettings;
      }

      const SlaveEntry& GetInfoForSlave(const std::shared_ptr<Controller::Ethercat::Device>& slave);
      std::shared_ptr<Master> GetMaster();
      const std::string& GetSetupFilePath();

      /**
       * @brief getSlavesOfType - return all slaves of type T (vector of shared_ptr).
       * @note Warning cache the result if you need them on a regular base. Might have bad performance
       */
      template<typename T, typename dummy = std::enable_if_t<std::is_base_of_v<Controller::Ethercat::Device, T>>>
      std::vector<std::shared_ptr<T>> GetSlavesOfType() {

          std::vector<std::shared_ptr<T>> slaves;

          for(auto& slave : m_Slaves) {

              auto ptr = std::dynamic_pointer_cast<T>(slave);
              if(ptr) {
                  slaves.push_back(ptr);
              }
          }
          return slaves;
      }
    void parseSlaves();

    private:
      //Stores the general master configuration.
      //If slaves on multiple bus interfaces are detected, the bus interface in this object will be the interface of the last configured interface
      Controller::Ethercat::MasterConfiguration m_MasterConfiguration;
      Controller::Motion::TrajectoryGeneratorSettings m_TrajectoryGeneratorSettings;
      std::vector<std::shared_ptr<Controller::Ethercat::Master>> m_Masters; //Vector of all configured masters
      std::vector<std::shared_ptr<Controller::Ethercat::Device>> m_Slaves; //Vector of all configured slaves (For all masters)
      std::vector<SlaveEntry> m_SlaveEntries;     //List of all parsed slave entries from the setup.yaml
      std::map<std::shared_ptr<Controller::Ethercat::Device>, SlaveEntry> m_SlaveToEntryMap; //Map that helps finding the right slave entry for a certain slave

      void ParseFile(std::string path);
      void Setup(bool startup);

      std::string HandleFilePath(const std::string& path, const std::string& setup_file_path) const;
      std::string m_SetupFilePath = "";
};

} // namespace Controller::Ethercat::Devices

#endif // DEVICE_CONFIGURATOR_H__
