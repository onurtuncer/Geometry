/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
-------------------------------------------------------------------------------*/

#ifndef __TYPE_UTILITY_H__
#define __TYPE_UTILITY_H__

// #include "BaseTypes.h"
// #include "SlaveTypes.h"
// #include "CyclicTypes.h"
// #include "ProcessImageTypes.h"

namespace Controller::Ethercat::EniParser {



  // Controller::Ethercat::EniParser::State String2State(const char* stateString)
  // {
  //   switch (Hash::GenerateFNVHash(stateString)) 
  //   {
  //     case Hash::GenerateFNVHash("INIT"):
  //       return State::INIT;
  //     case Hash::GenerateFNVHash("PREOP"):
  //       return State::PREOP;
  //     case Hash::GenerateFNVHash("SAFEOP"):
  //       return State::SAFEOP;
  //     case Hash::GenerateFNVHash("OP"):
  //       return State::OP;    
  //     default:
  //       break;
  //     }
  // }

/*   auto HexToBytes(const std::string& hex) noexcept -> std::vector<std::byte> {
  std::vector<std::byte> bytes;
  for (unsigned int i = 0; i < hex.length(); i += 2) {
    std::string byteString = hex.substr(i, 2);
    auto byte = (std::byte) std::strtol(byteString.c_str(), NULL, 16);
    bytes.push_back(byte);
  }
  return bytes;
} */

//   enum class Require;
//   auto String2Require(const std::string& hexString) noexcept -> Require {

//     switch (Hash::GenerateFNVHash(hexString)) {
//       case Hash::GenerateFNVHash("frame") :
//         return EcRequire::frame;
//         break;
//       case Hash::GenerateFNVHash("cycle") :
//         return EcRequire::cycle;
//         break;
//       default:
//         break;
//     } // switch
//  }

// auto String2DataType(const std::string& type) -> DataType {
//    switch (Hash::GenerateFNVHash(type)) {
//      case Hash::GenerateFNVHash("UINT8") :
//        return DataType::UINT8;
//        break;
//       case Hash::GenerateFNVHash("UINT16") :
//         return DataType::UINT16;
//         break;
//       case Hash::GenerateFNVHash("UINT32") :
//         return DataType::UINT32;
//         break;
//       case Hash::GenerateFNVHash("INT8") :
//         return DataType::INT8;
//         break;
//       case Hash::GenerateFNVHash("INT16") :
//         return DataType::INT16;
//         break;
//       case Hash::GenerateFNVHash("INT32") :
//         return DataType::INT32;
//         break;
//       case Hash::GenerateFNVHash("SINT") : 
//         return DataType::SINT;
//         break;
//       case Hash::GenerateFNVHash("DINT") : 
//         return DataType::DINT;
//         break;
//       case Hash::GenerateFNVHash("UINT") : 
//         return DataType::UINT;
//         break;
//        case Hash::GenerateFNVHash("INT") : 
//         return DataType::INT;
//         break;
//       default:
//         throw new std::invalid_argument("Unknown data type");
//    } // switch
// }

//  auto String2BaseDataType(const std::string& type) -> BaseDataType {

//    switch (Hash::GenerateFNVHash(type)) {
//      case Hash::GenerateFNVHash("BOOLEAN") :
//        return BaseDataType::BOOLEAN;
//        break;
//      case Hash::GenerateFNVHash("INTEGER8") :
//        return BaseDataType::INTEGER8;
//        break;
//     case Hash::GenerateFNVHash("INTEGER16") :
//       return BaseDataType::INTEGER16;
//       break;
//     case Hash::GenerateFNVHash("INTEGEfloat") :
//       return BaseDataType::INTEGEfloat;
//       break;
//     case Hash::GenerateFNVHash("UNSIGNED8") :
//       return BaseDataType::UNSIGNED8;
//       break;
//     case Hash::GenerateFNVHash("UNSIGNED32") :
//       return BaseDataType::UNSIGNED32;
//       break;
//     case Hash::GenerateFNVHash("REAL32") :
//       return BaseDataType::REAL32;
//       break;
//     case Hash::GenerateFNVHash("VISIBLE_STRING") :
//       return BaseDataType::VISIBLE_STRING;
//       break;
//     case Hash::GenerateFNVHash("OCTET_STRING") :
//       return BaseDataType::OCTET_STRING;
//       break;
//     case Hash::GenerateFNVHash("UNICODE_STRING") :
//       return BaseDataType::UNICODE_STRING;
//       break;
//     case Hash::GenerateFNVHash("TIME_OF_DAY") :
//       return BaseDataType::TIME_OF_DAY;
//       break;
//     case Hash::GenerateFNVHash("TIME_DIFFERENCE") :
//       return BaseDataType::TIME_DIFFERENCE;
//       break;
//     case Hash::GenerateFNVHash("DOMAIN") :
//       return BaseDataType::DOMAIN;
//       break;
//     case Hash::GenerateFNVHash("INTEGER24") :
//       return BaseDataType::INTEGER24;
//       break;
//     case Hash::GenerateFNVHash("REAL64") :
//       return BaseDataType::REAL64;
//       break;
//     case Hash::GenerateFNVHash("INTEGEdouble") :
//       return BaseDataType::INTEGEdouble;
//       break;
//     case Hash::GenerateFNVHash("UNSIGNED24") :
//       return BaseDataType::UNSIGNED24;
//       break;
//     case Hash::GenerateFNVHash("UNSIGNED64") :
//       return BaseDataType::UNSIGNED64;
//       break;
//     case "BIT1"_ :
//       return BaseDataType::BIT1;
//       break;
//      case "BIT2"_ :
//       return BaseDataType::BIT2;
//       break;
//      case "BIT3"_ :
//       return BaseDataType::BIT3;
//       break;
//      case "BIT4"_ :
//       return BaseDataType::BIT4;
//       break;
//      case "BIT5"_ :
//       return BaseDataType::BIT5;
//       break;
//      case "BIT6"_ :
//       return BaseDataType::BIT6;
//       break;
//      case "BIT7"_ :
//       return BaseDataType::BIT7;
//       break;
//      case "BIT8"_ :
//       return BaseDataType::BIT8;
//       break;
//      default:
//       throw new std::invalid_argument("Unknown data type");
//    } // switch
// }

// auto String2Cmd(const std::string& cmdString) -> Cmd {

//   switch (Hash::GenerateFNVHash(cmdString)) {
//     case "NOP"_ :
//       return EcCmd::NOP;
//       break;
//     case "APRD"_ :
//       return EcCmd::APRD;
//       break;
//     case "APWR"_ :
//       return EcCmd::APWR;
//       break;
//     case "APRW"_ :
//       return EcCmd::APRW;
//       break;
//     case "FPRD"_ :
//       return EcCmd::FPRD;
//       break;
//     case "FPWR"_ :
//       return EcCmd::FPWR;
//       break;
//     case "FPRW"_ :
//       return EcCmd::FPRW;
//       break;
//     case "BRD"_ :
//       return EcCmd::BRD;
//       break;
//     case "BWR"_ :
//       return EcCmd::BWR;
//       break;
//     case "BRW"_ :
//       return EcCmd::BRW;
//       break;
//     case "LRD"_ :
//       return EcCmd::LRD;
//       break;
//     case "LWR"_ :
//       return EcCmd::LWR;
//       break;
//     case "LRW"_ :
//       return EcCmd::LRW;
//       break;
//     case "ARMW"_ :
//       return EcCmd::ARMW;
//       break;
//     case "FRMW"_ :
//       return EcCmd::FRMW;
//       break;
//     // default:
//     // //  throw new("Unrecognized string");
//     //   break;
//   } // switch
// }

// auto String2Transition(const std::string& transitionString) noexcept -> Transition {

//   switch (Hash::GenerateFNVHash(transitionString)) {
//     case "II"_ :
//       return EcTransition::II;
//       break;
//     case "IP"_ :
//       return EcTransition::IP;
//       break;
//     case "PP"_ :
//       return EcTransition::PP;
//       break;
//     case "PO"_ :
//       return EcTransition::PO;
//       break;
//     case "PS"_ :
//       return EcTransition::PS;
//       break;
//     case "PI"_ :
//       return EcTransition::PI;
//       break;
//     case "SS"_ :
//       return EcTransition::SS;
//       break;
//     case "SP"_ :
//       return EcTransition::SP;
//       break;
//     case "SO"_ :
//       return EcTransition::SO;
//       break;
//     case "SI"_ :
//       return EcTransition::SI;
//       break;
//     case "OS"_ :
//       return EcTransition::OS;
//       break;
//     case "OP"_ :
//       return EcTransition::OP;
//       break;
//     case "OI"_:
//       return EcTransition::OI;
//       break;
//     case "IB"_ :
//       return EcTransition::IB;
//       break;
//     case "BI"_ :
//       return EcTransition::BI;
//       break;
//     // default:
//     //   std::unreachable();
//   } // switch
// }

// auto String2Boolean(const std::string& boolString) noexcept -> bool {

//   switch (Hash::GenerateFNVHash(boolString)) {
//     case "True"_ :
//       return true;
//       break;
//     case "False"_ :
//       return false;
//       break;
//     // default:
//     //   std::unreachable();
//   } // switch
// }

// auto EtherType2String(const EtherType_t et) noexcept -> std::string {
//
//    switch (et) {
//     case EtherType_t::ethercat :
//       return "Ethercat";
//       break;
//     case EtherType_t::udp :
//       return "UDP";
//       break;
//      default :
//       return "Unknown ethertype";
//   } // switch
// }

} // namespace Controller::Ethercat

#endif // __TYPE_UTILITY_H__