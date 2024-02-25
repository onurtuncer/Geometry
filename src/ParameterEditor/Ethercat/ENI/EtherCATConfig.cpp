/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Written by SIMSOFT, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact ertugrul.kalkan@simsoft.com.tr
  Contact hakan.sac@simsoft.com.tr
-------------------------------------------------------------------------------*/

#include "EtherCATConfig.h"

namespace Controller::Ethercat::EniParser::EtherCATConfig {

  void AttributesType::Parse(rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)){
        case (Hash::GenerateFNVHash("Version")):
          SetVersion(attr->value());
          break;
        default:
          std::cout << "Unkown attribute `" << attrName << "`" << std::endl;
          // throw new std::invalid_argument("Invalid attribute name in ENI file");
          break;
      }
    }
  }

  void AttributesType::SetVersion(const std::string& version) noexcept {
    m_hasVersion = true;
    m_Version = version;
  }

  std::optional<std::string> AttributesType::GetVersion() noexcept {
    if(m_hasVersion) return m_Version;
    return std::nullopt;
  }

  void EtherCATConfig::Parse(rapidxml::xml_node<> *n) {
    Attributes.Parse(n);

    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)){
        case (Hash::GenerateFNVHash("Config")): {
          Config::Config config;
          config.Parse(node);
          SetConfig(config);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node in ENI file");
          break;
        }
    }
  }
  
  void EtherCATConfig::SetConfig(const Config::Config& config) noexcept {
    m_Config = config;
  }

  Config::Config& EtherCATConfig::GetConfig() noexcept {
    return m_Config;
  }

} // Controller::Ethercat::EniParser::EtherCATConfig