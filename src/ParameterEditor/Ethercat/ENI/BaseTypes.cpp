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

#include "BaseTypes.h"

namespace Controller::Ethercat::EniParser::BaseTypes {

  void operator|=(Choice_Ado_Addr& l, const Choice_Ado_Addr& r) {
    auto sum = static_cast<int>(l) + static_cast<int>(r);
    l = (sum < static_cast<int>(Choice_Ado_Addr::Error)) ? static_cast<Choice_Ado_Addr>(sum) : Choice_Ado_Addr::Error; 
  }

  void operator|=(Choice_Data_DataLength& l, const Choice_Data_DataLength& r) {
    auto sum = static_cast<int>(l) + static_cast<int>(r);
    l = (sum < static_cast<int>(Choice_Data_DataLength::Error)) ? static_cast<Choice_Data_DataLength>(sum) : Choice_Data_DataLength::Error; 
  }

  void operator|=(Choice_Validate_Timeout& l, const Choice_Validate_Timeout& r) {
    auto sum = static_cast<int>(l) + static_cast<int>(r);
    l = (sum < static_cast<int>(Choice_Validate_Timeout::Error)) ? static_cast<Choice_Validate_Timeout>(sum) : Choice_Validate_Timeout::Error; 
  }
  
  uint64_t HexDecValue::parse_hex(const std::string& value_str) {
    uint64_t result = 0;
    for (int i = 2; i < value_str.size(); i++) {
      int digit = 0;
      if (value_str[i] >= '0' && value_str[i] <= '9') {
        digit = value_str[i] - '0';
      } else if (value_str[i] >= 'a' && value_str[i] <= 'f') {
        digit = value_str[i] - 'a' + 10;
      } else if (value_str[i] >= 'A' && value_str[i] <= 'F') {
        digit = value_str[i] - 'A' + 10;
      } else {
        throw std::invalid_argument("Invalid hexadecimal digit");
      }
      result = (result << 4) | digit;
    }
    return result;
  }

  uint64_t HexDecValue::parse_dec(const std::string& value_str) {
    uint64_t result = 0;
    for (int i = 0; i < value_str.size(); i++) {
      if (value_str[i] >= '0' && value_str[i] <= '9') {
        result = result * 10 + (value_str[i] - '0');
      } else {
        throw std::invalid_argument("Invalid decimal digit");
      }
    }
    return result;
  }

  uint64_t HexDecValue::value() const {
    return m_Value;
  }

  void HexDecValue::set(const std::string& hdv) {
    if (hdv.empty()) {
      throw std::invalid_argument("Empty hexadecimal or decimal value");
    }
    if (hdv[0] == '#' || hdv[0] == '0') {
      // hexadecimal value
      m_Value = parse_hex(hdv);
    } else {
      // decimal value
      m_Value = parse_dec(hdv);
    }
  }

  HexBinary& HexBinary::operator=(const HexBinary& other) {
    std::memcpy(m_Buffer, other.m_Buffer, sizeof(m_Buffer));
    m_Size = other.m_Size;
    return *this;
  }

  bool HexBinary::operator==(const HexBinary& other) const {
    if (m_Size != other.m_Size) {
      return false;
    }
    return std::memcmp(m_Buffer, other.m_Buffer, m_Size) == 0;
  }

  void HexBinary::set(const std::string& hex_string) {
    if (hex_string.size() % 2 != 0) {
      throw std::invalid_argument("Invalid HexBinary string: odd number of characters");
    }
    if (hex_string.size() / 2 > BUFFER_SIZE) {
      throw std::invalid_argument("HexBinary string too long");
    }
    std::istringstream iss(hex_string);
    std::string octet_string;
    for (size_t i = 0; i < hex_string.size() / 2; i++) {
      iss >> std::setw(2) >> octet_string;
      if (!iss) {
        throw std::invalid_argument("Invalid HexBinary string: invalid octet");
      }
      std::istringstream octet_iss(octet_string);
      int octet = 0;
      if (!(octet_iss >> std::hex >> octet) || octet < 0 || octet > 255) {
        throw std::invalid_argument("Invalid HexBinary string: invalid octet");
      }
      m_Buffer[i] = static_cast<uint8_t>(octet);
    }
    m_Size = hex_string.size() / 2;
  }

  size_t HexBinary::size() const {
    return m_Size;
  }

  const uint8_t* HexBinary::data() const {
    return m_Buffer;
  }

  uint8_t& HexBinary::operator[](size_t index) {
    if (index >= m_Size) {
      throw std::out_of_range("HexBinary index out of range");
    }
    return m_Buffer[index];
  }

  const uint8_t& HexBinary::operator[](size_t index) const {
    if (index >= m_Size) {
      throw std::out_of_range("HexBinary index out of range");
    }
    return m_Buffer[index];
  }

  HexBinary::operator uint8_t() const {
    if (m_Size == 0) {
      throw std::runtime_error("HexBinary has no data");
    }
    if (m_Size > sizeof(uint8_t)) {
      throw std::runtime_error("HexBinary is too long to cast as uint8_t");
    }
    return m_Buffer[0];
  }

  HexBinary::operator uint16_t() const {
    if (m_Size == 0) {
      throw std::runtime_error("HexBinary has no data");
    }
    if (m_Size > sizeof(uint16_t)) {
      throw std::runtime_error("HexBinary is too long to cast as uint16_t");
    }
    uint16_t value = 0;
    for (size_t i = 0; i < m_Size; i++) {
      value |= static_cast<uint16_t>(m_Buffer[i]) << (i * 8);
    }
    return value;
  }

  HexBinary::operator uint32_t() const {
    if (m_Size == 0) {
      throw std::runtime_error("HexBinary has no data");
    }
    if (m_Size > sizeof(uint32_t)) {
      throw std::runtime_error("HexBinary is too long to cast as uint32_t");
    }
    uint32_t value = 0;
    for (size_t i = 0; i < m_Size; i++) {
      value |= static_cast<uint32_t>(m_Buffer[i]) << (i * 8);
    }
    return value;
  }

  HexBinary::operator uint64_t() const {
    if (m_Size == 0) {
      throw std::runtime_error("HexBinary has no data");
    }
    if (m_Size > sizeof(uint64_t)) {
      throw std::runtime_error("HexBinary is too long to cast as uint64_t");
    }
    uint64_t value = 0;
    for (size_t i = 0; i < m_Size; i++) {
      value |= static_cast<uint64_t>(m_Buffer[i]) << (i * 8);
    }
    return value;
  }

  auto Commentable::SetComment(const std::string comment) noexcept -> void {
    m_Comment = comment;
  }

  auto Commentable::GetComment() const noexcept -> const std::optional<std::string> {
    if (!m_Comment.empty()) return m_Comment;
    else return std::nullopt;
  }

  auto NameType::AttributesType::Parse(rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_attribute<>* attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = attr->name();

      std::cout << "Attr name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)){
        case Hash::GenerateFNVHash("LcId"):
          SetLcId(std::stoi(attr->value()));
          break;
        default:
          // ! TODO : maybe throw here ?
          std::cout << "Unknown attribute `" << attr->name() << "`" << std::endl;
          break;
      }
    }
  }

  auto NameType::AttributesType::SetLcId(int lcid) noexcept -> void {
    m_hasLdId = true;
    m_LcId = lcid;
  }

  auto NameType::AttributesType::GetLcId() const noexcept -> std::optional<int> {
    if(m_hasLdId) return m_LcId;
    return std::nullopt;
  }

  auto NameType::Parse(rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);
    assign(n->value());
  }

  void ECatCmdType::ValidateType::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for (rapidxml::xml_attribute<>* attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = attr->name();

      std::cout << "Attr name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)){
        case Hash::GenerateFNVHash("Type"):
          SetType(attr->value());
          break;
        case Hash::GenerateFNVHash("Signed"): {
          auto str = std::string(attr->value());
          if(str == "true") Signed = true;
          else if(str == "false") Signed = false;
          break;
        }
        default:
          // ! TODO : maybe throw here ?
          std::cout << "Unknown attribute `" << attr->name() << "`" << std::endl;
          break;
      }
    }
  }

  void ECatCmdType::ValidateType::AttributesType::SetType(const std::string type) noexcept {
    m_hasType = true;
    m_Type = type;
  }
  
  std::optional<std::string> ECatCmdType::ValidateType::AttributesType::GetType() noexcept {
    if(m_hasType) return m_Type;
    return std::nullopt;
  }

  void ECatCmdType::ValidateType::Parse(const rapidxml::xml_node<> *n) {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = node->name();

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("Data") :
          Data.set(node->value());
          break;
        case Hash::GenerateFNVHash("DataMask") : {
          HexBinary dataMask;
          dataMask.set(node->value());
          SetDataMask(dataMask);
          break;
        }
        case Hash::GenerateFNVHash("Timeout") :
          Timeout = std::stoi(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void ECatCmdType::ValidateType::SetDataMask(const HexBinary dataMask) {
    m_hasDataMask = true;
    m_DataMask = dataMask;
  }

  std::optional<HexBinary> ECatCmdType::ValidateType::GetDataMask() noexcept {
    if(m_hasDataMask) return m_DataMask;
    return std::nullopt;
  }

  auto ECatCmdType::Parse(rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case (Hash::GenerateFNVHash("Transition")) : {
          auto str = node->value();
          switch (Hash::GenerateFNVHash(str)) {
            case Hash::GenerateFNVHash("II"):
              AddTransition(TransitionType::II);
              break;
            case Hash::GenerateFNVHash("IP"):
              AddTransition(TransitionType::IP);
              break;
            case Hash::GenerateFNVHash("PP"):
              AddTransition(TransitionType::PP);
              break;
            case Hash::GenerateFNVHash("PO"):
              AddTransition(TransitionType::PO);
              break;
            case Hash::GenerateFNVHash("PS"):
              AddTransition(TransitionType::PS);
              break;
            case Hash::GenerateFNVHash("PI"):
              AddTransition(TransitionType::PI);
              break;
            case Hash::GenerateFNVHash("SS"):
              AddTransition(TransitionType::SS);
              break;
            case Hash::GenerateFNVHash("SP"):
              AddTransition(TransitionType::SP);
              break;
            case Hash::GenerateFNVHash("SO"):
              AddTransition(TransitionType::SO);
              break;
            case Hash::GenerateFNVHash("SI"):
              AddTransition(TransitionType::SI);
              break;
            case Hash::GenerateFNVHash("OS"):
              AddTransition(TransitionType::OS);
              break;
            case Hash::GenerateFNVHash("OP"):
              AddTransition(TransitionType::OP);
              break;
            case Hash::GenerateFNVHash("OI"):
              AddTransition(TransitionType::OI);
              break;
            case Hash::GenerateFNVHash("IB"):
              AddTransition(TransitionType::IB);
              break;
            case Hash::GenerateFNVHash("BI"):
              AddTransition(TransitionType::BI);
              break;
            default:
              throw new std::invalid_argument("Invalid node name in ENI file");
              break;
          } // switch
          break;
        }
        case (Hash::GenerateFNVHash("BeforeSlave")) : {
          auto str = std::string(node->value());
          if (str == "true") SetBeforeSlave(true);
          else if (str == "false") SetBeforeSlave(false);
          break;
        }
        case (Hash::GenerateFNVHash("Comment")) :
          SetComment(node->first_node()->value());
          break;
        case (Hash::GenerateFNVHash("Requires")) : {
          auto str = std::string(node->value());
          if (str == "cycle") SetRequire(Require::cycle);
          else if (str == "frame") SetRequire(Require::frame);
          else; // ! TODO : maybe throw here ?
          break;
        }
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
          } // switch
          break;
        }
        case (Hash::GenerateFNVHash("Adp")) :
          SetAdp(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Ado")) :
          SetAdo(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Addr")) :
          SetAddr(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Data")) :
          SetData(node->value());
          break;
        case (Hash::GenerateFNVHash("DataLength")):
          SetDataLength(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Cnt")) :
          SetCnt(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Retries")) :
          SetRetries(std::stoi(node->value()));
          break;
        case (Hash::GenerateFNVHash("Validate")) : {
          ValidateType validate;
          validate.Parse(node);
          SetValidate(validate);
          break;
        }
        case (Hash::GenerateFNVHash("Timeout")) : {
          SetTimeout(std::stoi(node->value()));
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto ECatCmdType::SetTransitionList(std::vector<TransitionType> transitionList) noexcept -> void {
    m_TransitionList = transitionList;
  }

  auto ECatCmdType::AddTransition(TransitionType transition) -> void {
    m_TransitionList.push_back(transition);
  }

  auto ECatCmdType::GetTransitionList() noexcept -> std::vector<TransitionType>& {
    return m_TransitionList;
  }

  void ECatCmdType::SetBeforeSlave(const bool before_slave) {
    m_hasBeforeSlave = true;
    m_BeforeSlave = before_slave;
  }

  std::optional<bool> ECatCmdType::GetBeforeSlave() {
    if (m_hasBeforeSlave) return m_BeforeSlave;
    return std::nullopt;
  }

  auto ECatCmdType::SetRequire(Require req) noexcept -> void {
    m_hasRequires = true;
    m_Requires = req;
  }

  auto ECatCmdType::GetRequire() const -> const std::optional<Require> {
    if (m_hasRequires) return m_Requires;
    return std::nullopt;
  }

  auto ECatCmdType::SetCnt(const int cnt) noexcept -> void {
    m_hasCnt = true;
    m_Cnt = cnt;
  }

  auto ECatCmdType::GetCnt() const noexcept -> const std::optional<int> {
    if (m_hasCnt) return m_Cnt;
    return std::nullopt;
  }

  auto ECatCmdType::SetRetries(int retries) noexcept -> void {
    m_hasRetries = true;
    m_Retries = retries;
  }

  auto ECatCmdType::GetRetries() const noexcept -> const std::optional<int> {
    if (m_hasRetries) return m_Retries;
    return std::nullopt;
  }

  // ! NOTE : the ADP field is optional `ONLY IF` ADO is SET !
  auto ECatCmdType::SetAdp(const uint16_t adp) noexcept -> void {
    m_hasAdp = true;
    m_Adp = adp;
  }

  auto ECatCmdType::GetAdp() const noexcept -> const std::optional<uint16_t> {
    if (m_hasAdp) return m_Adp;
    return std::nullopt;
  }

  auto ECatCmdType::SetAdo(const uint16_t ado) noexcept -> void {
    m_Choice_Ado_Addr |= Choice_Ado_Addr::Ado;
    m_Ado = ado;
  }

  auto ECatCmdType::GetAdo() const noexcept -> const std::optional<uint16_t> {
    if (m_Choice_Ado_Addr == Choice_Ado_Addr::Ado) return m_Ado;
    return std::nullopt;
  }

  auto ECatCmdType::SetAddr(const int address) noexcept -> void {
    m_Choice_Ado_Addr |= Choice_Ado_Addr::Addr;      
    m_Addr = address;
  }

  auto ECatCmdType::GetAddr() const noexcept -> std::optional<const int> {
    if(m_Choice_Ado_Addr == Choice_Ado_Addr::Addr) return m_Addr;
    return std::nullopt;
  }

  auto ECatCmdType::SetData(const std::string data) noexcept -> void {
    m_Choice_Data_DataLength |= Choice_Data_DataLength::Data;
    m_Data.set(data);
  }

  auto ECatCmdType::GetData() const noexcept -> const std::optional<HexBinary> {
    if (m_Choice_Data_DataLength == Choice_Data_DataLength::Data) return m_Data;
    return std::nullopt;
  }

  auto ECatCmdType::SetDataLength(const int length) noexcept -> void {
    m_Choice_Data_DataLength |= Choice_Data_DataLength::DataLength;
    m_DataLength = length;
  }

  auto ECatCmdType::GetDataLength() const noexcept -> const std::optional<int> {
    if (m_Choice_Data_DataLength == Choice_Data_DataLength::DataLength) return m_DataLength;
    return std::nullopt;
  }
  
  auto ECatCmdType::SetTimeout(const int timeOut) noexcept -> void {
    m_Choice_Validate_Timeout |= Choice_Validate_Timeout::Timeout;
    m_Timeout = timeOut;
  }

  auto ECatCmdType::GetTimeout() const noexcept -> const std::optional<int> {
    if (m_Choice_Validate_Timeout == Choice_Validate_Timeout::Timeout) return m_Timeout;
    return std::nullopt;
  }

  auto ECatCmdType::SetValidate(const ValidateType& validate) noexcept -> void {
    m_Choice_Validate_Timeout |= Choice_Validate_Timeout::Validate;
    m_Validate = validate;
  }

  auto ECatCmdType::GetValidate() noexcept -> std::optional<ValidateType> {
    if (m_Choice_Validate_Timeout == Choice_Validate_Timeout::Validate) return m_Validate;
    return std::nullopt;
  }

  auto ECatCmdType::__IsValid() noexcept -> bool {
    return (
      ((m_Choice_Ado_Addr != Choice_Ado_Addr::Error) && (m_Choice_Ado_Addr != Choice_Ado_Addr::ErrorNone))
      && (m_Choice_Validate_Timeout != Choice_Validate_Timeout::Error)
      && ((m_Choice_Data_DataLength != Choice_Data_DataLength::Error) && (m_Choice_Data_DataLength != Choice_Data_DataLength::ErrorNone))
    );
  }


} // namespace Controller::Ethercat::EniParser::BaseTypes