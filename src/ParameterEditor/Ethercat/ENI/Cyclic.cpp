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

#include "Cyclic.h"
#include <iostream>

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Cyclic {
  
  auto FrameType::CmdType::CopyInfosType::CopyInfoType::Parse(rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case (Hash::GenerateFNVHash("SrcBitOffs")):
          SrcBitOffs.set(node->value());
          break;
        case (Hash::GenerateFNVHash("DestBitOffs")):
          DestBitOffs.set(node->value());
          break;
        case (Hash::GenerateFNVHash("BitSize")):
          BitSize.set(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break; 
      } // switch
    }
  }

  auto FrameType::CmdType::CopyInfosType::Parse(rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case (Hash::GenerateFNVHash("CopyInfo")): {
          CopyInfoType copyInfo;
          copyInfo.Parse(node);
          AddCopyInfo(copyInfo);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break; 
      } // switch
    }
  }

  auto FrameType::CmdType::CopyInfosType::AddCopyInfo(const CopyInfoType& copyinfo) noexcept -> void {
    m_CopyInfoList.push_back(copyinfo);
  }

  auto FrameType::CmdType::CopyInfosType::GetCopyInfos() noexcept -> std::vector<CopyInfoType>& {
    return m_CopyInfoList;
  }

  auto FrameType::CmdType::Parse(rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case (Hash::GenerateFNVHash("Cmd")) : {
          auto c = std::stoi(node->value());
          switch (c) {
            case 0:
              Cmd = enum_Cmd::NOP;
              break;
            case 1:
              Cmd = enum_Cmd::APRD;
              break;
            case 2:
              Cmd = enum_Cmd::APWR;
              break;
            case 3:
              Cmd = enum_Cmd::APRW;
              break;
            case 4:
              Cmd = enum_Cmd::FPRD;
              break;
            case 5:
              Cmd = enum_Cmd::FPWR;
              break;
            case 6:
              Cmd = enum_Cmd::FPRW;
              break;
            case 7:
              Cmd = enum_Cmd::BRD;
              break;
            case 8:
              Cmd = enum_Cmd::BWR;
              break;
            case 9:
              Cmd = enum_Cmd::BRW;
              break;
            case 10:
              Cmd = enum_Cmd::LRD;
              break;
            case 11:
              Cmd = enum_Cmd::LWR;
              break;
            case 12:
              Cmd = enum_Cmd::LRW;
              break;
            case 13:
              Cmd = enum_Cmd::APRW;
              break;
            case 14:
              Cmd = enum_Cmd::FRMW;
              break;
            default:
              throw new std::invalid_argument("Invalid node name in ENI file");
              break;
          } // switch(c)
          break;
        }
        case (Hash::GenerateFNVHash("InputOffs")):
          InputOffs = std::stoi(node->value());
          break;
        case (Hash::GenerateFNVHash("OutputOffs")):
          OutputOffs = std::stoi(node->value());
          break;
        case (Hash::GenerateFNVHash("State")): {
          auto str = std::string(node->value());
          State state;
          switch (Hash::GenerateFNVHash(str)) {
            case (Hash::GenerateFNVHash("INIT")):
              state = State::INIT;
              break;
            case (Hash::GenerateFNVHash("PREOP")):
              state = State::PREOP;
              break;
            case (Hash::GenerateFNVHash("SAFEOP")):
              state = State::SAFEOP;
              break;
            case (Hash::GenerateFNVHash("OP")):
              state = State::OP;
              break;
            default:
              throw new std::invalid_argument("Unknown state");
              break;
          }
          AddState(state);
          break;
        }
        case (Hash::GenerateFNVHash("Adp")):
          SetAdp(static_cast<uint16_t>(std::stoi(node->value())));
          break;
        case (Hash::GenerateFNVHash("Ado")):
          SetAdo(static_cast<uint16_t>(std::stoi(node->value())));
          break;
        case (Hash::GenerateFNVHash("Addr")):
          SetAddr(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Data")):
          SetData(node->value());
          break;
        case (Hash::GenerateFNVHash("DataLength")):
          SetDataLength(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Cnt")):
          SetCnt(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("CopyInfos")): {
          CopyInfosType copyInfos;
          copyInfos.Parse(node);
          SetCopyInfos(copyInfos);
          break;
        }
        case (Hash::GenerateFNVHash("Comment")):
          SetComment(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break; 
      } // switch
    }
  }

  auto FrameType::CmdType::AddState(const State state) noexcept -> void {
    m_StateList.push_back(state);
  }

  auto FrameType::CmdType::GetStateList() noexcept -> std::vector<State>& {
    return m_StateList;
  }

  // ! NOTE : the ADP field is optional `ONLY IF` ADO is SET !
  auto FrameType::CmdType::SetAdp(const uint16_t adp) noexcept -> void {
    m_hasAdp = true;
    m_Adp = adp;
  }

  auto FrameType::CmdType::GetAdp() const noexcept -> const std::optional<uint16_t> {
    if (m_hasAdp) return m_Adp;
    return std::nullopt;
  }

  auto FrameType::CmdType::SetAdo(const uint16_t ado) noexcept -> void {
    m_Choice_Ado_Addr |= Choice_Ado_Addr::Ado;
    m_Ado = ado;
  }

  auto FrameType::CmdType::GetAdo() const noexcept -> const std::optional<uint16_t> {
    if (m_Choice_Ado_Addr == Choice_Ado_Addr::Ado) return m_Ado;
    return std::nullopt;
  }

  auto FrameType::CmdType::SetAddr(const int address) noexcept -> void {
    m_Choice_Ado_Addr |= Choice_Ado_Addr::Addr;      
    m_Addr = address;
  }

  auto FrameType::CmdType::GetAddr() noexcept -> std::optional<int> {
    if(m_Choice_Ado_Addr == Choice_Ado_Addr::Addr) return m_Addr;
    return std::nullopt;
  }

  auto FrameType::CmdType::SetData(const std::string data) noexcept -> void {
    m_Choice_Data_DataLength |= Choice_Data_DataLength::Data;
    m_Data.set(data);
  }

  auto FrameType::CmdType::GetData() const noexcept -> const std::optional<HexBinary> {
    if (m_Choice_Data_DataLength == Choice_Data_DataLength::Data) return m_Data;
    return std::nullopt;
  }

  auto FrameType::CmdType::SetDataLength(const int length) noexcept -> void {
    m_Choice_Data_DataLength |= Choice_Data_DataLength::DataLength;
    m_DataLength = length;
  }

  auto FrameType::CmdType::GetDataLength() const noexcept -> const std::optional<int> {
    if (m_Choice_Data_DataLength == Choice_Data_DataLength::DataLength) return m_DataLength;
    return std::nullopt;
  }
  
  auto FrameType::CmdType::SetCnt(const int cnt) noexcept -> void {
    m_hasCnt = true;
    m_Cnt = cnt;
  }

  auto FrameType::CmdType::GetCnt() noexcept -> std::optional<int> {
    if(m_hasCnt) return m_Cnt;
    return std::nullopt;
  }

  auto FrameType::CmdType::SetCopyInfos(const CopyInfosType& copyinfos) noexcept -> void {
    m_hasCopyInfos = true;
    m_CopyInfos = copyinfos;
  }
  
  auto FrameType::CmdType::GetCopyInfos() noexcept -> std::optional<CopyInfosType> {
    if(m_hasCopyInfos) return m_CopyInfos;
    return std::nullopt;
  }

  auto FrameType::CmdType::__IsValid() noexcept -> bool {
    bool ret_val = true;
    ret_val = ret_val && (m_StateList.size() > 0) && (m_StateList.size() <= 4);
    ret_val = ret_val && ((m_Choice_Ado_Addr != Choice_Ado_Addr::Error) && (m_Choice_Ado_Addr != Choice_Ado_Addr::ErrorNone));
    ret_val = ret_val && ((m_Choice_Data_DataLength != Choice_Data_DataLength::Error) && (m_Choice_Data_DataLength != Choice_Data_DataLength::ErrorNone));
    return ret_val;
  }

  auto FrameType::Parse(rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case (Hash::GenerateFNVHash("Cmd")): {
          CmdType cmd;
          cmd.Parse(node);
          AddCmd(cmd);
          break;
        }
        case (Hash::GenerateFNVHash("Comment")):
          SetComment(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break; 
      } // switch
    }
  }

  auto FrameType::AddCmd(const CmdType& cmd) noexcept -> void {
    m_CmdList.push_back(cmd);
  }
  auto FrameType::GetCmdList() noexcept -> std::vector<CmdType>& {
    return m_CmdList;
  }

  auto FrameType::__IsValid() noexcept -> bool {
    return(m_CmdList.size() > 0);
  }

  auto Cyclic::Parse(rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case (Hash::GenerateFNVHash("CycleTime")):
          SetCycleTime(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Priority")):
          SetPriority(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("TaskId")):
          SetTaskID(node->value());
          break;
        case (Hash::GenerateFNVHash("Frame")): {
          FrameType frame;
          frame.Parse(node);
          AddFrame(frame);
          break;
        }
        case (Hash::GenerateFNVHash("Comment")):
          SetComment(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break; 
      } // switch
    }
  }

  auto Cyclic::SetCycleTime(const int time) noexcept -> void {
    m_hasCycleTime = true;
    m_CycleTime = time;
  }
  auto Cyclic::GetCycleTime() noexcept -> std::optional<int> {
    if(m_hasCycleTime) return m_CycleTime;
    return std::nullopt;
  }

  auto Cyclic::SetPriority(const int priority) noexcept -> void {
    m_hasPriority = true;
    m_Priority = priority;
  }
  auto Cyclic::GetPriority() noexcept -> const std::optional<int> {
    if(m_hasPriority) return m_Priority;
    return std::nullopt;
  }

  auto Cyclic::SetTaskID(const std::string id) noexcept -> void {
    m_hasTaskId = true;
    m_TaskID = id;
  }
  auto Cyclic::GetTaskID() const noexcept -> const std::optional<std::string> {
    if(m_hasTaskId) return m_TaskID;
    return std::nullopt;
  }

  auto Cyclic::AddFrame(const FrameType& frame) noexcept -> void {
    m_FrameList.push_back(frame);
  }
  auto Cyclic::GetFrameList() noexcept -> std::vector<FrameType>& {
    return m_FrameList;
  }

  auto Cyclic::__IsValid() noexcept -> bool {
    return(m_FrameList.size() > 0);
  }

} // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Cyclic