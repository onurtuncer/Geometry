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

#include "Master.h"
#include "../controller/Core/Hash.h"
#include <iostream>

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Master {

  void InfoType::Parse(const rapidxml::xml_node<> *n) {
    for (rapidxml::xml_node<>* node = n->first_node(); node ; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("Name"):
          Name = node->first_node()->value();
          break;
        case Hash::GenerateFNVHash("Destination") :
          Destination.set(node->value());
          break;
        case Hash::GenerateFNVHash("Source") :
          Source.set(node->value());
          break;
        case Hash::GenerateFNVHash("EtherType") : {
          HexBinary etherType;
          etherType.set(node->value());
          SetEtherType(static_cast<InfoType::EtherType_t>(static_cast<uint16_t>(etherType)));
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void InfoType::SetEtherType(const InfoType::EtherType_t etherType) noexcept {
    m_hasEtherType = true;
    m_EtherType = etherType;
  }

  std::optional<InfoType::EtherType_t> InfoType::GetEtherType() noexcept {
    if (m_hasEtherType) return m_EtherType;
    return std::nullopt;
  }

  void MailboxStatesType::Parse(const rapidxml::xml_node<> *n) {
    for (rapidxml::xml_node<>* node = n->first_node(); node ; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("StartAddr") :
          StartAddr = static_cast<uint32_t>(std::atoi(node->value()));
          break;
        case Hash::GenerateFNVHash("Count") :
          Count = std::atoi(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void EoEType::Parse(const rapidxml::xml_node<> *n) {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("MaxPorts") :
          MaxPorts = std::atoi(node->value());
          break;
        case Hash::GenerateFNVHash("MaxFrames") :
          MaxFrames = std::atoi(node->value());
          break;
        case Hash::GenerateFNVHash("MaxMACs") :
          MaxMACs = std::atoi(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }
  
  void InitCmdsType::Parse(const rapidxml::xml_node<> *n) {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName))
      {
      case (Hash::GenerateFNVHash("InitCmd")): {
        ECatCmdType initCmd;
        initCmd.Parse(node);
        AddInitCmd(initCmd);
        break;
      }
      default:
        throw new std::invalid_argument("Invalid node name in ENI file");
        break;
      }
    }
  }

  void InitCmdsType::AddInitCmd(const ECatCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<ECatCmdType>& InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  void Master::Parse(const rapidxml::xml_node<>* n) {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {

      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("Info") : {
          InfoType infoType;
          infoType.Parse(node);
          SetInfo(infoType);
          break;
        }
        case Hash::GenerateFNVHash("MailboxStates") : {
          MailboxStatesType mailboxStates;
          mailboxStates.Parse(node);
          SetMailboxStates(mailboxStates);
          break;
        }
        case Hash::GenerateFNVHash("EoE") : {
          EoEType eoe;
          eoe.Parse(node);
          SetEoE(eoe);
          break;
        }
        case Hash::GenerateFNVHash("InitCmds"): {
          InitCmdsType initCmds;
          initCmds.Parse(node);
          SetInitCmds(initCmds);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Master::SetInfo(const InfoType& info) noexcept {
    m_Info = info;
  }

  InfoType& Master::GetInfo() noexcept {
    return m_Info;
  }

  void Master::SetMailboxStates(const MailboxStatesType& mailboxStates) noexcept {
    m_hasMailboxStates = true;
    m_MailboxStates = mailboxStates;
  }
    
  std::optional<MailboxStatesType> Master::GetMailboxStates() noexcept {
    if(m_hasMailboxStates) return m_MailboxStates;
    return std::nullopt;
  }
    
  void Master::SetEoE(const EoEType& eoe) noexcept {
    m_hasEoE = true;
    m_EoE = eoe;
  }
    
  std::optional<EoEType> Master::GetEoE() noexcept {
    if(m_hasEoE) return m_EoE;
    return std::nullopt;
  }
  
  void Master::SetInitCmds(const InitCmdsType& initCmds) noexcept {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }

  std::optional<InitCmdsType> Master::GetInitCmds() noexcept {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }
} // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Master
