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

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <vector>
#include <optional>

#include "Master.h"
#include "Slave.h"
#include "Cyclic.h"
#include "ProcessImage.h"

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config {

  class Config {
  public:
    void Parse(rapidxml::xml_node<> *n);
    
    void SetMaster(const Master::Master& master) noexcept;
    Master::Master GetMaster() noexcept;
    
    void AddSlave(const Slave::Slave& slave) noexcept;
    std::vector<Slave::Slave> GetSlaveList() noexcept;
    
    void AddCyclic(const Cyclic::Cyclic& cyclic) noexcept;
    std::vector<Cyclic::Cyclic> GetCyclicList() noexcept;
    
    void SetProcessImage(const ProcessImage::ProcessImage& processImage) noexcept;
    std::optional<ProcessImage::ProcessImage> GetProcessImage() noexcept;

  private:
    // mandatory
    Master::Master m_Master;
    // optional
    std::vector<Slave::Slave> m_SlaveList;
    // optional
    std::vector<Cyclic::Cyclic> m_CyclicList;
    // optional (0 to 1)
    ProcessImage::ProcessImage m_ProcessImage;
    bool                       m_hasProcessImage = false;
  };

} // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config

#endif // __CONFIG_H__
