/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN
  Provides context to visitor pattern implementation such that variable/function
  names and values can be passed alongside within the correct scope

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
-------------------------------------------------------------------------------*/

#ifndef DRIVE_STATE_H__
#define DRIVE_STATE_H__

#include <ostream>

namespace Controller::Ethercat::DS402 {

  enum class DriveState : uint8_t {
    NotReadyToSwitchOn = 0,
    SwitchOnDisabled,
    ReadyToSwitchOn,
    SwitchedOn,
    OperationEnabled,
    QuickStopActive,
    FaultReactionActive,
    Fault,
    NA
  };


  enum class StateTransition : uint8_t {
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _10,
    _11,
    _12,
    _15 };

} // namespace Controller::Ethercat::DS402

std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::DriveState& driveState);

#endif // DRIVE_STATE_H__
