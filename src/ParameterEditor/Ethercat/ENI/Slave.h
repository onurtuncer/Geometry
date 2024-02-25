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

#ifndef __SLAVE_H__
#define __SLAVE_H__

#include "BaseTypes.h"

#include <any>
#include <iostream>

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Slave {

  using namespace Controller::Ethercat::EniParser::BaseTypes;

  struct InfoType {
    // Due to EtherCAT standard ETG2100 ENI spec document section 6.1
    enum Flags_PAPI {
      HasPhysAddr = 1,
      HasAutoIncAddr = 2,
      HasPhysics = 4,
      HasIdentification = 8,
    };

    enum Flags_PAPI_Valid_States {
      State_0 = 0,
      State_1 = (Flags_PAPI::HasAutoIncAddr | Flags_PAPI::HasPhysAddr | Flags_PAPI::HasPhysics),
      State_2 = State_1 | (Flags_PAPI::HasIdentification),
    };

    inline bool check_Flags_PAPI_Valid_States(uint16_t state)
    {
      return (state == Flags_PAPI_Valid_States::State_0
            || state == Flags_PAPI_Valid_States::State_1
            || state == Flags_PAPI_Valid_States::State_2);
    }

    struct IdentificationType {
      
      struct AttributesType {
        HexDecValue Value;
      public:
        void Parse(const rapidxml::xml_node<> *n);
      };
    public:
      AttributesType Attributes;
      HexDecValue Ado;
    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;
    };

  public:
    std::string         Name;            /* mandatory */
    int32_t             VendorID;        /* mandatory */
    int32_t             ProductCode;     /* mandatory */
    int32_t             RevisionNo;      /* mandatory */
    int32_t             SerialNo;        /* mandatory */
  private:  
    int32_t             m_PhysAddr;                  //    0..1 -------|
    int32_t             m_AutoIncAddr;        // ----------------------|
    std::string         m_Physics;             //----------------------|
    IdentificationType  m_Identification;              //-----0..1-----|
    uint16_t            m_PAPI_Flag = 0;
  
    int32_t             m_ProductRevision;
    bool                m_hasProductRevision = false;
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    auto SetPhysAddress(const int32_t addr) noexcept -> void;
    auto GetPhysAddress() noexcept -> std::optional<int32_t>;

    auto SetAutoIncAddr(const int32_t addr) noexcept -> void;
    auto GetAutoIncAddr() noexcept -> std::optional<int32_t>;

    auto SetPhysics(const std::string phy) noexcept -> void;
    auto GetPhysics() noexcept -> std::optional<std::string>;

    auto SetIdentitication(const IdentificationType& identification) noexcept -> void;
    auto GetIdentification() noexcept -> std::optional<IdentificationType>;

    auto SetProductRevision(const int32_t rev) noexcept -> void;
    auto GetProductRevision() noexcept -> const std::optional<int32_t>;

    uint16_t __IsValid();
  };

  struct ProcessDataType {
    
    struct SendType {
      // mandatory
      int32_t BitStart;
      // mandatory
      int32_t BitLength;

    public:
      void Parse(const rapidxml::xml_node<> *n);
    };

    struct RecvType {
      // mandatory
      int32_t BitStart;
      // mandatory
      int32_t BitLength;

    public:
      void Parse(const rapidxml::xml_node<> *n);
    };

    struct SyncManagerSettingsType  {
      enum class Type {
        Outputs = 1,
        Inputs,
      };

    public:
      // mandatory (not a field)
      SynchManager  SynchManagerNo;
      // mandatory
      Type          Type;
      // mandatory
      uint32_t      StartAddress;
      // mandatory
      uint32_t      ControlByte;
      // mandatory
      bool          Enable;  // 0 or 1 in the ENI file
    private:
      uint32_t      m_MinSize;
      bool          m_hasMinSize = false;
      uint32_t      m_MaxSize;
      bool          m_hasMaxSize = false;
      uint32_t      m_DefaultSize;
      bool          m_hasDefaultSize = false;
      bool          m_Virtual;
      bool          m_hasVirtual = false;
      uint32_t      m_Watchdog;
      bool          m_hasWatchdog = false;
      std::vector<uint16_t> m_PdoList;
    public:
      auto Parse(const rapidxml::xml_node<> *n, SynchManager sm_no) -> void;

      auto SetMinSize(const uint32_t size) noexcept -> void;
      auto GetMinSize() noexcept -> const std::optional<uint32_t>;

      auto SetMaxSize(const uint32_t size) noexcept -> void;
      auto GetMaxSize() noexcept -> const std::optional<uint32_t>;

      auto SetDefaultSize(const uint32_t size) noexcept -> void;
      auto GetDefaultSize() noexcept -> const std::optional<uint32_t>;

      auto SetVirtual(const bool v) noexcept -> void;
      auto GetVirtual() noexcept -> const std::optional<bool>;

      auto SetWatchdog(const uint32_t watchdog) noexcept -> void;
      auto GetWatchdog() noexcept -> const std::optional<uint32_t>;

      auto AddPdoIndex(const uint16_t index) noexcept -> void;
      auto GetPdoList() noexcept -> std::vector<uint16_t>&;
    };

    struct PdoType {

      struct AttributesType {
      private:
        //Fixed
        bool m_Fixed;
        bool m_hasFixed = false;

        //Mandatory
        bool m_Mandatory;
        bool m_hasMandatory = false;

        //Virtual
        bool m_Virtual;
        bool m_hasVirtual = false;

        // SyncManager
        SynchManager m_Sm;
        bool m_hasSm = false;
        
        // SyncUnit
        uint16_t m_Su;
        bool m_hasSu = false;

        // PdoOrder
        uint16_t m_PdoOrder;
        bool m_hasPdoOrder = false;

        // OSFac
        uint16_t m_OSFac;
        bool m_hasOSFac = false;

        //OSMin
        uint16_t m_OSMin;
        bool m_hasOSMin = false;

        //OSMax
        uint16_t m_OSMax;
        bool m_hasOSMax = false;

        //OSIndexInc
        uint16_t m_OSIndexInc;
        bool m_hasOSIndexInc = false;
      
      public:
        void Parse(const rapidxml::xml_node<> *n);

        std::optional<bool> GetFixed() noexcept;
        void SetFixed(const bool fixed) noexcept;

        std::optional<bool> GetMandatory() noexcept;
        void SetMandatory(const bool mandatory) noexcept;

        std::optional<bool> GetVirtual() noexcept;
        void SetVirtual(const bool virtuall) noexcept;

        std::optional<SynchManager> GetSm() noexcept;
        void SetSm(const SynchManager sm) noexcept;

        std::optional<uint16_t> GetSu() noexcept;
        void SetSu(const uint16_t su) noexcept;

        std::optional<uint16_t> GetPdoOrder() noexcept;
        void SetPdoOrder(const uint16_t PdoOrder) noexcept;

        std::optional<uint16_t> GetOSFac() noexcept;
        void SetOSFac(const uint16_t OSFac) noexcept;

        std::optional<uint16_t> GetOSMin() noexcept;
        void SetOSMin(const uint16_t OSMin) noexcept;

        std::optional<uint16_t> GetOSMax() noexcept;
        void SetOSMax(const uint16_t OSMax) noexcept;

        std::optional<uint16_t> GetOSIndexInc() noexcept;
        void SetOSIndexInc(const uint16_t OSIndexInc) noexcept;
      };
    
      struct EntryType : public Commentable {
        
        struct DataType_t : public std::string {
          
          struct AttributesType {
          private:
            std::string m_DScale;
            bool        m_hasDScale = false;
          public:
            void Parse(const rapidxml::xml_node<> *n);

            void SetDScale(const std::string& dscale);
            std::optional<std::string> GetDScale();
          };

        public:
          AttributesType Attributes;

          DataType_t() : std::string() {}
          DataType_t(const std::string& datatype) : std::string(datatype) {}
        };

      public:
        AttributesType  Attributes;

        HexDecValue     Index;  // ! TODO  signed as attributable at document but we dont know what are the attributes yet
        int32_t         BitLen;

      private:
        std::vector<NameType>        m_NameList;
        
        HexDecValue     m_SubIndex;
        bool            m_hasSubIndex = false;
        DataType_t      m_DataType;
        bool            m_hasDataType = false;

      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        auto SetSubIndex(const HexDecValue& subindex) noexcept -> void;
        auto GetSubIndex() noexcept -> const std::optional<HexDecValue>;

        auto AddName(const NameType& name) noexcept -> void;
        auto GetNameList() noexcept -> std::vector<NameType>&;

        auto SetDataType(const std::string datatype) noexcept -> void;
        auto GetDataType() noexcept -> const std::optional<std::string>;

        EntryType() {}
      };

      struct ExcludeType : public HexDecValue {
      public:
        AttributesType Attributes;

        void Parse(const rapidxml::xml_node<> *n);

        ExcludeType() {}
        ExcludeType(const HexDecValue& hdv) : HexDecValue(hdv) {}
      };

    public:
      AttributesType              Attributes;
      // mandatory
      HexDecValue                 Index;
    
    private:
      // mandatory list
      std::vector<NameType>       m_NameList;
      // optional list
      std::vector<ExcludeType>    m_ExcludeList;
      // optional list
      std::vector<EntryType>      m_EntryList;

    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;
      
      void AddName(const NameType& name) noexcept;
      std::vector<NameType>& GetNameList() noexcept;

      void AddExclude(const ExcludeType& exclude) noexcept;
      std::vector<ExcludeType>& GetExcludeList() noexcept;

      void AddEntry(const EntryType& entry) noexcept;
      std::vector<EntryType>& GetEntryList() noexcept;

      // will be called only at parse
      bool __IsValid() noexcept;
    };

  private:
    std::vector<SendType>                 m_SendList;
    std::vector<RecvType>                 m_RecvList;
    std::vector<SyncManagerSettingsType>  m_SMList;
    std::vector<PdoType>                  m_RxPDOList;
    std::vector<PdoType>                  m_TxPDOList;
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    auto AddSend(const SendType& send) noexcept -> void;
    auto GetSendList() noexcept -> std::vector<SendType>&;

    auto AddRecv(const RecvType& rcv) noexcept -> void;
    auto GetRecvList() noexcept -> std::vector<RecvType>&;
    
    auto AddSM(const SyncManagerSettingsType& sm) noexcept -> void;
    auto GetSMList() noexcept -> std::vector<SyncManagerSettingsType>&;

    auto AddRxPdo(const PdoType& pdo) noexcept -> void;
    auto GetRxPDOList() noexcept -> std::vector<PdoType>&;

    auto AddTxPdo(const PdoType& pdo) noexcept -> void;
    auto GetTxPDOList() noexcept -> std::vector<PdoType>&;
  };

  struct Mailbox {

    struct AttributesType {
    private:
      bool m_DataLinkLayer;
      bool m_hasDataLinkLayer = false;
    public:
      void Parse(const rapidxml::xml_node<> *n);

      void SetDataLinkLayer(bool datalinklayer) noexcept;
      std::optional<bool> GetDataLinkLayer() noexcept;
    };

    struct MailboxSendInfoType {
    public:
      int32_t Start;
      int32_t Length;
    private:
      bool m_ShortSend;
      bool m_hasShortSend = false;
    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;

      void SetShortSend(const bool shortsend) noexcept;
      std::optional<bool> GetShortSend() noexcept;
    };

    struct MailboxRecvInfoType {
    public:
      int32_t   Start;
      int32_t   Length;
    private:
      int32_t   m_PollTime;
      bool      m_hasPollTime = false;
      int32_t   m_StatusBitAddr;
      bool      m_hasStatusBitAddr = false;

    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;

      void SetPollTime(const int32_t polltime) noexcept;
      std::optional<int32_t> GetPollTime() noexcept;

      void SetStatusBitAddr(const int32_t statusbitaddr) noexcept;
      std::optional<int32_t> GetStatusBitAddr() noexcept;
    };

    struct MailboxCmdType : public Commentable {
          
      struct AttributesType {
        // ! TODO : there should be some attributes upto document but there are none described...
      };

    public:
      AttributesType   Attributes;
      // mandatory
      uint16_t         Timeout;
      // mandatory
      HexBinary        Data;

    private:
      // mandatory list
      std::vector<TransitionType>   m_TransitionList;

      // optional
      bool                          m_Disabled;    
      bool                          m_hasDisabled = false;

    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;
      
      void AddTransitionList(const TransitionType& transition) noexcept;
      std::vector<TransitionType>& GetTransitionList() noexcept;

      void SetDisabled(const bool disabled) noexcept;
      std::optional<bool> GetDisabled() noexcept;

      // will be called only at parse
      bool __IsValid() noexcept;
    };

    struct BootstrapType {
    public:
      MailboxSendInfoType Send;
      MailboxRecvInfoType Recv;
    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;
    };

    struct CoEType {

      struct InitCmdsType{

        struct InitCmdType : public Commentable {
          
          struct AttributesType {
          private:
            bool    m_Fixed;
            bool    m_hasFixed = false;
            bool    m_CompleteAccess;
            bool    m_hasCompleteAcces = false;
          public:
            void Parse(const rapidxml::xml_node<> *n);

            void SetFixed(bool fixed) noexcept;
            std::optional<bool> GetFixed() noexcept;

            void SetCompleteAcces(bool completeAcces) noexcept;
            std::optional<bool> GetCompleteAcces() noexcept;
          };

        public:

          AttributesType   Attributes;
          // mandatory
          uint16_t         Timeout;
          // mandatory
          uint16_t         Ccs;
          // mandatory
          uint16_t         Index;
          // mandatory
          uint16_t         Subindex;
         
        private:
          // mandatory list
          std::vector<TransitionType>   m_TransitionList;
          // optional
          HexBinary                     m_Data;
          bool                          m_hasData = false;
          // optional
          bool                          m_Disabled;    
          bool                          m_hasDisabled = false;

        public:
          auto Parse(const rapidxml::xml_node<> *n) -> void;

          void AddTransitionList(const TransitionType& transition) noexcept;
          std::vector<TransitionType>& GetTransitionList() noexcept;

          void SetData(const HexBinary& data) noexcept;
          std::optional<HexBinary> GetData() noexcept;

          void SetDisabled(const bool disabled) noexcept;
          std::optional<bool> GetDisabled() noexcept;

          // will be called only at parse
          bool __IsValid() noexcept;
        };
      

      private:
        std::vector<InitCmdType>        m_InitCmdList;
      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        void AddInitCmd(const InitCmdType& initcmd) noexcept;
        std::vector<InitCmdType>& GetInitCmdList() noexcept;
      };

      struct ProfileType {
        
        struct ChannelInfoType {

          struct AttributeType {
          private:
            bool m_OverwrittenByModule;
            bool m_hasOverwrittenByModule;
          public:
            void Parse(const rapidxml::xml_node<> *n);

            void SetOverwrittenByModule(const bool overwrittenByModule) noexcept;
            std::optional<bool> GetOverwrittenByModule() noexcept;
          };

        public:
          AttributesType Attributes;
          // mandatory
          uint32_t    ProfileNo;
        private:
          // optional
          uint32_t    m_AddInfo;
          bool        m_hasAddInfo = false;
          
          std::vector<NameType> m_DisplayNameList;
        public:
          
          auto Parse(const rapidxml::xml_node<> *n) -> void;

          void SetAddInfo(const uint32_t addInfo) noexcept;
          std::optional<uint32_t> GetAddInfo() noexcept;

          void AddDisplayName(const NameType& name) noexcept;
          std::vector<NameType>& GetDisplayNameList() noexcept;
        };
         
        struct VendorSpecificType {
        // ! WTF ANY ?
        private:
          std::vector<std::any> m_AnyList;
        public:
          auto AddAny(const std::any a) noexcept -> void {
            m_AnyList.push_back(a);
          }
          auto GetAnyList() noexcept -> std::vector<std::any>& {
            return m_AnyList;
          }
        };

      private:

        // mandatory list
        std::vector<ChannelInfoType> m_ChannelInfoList;
        // optional
        VendorSpecificType m_VendorSpecific;
        bool m_hasVendorSpecific = false;

      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        void AddChannelInfo(const ChannelInfoType& channelInfo) noexcept;
        std::vector<ChannelInfoType>& GetChannelInfoList() noexcept;

        void SetVendorSpecific(const VendorSpecificType& vendorSpecific) noexcept;
        std::optional<VendorSpecificType> GetVendorSpecific() noexcept;

        // will be called only at parse
        bool __IsValid() noexcept;
      };

    private:
      InitCmdsType     m_InitCmds;
      bool             m_hasInitCmds = false;
      ProfileType      m_Profile;
      bool             m_hasProfile = false;
    
    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;

      void SetInitCmds(const InitCmdsType& initCmds) noexcept;
      std::optional<InitCmdsType> GetInitCmds() noexcept;

      void SetProfile(const ProfileType& profile) noexcept;
      std::optional<ProfileType> GetProfile() noexcept;
    };
    
    struct SoEType {

      struct InitCmdsType{

        struct InitCmdType : public Commentable {
          
          struct AttributesType {
          private:                  
            bool    m_Fixed;
            bool    m_hasFixed = false;
          public:
            void Parse(const rapidxml::xml_node<> *n);

            void SetFixed(bool fixed) noexcept;
            std::optional<bool> GetFixed() noexcept;
          };

        public:
          AttributesType   Attributes;
          // mandatory
          uint16_t         Timeout;
          // mandatory
          uint16_t         OpCode;
          // mandatory
          uint16_t         DriveNo;
          // mandatory
          uint16_t         IDN;
          // mandatory
          uint16_t         Elements;
          // mandatory
          uint16_t         Attribute;

        private:
          // mandatory list
          std::vector<TransitionType>   m_TransitionList;
          // optional
          HexBinary                     m_Data;
          bool                          m_hasData = false;
          // optional
          bool                          m_Disabled;    
          bool                          m_hasDisabled = false;

        public:
          auto Parse(const rapidxml::xml_node<> *n) -> void;

          void AddTransitionList(const TransitionType& transition) noexcept;
          std::vector<TransitionType>& GetTransitionList() noexcept;

          void SetData(const HexBinary& data) noexcept;
          std::optional<HexBinary> GetData() noexcept;

          void SetDisabled(const bool disabled) noexcept;
          std::optional<bool> GetDisabled() noexcept;

          // will be called only at parse
          bool __IsValid() noexcept;
        };
      

      private:
        std::vector<InitCmdType>        m_InitCmdList;
      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        void AddInitCmd(const InitCmdType& initcmd) noexcept;
        std::vector<InitCmdType>& GetInitCmdList() noexcept;
      };

    private:
      InitCmdsType     m_InitCmds;
      bool             m_hasInitCmds = false;
    
    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;

      void SetInitCmds(const InitCmdsType& initCmds) noexcept;
      std::optional<InitCmdsType> GetInitCmds() noexcept;
    };
    
    struct AoEType {

      struct InitCmdsType {
      private:
        std::vector<MailboxCmdType>        m_InitCmdList;
      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        void AddInitCmd(const MailboxCmdType& initcmd) noexcept;
        std::vector<MailboxCmdType>& GetInitCmdList() noexcept;
      };

    private:
      InitCmdsType     m_InitCmds;
      bool             m_hasInitCmds = false;
    
      std::string      m_NetId;
      bool             m_hasNetId = false;
    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;

      void SetInitCmds(const InitCmdsType& initCmds) noexcept;
      std::optional<InitCmdsType> GetInitCmds() noexcept;

      void SetNetId(const std::string& netId) noexcept;
      std::optional<std::string> GetNetId() noexcept;
    };

    struct EoEType {

        struct InitCmdsType {
        private:
          std::vector<MailboxCmdType>        m_InitCmdList;
        public:
          auto Parse(const rapidxml::xml_node<> *n) -> void;

          void AddInitCmd(const MailboxCmdType& initcmd) noexcept;
          std::vector<MailboxCmdType>& GetInitCmdList() noexcept;
        };

      private:
        InitCmdsType     m_InitCmds;
        bool             m_hasInitCmds = false;
      
      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        void SetInitCmds(const InitCmdsType& initCmds) noexcept;
        std::optional<InitCmdsType> GetInitCmds() noexcept;
      };  

    struct FoEType {

          struct InitCmdsType {
          private:
            std::vector<MailboxCmdType>        m_InitCmdList;
          public:
            auto Parse(const rapidxml::xml_node<> *n) -> void;

            void AddInitCmd(const MailboxCmdType& initcmd) noexcept;
            std::vector<MailboxCmdType>& GetInitCmdList() noexcept;
          };

        private:
          InitCmdsType     m_InitCmds;
          bool             m_hasInitCmds = false;
        
        public:
          auto Parse(const rapidxml::xml_node<> *n) -> void;

          void SetInitCmds(const InitCmdsType& initCmds) noexcept;
          std::optional<InitCmdsType> GetInitCmds() noexcept;
        };  

    struct VoEType {

      struct InitCmdsType {
      private:
        std::vector<MailboxCmdType>        m_InitCmdList;
      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        void AddInitCmd(const MailboxCmdType& initcmd) noexcept;
        std::vector<MailboxCmdType>& GetInitCmdList() noexcept;
      };

      private:
        InitCmdsType     m_InitCmds;
        bool             m_hasInitCmds = false;
      
      public:
        auto Parse(const rapidxml::xml_node<> *n) -> void;

        void SetInitCmds(const InitCmdsType& initCmds) noexcept;
        std::optional<InitCmdsType> GetInitCmds() noexcept;
      };  

  public:
    AttributesType Attributes;

    // mandatory
    MailboxSendInfoType Send;
    // mandatory
    MailboxRecvInfoType Recv;
  private:
    BootstrapType           m_Bootstrap;
    bool                    m_hasBootStrap = false;

    std::vector<Protocol>   m_ProtocolList;

    CoEType                 m_CoE;
    bool                    m_hasCoE = false;
    SoEType                 m_SoE;
    bool                    m_hasSoE = false;
    AoEType                 m_AoE;
    bool                    m_hasAoE = false; 
    EoEType                 m_EoE;
    bool                    m_hasEoE = false;
    FoEType                 m_FoE;
    bool                    m_hasFoE = false;
    VoEType                 m_VoE;
    bool                    m_hasVoE = false;
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    auto SetBootstrap(const BootstrapType& bootstrap) noexcept -> void;
    auto GetBootStrap() noexcept -> std::optional<BootstrapType>;
    
    auto AddProtocol(const Protocol& protocol) noexcept -> void;
    auto GetProtocolList() noexcept -> std::vector<Protocol>&;

    auto SetCoE(const CoEType& coe) noexcept -> void;
    auto GetCoE() noexcept -> const std::optional<CoEType>;

    auto SetSoE(const SoEType& soe) noexcept -> void;
    auto GetSoE() noexcept -> const std::optional<SoEType>;

    auto SetAoE(const AoEType& aoe) noexcept -> void;
    auto GetAoE() noexcept -> const std::optional<AoEType>;

    auto SetEoE(const EoEType& eoe) noexcept -> void;
    auto GetEoE() noexcept -> const std::optional<EoEType>;

    auto SetFoE(const FoEType& foe) noexcept -> void;
    auto GetFoE() noexcept -> const std::optional<FoEType>;

    auto SetVoE(const VoEType& voe) noexcept -> void;
    auto GetVoE() noexcept -> const std::optional<VoEType>;
  };

  struct InitCmdsType {
  private:
    std::vector<ECatCmdType>        m_InitCmdList;
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    void AddInitCmd(const ECatCmdType& initcmd) noexcept;
    std::vector<ECatCmdType>& GetInitCmdList() noexcept;
  };

  struct PreviousPortType {
    
    struct AttributesType {
    private:
      bool m_Selected;
      bool m_hasSelected = false;
    public:
      void Parse(const rapidxml::xml_node<> *n);

      void SetSelected(const bool selected) noexcept;
      std::optional<bool> GetSelected() noexcept;
    };

  public:
    AttributesType  Attributes;

    // mandatory
    std::string     Port;
  private:
    // optional and reserved
    uint16_t        m_DeviceID;
    bool            m_hasDeviceID = false;

    // optional
    uint16_t        m_PhysAddr;
    bool            m_hasPhysAddr = false;
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    std::optional<uint16_t> GetDeviceID() noexcept;
    void SetDeviceID(const uint16_t deviceID) noexcept;

    std::optional<uint16_t> GetPhysAddr() noexcept;
    void SetPhysAddr(const uint16_t physAddr) noexcept;
  };

  struct HotConnectType {
  public:
  // Mandatory
    int16_t                   GroupMemberCnt;

  private:
    // optional
    NameType                  m_GroupName;
    bool                      m_hasGroupName = false;
    // mandatory (1 to infinity)
    std::vector<ECatCmdType>  m_IdentifyCmdList;

  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    void SetGroupName(const NameType& groupName) noexcept;
    std::optional<NameType> GetGroupName() noexcept;

    void AddIdentifyCmdList(const ECatCmdType& identifyCmd) noexcept;
    std::vector<ECatCmdType>& GetIdentifyCmdList() noexcept;

    // will be called only at parse
    bool __IsValid() noexcept;
  };

  struct DCType {
  private:
    // optional (0 to 1)
    bool      m_PotentialReferenceClock;
    bool      m_hasPotentialReferenceClock = false;
    // optional (0 to 1)
    bool      m_ReferenceClock;
    bool      m_hasReferenceClock = false;
    // optional (0 to 1)
    int32_t  m_CycleTime0;
    bool      m_hasCycleTime0 = false;
    // optional (0 to 1)
    int32_t  m_CycleTime1;
    bool      m_hasCycleTime1 = false;
    // optional (0 to 1)
    int32_t  m_ShiftTime;
    bool      m_hasShiftTime = false;
  public: 
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    std::optional<bool> GetPotentialReferenceClock() noexcept;
    void SetPotentialReferenceClock(const bool potentialReferenceClock) noexcept;

    std::optional<bool> GetReferenceClock() noexcept;
    void SetReferenceClock(const bool referenceClock) noexcept;

    std::optional<int32_t> GetCycleTime0() noexcept;
    void SetCycleTime0(const int32_t cycleTime0) noexcept;

    std::optional<int32_t> GetCycleTime1() noexcept;
    void SetCycleTime1(const int32_t cycleTime1) noexcept;

    std::optional<int32_t> GetShiftTime() noexcept;
    void SetShiftTime(const int32_t shiftTime) noexcept;
  };

  class Slave { // Figure 5, page 9
  private:
    // mandatory
    InfoType                        m_Info;
    // optional
    ProcessDataType                 m_ProcessData;
    bool                            m_hasProcessData = false;
    // optional
    Mailbox                         m_Mailbox;
    bool                            m_hasMailbox = false;
    // optional
    InitCmdsType                    m_InitCmds;
    bool                            m_hasInitCmds = false;
    // conditional: 0 to infinity (Mandatory if slave has no HotConnect entry and is not connected to the master.)
    std::vector<PreviousPortType>   m_PreviousPortList;
    // optional
    HotConnectType                  m_HotConnect;
    bool                            m_hasHotConnect = false;
    // optional
    DCType                          m_DC;
    bool                            m_hasDC   = false;
  
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    auto SetInfo(const InfoType& info) noexcept -> void;
    auto GetInfo() noexcept -> InfoType&;

    auto SetProcessData(const ProcessDataType& prData) noexcept -> void;
    auto GetProcessData() noexcept -> std::optional<ProcessDataType>;

    auto SetMailbox(const Mailbox& mailbox) noexcept -> void;
    auto GetMailBox() noexcept -> std::optional<Mailbox>;

    auto SetInitCmds(const InitCmdsType& initCmds) noexcept -> void;
    auto GetInitCmds() noexcept -> std::optional<InitCmdsType>;

    auto AddPreviousPort(const PreviousPortType& previousPort) noexcept -> void;
    auto GetPreviousPortList() noexcept -> std::vector<PreviousPortType>&;

    auto SetHotConnect(const HotConnectType& hotConnect) noexcept -> void;
    auto GetHotConnect() noexcept -> std::optional<HotConnectType>;

    auto SetDC(const DCType& dc) noexcept -> void;
    auto GetDC() noexcept -> std::optional<DCType>;
  };
}  // Controller::Ethercat::EniParser::EtherCATConfig::Config::Slave

#endif // __SLAVE_H__
