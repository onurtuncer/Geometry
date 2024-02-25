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

#ifndef __CYCYLIC_H__
#define __CYCYLIC_H__

#include "BaseTypes.h"

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Cyclic {

  using namespace Controller::Ethercat::EniParser::BaseTypes;

  struct FrameType : public Commentable {
    
    struct CmdType : public Commentable {

      struct CopyInfosType {

        struct CopyInfoType {
        public:
          // mandatory
          HexDecValue SrcBitOffs;
          // mandatory
          HexDecValue DestBitOffs;
          // mandatory
          HexDecValue BitSize;
        public:
          auto Parse(rapidxml::xml_node<> *n) -> void;
        };

      private:
        std::vector<CopyInfoType> m_CopyInfoList;
      public:
        auto Parse(rapidxml::xml_node<> *n) -> void;

        auto AddCopyInfo(const CopyInfoType& copyinfo) noexcept -> void;
        auto GetCopyInfos() noexcept -> std::vector<CopyInfoType>&;
      };

    public:
      enum_Cmd                Cmd;
      int                InputOffs;
      int                OutputOffs;

    private:
      // mandatory list limited (1 to 4)
      std::vector<State> m_StateList;
      
      // one of ADO or ADDR is mandatory but ADP is optional only if ADO is set
      uint16_t                  m_Adp;
      bool                      m_hasAdp = false;
      uint16_t                  m_Ado;
      int                       m_Addr;
      Choice_Ado_Addr           m_Choice_Ado_Addr = Choice_Ado_Addr::ErrorNone;
      
      // one of DATA or DATALENGTH is mandatory
      HexBinary                 m_Data;
      int                       m_DataLength;
      Choice_Data_DataLength    m_Choice_Data_DataLength = Choice_Data_DataLength::ErrorNone;
    
      int                       m_Cnt;
      bool                      m_hasCnt = false;
      CopyInfosType             m_CopyInfos;
      bool                      m_hasCopyInfos = false;
    public:
      auto Parse(rapidxml::xml_node<> *n) -> void;

      auto AddState(const State state) noexcept -> void;
      auto GetStateList() noexcept -> std::vector<State>&;

      // ! NOTE : the ADP field is optional `ONLY IF` ADO is SET !
      auto SetAdp(const uint16_t adp) noexcept -> void;
      auto GetAdp() const noexcept -> const std::optional<uint16_t>;

      auto SetAdo(const uint16_t ado) noexcept -> void;
      auto GetAdo() const noexcept -> const std::optional<uint16_t>;

      auto SetAddr(const int address) noexcept -> void;
      auto GetAddr() noexcept -> std::optional<int>;

      auto SetData(const std::string data) noexcept -> void;
      auto GetData() const noexcept -> const std::optional<HexBinary>;

      auto SetDataLength(const int length) noexcept -> void;
      auto GetDataLength() const noexcept -> const std::optional<int>;
      
      auto SetCnt(const int cnt) noexcept -> void;
      auto GetCnt() noexcept -> std::optional<int>;

      auto SetCopyInfos(const CopyInfosType& copyinfos) noexcept -> void;
      auto GetCopyInfos() noexcept -> std::optional<CopyInfosType>;

      auto __IsValid() noexcept -> bool;
    };

  private:
    // mandatory list
    std::vector<CmdType> m_CmdList;
  public:
    auto Parse(rapidxml::xml_node<> *n) -> void;

    auto AddCmd(const CmdType& cmd) noexcept -> void;
    auto GetCmdList() noexcept -> std::vector<CmdType>&;

    auto __IsValid() noexcept -> bool;
  };

  class Cyclic : public Commentable {  // from page 28
  private:
    // optional
    int32_t               m_CycleTime;
    bool                  m_hasCycleTime = false;
    // optional
    int32_t               m_Priority;
    bool                  m_hasPriority = false;
    // optional
    std::string           m_TaskID;
    bool                  m_hasTaskId = false;

    // mandatory list
    std::vector<FrameType>    m_FrameList;
  public:
    auto Parse(rapidxml::xml_node<> *n) -> void;

    auto SetCycleTime(const int time) noexcept -> void;
    auto GetCycleTime() noexcept -> std::optional<int>;

    auto SetPriority(const int priority) noexcept -> void;
    auto GetPriority() noexcept -> const std::optional<int>;

    auto SetTaskID(const std::string id) noexcept -> void;
    auto GetTaskID() const noexcept -> const std::optional<std::string>;

    auto AddFrame(const FrameType& frame) noexcept -> void;
    auto GetFrameList() noexcept -> std::vector<FrameType>&;

    auto __IsValid() noexcept -> bool;
  };
} // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Cyclic

#endif // __CYCYLIC_H__
