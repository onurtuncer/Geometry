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

#include "EniParser.h"
#include "rapidxml_utils.hpp"

namespace Controller::Ethercat::EniParser {
  
  bool EniParser::Parse() {
    
    auto parse_error = false;

    try {
      rapidxml::file<> xmlFile(m_EniFileName.c_str());
      rapidxml::xml_document<> document;
      document.parse<rapidxml::parse_default>(xmlFile.data());

      m_EthercatConfig.Parse(document.first_node());
    }
    catch (rapidxml::parse_error e) {
      std::cout << "XML parser some error occurred" << std::endl;
      std::cout << e.what() << std::endl; 
      parse_error = true;
    }
    catch (std::exception e) {
      std::cout << "Eni parser some error occurred" << std::endl;
      std::cout << e.what() << std::endl;
      parse_error = true;
    }

    return !parse_error;
  }

  EtherCATConfig::EtherCATConfig EniParser::GetEtherCATConfig() noexcept {
    return m_EthercatConfig;
  }

} // namespace Controller::Ethercat::EniParser