/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef DEVICE_CREATOR_H__
#define DEVICE_CREATOR_H__

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <type_traits>
#include "DeviceTypes.h"
#include "Core/Parameter/ParameterManager.h"
#include "Ethercat/Master.h"
/* #include "Ethercat/MasterConfiguration.h" */
/* #include "Ethercat/Devices/XMC.h" */
#include "Ethercat/Devices/DeltaIO.h"
#include "Ethercat/Devices/SMB.h"
#include "Ethercat/Devices/Yaskawa.h"

#include "../../Motion/TrajectoryGeneratorSettings.h"

namespace Controller::Ethercat::Devices {

  class Creator {

    public:

      struct SlaveInfo {

          SlaveType type;
          std::string name;
          std::string config_path;

          uint32_t    ethercat_address;
          std::string ethercat_bus;
          std::string ethercat_pdo_type;
      };

      explicit Creator(std::shared_ptr<ParameterManager> param, bool startup = false);
      virtual ~Creator() = default;

      std::vector<std::shared_ptr<Ethercat::ParametricDevice>> GetSlaves();
      std::shared_ptr<Ethercat::ParametricDevice> GetSlave(std::string name);

/*       const Ethercat::MasterConfiguration& GetMasterConfiguration() const {
        return m_MasterConfiguration;
      } */

      // TODO this does not belong here! Rather in a motion related class...
      const Controller::Motion::TrajectoryGeneratorSettings& GetTrajectoryGeneratorSettings() const {
        return m_TrajectoryGeneratorSettings;
      }

      const SlaveInfo& GetInfoForSlave(const std::shared_ptr<Ethercat::ParametricDevice>& slave);
      std::shared_ptr<Master> GetMaster();
     /*  const std::string& GetSetupFilePath(); */

      /**
       * @brief getSlavesOfType - return all slaves of type T (vector of shared_ptr).
       * @note Warning cache the result if you need them on a regular base. Might have bad performance
       */
      template<typename T, typename dummy = std::enable_if_t<std::is_base_of_v<Ethercat::Device, T>>>
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

      void ReadFromManager();

      std::shared_ptr<ParameterManager> GetParameterManagerPtr() const {return pm;}

    private:
      //Stores the general master configuration.
      //If slaves on multiple bus interfaces are detected, the bus interface in this object will be the interface of the last configured interface
   /*    Ethercat::MasterConfiguration m_MasterConfiguration; */
      Motion::TrajectoryGeneratorSettings m_TrajectoryGeneratorSettings;
      std::shared_ptr<Ethercat::Master> m_MasterPtr; // Master pointer
      std::vector<std::shared_ptr<Controller::Ethercat::ParametricDevice>> m_Slaves; //Vector of all configured slaves (For all masters)
      std::vector<SlaveInfo> m_SlaveInfos;     //List of all parsed slave entries from the setup.yaml
      std::map<std::shared_ptr<Ethercat::ParametricDevice>, SlaveInfo> m_SlavePtrToInfoMap; //Map that helps finding the right slave entry for a certain slave

      void Create(bool startup);

      std::shared_ptr<ParameterManager> pm;
};

} // namespace Controller::Ethercat::Devices

#endif // DEVICE_CREATOR_H__