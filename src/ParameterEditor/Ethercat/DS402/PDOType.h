/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#ifndef PDO_TYPE_H_
#define PDO_TYPE_H_

#include <cstdint>
#include <ostream>

namespace Controller::Ethercat::DS402 {

  enum class RxPdoTypeEnum : int8_t { NA = 0,
                                      RxPdoStandard,
                                      RxPdoCSP,
                                      RxPdoCSV,
                                      RxPdoCSTCSPCSV};

  enum class TxPdoTypeEnum : int8_t { NA = -128,
                                      TxPdoStandard,
                                      TxPdoCSP,
                                      TxPdoCSV,
                                      TxPdoCSTCSPCSV};

} // namespace Controller::Ethercat::DS402

std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::TxPdoTypeEnum& txPdoTypeEnum);
std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::RxPdoTypeEnum& rxPdoTypeEnum);

#endif // PDO_TYPE_H_
