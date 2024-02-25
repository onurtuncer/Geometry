/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN
  Provides context to visitor pattern implementation such that variable/function
  names and values can be passed alongside within the correct scope

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <iostream>

#include "ISlave.h"

namespace Controller::Ethercat {

ISlave::ISlave(BusBase* bus, const uint32_t address) : m_Bus(bus), m_Address(address) {}
ISlave::ISlave() : m_Bus(nullptr), m_Address(0) {}

auto ISlave::SendSdoReadGeneric(const std::string& indexString, const std::string& subindexString,
                                           const std::string& valueTypeString, std::string& valueString) -> bool {
  PrintWarnNotImplemented();
  return false;
}

auto ISlave::SendSdoWriteGeneric(const std::string& indexString, const std::string& subindexString,
                                const std::string& valueTypeString, const std::string& valueString) -> bool {
  PrintWarnNotImplemented();
  return false;
}

auto ISlave::SendSdoReadVisibleString(const uint16_t index, const uint8_t subindex, std::string& value) -> bool {
  std::lock_guard<std::recursive_mutex> lock(m_Mutex);
  return m_Bus->SendSdoReadVisibleString(m_Address, index, subindex, value);
}

void ISlave::reloadODList()
{

  m_Bus->reloadODList(m_Address, m_ODlist, m_OElist);
}

}  // namespace Controller::Ethercat
