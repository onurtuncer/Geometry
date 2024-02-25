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

#include "Config.h"
#include "rapidxml.hpp"

#include <iostream>  // Remove later on TODO
#include <string> // std::stoi, std::stol, std::stoll
#include <cstdint> // int32_t etc.
#include "../controller/Core/Hash.h"

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config {

  void Config::Parse(rapidxml::xml_node<> *n) {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
      case (Hash::GenerateFNVHash("Master")): {
        Master::Master master;
        master.Parse(node);
        SetMaster(master);
        break;
      }
      case (Hash::GenerateFNVHash("Slave")): {
        Slave::Slave slave;
        slave.Parse(node);
        AddSlave(slave);
        break;
      }
      case (Hash::GenerateFNVHash("Cyclic")): {
        Cyclic::Cyclic cyclic;
        cyclic.Parse(node);
        AddCyclic(cyclic);
        break;
      }
      case (Hash::GenerateFNVHash("ProcessImage")): {
        ProcessImage::ProcessImage processImage;
        processImage.Parse(node);
        SetProcessImage(processImage);
        break;
      }
      default:
        throw new std::invalid_argument("Invalid node name in ENI file");
        break;
      }
    }
  }

  void Config::SetMaster(const Master::Master& master) noexcept {
    m_Master = master;
  }

  Master::Master Config::GetMaster() noexcept {
    return m_Master;
  }
  
  void Config::AddSlave(const Slave::Slave& slave) noexcept {
    m_SlaveList.push_back(slave);
  }

  std::vector<Slave::Slave> Config::GetSlaveList() noexcept {
    return m_SlaveList;
  }
  
  void Config::AddCyclic(const Cyclic::Cyclic& cyclic) noexcept {
    m_CyclicList.push_back(cyclic);
  }

  std::vector<Cyclic::Cyclic> Config::GetCyclicList() noexcept {
    return m_CyclicList;
  }
  
  void Config::SetProcessImage(const ProcessImage::ProcessImage& processImage) noexcept {
    m_hasProcessImage = true;
    m_ProcessImage = processImage;
  }

  std::optional<ProcessImage::ProcessImage> Config::GetProcessImage() noexcept {
    if(m_hasProcessImage) return m_ProcessImage;
    return std::nullopt;
  }
} // namespace Controller::Ethercat
