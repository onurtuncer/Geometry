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

#ifndef __ENIPARSER_H__
#define __ENIPARSER_H__

#include "EtherCATConfig.h"

namespace Controller::Ethercat::EniParser {

  class EniParser {
  private:
    std::string m_EniFileName;
    
    EtherCATConfig::EtherCATConfig m_EthercatConfig;
  public:
    explicit EniParser(std::string& fileName) : m_EniFileName(fileName) {/*empty*/}
    EniParser(const EniParser&) = delete;
    virtual ~EniParser() = default;
    
    bool Parse();

    EtherCATConfig::EtherCATConfig GetEtherCATConfig() noexcept;
  };

} // namespace Controller::Ethercat::EniParser

#endif // __ENIPARSER_H__
