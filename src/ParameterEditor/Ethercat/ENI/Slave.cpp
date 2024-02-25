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

#include "Slave.h"

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Slave {
  
  void InfoType::IdentificationType::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
      case (Hash::GenerateFNVHash("Value")):
        Value.set(attr->value());
        break;
      default:
        std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
        throw new std::invalid_argument("Unknown attribute in ENI file.");
        break;
      }
    }
  }

  auto InfoType::IdentificationType::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node Name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
      case (Hash::GenerateFNVHash("Ado")):
        Ado.set(node->value());
        break;
      default:
        std::cout << "Unknown node `" << nodeName << "`" << std::endl;
        throw new std::invalid_argument("Unknown node in ENI file.");
        break;
      }
    }
  }

  auto InfoType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Name")) :
          Name = std::string(node->first_node()->value());
          break;
        case(Hash::GenerateFNVHash("PhysAddr")) :
          SetPhysAddress(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("AutoIncAddr")) :
          SetAutoIncAddr(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Physics")) :
          SetPhysics(node->value());
          break;
        case(Hash::GenerateFNVHash("Identification")):{
          IdentificationType identification;
          identification.Parse(node);
          SetIdentitication(identification);
          break;
        }
        case(Hash::GenerateFNVHash("VendorId")) :
          VendorID = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("ProductCode")) :
          ProductCode = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("RevisionNo")) :
          RevisionNo = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("SerialNo")):
          SerialNo = std::stoi(node->value());
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
    if(!__IsValid())
      throw new std::runtime_error("Invalid Slave::Info node configuration in ENI file");
  }

  auto InfoType::SetPhysAddress(const int32_t addr) noexcept -> void {
    m_PAPI_Flag |= Flags_PAPI::HasPhysAddr;
    m_PhysAddr = addr;
  }

  auto InfoType::GetPhysAddress() noexcept -> std::optional<int32_t> {
    if (m_PAPI_Flag & Flags_PAPI::HasPhysAddr) return m_PhysAddr;
    return std::nullopt;
  }

  auto InfoType::SetAutoIncAddr(const int32_t addr) noexcept -> void {
    m_PAPI_Flag |= Flags_PAPI::HasAutoIncAddr;
    m_AutoIncAddr = addr;
  }

  auto InfoType::GetAutoIncAddr() noexcept -> std::optional<int32_t> {
    if (m_PAPI_Flag & Flags_PAPI::HasAutoIncAddr) return m_AutoIncAddr;
    return std::nullopt;
  }

  auto InfoType::SetPhysics(const std::string phy) noexcept -> void {
    m_PAPI_Flag |= Flags_PAPI::HasPhysics;
    m_Physics = phy;
  }

  auto InfoType::GetPhysics() noexcept -> std::optional<std::string> {
    if ((m_PAPI_Flag & Flags_PAPI::HasPhysics) && !m_Physics.empty()) return m_Physics;
    return std::nullopt;
  }

  auto InfoType::SetIdentitication(const IdentificationType& identification) noexcept -> void {
    m_PAPI_Flag |= Flags_PAPI::HasIdentification;
    m_Identification = identification;
  }

  auto InfoType::GetIdentification() noexcept -> std::optional<IdentificationType> {
    if (m_PAPI_Flag & Flags_PAPI::HasIdentification) return m_Identification;
    return std::nullopt;
  }

  auto InfoType::SetProductRevision(const int32_t rev) noexcept -> void {
    m_hasProductRevision = true;
    m_ProductRevision = rev;
  }

  auto InfoType::GetProductRevision() noexcept -> const std::optional<int32_t> {
    if (m_hasProductRevision) return m_ProductRevision;
    return std::nullopt;
  }

  uint16_t InfoType::__IsValid() {
    return check_Flags_PAPI_Valid_States(m_PAPI_Flag);
  }

  void ProcessDataType::SendType::Parse(const rapidxml::xml_node<> *n) {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = (const char*)node->name();

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("BitStart")):
          BitStart = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("BitLength")):
          BitLength = static_cast<int32_t>(std::stol(node->value()));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      }
    }
  }

  void ProcessDataType::RecvType::Parse(const rapidxml::xml_node<> *n) {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = (const char*)node->name();

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("BitStart")):
          BitStart = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("BitLength")):
          BitLength = static_cast<int32_t>(std::stol(node->value()));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      }
    }
  }

  auto ProcessDataType::SyncManagerSettingsType::Parse(const rapidxml::xml_node<> *n, SynchManager sm_no) -> void {
    SynchManagerNo = sm_no;

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Type")) :{
          auto strType = std::string(node->value());
          if(strType == "Outputs") Type = Type::Outputs;
          else if(strType == "Inputs") Type = Type::Inputs;
          break;
        }
        case(Hash::GenerateFNVHash("MinSize")) :
          SetMinSize(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("MaxSize")) :
          SetMaxSize(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("DefaultSize")) :
          SetDefaultSize(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("StartAddress")) :
          StartAddress = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("ControlByte")) :
          ControlByte = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("Enable")) :
          Enable = static_cast<bool>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Virtual")) :
          SetVirtual(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Watchdog")) :
          SetWatchdog(static_cast<int32_t>(std::stol(node->value())));
          break;
        case(Hash::GenerateFNVHash("Pdo")) :
          AddPdoIndex(static_cast<int32_t>(std::stol(node->value())));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto ProcessDataType::SyncManagerSettingsType::SetMinSize(const uint32_t size) noexcept -> void {
    m_hasMinSize = true;
    m_MinSize = size;
  }

  auto ProcessDataType::SyncManagerSettingsType::GetMinSize() noexcept -> const std::optional<uint32_t> {
    if (m_hasMinSize) return m_MinSize;
    return std::nullopt;
  }

  auto ProcessDataType::SyncManagerSettingsType::SetMaxSize(const uint32_t size) noexcept -> void {
    m_hasMaxSize = true;
    m_MaxSize = size;
  }

  auto ProcessDataType::SyncManagerSettingsType::GetMaxSize() noexcept -> const std::optional<uint32_t> {
    if (m_hasMaxSize) return m_MaxSize;
    return std::nullopt;
  }

  auto ProcessDataType::SyncManagerSettingsType::SetDefaultSize(const uint32_t size) noexcept -> void {
    m_hasDefaultSize = true;
    m_DefaultSize = size;
  }

  auto ProcessDataType::SyncManagerSettingsType::GetDefaultSize() noexcept -> const std::optional<uint32_t> {
    if (m_hasDefaultSize) return m_DefaultSize;
    return std::nullopt;
  }

  auto ProcessDataType::SyncManagerSettingsType::SetVirtual(const bool v) noexcept -> void {
    m_hasVirtual = true;
    m_Virtual = v;
  }

  auto ProcessDataType::SyncManagerSettingsType::GetVirtual() noexcept -> const std::optional<bool> {
    if (m_hasVirtual) return m_Virtual;
    return std::nullopt;
  }

  auto ProcessDataType::SyncManagerSettingsType::SetWatchdog(const uint32_t watchdog) noexcept -> void {
    // ! TODO : maybe throw here ?
    std::cout << "`Watchdog` not used anymore" << std::endl;
    m_hasWatchdog = true;
    m_Watchdog = watchdog;
  }

  auto ProcessDataType::SyncManagerSettingsType::GetWatchdog() noexcept -> const std::optional<uint32_t> {
    if(m_hasWatchdog) return m_Watchdog;
    return std::nullopt;
  }

  auto ProcessDataType::SyncManagerSettingsType::AddPdoIndex(const uint16_t index) noexcept -> void {
    m_PdoList.push_back(index);
  }

  auto ProcessDataType::SyncManagerSettingsType::GetPdoList() noexcept -> std::vector<uint16_t>& {
    return m_PdoList;
  }

  void ProcessDataType::PdoType::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
        case(Hash::GenerateFNVHash("Fixed")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetFixed(true);
          else if(str == "false") SetFixed(false);
          break;
        }
        case(Hash::GenerateFNVHash("Mandatory")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetMandatory(true);
          else if(str == "false") SetMandatory(false);
          break;
        }
        case(Hash::GenerateFNVHash("Virtual")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetVirtual(true);
          else if(str == "false") SetVirtual(false);
          break;
        }
        case(Hash::GenerateFNVHash("Sm")) :
          SetSm(static_cast<SynchManager>(std::stoi(attr->value())));
          break;
        case(Hash::GenerateFNVHash("Su")) :
          SetSu(static_cast<int16_t>(std::stoi(attr->value())));
          break;
        case(Hash::GenerateFNVHash("PdoOrder")) :
          SetPdoOrder(static_cast<int16_t>(std::stoi(attr->value())));
          break;
        case(Hash::GenerateFNVHash("OSFac")) :
          SetOSFac(static_cast<int16_t>(std::stoi(attr->value())));
          break;
        case(Hash::GenerateFNVHash("OSMin")) :
          SetOSMin(static_cast<int16_t>(std::stoi(attr->value())));
          break;
        case(Hash::GenerateFNVHash("OSMax")) :
          SetOSMax(static_cast<int16_t>(std::stoi(attr->value())));
        case(Hash::GenerateFNVHash("OSIndexInc")) :
          SetOSIndexInc(static_cast<int16_t>(std::stoi(attr->value())));
          break;
        default:
          std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
          throw new std::invalid_argument("Unknown attribute in ENI file.");
          break;
      }
    }
  }

  std::optional<bool> ProcessDataType::PdoType::AttributesType::GetFixed() noexcept {
    if(m_hasFixed) return m_Fixed;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetFixed(const bool fixed) noexcept {
    m_hasFixed = true;
    m_Fixed = fixed;
  }

  std::optional<bool> ProcessDataType::PdoType::AttributesType::GetMandatory() noexcept {
    if(m_hasMandatory) return m_Mandatory;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetMandatory(const bool mandatory) noexcept {
    m_hasMandatory = true;
    m_Mandatory = mandatory;
  }

  std::optional<bool> ProcessDataType::PdoType::AttributesType::GetVirtual() noexcept {
    if(m_hasVirtual) return m_Virtual;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetVirtual(const bool virtuall) noexcept {
    m_hasVirtual = true;
    m_Virtual = virtuall;
  }

  std::optional<SynchManager> ProcessDataType::PdoType::AttributesType::GetSm() noexcept {
    if(m_hasSm) return m_Sm;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetSm(const SynchManager sm) noexcept {
    m_hasSm = true;
    m_Sm = sm;
  }

  std::optional<uint16_t> ProcessDataType::PdoType::AttributesType::GetSu() noexcept {
    if(m_hasSu) return m_Su;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetSu(const uint16_t su) noexcept {
    m_hasSu = true;
    m_Su = su;
  }

  std::optional<uint16_t> ProcessDataType::PdoType::AttributesType::GetPdoOrder() noexcept {
    if(m_hasPdoOrder) return m_PdoOrder;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetPdoOrder(const uint16_t PdoOrder) noexcept {
    m_hasPdoOrder = true;
    m_PdoOrder = PdoOrder;
  }

  std::optional<uint16_t> ProcessDataType::PdoType::AttributesType::GetOSFac() noexcept {
    if(m_hasOSFac) return m_OSFac;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetOSFac(const uint16_t OSFac) noexcept {
    m_hasOSFac = true;
    m_OSFac = OSFac;
  }

  std::optional<uint16_t> ProcessDataType::PdoType::AttributesType::GetOSMin() noexcept {
    if(m_hasOSMin) return m_OSMin;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetOSMin(const uint16_t OSMin) noexcept {
    m_hasOSMin = true;
    m_OSMin = OSMin;
  }

  std::optional<uint16_t> ProcessDataType::PdoType::AttributesType::GetOSMax() noexcept {
    if(m_hasOSMax) return m_OSMax;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetOSMax(const uint16_t OSMax) noexcept {
    m_hasOSMax = true;
    m_OSMax = OSMax;
  }

  std::optional<uint16_t> ProcessDataType::PdoType::AttributesType::GetOSIndexInc() noexcept {
    if(m_hasOSIndexInc) return m_OSIndexInc;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::AttributesType::SetOSIndexInc(const uint16_t OSIndexInc) noexcept {
    m_hasOSIndexInc = true;
    m_OSIndexInc = OSIndexInc;
  }

  void ProcessDataType::PdoType::EntryType::DataType_t::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
      case (Hash::GenerateFNVHash("DScale")):
        SetDScale(std::string(attr->value()));
        break;
      default:
        std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
        throw new std::invalid_argument("Unknown attribute in ENI file.");
        break;
      }
    }
  }

  void ProcessDataType::PdoType::EntryType::DataType_t::AttributesType::SetDScale(const std::string& dscale) {
    m_hasDScale = true;
    m_DScale = dscale;
  }

  std::optional<std::string> ProcessDataType::PdoType::EntryType::DataType_t::AttributesType::GetDScale() {
    if(m_hasDScale) return m_DScale;
    return std::nullopt;
  }

  auto ProcessDataType::PdoType::EntryType::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Index")) :
          Index.set(std::string(node->value()));
          break;
        case(Hash::GenerateFNVHash("SubIndex")) : {
          HexDecValue subIndex;
          subIndex.set(std::string(node->value()));
          SetSubIndex(subIndex);
          break;
        }
        case(Hash::GenerateFNVHash("BitLen")) :
          BitLen = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("Name")) : {
          NameType name;
          name.Parse(node);
          AddName(name);
          break;
        }
        case(Hash::GenerateFNVHash("Comment")) :
          SetComment(std::string(node->value()));
          break;
        case(Hash::GenerateFNVHash("DataType")) :
          SetDataType(std::string(node->value()));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto ProcessDataType::PdoType::EntryType::SetSubIndex(const HexDecValue& subindex) noexcept -> void {
    m_hasSubIndex = true;
    m_SubIndex = subindex;
  }

  auto ProcessDataType::PdoType::EntryType::GetSubIndex() noexcept -> const std::optional<HexDecValue> {
    if (m_hasSubIndex) return m_SubIndex;
    return std::nullopt;
  }

  auto ProcessDataType::PdoType::EntryType::AddName(const NameType& name) noexcept -> void {
    m_NameList.push_back(name);
  }

  auto ProcessDataType::PdoType::EntryType::GetNameList() noexcept -> std::vector<NameType>& {
    return m_NameList;
  }

  auto ProcessDataType::PdoType::EntryType::SetDataType(const std::string datatype) noexcept -> void {
    m_hasDataType = true;
    m_DataType = datatype;
  }

  auto ProcessDataType::PdoType::EntryType::GetDataType() noexcept -> const std::optional<std::string> {
    if (m_hasDataType) return m_DataType;
    return std::nullopt;
  }

  void ProcessDataType::PdoType::ExcludeType::Parse(const rapidxml::xml_node<> *n) {
    Attributes.Parse(n);
    set(std::string(n->value()));
  }

  auto ProcessDataType::PdoType::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Index")) :
          Index.set(node->value());
          break;
        case(Hash::GenerateFNVHash("Name")) : {
          NameType name;
          name.Parse(node);
          AddName(name);
          break;
        }
        case(Hash::GenerateFNVHash("Exclude")) : {
          // ! Check
          ExcludeType exclude;
          exclude.Parse(node);
          AddExclude(exclude);
          break;
        }
        case(Hash::GenerateFNVHash("Entry")) : {
          EntryType entry;
          entry.Parse(node);
          AddEntry(entry);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void ProcessDataType::PdoType::AddName(const NameType& name) noexcept {
    m_NameList.push_back(name);
  }

  std::vector<NameType>& ProcessDataType::PdoType::GetNameList() noexcept {
    return m_NameList;
  }

  void ProcessDataType::PdoType::AddExclude(const ExcludeType& exclude) noexcept {
    m_ExcludeList.push_back(exclude);
  }

  std::vector<ProcessDataType::PdoType::ExcludeType>& ProcessDataType::PdoType::GetExcludeList() noexcept {
    return m_ExcludeList;
  }

  void ProcessDataType::PdoType::AddEntry(const EntryType& entry) noexcept {
    m_EntryList.push_back(entry);
  }

  std::vector<ProcessDataType::PdoType::EntryType>& ProcessDataType::PdoType::GetEntryList() noexcept {
    return m_EntryList;
  }

  // will be called only at parse
  bool ProcessDataType::PdoType::__IsValid() noexcept {
    return(m_NameList.size() > 0);
  }

  auto ProcessDataType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Send")) : {
          SendType send;
          send.Parse(node);
          AddSend(send);
          break;
        }
        case(Hash::GenerateFNVHash("Recv")) : {
          RecvType receive;
          receive.Parse(node);
          AddRecv(receive);
          break;
        }
        case(Hash::GenerateFNVHash("Sm0")) : {
          SyncManagerSettingsType sm0;
          sm0.Parse(node, SynchManager::Sm0);
          AddSM(sm0);
          break;
        }  
        case(Hash::GenerateFNVHash("Sm1")) : {
          SyncManagerSettingsType sm1;
          sm1.Parse(node, SynchManager::Sm1);
          AddSM(sm1);
          break;
        }
        case(Hash::GenerateFNVHash("Sm2")) : {
          SyncManagerSettingsType sm2;
          sm2.Parse(node, SynchManager::Sm2);
          AddSM(sm2);
          break;
        }
        case(Hash::GenerateFNVHash("Sm3")) : {
          SyncManagerSettingsType sm3;
          sm3.Parse(node, SynchManager::Sm3);
          AddSM(sm3);
          break;
        }
        case(Hash::GenerateFNVHash("Sm4")) : {
          SyncManagerSettingsType sm4;
          sm4.Parse(node, SynchManager::Sm4);
          AddSM(sm4);
          break;
        }
          
        case(Hash::GenerateFNVHash("Sm5")) : {
          SyncManagerSettingsType sm5;
          sm5.Parse(node, SynchManager::Sm5);
          AddSM(sm5);
          break;
        }
        case(Hash::GenerateFNVHash("Sm6")) : {
          SyncManagerSettingsType sm6;
          sm6.Parse(node, SynchManager::Sm6);
          AddSM(sm6);
          break;
        }
        case(Hash::GenerateFNVHash("Sm7")) : {
          SyncManagerSettingsType sm7;
          sm7.Parse(node, SynchManager::Sm7);
          AddSM(sm7);
          break;
        }
        case(Hash::GenerateFNVHash("Sm8")) : {
          SyncManagerSettingsType sm8;
          sm8.Parse(node, SynchManager::Sm8);
          AddSM(sm8);
          break;
        }
        case(Hash::GenerateFNVHash("Sm9")) : {
          SyncManagerSettingsType sm9;
          sm9.Parse(node, SynchManager::Sm9);
          AddSM(sm9);
          break;
        }
        case(Hash::GenerateFNVHash("Sm10")) : {
          SyncManagerSettingsType sm10;
          sm10.Parse(node, SynchManager::Sm10);
          AddSM(sm10);
          break;
        }
        case(Hash::GenerateFNVHash("Sm11")) : {
          SyncManagerSettingsType sm11;
          sm11.Parse(node, SynchManager::Sm11);
          AddSM(sm11);
          break;
        }
        case(Hash::GenerateFNVHash("Sm12")) : {
          SyncManagerSettingsType sm12;
          sm12.Parse(node, SynchManager::Sm12);
          AddSM(sm12);
          break;
        }
        case(Hash::GenerateFNVHash("Sm13")) : {
          SyncManagerSettingsType sm13;
          sm13.Parse(node, SynchManager::Sm13);
          AddSM(sm13);
          break;
        }
        case(Hash::GenerateFNVHash("Sm14")) : {
          SyncManagerSettingsType sm14;
          sm14.Parse(node, SynchManager::Sm14);
          AddSM(sm14);
          break;
        }
        case(Hash::GenerateFNVHash("Sm15")) : {
          SyncManagerSettingsType sm15;
          sm15.Parse(node, SynchManager::Sm15);
          AddSM(sm15);
          break;
        }
        case(Hash::GenerateFNVHash("Sm16")) : {
          SyncManagerSettingsType sm16;
          sm16.Parse(node, SynchManager::Sm1);
          AddSM(sm16);
          break;
        }
        case(Hash::GenerateFNVHash("RxPdo")) : {
          PdoType rxPdo;
          rxPdo.Parse(node);
          AddRxPdo(rxPdo);
          break;
        }
        case(Hash::GenerateFNVHash("TxPdo")) : {
          PdoType txPdo;
          txPdo.Parse(node);
          AddTxPdo(txPdo);
          break;
        } 
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto ProcessDataType::AddSend(const SendType& send) noexcept -> void {
    m_SendList.push_back(send);
  }

  auto ProcessDataType::GetSendList() noexcept -> std::vector<SendType>& {
    return m_SendList;
  }

  auto ProcessDataType::AddRecv(const RecvType& rcv) noexcept -> void {
    m_RecvList.push_back(rcv);
  }

  auto ProcessDataType::GetRecvList() noexcept -> std::vector<RecvType>& {
    return m_RecvList;
  }
  
  auto ProcessDataType::AddSM(const SyncManagerSettingsType& sm) noexcept -> void {
    m_SMList.push_back(sm);
  }

  auto ProcessDataType::GetSMList() noexcept -> std::vector<SyncManagerSettingsType>& {
    return m_SMList;
  }

  auto ProcessDataType::AddRxPdo(const PdoType& pdo) noexcept -> void {
    m_RxPDOList.push_back(pdo);
  }

  auto ProcessDataType::GetRxPDOList() noexcept -> std::vector<PdoType>& {
    return m_RxPDOList;
  }

  auto ProcessDataType::AddTxPdo(const PdoType& pdo) noexcept -> void {
    m_TxPDOList.push_back(pdo);
  }

  auto ProcessDataType::GetTxPDOList() noexcept -> std::vector<PdoType>& {
    return m_TxPDOList;
  }

  void Mailbox::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
        case(Hash::GenerateFNVHash("DataLinkLayer")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetDataLinkLayer(true);
          else if(str == "false") SetDataLinkLayer(false);
          break;
        }
        default:
          std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
          throw new std::invalid_argument("Unknown attribute in ENI file.");
          break;
      }
    }
  }

  void Mailbox::AttributesType::SetDataLinkLayer(bool datalinklayer) noexcept {
    m_hasDataLinkLayer = true;
    m_DataLinkLayer = datalinklayer;
  }

  std::optional<bool> Mailbox::AttributesType::GetDataLinkLayer() noexcept {
    if(m_hasDataLinkLayer) return m_DataLinkLayer;
    return std::nullopt;
  }

  auto Mailbox::MailboxSendInfoType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Start")) :
          Start = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("Length")) :
          Length = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("ShortSend")) :
          SetShortSend(std::stoi(node->value()));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::MailboxSendInfoType::SetShortSend(const bool shortsend) noexcept {
    m_hasShortSend = true;
    m_ShortSend = shortsend;
  }

  std::optional<bool> Mailbox::MailboxSendInfoType::GetShortSend() noexcept {
    if(m_hasShortSend) return m_ShortSend;
    return std::nullopt;
  }

  auto Mailbox::MailboxRecvInfoType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Start")) :
          Start = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("Length")) :
          Length = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("PollTime")) :
          SetPollTime(static_cast<int32_t>(std::stol(node->value())));
          break;
        case(Hash::GenerateFNVHash("StatusBitAddr")) :
          SetStatusBitAddr(static_cast<int32_t>(std::stol(node->value())));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }
  
  void Mailbox::MailboxRecvInfoType::SetPollTime(const int32_t polltime) noexcept {
    m_hasPollTime = true;
    m_PollTime = polltime;
  }

  std::optional<int32_t> Mailbox::MailboxRecvInfoType::GetPollTime() noexcept {
    if(m_hasPollTime) return m_PollTime;
    return std::nullopt;
  }

  void Mailbox::MailboxRecvInfoType::SetStatusBitAddr(const int32_t statusbitaddr) noexcept {
    m_hasStatusBitAddr = true;
    m_StatusBitAddr = statusbitaddr;
  }

  std::optional<int32_t> Mailbox::MailboxRecvInfoType::GetStatusBitAddr() noexcept {
    if(m_hasStatusBitAddr) return m_StatusBitAddr;
    return std::nullopt;
  }

  auto Mailbox::MailboxCmdType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case (Hash::GenerateFNVHash("Transition")) : {
          auto str = node->value();
          switch (Hash::GenerateFNVHash(str)) {
            case Hash::GenerateFNVHash("II"):
              AddTransitionList(TransitionType::II);
              break;
            case Hash::GenerateFNVHash("IP"):
              AddTransitionList(TransitionType::IP);
              break;
            case Hash::GenerateFNVHash("PP"):
              AddTransitionList(TransitionType::PP);
              break;
            case Hash::GenerateFNVHash("PO"):
              AddTransitionList(TransitionType::PO);
              break;
            case Hash::GenerateFNVHash("PS"):
              AddTransitionList(TransitionType::PS);
              break;
            case Hash::GenerateFNVHash("PI"):
              AddTransitionList(TransitionType::PI);
              break;
            case Hash::GenerateFNVHash("SS"):
              AddTransitionList(TransitionType::SS);
              break;
            case Hash::GenerateFNVHash("SP"):
              AddTransitionList(TransitionType::SP);
              break;
            case Hash::GenerateFNVHash("SO"):
              AddTransitionList(TransitionType::SO);
              break;
            case Hash::GenerateFNVHash("SI"):
              AddTransitionList(TransitionType::SI);
              break;
            case Hash::GenerateFNVHash("OS"):
              AddTransitionList(TransitionType::OS);
              break;
            case Hash::GenerateFNVHash("OP"):
              AddTransitionList(TransitionType::OP);
              break;
            case Hash::GenerateFNVHash("OI"):
              AddTransitionList(TransitionType::OI);
              break;
            case Hash::GenerateFNVHash("IB"):
              AddTransitionList(TransitionType::IB);
              break;
            case Hash::GenerateFNVHash("BI"):
              AddTransitionList(TransitionType::BI);
              break;
            default:
              throw new std::invalid_argument("Invalid node name in ENI file");
              break;
          } // switch
          break;
        }
        case(Hash::GenerateFNVHash("Comment")) :
          SetComment(std::string(node->value()));
          break;
        case(Hash::GenerateFNVHash("Timeout")) :
          Timeout = static_cast<int16_t>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Data")) : 
          Data.set(std::string(node->value()));
          break;
        case(Hash::GenerateFNVHash("Disabled")) : {
          auto str = std::string(node->value());
          if(str == "true") SetDisabled(true);
          else if(str == "false") SetDisabled(false);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }
  
  void Mailbox::MailboxCmdType::AddTransitionList(const TransitionType& transition) noexcept {
    m_TransitionList.push_back(transition);
  }
  
  std::vector<TransitionType>& Mailbox::MailboxCmdType::GetTransitionList() noexcept {
    return m_TransitionList;
  }

  void Mailbox::MailboxCmdType::SetDisabled(const bool disabled) noexcept {
    m_hasDisabled = true;
    m_Disabled = disabled;
  }

  std::optional<bool> Mailbox::MailboxCmdType::GetDisabled() noexcept {
    if(m_hasDisabled) return m_Disabled;
    return std::nullopt;
  }

  // will be called only at parse
  bool Mailbox::MailboxCmdType::__IsValid() noexcept {
    return(m_TransitionList.size() > 0);
  }

  auto Mailbox::BootstrapType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Send")) :
          Send.Parse(node);
          break;
        case(Hash::GenerateFNVHash("Recv")) :
          Recv.Parse(node);
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::CoEType::InitCmdsType::InitCmdType::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
        case(Hash::GenerateFNVHash("Fixed")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetFixed(true);
          else if(str == "false") SetFixed(false);
          break;
        }
        case(Hash::GenerateFNVHash("CompleteAccess")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetCompleteAcces(true);
          else if(str == "false") SetCompleteAcces(false);
          break;
        }
        default:
          std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
          // throw new std::invalid_argument("Unknown attribute in ENI file.");
          break;
      }
    }
  }

  void Mailbox::CoEType::InitCmdsType::InitCmdType::AttributesType::SetFixed(bool fixed) noexcept {
    m_hasFixed = true;
    m_Fixed = fixed;
  }

  std::optional<bool> Mailbox::CoEType::InitCmdsType::InitCmdType::AttributesType::GetFixed() noexcept {
    if(m_hasFixed) return m_Fixed;
    return std::nullopt;
  }

  void Mailbox::CoEType::InitCmdsType::InitCmdType::AttributesType::SetCompleteAcces(bool completeAcces) noexcept {
    m_hasCompleteAcces = true;
    m_CompleteAccess = completeAcces;
  }

  std::optional<bool> Mailbox::CoEType::InitCmdsType::InitCmdType::AttributesType::GetCompleteAcces() noexcept {
    if(m_hasCompleteAcces) return m_CompleteAccess;
    return std::nullopt;
  }

  auto Mailbox::CoEType::InitCmdsType::InitCmdType::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Transition")) : {
          auto str = node->value();
          switch (Hash::GenerateFNVHash(str)) {
            case Hash::GenerateFNVHash("II"):
              AddTransitionList(TransitionType::II);
              break;
            case Hash::GenerateFNVHash("IP"):
              AddTransitionList(TransitionType::IP);
              break;
            case Hash::GenerateFNVHash("PP"):
              AddTransitionList(TransitionType::PP);
              break;
            case Hash::GenerateFNVHash("PO"):
              AddTransitionList(TransitionType::PO);
              break;
            case Hash::GenerateFNVHash("PS"):
              AddTransitionList(TransitionType::PS);
              break;
            case Hash::GenerateFNVHash("PI"):
              AddTransitionList(TransitionType::PI);
              break;
            case Hash::GenerateFNVHash("SS"):
              AddTransitionList(TransitionType::SS);
              break;
            case Hash::GenerateFNVHash("SP"):
              AddTransitionList(TransitionType::SP);
              break;
            case Hash::GenerateFNVHash("SO"):
              AddTransitionList(TransitionType::SO);
              break;
            case Hash::GenerateFNVHash("SI"):
              AddTransitionList(TransitionType::SI);
              break;
            case Hash::GenerateFNVHash("OS"):
              AddTransitionList(TransitionType::OS);
              break;
            case Hash::GenerateFNVHash("OP"):
              AddTransitionList(TransitionType::OP);
              break;
            case Hash::GenerateFNVHash("OI"):
              AddTransitionList(TransitionType::OI);
              break;
            case Hash::GenerateFNVHash("IB"):
              AddTransitionList(TransitionType::IB);
              break;
            case Hash::GenerateFNVHash("BI"):
              AddTransitionList(TransitionType::BI);
              break;
            default:
              throw new std::invalid_argument("Invalid node name in ENI file");
              break;
          } // switch
          break;
        }
        case(Hash::GenerateFNVHash("Comment")) :
          SetComment(std::string(node->value()));
          break;
        case(Hash::GenerateFNVHash("Timeout")) :
          Timeout = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("Ccs")) :
          Ccs = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("Index")) :
          Index = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("SubIndex")) :
          Subindex = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("Data")) : {
          HexBinary data;
          data.set(node->value());
          SetData(data);
          break;
        }
        case(Hash::GenerateFNVHash("Disabled")) : {
          auto str = std::string(node->value());
          if(str == "true") SetDisabled(true);
          else if(str == "false") SetDisabled(false);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::CoEType::InitCmdsType::InitCmdType::AddTransitionList(const TransitionType& transition) noexcept {
    m_TransitionList.push_back(transition);
  }

  std::vector<TransitionType>& Mailbox::CoEType::InitCmdsType::InitCmdType::GetTransitionList() noexcept {
    return m_TransitionList;
  }

  void Mailbox::CoEType::InitCmdsType::InitCmdType::SetData(const HexBinary& data) noexcept {
    m_hasData = true;
    m_Data = data;
  }

  std::optional<HexBinary> Mailbox::CoEType::InitCmdsType::InitCmdType::GetData() noexcept {
    if(m_hasData) return m_Data;
    return std::nullopt;
  }

  void Mailbox::CoEType::InitCmdsType::InitCmdType::SetDisabled(const bool disabled) noexcept {
    m_hasDisabled = true;
    m_Disabled = disabled;
  }
  std::optional<bool> Mailbox::CoEType::InitCmdsType::InitCmdType::GetDisabled() noexcept {
    if(m_hasDisabled) return m_Disabled;
    return std::nullopt;
  }

  // will be called only at parse
  bool Mailbox::CoEType::InitCmdsType::InitCmdType::__IsValid() noexcept {
    return(m_TransitionList.size() > 0);
  }

  auto Mailbox::CoEType::InitCmdsType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmd")) : {
          InitCmdType initCmd;
          initCmd.Parse(node);
          AddInitCmd(initCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::CoEType::InitCmdsType::AddInitCmd(const InitCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<Mailbox::CoEType::InitCmdsType::InitCmdType>& Mailbox::CoEType::InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  void Mailbox::CoEType::ProfileType::ChannelInfoType::AttributeType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
        case(Hash::GenerateFNVHash("OverwrittenByModule")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetOverwrittenByModule(true);
          else if (str == "false") SetOverwrittenByModule(false);
          break;
        }
        default:
          std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
          throw new std::invalid_argument("Unknown attribute in ENI file.");
          break;
      }
    }
  }

  void Mailbox::CoEType::ProfileType::ChannelInfoType::AttributeType::SetOverwrittenByModule(const bool overwrittenByModule) noexcept {
    m_hasOverwrittenByModule = true;
    m_OverwrittenByModule = overwrittenByModule;
  }

  std::optional<bool> Mailbox::CoEType::ProfileType::ChannelInfoType::AttributeType::GetOverwrittenByModule() noexcept {
    if(m_hasOverwrittenByModule) return m_OverwrittenByModule;
    return std::nullopt;
  }

  auto Mailbox::CoEType::ProfileType::ChannelInfoType::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("ProfileNo")) :
          ProfileNo = static_cast<int32_t>(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("AddInfo")) :
          SetAddInfo(static_cast<int32_t>(std::stol(node->value())));
          break;
        case(Hash::GenerateFNVHash("DisplayName")) : {
          NameType displayName;
          displayName.Parse(node);
          AddDisplayName(displayName);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::CoEType::ProfileType::ChannelInfoType::SetAddInfo(const uint32_t addInfo) noexcept {
    m_hasAddInfo = true;
    m_AddInfo = addInfo;
  }

  std::optional<uint32_t> Mailbox::CoEType::ProfileType::ChannelInfoType::GetAddInfo() noexcept {
    if(m_hasAddInfo) return m_AddInfo;
    return std::nullopt;
  }

  void Mailbox::CoEType::ProfileType::ChannelInfoType::AddDisplayName(const NameType& name) noexcept {
    m_DisplayNameList.push_back(name);
  }

  std::vector<NameType>& Mailbox::CoEType::ProfileType::ChannelInfoType::GetDisplayNameList() noexcept {
    return m_DisplayNameList;
  }

  auto Mailbox::CoEType::ProfileType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("ChannelInfo")) : {  
          ChannelInfoType channelInfo;
          channelInfo.Parse(node);
          AddChannelInfo(channelInfo);
          break;
        }
        // ! TODO
        case(Hash::GenerateFNVHash("VendorSpecific")) :
          std::cout << "`Config::Slave::Mailbox::CoEType::ProfileType::VendorSpecificType` not supported node..." << std::endl;
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::CoEType::ProfileType::AddChannelInfo(const ChannelInfoType& channelInfo) noexcept {
    m_ChannelInfoList.push_back(channelInfo);
  }

  std::vector<Mailbox::CoEType::ProfileType::ChannelInfoType>& Mailbox::CoEType::ProfileType::GetChannelInfoList() noexcept {
    return m_ChannelInfoList;
  }

  void Mailbox::CoEType::ProfileType::SetVendorSpecific(const VendorSpecificType& vendorSpecific) noexcept {
    std::cout << "`Config::Slave::Mailbox::CoEType::ProfileType::VendorSpecificType` not supported node..." << std::endl;
    m_hasVendorSpecific = true;
    m_VendorSpecific = vendorSpecific;
  }

  std::optional<Mailbox::CoEType::ProfileType::VendorSpecificType> Mailbox::CoEType::ProfileType::GetVendorSpecific() noexcept {
    std::cout << "`Config::Slave::Mailbox::CoEType::ProfileType::VendorSpecificType` not supported node..." << std::endl;
    if(m_hasVendorSpecific) return m_VendorSpecific;
    return std::nullopt;
  }

  // will be called only at parse
  bool Mailbox::CoEType::ProfileType::__IsValid() noexcept {
    return(m_ChannelInfoList.size() > 0);
  }

  auto Mailbox::CoEType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmds")) : {
          InitCmdsType initCmds;
          initCmds.Parse(node);
          SetInitCmds(initCmds);
          break;
        }
        case(Hash::GenerateFNVHash("Profile")) : {
          ProfileType profile;
          profile.Parse(node);
          SetProfile(profile);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }      

  void Mailbox::CoEType::SetInitCmds(const InitCmdsType& initCmds) noexcept {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }

  std::optional<Mailbox::CoEType::InitCmdsType> Mailbox::CoEType::GetInitCmds() noexcept {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }

  void Mailbox::CoEType::SetProfile(const ProfileType& profile) noexcept {
    m_hasProfile = true;
    m_Profile = profile;
  }

  std::optional<Mailbox::CoEType::ProfileType> Mailbox::CoEType::GetProfile() noexcept {
    if(m_hasProfile) return m_Profile;
    return std::nullopt;
  }

  void Mailbox::SoEType::InitCmdsType::InitCmdType::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
        case(Hash::GenerateFNVHash("Fixed")) : {
          auto str = std::string(attr->value());
          if(str == "true") SetFixed(true);
          else if(str == "false") SetFixed(false);
          break;
        }
        default:
          std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
          throw new std::invalid_argument("Unknown attribute in ENI file.");
          break;
      }
    }
  }

  void Mailbox::SoEType::InitCmdsType::InitCmdType::AttributesType::SetFixed(bool fixed) noexcept {
    m_hasFixed = true;
    m_Fixed = fixed;
  }

  std::optional<bool> Mailbox::SoEType::InitCmdsType::InitCmdType::AttributesType::GetFixed() noexcept {
    if(m_hasFixed) return m_Fixed;
    return std::nullopt;
  }

  auto Mailbox::SoEType::InitCmdsType::InitCmdType::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Transition")) : {
          auto str = node->value();
          switch (Hash::GenerateFNVHash(str)) {
            case Hash::GenerateFNVHash("II"):
              AddTransitionList(TransitionType::II);
              break;
            case Hash::GenerateFNVHash("IP"):
              AddTransitionList(TransitionType::IP);
              break;
            case Hash::GenerateFNVHash("PP"):
              AddTransitionList(TransitionType::PP);
              break;
            case Hash::GenerateFNVHash("PO"):
              AddTransitionList(TransitionType::PO);
              break;
            case Hash::GenerateFNVHash("PS"):
              AddTransitionList(TransitionType::PS);
              break;
            case Hash::GenerateFNVHash("PI"):
              AddTransitionList(TransitionType::PI);
              break;
            case Hash::GenerateFNVHash("SS"):
              AddTransitionList(TransitionType::SS);
              break;
            case Hash::GenerateFNVHash("SP"):
              AddTransitionList(TransitionType::SP);
              break;
            case Hash::GenerateFNVHash("SO"):
              AddTransitionList(TransitionType::SO);
              break;
            case Hash::GenerateFNVHash("SI"):
              AddTransitionList(TransitionType::SI);
              break;
            case Hash::GenerateFNVHash("OS"):
              AddTransitionList(TransitionType::OS);
              break;
            case Hash::GenerateFNVHash("OP"):
              AddTransitionList(TransitionType::OP);
              break;
            case Hash::GenerateFNVHash("OI"):
              AddTransitionList(TransitionType::OI);
              break;
            case Hash::GenerateFNVHash("IB"):
              AddTransitionList(TransitionType::IB);
              break;
            case Hash::GenerateFNVHash("BI"):
              AddTransitionList(TransitionType::BI);
              break;
            default:
              throw new std::invalid_argument("Invalid node name in ENI file");
              break;
          } // switch
          break;
        }
        case(Hash::GenerateFNVHash("Comment")) :
          SetComment(std::string(node->value()));
          break;
        case(Hash::GenerateFNVHash("Timeout")) :
          Timeout = static_cast<uint16_t>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("OpCode")) :
          OpCode = static_cast<uint16_t>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("DriveNo")) :
          DriveNo = static_cast<uint16_t>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("IDN")) :
          IDN = static_cast<uint16_t>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Elements")) :
          Elements = static_cast<uint16_t>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Attribute")) :
          Attribute = static_cast<uint16_t>(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Data")) : {
          HexBinary data;
          data.set(node->value());
          SetData(data);
          break;
        }
        case(Hash::GenerateFNVHash("Disabled")) : {
          auto str = std::string(node->value());
          if(str == "true") SetDisabled(true);
          else if(str == "false") SetDisabled(false);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::SoEType::InitCmdsType::InitCmdType::AddTransitionList(const TransitionType& transition) noexcept {
    m_TransitionList.push_back(transition);
  }
  
  std::vector<TransitionType>& Mailbox::SoEType::InitCmdsType::InitCmdType::GetTransitionList() noexcept {
    return m_TransitionList;
  }

  void Mailbox::SoEType::InitCmdsType::InitCmdType::SetData(const HexBinary& data) noexcept {
    m_hasData = true;
    m_Data = data;
  }

  std::optional<HexBinary> Mailbox::SoEType::InitCmdsType::InitCmdType::GetData() noexcept {
    if(m_hasData) return m_Data;
    return std::nullopt;
  }

  void Mailbox::SoEType::InitCmdsType::InitCmdType::SetDisabled(const bool disabled) noexcept {
    m_hasDisabled = true;
    m_Disabled = disabled;
  }

  std::optional<bool> Mailbox::SoEType::InitCmdsType::InitCmdType::GetDisabled() noexcept {
    if(m_hasDisabled) return m_Disabled;
    return std::nullopt;
  }

  // will be called only at parse
  bool Mailbox::SoEType::InitCmdsType::InitCmdType::__IsValid() noexcept {
    return(m_TransitionList.size() > 0);
  }

  auto Mailbox::SoEType::InitCmdsType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmd")) : {
          InitCmdType initCmd;
          initCmd.Parse(node);
          AddInitCmd(initCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::SoEType::InitCmdsType::AddInitCmd(const InitCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<Mailbox::SoEType::InitCmdsType::InitCmdType>& Mailbox::SoEType::InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  auto Mailbox::SoEType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmds")) : {
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
  
  void Mailbox::SoEType::SetInitCmds(const InitCmdsType& initCmds) noexcept {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }

  std::optional<Mailbox::SoEType::InitCmdsType> Mailbox::SoEType::GetInitCmds() noexcept {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }

  auto Mailbox::AoEType::InitCmdsType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmd")) : {
          MailboxCmdType initCmd;
          initCmd.Parse(node);
          AddInitCmd(initCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::AoEType::InitCmdsType::AddInitCmd(const MailboxCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<Mailbox::MailboxCmdType>& Mailbox::AoEType::InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  auto Mailbox::AoEType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmds")) : {
          InitCmdsType initCmds;
          initCmds.Parse(node);
          SetInitCmds(initCmds);
          break;
        }
        case(Hash::GenerateFNVHash("NetID")) : {
          SetNetId(std::string(node->value()));
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }     

  void Mailbox::AoEType::SetInitCmds(const InitCmdsType& initCmds) noexcept {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }

  std::optional<Mailbox::AoEType::InitCmdsType> Mailbox::AoEType::GetInitCmds() noexcept {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }

  void Mailbox::AoEType::SetNetId(const std::string& netId) noexcept {
    m_hasNetId = true;
    m_NetId = netId;
  }

  std::optional<std::string> Mailbox::AoEType::GetNetId() noexcept {
    if(m_hasNetId) return m_NetId;
    return std::nullopt;
  }

  auto Mailbox::EoEType::InitCmdsType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmd")) : {
          MailboxCmdType initCmd;
          initCmd.Parse(node);
          AddInitCmd(initCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::EoEType::InitCmdsType::AddInitCmd(const MailboxCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<Mailbox::MailboxCmdType>& Mailbox::EoEType::InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  auto Mailbox::EoEType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmds")) : {
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

  void Mailbox::EoEType::SetInitCmds(const InitCmdsType& initCmds) noexcept {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }

  std::optional<Mailbox::EoEType::InitCmdsType> Mailbox::EoEType::GetInitCmds() noexcept {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }

  auto Mailbox::FoEType::InitCmdsType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmd")) : {
          MailboxCmdType initCmd;
          initCmd.Parse(node);
          AddInitCmd(initCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::FoEType::InitCmdsType::AddInitCmd(const MailboxCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<Mailbox::MailboxCmdType>& Mailbox::FoEType::InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  auto Mailbox::FoEType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmds")) : {
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

  void Mailbox::FoEType::SetInitCmds(const InitCmdsType& initCmds) noexcept {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }

  std::optional<Mailbox::FoEType::InitCmdsType> Mailbox::FoEType::GetInitCmds() noexcept {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }

  auto Mailbox::VoEType::InitCmdsType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmd")) : {
          MailboxCmdType initCmd;
          initCmd.Parse(node);
          AddInitCmd(initCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void Mailbox::VoEType::InitCmdsType::AddInitCmd(const MailboxCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<Mailbox::MailboxCmdType>& Mailbox::VoEType::InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  auto Mailbox::VoEType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmds")) : {
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

  void Mailbox::VoEType::SetInitCmds(const InitCmdsType& initCmds) noexcept {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }
  std::optional<Mailbox::VoEType::InitCmdsType> Mailbox::VoEType::GetInitCmds() noexcept {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }

  auto Mailbox::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);

    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Send")) :
          Send.Parse(node);
          break;
        case(Hash::GenerateFNVHash("Recv")) :
          Recv.Parse(node);
          break;
        case(Hash::GenerateFNVHash("Bootstrap")) : {
          BootstrapType bootstrap;
          bootstrap.Parse(node);
          SetBootstrap(bootstrap);
          break;
        }
        case(Hash::GenerateFNVHash("Protocol")) : {
          auto str = node->value();
          Protocol protocol;
          switch(Hash::GenerateFNVHash(str)) {
            case (Hash::GenerateFNVHash("CoE")):
              protocol = Protocol::CoE;
              break;
            case (Hash::GenerateFNVHash("SoE")):
              protocol = Protocol::SoE;
              break;
            case (Hash::GenerateFNVHash("AoE")):
              protocol = Protocol::AoE;
              break;
            case (Hash::GenerateFNVHash("EoE")):
              protocol = Protocol::EoE;
              break;
            case (Hash::GenerateFNVHash("FoE")):
              protocol = Protocol::FoE;
              break;
            case (Hash::GenerateFNVHash("VoE")):
              protocol = Protocol::VoE;
              break;
            default:
              //throw
              break;
          }
          AddProtocol(protocol);
          break;
        }
        case(Hash::GenerateFNVHash("CoE")) : {
          CoEType coe;
          coe.Parse(node);
          SetCoE(coe);
          break;
        }
        case(Hash::GenerateFNVHash("SoE")) : {
          SoEType soe;
          soe.Parse(node);
          SetSoE(soe);
          break;
        }
        case(Hash::GenerateFNVHash("AoE")) : {
          AoEType aoe;
          aoe.Parse(node);
          SetAoE(aoe);
          break;
        }
        case(Hash::GenerateFNVHash("EoE")) : {
          EoEType eoe;
          eoe.Parse(node);
          SetEoE(eoe);
          break;
        }
        case(Hash::GenerateFNVHash("FoE")) : {
          FoEType foe;
          foe.Parse(node);
          SetFoE(foe);
          break;
        }
        case(Hash::GenerateFNVHash("VoE")) : {
          VoEType voe;
          voe.Parse(node);
          SetVoE(voe);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto Mailbox::SetBootstrap(const BootstrapType& bootstrap) noexcept -> void {
    m_hasBootStrap = true;
    m_Bootstrap = bootstrap;
  }

  auto Mailbox::GetBootStrap() noexcept -> std::optional<BootstrapType> {
    if (m_hasBootStrap) return m_Bootstrap;
    return std::nullopt;
  }

  auto Mailbox::AddProtocol(const Protocol& protocol) noexcept -> void {
    m_ProtocolList.push_back(protocol);
  }

  auto Mailbox::GetProtocolList() noexcept -> std::vector<Protocol>& {
    return m_ProtocolList;
  }

  auto Mailbox::SetCoE(const CoEType& coe) noexcept -> void {
    m_hasCoE = true;
    m_CoE = coe;
  }

  auto Mailbox::GetCoE() noexcept -> const std::optional<CoEType> {
    if(m_hasCoE) return m_CoE;
    return std::nullopt;
  }

  auto Mailbox::SetSoE(const SoEType& soe) noexcept -> void {
    m_hasSoE = true;
    m_SoE = soe;
  }

  auto Mailbox::GetSoE() noexcept -> const std::optional<SoEType> {
    if(m_hasSoE) return m_SoE;
    return std::nullopt;
  }

  auto Mailbox::SetAoE(const AoEType& aoe) noexcept -> void {
    m_hasAoE = true;
    m_AoE = aoe;
  }

  auto Mailbox::GetAoE() noexcept -> const std::optional<AoEType> {
    if (m_hasAoE) return m_AoE;
    return std::nullopt;
  }

  auto Mailbox::SetEoE(const EoEType& eoe) noexcept -> void {
    m_hasEoE = true;
    m_EoE = eoe;
  }

  auto Mailbox::GetEoE() noexcept -> const std::optional<EoEType> {
    if(m_hasEoE) return m_EoE;
    return std::nullopt;
  }

  auto Mailbox::SetFoE(const FoEType& foe) noexcept -> void {
    m_hasFoE = true;
    m_FoE = foe;
  }

  auto Mailbox::GetFoE() noexcept -> const std::optional<FoEType> {
    if(m_hasFoE) return m_FoE;
    return std::nullopt;
  }

  auto Mailbox::SetVoE(const VoEType& voe) noexcept -> void {
    m_hasVoE = true;
    m_VoE = voe;
  }

  auto Mailbox::GetVoE() noexcept -> const std::optional<VoEType> {
    if(m_hasVoE) return m_VoE;
    return std::nullopt;
  }

  auto InitCmdsType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("InitCmd")) : {
          ECatCmdType initCmd;
          initCmd.Parse(node);
          AddInitCmd(initCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  void InitCmdsType::AddInitCmd(const ECatCmdType& initcmd) noexcept {
    m_InitCmdList.push_back(initcmd);
  }

  std::vector<ECatCmdType>& InitCmdsType::GetInitCmdList() noexcept {
    return m_InitCmdList;
  }

  void PreviousPortType::AttributesType::Parse(const rapidxml::xml_node<> *n) {
    for(rapidxml::xml_attribute<> *attr = n->first_attribute(); attr; attr = attr->next_attribute()) {
      auto attrName = std::string(attr->name());

      std::cout << "Attribute Name = " << attrName << std::endl;

      switch (Hash::GenerateFNVHash(attrName)) {
        case(Hash::GenerateFNVHash("Selected")) : {
            auto str = std::string(attr->value());
            if(str == "true") SetSelected(true);
            else if(str == "false") SetSelected(false);
            break;
          }
        default:
          std::cout << "Unknown attribute `" << attrName << "`" << std::endl;
          throw new std::invalid_argument("Unknown attribute in ENI file.");
          break;
      }
    }
  }

  void PreviousPortType::AttributesType::SetSelected(const bool selected) noexcept {
    m_hasSelected = true;
    m_Selected = selected;
  }

  std::optional<bool> PreviousPortType::AttributesType::GetSelected() noexcept {
    if(m_hasSelected) return m_Selected;
    return std::nullopt;
  }

  auto PreviousPortType::Parse(const rapidxml::xml_node<> *n) -> void {
    Attributes.Parse(n);
  
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("DeviceId")) :
          SetDeviceID(std::stoi(node->value()));
          break;
        case(Hash::GenerateFNVHash("Port")) :
          Port = std::string(node->value());
          break;
        case(Hash::GenerateFNVHash("PhysAddr")) :
          SetPhysAddr(std::stoi(node->value()));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  std::optional<uint16_t> PreviousPortType::GetDeviceID() noexcept {
    if(m_hasDeviceID) return m_DeviceID;
    return std::nullopt;
  }

  void PreviousPortType::SetDeviceID(const uint16_t deviceID) noexcept {
    m_hasDeviceID = true;
    m_DeviceID = deviceID;
  }

  std::optional<uint16_t> PreviousPortType::GetPhysAddr() noexcept {
    if(m_hasPhysAddr) return m_PhysAddr;
    return std::nullopt;
  }

  void PreviousPortType::SetPhysAddr(const uint16_t physAddr) noexcept {
    m_hasPhysAddr = true;
    m_PhysAddr = physAddr;
  }

  auto HotConnectType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("GroupName")) : {
          NameType groupName;
          groupName.Parse(node);
          SetGroupName(groupName);
          break;
        }
        case(Hash::GenerateFNVHash("GroupMemberCnt")) :
          GroupMemberCnt = std::stoi(node->value());
          break;
        case(Hash::GenerateFNVHash("IdentifyCmd")) : {
          ECatCmdType identifyCmd;
          identifyCmd.Parse(node);
          AddIdentifyCmdList(identifyCmd);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }     

  void HotConnectType::SetGroupName(const NameType& groupName) noexcept {
    m_hasGroupName = true;
    m_GroupName = groupName;
  }

  std::optional<NameType> HotConnectType::GetGroupName() noexcept {
    if(m_hasGroupName) return m_GroupName;
    return std::nullopt;
  }

  void HotConnectType::AddIdentifyCmdList(const ECatCmdType& identifyCmd) noexcept {
    m_IdentifyCmdList.push_back(identifyCmd);
  }

  std::vector<ECatCmdType>& HotConnectType::GetIdentifyCmdList() noexcept {
    return m_IdentifyCmdList;
  }

  // will be called only at parse
  bool HotConnectType::__IsValid() noexcept {
    return(m_IdentifyCmdList.size() > 0);
  }

  auto DCType::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("PotentialReferenceClock")) : {
          auto str = std::string(node->value());
          if(str == "true") SetPotentialReferenceClock(true);
          else if(str == "false") SetPotentialReferenceClock(false);
          break;
        }
        case(Hash::GenerateFNVHash("ReferenceClock")) : {
          auto str = std::string(node->value());
          if(str == "true") SetReferenceClock(true);
          else if(str == "false") SetReferenceClock(false);
          break;
        }
        case(Hash::GenerateFNVHash("CycleTime0")) :
          SetCycleTime0(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("CycleTime1")) :
          SetCycleTime1(std::stol(node->value()));
          break;
        case(Hash::GenerateFNVHash("ShiftTime")) :
          SetShiftTime(std::stol(node->value()));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  std::optional<bool> DCType::GetPotentialReferenceClock() noexcept {
    if(m_hasPotentialReferenceClock) return m_PotentialReferenceClock;
    return std::nullopt;
  }

  void DCType::SetPotentialReferenceClock(const bool potentialReferenceClock) noexcept {
    m_hasPotentialReferenceClock = true;
    m_PotentialReferenceClock = potentialReferenceClock;
  }

  std::optional<bool> DCType::GetReferenceClock() noexcept {
    if(m_hasReferenceClock) return m_ReferenceClock;
    return std::nullopt;
  }

  void DCType::SetReferenceClock(const bool referenceClock) noexcept {
    m_hasReferenceClock = true;
    m_ReferenceClock = referenceClock;
  }

  std::optional<int32_t> DCType::GetCycleTime0() noexcept {
    if(m_hasCycleTime0) return m_CycleTime0;
    return std::nullopt;
  }

  void DCType::SetCycleTime0(const int32_t cycleTime0) noexcept {
    m_hasCycleTime0 = true;
    m_CycleTime0 = cycleTime0;
  }

  std::optional<int32_t> DCType::GetCycleTime1() noexcept {
    if(m_hasCycleTime1) return m_CycleTime1;
    return std::nullopt;
  }

  void DCType::SetCycleTime1(const int32_t cycleTime1) noexcept {
    m_hasCycleTime1 = true;
    m_CycleTime1 = cycleTime1;
  }

  std::optional<int32_t> DCType::GetShiftTime() noexcept {
    if(m_hasShiftTime) return m_ShiftTime;
    return std::nullopt;
  }

  void DCType::SetShiftTime(const int32_t shiftTime) noexcept {
    m_hasShiftTime = true;
    m_ShiftTime = shiftTime;
  }

  auto Slave::Parse(const rapidxml::xml_node<> *n) -> void {
    for (rapidxml::xml_node<>* node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case(Hash::GenerateFNVHash("Info")) :{
          InfoType info;
          info.Parse(node);
          SetInfo(info);
          break;
        }
        case(Hash::GenerateFNVHash("ProcessData")) :{
          ProcessDataType processData;
          processData.Parse(node);
          SetProcessData(processData);
          break;
        }
        case(Hash::GenerateFNVHash("Mailbox")) :{
          Mailbox mailbox;
          mailbox.Parse(node);
          SetMailbox(mailbox);
          break;
        }
        case(Hash::GenerateFNVHash("InitCmds")) :{
          InitCmdsType initCmds;
          initCmds.Parse(node);
          SetInitCmds(initCmds);
          break;
        }
        case(Hash::GenerateFNVHash("PreviousPort")) :{
          PreviousPortType previousPort;
          previousPort.Parse(node);
          AddPreviousPort(previousPort);
          break;
        }
        case(Hash::GenerateFNVHash("HotConnect")) :{
          HotConnectType hotConnect;
          hotConnect.Parse(node);
          SetHotConnect(hotConnect);
          break;
        }
        case(Hash::GenerateFNVHash("DC")) :{
          DCType dcType;
          dcType.Parse(node);
          SetDC(dcType);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto Slave::SetInfo(const InfoType& info) noexcept -> void {
    m_Info = info;
  }

  auto Slave::GetInfo() noexcept -> InfoType& {
    return m_Info;
  }

  auto Slave::SetProcessData(const ProcessDataType& prData) noexcept -> void {
    m_hasProcessData = true;
    m_ProcessData = prData;
  }

  auto Slave::GetProcessData() noexcept -> std::optional<ProcessDataType> {
    if (m_hasProcessData) return m_ProcessData;
    return std::nullopt;
  }

  auto Slave::SetMailbox(const Mailbox& mailbox) noexcept -> void {
    m_hasMailbox = true;
    m_Mailbox = mailbox;
  }

  auto Slave::GetMailBox() noexcept -> std::optional<Mailbox> {
    if(m_hasMailbox) return m_Mailbox;
    return std::nullopt;
  }

  auto Slave::SetInitCmds(const InitCmdsType& initCmds) noexcept -> void {
    m_hasInitCmds = true;
    m_InitCmds = initCmds;
  }

  auto Slave::GetInitCmds() noexcept -> std::optional<InitCmdsType> {
    if(m_hasInitCmds) return m_InitCmds;
    return std::nullopt;
  }

  auto Slave::AddPreviousPort(const PreviousPortType& previousPort) noexcept -> void {
    m_PreviousPortList.push_back(previousPort);
  }

  auto Slave::GetPreviousPortList() noexcept -> std::vector<PreviousPortType>& {
    return m_PreviousPortList;
  }

  auto Slave::SetHotConnect(const HotConnectType& hotConnect) noexcept -> void {
    m_hasHotConnect = true;
    m_HotConnect = hotConnect;
  }

  auto Slave::GetHotConnect() noexcept -> std::optional<HotConnectType> {
    if(m_hasHotConnect) return m_HotConnect;
    return std::nullopt;
  }

  auto Slave::SetDC(const DCType& dc) noexcept -> void {
    m_hasDC = true;
    m_DC = dc;
  }

  auto Slave::GetDC() noexcept -> std::optional<DCType> {
    if(m_hasDC) return m_DC;
    return std::nullopt;
  }
} // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::Slave