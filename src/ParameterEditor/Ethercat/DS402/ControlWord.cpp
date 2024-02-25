/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN
  Provides context to visitor pattern implementation such that variable/function
  names and values can be passed alongside within the correct scope

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Written by Bites, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#include <iomanip>
#include "ControlWord.h"

namespace Controller::Ethercat::DS402 {

  std::ostream& operator<<(std::ostream& os, const Controlword& controlword) {

  using std::setfill;
  using std::setw;

  os << std::left << std::boolalpha << setw(40) << setfill('-') << "|"
     << "|\n"
     << setw(40) << setfill(' ') << "| Controlword"
     << "|\n"
     << setw(25) << setfill('-') << "|" << setw(8) << "+" << setw(7) << "+"
     << "|"
     << "\n"
     << setw(25) << setfill(' ') << "| Name"
     << "| Value | Mode |"
     << "\n"
     << setw(25) << setfill('-') << "|" << setw(8) << "+" << setw(7) << "+"
     << "|"
     << "\n"
     << setw(25) << setfill(' ') << "| switch on:"
     << "| " << setw(6) << controlword.SwitchOn << "|" << setw(6) << " all"
     << "|\n"
     << setw(25) << setfill(' ') << "| enable voltage:"
     << "| " << setw(6) << controlword.EnableVoltage << "|" << setw(6) << " all"
     << "|\n"
     << setw(25) << setfill(' ') << "| quick stop:"
     << "| " << setw(6) << controlword.QuickStop << "|" << setw(6) << " all"
     << "|\n"
     << setw(25) << setfill(' ') << "| enable operation:"
     << "| " << setw(6) << controlword.EnableOperation << "|" << setw(6) << " all"
     << "|\n"
     << setw(25) << setfill(' ') << "| new Set point:"
     << "| " << setw(6) << controlword.NewSetPoint << "|" << setw(6) << " pp"
     << "|\n"
     << setw(25) << setfill(' ') << "| start homing:"
     << "| " << setw(6) << controlword.HomingOperationStart << "|" << setw(6) << " hm"
     << "|\n"
     << setw(25) << setfill(' ') << "| change Set:"
     << "| " << setw(6) << controlword.ChangeSetImmediately << "|" << setw(6) << " pp"
     << "|\n"
     << setw(25) << setfill(' ') << "| relative_:"
     << "| " << setw(6) << controlword.Relative << "|" << setw(6) << " pp "
     << "|\n"
     << setw(25) << setfill(' ') << "| fault_ reset:"
     << "| " << setw(6) << controlword.FaultReset << "|" << setw(6) << " all"
     << "|\n"
     << setw(25) << setfill(' ') << "| halt_:"
     << "| " << setw(6) << controlword.Halt << "|" << setw(6) << " all"
     << "|\n"
     <<

      setw(25) << setfill('-') << "|" << setw(8) << "+" << setw(7) << "+"
     << "|" << std::right << std::noboolalpha;

     return os;
  }


  uint16_t Controlword::GetRawControlword() {

    uint16_t rawControlword = 0;

    if (SwitchOn) {
      rawControlword |= (1 << 0);
    }
    if (EnableVoltage) {
      rawControlword |= (1 << 1);
    }
    if (QuickStop) {
      rawControlword |= (1 << 2);
    }
    if (EnableOperation) {
      rawControlword |= (1 << 3);
    }
    if (FaultReset) {
      rawControlword |= (1 << 7);
    }
    if (Halt) {
      rawControlword |= (1 << 8);
    }

    return rawControlword;
  }

  void Controlword::SetStateTransition2() {

    SetAllFalse();
    EnableVoltage = true;
    QuickStop = true;
  }

  void Controlword::SetStateTransition3() {
    SetAllFalse();
    SwitchOn = true;
    EnableVoltage = true;
    QuickStop = true;
  }

  void Controlword::SetStateTransition4() {
    SetAllFalse();
    SwitchOn = true;
    EnableVoltage = true;
    QuickStop = true;
    EnableOperation = true;
  }

  void Controlword::SetStateTransition5() {
    SetAllFalse();
    SwitchOn = true;
    EnableVoltage = true;
    QuickStop = true;
  }

  void Controlword::SetStateTransition6() {
    SetAllFalse();
    EnableVoltage = true;
    QuickStop = true;
  }

  void Controlword::SetStateTransition7() {
    SetAllFalse();
  }

  void Controlword::SetStateTransition8() {
    SetAllFalse();
    EnableVoltage = true;
    QuickStop = true;
  }

  void Controlword::SetStateTransition9() {
    SetAllFalse();
  }

  void Controlword::SetStateTransition10() {
    SetAllFalse();
  }

  void Controlword::SetStateTransition11() {
    SetAllFalse();
    EnableVoltage = true;
  }
  void Controlword::SetStateTransition12() {
    SetAllFalse();
  }

  void Controlword::SetStateTransition15() {
    SetAllFalse();
    FaultReset = true;
  }

  void Controlword::SetAllFalse() {

    SwitchOn = false;
    EnableVoltage = false;
    QuickStop = false;
    EnableOperation = false;
    NewSetPoint = false;
    HomingOperationStart = false;
    ChangeSetImmediately = false;
    Relative = false;
    FaultReset = false;
    Halt = false;
  }

  void Controlword::SetInit() {
    SetStateTransition2();
  }


} // namespace Controller::Ethercat::DS402
