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

#ifndef __BASE_TYPES_H__
#define __BASE_TYPES_H__

#include <vector>
#include <optional>
#include <cstdbool>
#include <string>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <iomanip>

#include "Core/Hash.h"

#include "rapidxml.hpp"
#include <iostream>

namespace Controller::Ethercat::EniParser::BaseTypes {

  struct HexDecValue {
  private:
    uint64_t m_Value = 0;

    uint64_t parse_hex(const std::string& value_str);
    uint64_t parse_dec(const std::string& value_str);

  public:
    uint64_t value() const;
    void set(const std::string& hdv);
  };

  struct HexBinary {
  private:
    static constexpr size_t BUFFER_SIZE = 32;
    uint8_t m_Buffer[BUFFER_SIZE];
    size_t m_Size;

  public:
    HexBinary() : m_Size(0) {}

    HexBinary& operator=(const HexBinary& other);
    bool operator==(const HexBinary& other) const;
    void set(const std::string& hex_string);
    size_t size() const;
    const uint8_t* data() const;
    uint8_t& operator[](size_t index);
    const uint8_t& operator[](size_t index) const;
    operator uint8_t() const;
    operator uint16_t() const;
    operator uint32_t() const;
    operator uint64_t() const;
  };

#pragma region Enumerations

  enum BaseDataType {
    BOOLEAN         = 0x0001,
    INTEGER8        = 0x0002,
    INTEGER16       = 0x0003,
    INTEGEfloat       = 0x0004,
    UNSIGNED8       = 0x0005,
    UNSIGNED16      = 0x0006,
    UNSIGNED32      = 0x0007,
    REAL32          = 0x0008,
    VISIBLE_STRING  = 0x0009,
    OCTET_STRING    = 0x000A,
    UNICODE_STRING  = 0x000B,
    TIME_OF_DAY     = 0x000C,
    TIME_DIFFERENCE = 0x000D,
    DOMAIN          = 0x000F,
    INTEGER24       = 0x0010,
    REAL64          = 0x0011,
    INTEGEdouble       = 0x0015,
    UNSIGNED24      = 0x0016,
    UNSIGNED64      = 0x001B,
    BIT1            = 0x0030,
    BIT2            = 0x0031,
    BIT3            = 0x0032,
    BIT4            = 0x0033,
    BIT5            = 0x0034,
    BIT6            = 0x0035,
    BIT7            = 0x0036,
    BIT8            = 0x0037
  };

  enum class enum_Cmd : int {
    NOP  = 0,   // No operation
    APRD = 1,   // Auto increment physical read
    APWR = 2,   // Auto increment physical write
    APRW = 3,   // Auto increment physical read write
    FPRD = 4,   // Configured address physical read
    FPWR = 5,   // Configured address physical write
    FPRW = 6,   // Configured address physical read write
    BRD  = 7,   // Broadcast read
    BWR  = 8,   // Broadcast write
    BRW  = 9,   // Broadcast read write
    LRD  = 10,  // Logical memory read
    LWR  = 11,  // Logical memory write
    LRW  = 12,  // Logical memory read write
    ARMW = 13,  // Auto increment physical read multiple write
    FRMW = 14   // Configured address physical read write
    // 15 - 255
  };

  enum DataType : int {
    UINT8   = 0,
    UINT16  = 1,
    UINT32  = 2,
    INT8    = 3,
    INT16   = 4,
    INT32   = 5,
    SINT    = 6,
    DINT    = 7,
    UINT    = 8,
    INT     = 9
  };

  enum Element {   // From Table 21
    DataState    = 0x1,
    Name         = 0x2,
    Attribute    = 0x4,
    Unit         = 0x8,
    Min          = 0x10,
    Max          = 0x20,
    Value        = 0x40,
    DefaultValue = 0x80
  };

  enum PDOType {
    RxPdo = 1,
    TxPdo
  };

  enum class Restriction {
    MBoxOut,
    MBoxIn,
    Outputs,
    Inputs
  };

  enum class Require : int {
    frame = 1,
    cycle
  };

  enum SynchManager {
    Sm0 = 0,
    Sm1 = 1,
    Sm2 = 2,
    Sm3 = 3,
    Sm4 = 4,
    Sm5 = 5,
    Sm6 = 6,
    Sm7 = 7,
    Sm8 = 8,
    Sm9 = 9,
    Sm10 = 10,
    Sm11 = 11,
    Sm12 = 12,
    Sm13 = 13,
    Sm14 = 14,
    Sm15 = 15,
  };

  enum class State {
    INIT = 0,
    PREOP,
    SAFEOP,
    OP
  };

  enum class TransitionType {
    II = 0,
    IP,
    PP,
    PO,
    PS,
    PI,
    SS,
    SP,
    SO,
    SI,
    OS,
    OP,
    OI,
    IB,
    BI
  };

  enum class Protocol : int {
    CoE = 0x01, // CANopen over EtherCAT
    SoE = 0x02, // Servo profile over EtherCAT
    AoE = 0x03, // ADS over EtherCAT
    EoE = 0x04, // Ethernet over EtherCAT
    FoE = 0x05, // File Access over EtherCAT
    VoE = 0x06, // Vendor specific profile over EtherCAT
  };

#pragma endregion

  struct Commentable {
  protected:
    std::string    m_Comment;
  public:
    auto SetComment(const std::string comment) noexcept -> void;
    auto GetComment() const noexcept -> const std::optional<std::string>;
  };

  struct NameType : public std::string {
    
    struct AttributesType {
      int     m_LcId;
      bool    m_hasLdId = false;
    public:
      auto Parse(rapidxml::xml_node<> *n) -> void;

      auto SetLcId(int lcid) noexcept -> void;
      auto GetLcId() const noexcept -> std::optional<int>;
    };
  public:
    AttributesType Attributes;
  public:
    auto Parse(rapidxml::xml_node<> *n) -> void;

    NameType(const std::string& name, std::optional<int> lcid = std::nullopt) : std::string(name) {
      if(lcid != std::nullopt) Attributes.SetLcId(lcid.value());
    }

    NameType() : std::string("") {}

  };

#pragma region ECatInitCmd

  enum class Choice_Ado_Addr {
    ErrorNone = 0,
    Ado = 1,
    Addr = 2,
    Error = 3,
  };

  void operator|=(Choice_Ado_Addr& l, const Choice_Ado_Addr& r);

  enum class Choice_Data_DataLength {
    ErrorNone = 0,
    Data = 1,
    DataLength = 2,
    Error = 3,
  };

  void operator|=(Choice_Data_DataLength& l, const Choice_Data_DataLength& r);

  enum class Choice_Validate_Timeout {
    None = 0,
    Validate = 1,
    Timeout = 2,
    Error = 3,
  };

  void operator|=(Choice_Validate_Timeout& l, const Choice_Validate_Timeout& r);
  
  struct ECatCmdType : public Commentable {

    struct ValidateType {

      struct AttributesType {
      public:
        bool Signed = false;
      private:
        std::string m_Type;
        bool m_hasType = false;
      public:
        void Parse(const rapidxml::xml_node<> *n);

        void SetType(const std::string type) noexcept;
        std::optional<std::string> GetType() noexcept;
      };

      AttributesType  Attributes;
      HexBinary       Data;
      int             Timeout;
    private:
      HexBinary       m_DataMask;
      bool            m_hasDataMask;
    public:
      void Parse(const rapidxml::xml_node<> *n);

      void SetDataMask(const HexBinary dataMask);
      std::optional<HexBinary> GetDataMask() noexcept;
    };
  public:
    enum_Cmd                       Cmd;
  private:
    // optioanal 0 to infinity
    std::vector<TransitionType>   m_TransitionList;

    bool                      m_BeforeSlave;
    bool                      m_hasBeforeSlave = false;
    Require                   m_Requires;
    bool                      m_hasRequires = false;
    int                       m_Cnt;
    bool                      m_hasCnt = false;
    int                       m_Retries;
    bool                      m_hasRetries = false;
    
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
    
    // Both Timeout and Validate are optional but cannot exist at the same time
    int                       m_Timeout;
    ValidateType              m_Validate;
    Choice_Validate_Timeout   m_Choice_Validate_Timeout = Choice_Validate_Timeout::None;

  public:
    auto Parse(rapidxml::xml_node<> *n) -> void;

    auto SetTransitionList(std::vector<TransitionType> transitionList) noexcept -> void;
    auto AddTransition(TransitionType transition) -> void;
    auto GetTransitionList() noexcept -> std::vector<TransitionType>&;

    void SetBeforeSlave(const bool before_slave);
    std::optional<bool> GetBeforeSlave();

    auto SetRequire(Require req) noexcept -> void;
    auto GetRequire() const -> const std::optional<Require>;

    auto SetCnt(const int cnt) noexcept -> void;
    auto GetCnt() const noexcept -> const std::optional<int>;

    auto SetRetries(int retries) noexcept -> void;
    auto GetRetries() const noexcept -> const std::optional<int>;

    // ! NOTE : the ADP field is optional `ONLY IF` ADO is SET !
    auto SetAdp(const uint16_t adp) noexcept -> void;
    auto GetAdp() const noexcept -> const std::optional<uint16_t>;

    auto SetAdo(const uint16_t ado) noexcept -> void;
    auto GetAdo() const noexcept -> const std::optional<uint16_t>;

    auto SetAddr(const int address) noexcept -> void;
    auto GetAddr() const noexcept -> std::optional<const int>;

    auto SetData(const std::string data) noexcept -> void;
    auto GetData() const noexcept -> const std::optional<HexBinary>;

    auto SetDataLength(const int length) noexcept -> void;
    auto GetDataLength() const noexcept -> const std::optional<int>;
    
    auto SetTimeout(const int timeOut) noexcept -> void;
    auto GetTimeout() const noexcept -> const std::optional<int>;

    auto SetValidate(const ValidateType& validate) noexcept -> void;
    auto GetValidate() noexcept -> std::optional<ValidateType>;

    auto __IsValid() noexcept -> bool;
  };

#pragma endregion ECatInitCmd

} // namespace Controller::Ethercat::EniParser::BaseTypes

#endif // __BASE_TYPES_H__
