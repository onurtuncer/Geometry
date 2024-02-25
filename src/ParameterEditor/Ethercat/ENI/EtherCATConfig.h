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

#ifndef __ETHERCATCONFIG_H__
#define __ETHERCATCONFIG_H__

#include <vector>
#include <optional>

#include "Config.h"

namespace Controller::Ethercat::EniParser::EtherCATConfig {

  struct AttributesType {
  private:
    std::string m_Version;
    bool        m_hasVersion = false;
  public:
    void Parse(rapidxml::xml_node<> *n);

    void SetVersion(const std::string& version) noexcept;
    std::optional<std::string> GetVersion() noexcept;
  };

  class EtherCATConfig {
  public:
    void Parse(rapidxml::xml_node<> *n);
    
    void SetConfig(const Config::Config& config) noexcept;
    Config::Config& GetConfig() noexcept;
    
  public:
    // mandatory
    AttributesType Attributes;
  private:
    // mandatory
    Config::Config m_Config;
  };

} // namespace Controller::Ethercat::EniParser::EtherCATConfig

#endif // __ETHERCATCONFIG_H__
