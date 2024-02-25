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

#ifndef YASKAWA_H
#define YASKAWA_H

#include "Ethercat/DS402/IServo.h"

namespace Controller::Ethercat::Devices {

  class Yaskawa : public Ethercat::DS402::IServo {

    public:

    //  static std::shared_ptr<Yaskawa> DeviceFromFile(const std::string& configFile, const std::string& name, const uint32_t address);
      static std::shared_ptr<Yaskawa> DeviceFromParameterManager(std::shared_ptr<ParameterManager> pm, const std::string& configPath, const std::string& name, const uint32_t address);
      Yaskawa(const std::string& name, const uint32_t address, const std::string& configPath, std::shared_ptr<ParameterManager> pm);
      virtual ~Yaskawa() override = default;

      bool Startup() override;
  };

} // namespace Controller::Ethercat::Devices

#endif // Yaskawa
