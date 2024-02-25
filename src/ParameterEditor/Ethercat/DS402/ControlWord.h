/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN
  Use of this software is restricted to MILTEKSAN
  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Written by Bites, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#ifndef CONTROLWORD_H
#define CONTROLWORD_H

#include <cstdint>
#include <ostream>

namespace Controller::Ethercat::DS402 {

  struct Controlword {

    bool SwitchOn{false};              // bit 0
    bool EnableVoltage{false};         // bit 1
    bool QuickStop{false};             // bit 2
    bool EnableOperation{false};       // bit 3
    bool NewSetPoint{false};           // bit 4 profiled position mode
    bool HomingOperationStart{false};  // bit 4 homing mode
    bool ChangeSetImmediately{false};  // bit 5 profiled position mode
    bool Relative{false};              // bit 6 profiled position mode
    bool FaultReset{false};            // bit 7
    bool Halt{false};                  // bit 8

    uint16_t GetRawControlword();

    void SetStateTransition2();  /* SWITCH ON DISABLED -> READY TO SWITCH ON */
    void SetStateTransition3(); /* READY TO SWITCH ON -> SWITCHED ON */
    void SetStateTransition4(); /* SWITCHED ON -> ENABLE OPERATION */
    void SetStateTransition5(); /* OPERATION ENABLED -> SWITCHED ON */
    void SetStateTransition6(); /* SWITCHED ON -> READY TO SWITCH ON */
    void SetStateTransition7(); /* READY TO SWITCH ON -> SWITCH ON DISABLED */
    void SetStateTransition8(); /* OPERATION ENABLED -> READY TO SWITCH ON */
    void SetStateTransition9(); /*  OPERATION ENABLED -> SWITCH ON DISABLED */
    void SetStateTransition10(); /* SWITCHED ON -> SWITCH ON DISABLED */
    void SetStateTransition11(); /* OPERATION ENABLED -> QUICK STOP ACTIVE */
    void SetStateTransition12(); /* QUICK STOP ACTIVE -> SWITCH ON DISABLED */
    void SetStateTransition15(); /* FAULT -> SWITCH ON DISABLED */
    void SetAllFalse();         /* Sets all bools of this struct to false */
    void SetInit();             /* Alias for state transition 2 */

    friend std::ostream& operator<<(std::ostream& os, const Controlword& controlword);
  };

} // namespace Controller::Ethercat::DS402

#endif // CONTROLWORD_H
