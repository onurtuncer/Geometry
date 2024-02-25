/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef _CONFIGURATION_PARSER_H__
#define _CONFIGURATION_PARSER_H__

#include <yaml-cpp/yaml.h>
#include <string>
#include "Core/Log/Log.h"
#include "Configuration.h"

namespace Controller::Ethercat::DS401 {

  class ConfigurationParser {

    public:

      ConfigurationParser() = delete;
      explicit ConfigurationParser(const std::string& filename);
      explicit ConfigurationParser(YAML::Node configNode);

      Configuration GetConfiguration() const;

    private:
      int numberOfDigitalInputs;

      int numberOfDigitalOutputs;

      int numberOfAnalogInputs;

      int numberOfAnalogOutputs;

      int digitalInputMappingStartIndex;

      int digitalOutputMappingStartIndex;

      int analogInputMappingStartIndex;

      int analogOutputMappingStartIndex;

      void ParseConfiguration(YAML::Node configNode);

    private:

      Configuration m_Configuration;
  };

} // namespace Controller::Ethercat::DS401

#endif // _CONFIGURATION_PARSER_H__
