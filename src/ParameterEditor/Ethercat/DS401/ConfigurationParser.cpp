/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <sstream>
#include "Core/Log/Log.h"
#include "ConfigurationParser.h"

namespace Controller::Ethercat::DS401 {

  template <typename T>
  bool GetValueFromFile(YAML::Node& yamlNode, const std::string& varName, T& var) {

    std::stringstream ss;

    if (!yamlNode[varName].IsDefined()) {
      ss << "[ConfigurationParser::parseConfiguration]: field '" << varName
        << "' is missing. Default value will be used." << std::endl;
      CONTROLLER_CORE_WARN(ss.str());
      return false;
    }
    try {
      T tmpVar = yamlNode[varName].as<T>();
      var = tmpVar;
      return true;
    } catch (...) {
      ss << "[ConfigurationParser::getValueFromFile] Error while parsing value \""
         << varName << "\", default values will be used" << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return false;
    }
  }

  ConfigurationParser::ConfigurationParser(const std::string& filename) {

    std::stringstream ss;

    YAML::Node configNode;
    try {
      configNode = YAML::LoadFile(filename);
    } catch (...) {
      ss << "[ConfigurationParser::ConfigurationParser] Loading YAML configuration file '"
         << filename << "' failed." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
    }
    ParseConfiguration(configNode);
  }

  ConfigurationParser::ConfigurationParser(YAML::Node configNode) {

    ParseConfiguration(configNode);
  }

  void ConfigurationParser::ParseConfiguration(YAML::Node configNode) {

    if (configNode["XMC"].IsDefined()) {
      /// A new node for the XMC class
      YAML::Node xmcNode = configNode["XMC"];

      unsigned int configRunSdoVerifyTimeout;
      if (GetValueFromFile(xmcNode, "config_run_sdo_verify_timeout", configRunSdoVerifyTimeout)) {
        m_Configuration.configRunSdoVerifyTimeout = configRunSdoVerifyTimeout;
      }

    }

     if (configNode["DELTA"].IsDefined()) {
      /// A new node for the DeltaIO class
      YAML::Node deltaNode = configNode["DELTA"];

      unsigned int configRunSdoVerifyTimeout;
      if (GetValueFromFile(deltaNode, "config_run_sdo_verify_timeout", configRunSdoVerifyTimeout)) {
        m_Configuration.configRunSdoVerifyTimeout = configRunSdoVerifyTimeout;
      }

    }

    /// The configuration options for the DS-401 IO module ("hardware")
    if (configNode["Hardware"].IsDefined()) {
      YAML::Node hardwareNode = configNode["Hardware"];

      if (GetValueFromFile(hardwareNode, "number_of_digital_inputs", numberOfDigitalInputs)) {
        m_Configuration.numberOfDigitalInputs = numberOfDigitalInputs;
      }

      if (GetValueFromFile(hardwareNode, "number_of_digital_outputs", numberOfDigitalOutputs)) {
        m_Configuration.numberOfDigitalOutputs = numberOfDigitalOutputs;
      }

      if (GetValueFromFile(hardwareNode, "number_of_analog_inputs", numberOfAnalogInputs)) {
        m_Configuration.numberOfAnalogInputs = numberOfAnalogInputs;
      }

      if (GetValueFromFile(hardwareNode, "number_of_analog_outputs", numberOfAnalogOutputs)) {
        m_Configuration.numberOfAnalogOutputs = numberOfAnalogOutputs;
      }
    }

    /// The configuration options for the DS-401 IO module ("mapping")
    if (configNode["Mapping"].IsDefined()) {
      YAML::Node mappingNode = configNode["Mapping"];

      if (GetValueFromFile(mappingNode, "digital_input_start_index", digitalInputMappingStartIndex)) {
        m_Configuration.digitalInputMappingStartIndex = digitalInputMappingStartIndex;
      }

      if (GetValueFromFile(mappingNode, "digital_output_start_index", digitalOutputMappingStartIndex)) {
        m_Configuration.digitalOutputMappingStartIndex = digitalOutputMappingStartIndex;
      }

      if (GetValueFromFile(mappingNode, "analog_input_start_index", analogInputMappingStartIndex)) {
        m_Configuration.analogInputMappingStartIndex = analogInputMappingStartIndex;
      }

      if (GetValueFromFile(mappingNode, "analog_output_start_index", analogOutputMappingStartIndex)) {
        m_Configuration.analogOutputMappingStartIndex = analogOutputMappingStartIndex;
      }
    }

  }

  Configuration ConfigurationParser::GetConfiguration() const {

    return m_Configuration;
  }

} // namespace Controller::Ethercat::DS401
