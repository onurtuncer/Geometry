/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include "PDOType.h"

std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::TxPdoTypeEnum& txPdoTypeEnum) {

  switch (txPdoTypeEnum) {
    case Controller::Ethercat::DS402::TxPdoTypeEnum::NA:
      os << "NA";
      break;
    case Controller::Ethercat::DS402::TxPdoTypeEnum::TxPdoStandard :
      os << "TxPdoStandard";
      break;
    case Controller::Ethercat::DS402::TxPdoTypeEnum::TxPdoCSP :
      os << "TxPdoCSP";
      break;
    case Controller::Ethercat::DS402::TxPdoTypeEnum::TxPdoCSV :
      os << "TxPdoCSV";
      break;
    case Controller::Ethercat::DS402::TxPdoTypeEnum::TxPdoCSTCSPCSV :
      os << "TxPdoCSTCSPCSV";
      break;
    default:
      break;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::RxPdoTypeEnum& rxPdoTypeEnum) {

  switch (rxPdoTypeEnum) {
    case Controller::Ethercat::DS402::RxPdoTypeEnum::NA:
      os << "NA";
      break;
    case Controller::Ethercat::DS402::RxPdoTypeEnum::RxPdoStandard:
      os << "RxPdoStandard";
      break;
    case Controller::Ethercat::DS402::RxPdoTypeEnum::RxPdoCSP :
      os << "RxPdoCSP";
      break;
    case Controller::Ethercat::DS402::RxPdoTypeEnum::RxPdoCSV :
      os << "RxPdoCSV";
      break;
    case Controller::Ethercat::DS402::RxPdoTypeEnum::RxPdoCSTCSPCSV :
      os << "RxPdoCSTCSPCSV";
      break;
    default:
      break;
  }
  return os;
}
