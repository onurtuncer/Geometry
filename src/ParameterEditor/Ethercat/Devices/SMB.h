/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN
  Use of this software is restricted to MILTEKSAN
  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Written by Bites, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#ifndef SMB_H
#define SMB_H

#include "Ethercat/DS402/IServo.h"
#include "Core/Parameter/ParameterManager.h"

namespace Controller::Ethercat::Devices {

  class SMB : public Controller::Ethercat::DS402::IServo {

  //  using namespace Controller::Ethercat::DS402;

    public:
     // static std::shared_ptr<SMB> DeviceFromFile(const std::string& configFile, const std::string& name, const uint32_t address);  // OBSOLETE
      static std::shared_ptr<SMB> DeviceFromParameterManager(std::shared_ptr<ParameterManager> pm, const std::string& configPath, const std::string& name, const uint32_t address);
      SMB(const std::string& name, const uint32_t address, const std::string& configPath, std::shared_ptr<ParameterManager> pm);
      virtual ~SMB() override = default;

      bool Startup() override;
    
   
  };

} // namespace Controller::Ethercat::Devices

#endif // SMB_H