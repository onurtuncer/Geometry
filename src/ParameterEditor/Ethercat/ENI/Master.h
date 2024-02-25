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

#ifndef __MASTER_H__
#define __MASTER_H__

#include "BaseTypes.h"
#include "rapidxml.hpp"

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Master {

  using namespace Controller::Ethercat::EniParser::BaseTypes;

  struct InfoType {
    enum class EtherType_t : uint16_t {
      ethercat = 0x8000,
      udp      = 0x88a4,
    };

  public:
    // mandatory
    std::string Name;
    // mandatory
    HexBinary Source;
    // mandatory
    HexBinary Destination;
    // mandatory
  
  private:
    EtherType_t m_EtherType;
    bool m_hasEtherType = false;

  public:
    void Parse(const rapidxml::xml_node<> *n);
    void SetEtherType(const EtherType_t ethertype) noexcept;
    std::optional<EtherType_t> GetEtherType() noexcept;
  };

  struct MailboxStatesType {
    // mandatory
    uint32_t StartAddr;
    // mandatory
    int Count;
  public:
    void Parse(const rapidxml::xml_node<> *n);
  };

  struct EoEType {
    // mandatory
    int MaxPorts;
    // mandatory
    int MaxFrames;
    // mandatory
    int MaxMACs;

  public:
    void Parse(const rapidxml::xml_node<> *n);
  };


  struct InitCmdsType {
  private:
    std::vector<ECatCmdType> m_InitCmdList;
  public:
    void Parse(const rapidxml::xml_node<> *n);
    void AddInitCmd(const ECatCmdType& initcmd) noexcept;
    std::vector<ECatCmdType>& GetInitCmdList() noexcept;
  };

  class Master {
  private:
    // mandatory
    InfoType                      m_Info;
    
    // optional (0 or 1)
    MailboxStatesType             m_MailboxStates;
    bool                          m_hasMailboxStates = false;
    // optional (0 or 1)
    EoEType                       m_EoE;
    bool                          m_hasEoE = false;
    // optional (0 to 1)
    InitCmdsType                  m_InitCmds;
    bool                          m_hasInitCmds = false;

  public:
    void Parse(const rapidxml::xml_node<>* n);

    void SetInfo(const InfoType& info) noexcept;
    InfoType& GetInfo() noexcept;

    void SetMailboxStates(const MailboxStatesType& mailboxStates) noexcept;
    std::optional<MailboxStatesType> GetMailboxStates() noexcept;
    
    void SetEoE(const EoEType& eoe) noexcept;
    std::optional<EoEType> GetEoE() noexcept;
    
    void SetInitCmds(const InitCmdsType& initCmds) noexcept;
    std::optional<InitCmdsType> GetInitCmds() noexcept;
  };

}  // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Master

#endif // __MASTER_H__
