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

#include "DriveState.h"

std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::DriveState& driveState) {
  switch (driveState) {
    case Controller::Ethercat::DS402::DriveState::NotReadyToSwitchOn:
      os << "NotReadyToSwitchOn";
      break;
      case Controller::Ethercat::DS402::DriveState::SwitchOnDisabled:
      os << "SwitchOnDisabled";
      break;
      case Controller::Ethercat::DS402::DriveState::ReadyToSwitchOn:
      os << "ReadyToSwitchOn";
      break;
      case Controller::Ethercat::DS402::DriveState::SwitchedOn:
      os << "SwitchedOn";
      break;
      case Controller::Ethercat::DS402::DriveState::OperationEnabled:
      os << "OperationEnabled";
      break;
      case Controller::Ethercat::DS402::DriveState::QuickStopActive:
      os << "QuickStopActive";
      break;
      case Controller::Ethercat::DS402::DriveState::FaultReactionActive:
      os << "FaultReactionActive";
      break;
      case Controller::Ethercat::DS402::DriveState::Fault:
      os << "Fault";
      break;
      case Controller::Ethercat::DS402::DriveState::NA:
      os << "N/A";
      break;
  } // switch
  return os;
}
