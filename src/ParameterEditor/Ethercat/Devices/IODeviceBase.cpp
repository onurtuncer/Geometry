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

#include "IODeviceBase.h"

namespace Controller::Ethercat::Devices {

bool IODeviceBase::LoadConfigFile(const std::string& fileName) {

    Controller::Ethercat::DS401::ConfigurationParser configurationParser(fileName);
    return LoadConfiguration(configurationParser.GetConfiguration());
  }

  bool IODeviceBase::LoadConfiguration(const Controller::Ethercat::DS401::Configuration& configuration) {

    m_Configuration = configuration;

    std::stringstream ss;
    ss << "[IO Device] Sanity check for '" << m_Name << "':" << std::endl;
    CONTROLLER_CORE_ERROR(ss.str());
    auto non_const_config = const_cast<Controller::Ethercat::DS401::Configuration&>(configuration);
    return non_const_config.SanityCheck();
  }

  Controller::Ethercat::DS401::Configuration IODeviceBase::GetConfiguration() const { return m_Configuration; }

  bool IODeviceBase::LoadConfigNode(YAML::Node configNode) {

    Controller::Ethercat::DS401::ConfigurationParser configurationParser(configNode);
    return LoadConfiguration(configurationParser.GetConfiguration());
  }


} // namespace Controller::Ethercat::Devices