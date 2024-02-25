/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <iomanip>
#include "StatusWord.h"

namespace Controller::Ethercat::DS402 {

  std::ostream& operator<<(std::ostream& os, const Statusword& statusword) {

    using std::setfill;
    using std::setw;

    std::string driveStateString = statusword.GetDriveStateString();
    int gapSize2 = driveStateString.size() + 1;
    if (gapSize2 < 6) {
      gapSize2 = 6;
    }
    os << std::left << std::boolalpha << setw(gapSize2 + 27) << setfill('-') << "|"
       << "|\n"
       << setw(gapSize2 + 27) << setfill(' ') << "| Statusword"
       << "|\n"
       << setw(gapSize2 + 27) << setfill('-') << "|"
       << "|\n"
       << setw(25) << setfill(' ') << "| Name of Bit" << setw(gapSize2 + 2) << "| Value"
       << "|\n"
       << setw(25) << setfill('-') << "|" << setw(gapSize2 + 2) << "+"
       << "|\n"
       << setfill(' ') <<

        setw(25) << "| Ready to switch on:"
       << "| " << setw(gapSize2) << statusword.m_ReadyToSwitchOn << "|\n"
       << setw(25) << "| Switched on:"
       << "| " << setw(gapSize2) << statusword.m_SwitchedOn << "|\n"
       << setw(25) << "| Operation enabled:"
       << "| " << setw(gapSize2) << statusword.m_OperationEnabled << "|\n"
       << setw(25) << "| Fault:"
       << "| " << setw(gapSize2) << statusword.m_Fault << "|\n"
       << setw(25) << "| Voltage enabled:"
       << "| " << setw(gapSize2) << statusword.m_VoltageEnabled << "|\n"
       << setw(25) << "| Quick stop:"
       << "| " << setw(gapSize2) << statusword.m_QuickStop << "|\n"
       << setw(25) << "| Switch on disabled:"
       << "| " << setw(gapSize2) << statusword.m_SwitchOnDisabled << "|\n"
       << setw(25) << "| Warning:"
       << "| " << setw(gapSize2) << statusword.m_Warning << "|\n"
       << setw(25) << "| Target reached:"
       << "| " << setw(gapSize2) << statusword.m_TargetReached << "|\n"
       << setw(25) << "| Internal limit active:"
       << "| " << setw(gapSize2) << statusword.m_InternalLimitActive << "|\n"
       <<
        // setw(25)<<"| Following error:"<<"|
        // "<<setw(gapSize2)<<statusword.followingError_<<"| \n"<< // mode of
        // operation specific
        setw(25) << setfill('-') << "|" << setw(gapSize2 + 2) << "+"
       << "|\n"
       << setfill(' ') << setw(25) << "| Resulting Drive State:"
       << "| " << setw(gapSize2) << driveStateString << "|\n"
       << setw(25) << setfill('-') << "|" << setw(gapSize2 + 2) << "+"
       << "|" <<

        std::noboolalpha << std::right << setfill(' ');

    return os;
  }

  void Statusword::SetFromRawStatusword(uint16_t status) {

    m_ReadyToSwitchOn = static_cast<bool>(status & 1 << (0));
    m_SwitchedOn = static_cast<bool>(status & 1 << (1));
    m_OperationEnabled = static_cast<bool>(status & 1 << (2));
    m_Fault = static_cast<bool>(status & 1 << (3));
    m_VoltageEnabled = static_cast<bool>(status & 1 << (4));
    m_QuickStop = static_cast<bool>(status & 1 << (5));
    m_SwitchOnDisabled = static_cast<bool>(status & 1 << (6));
    m_Warning = static_cast<bool>(status & 1 << (7));
    m_TargetReached = static_cast<bool>(status & 1 << (10));
    m_InternalLimitActive = static_cast<bool>(status & 1 << (11));
    m_FollowingError = static_cast<bool>(status & 1 << (13));

    m_RawStatusword = status;
  }

  DriveState Statusword::GetDriveState() const {

    DriveState driveState = DriveState::NA;

    if ((m_RawStatusword & 0b0000000001001111) == 0b0000000000000000) {
      driveState = DriveState::NotReadyToSwitchOn;
    } else if ((m_RawStatusword & 0b0000000001001111) == 0b0000000001000000) {
      driveState = DriveState::SwitchOnDisabled;
    } else if ((m_RawStatusword & 0b0000000001101111) == 0b0000000000100001) {
      driveState = DriveState::ReadyToSwitchOn;
    } else if ((m_RawStatusword & 0b0000000001101111) == 0b0000000000100011) {
      driveState = DriveState::SwitchedOn;
    } else if ((m_RawStatusword & 0b0000000001101111) == 0b0000000000100111) {
      driveState = DriveState::OperationEnabled;
    } else if ((m_RawStatusword & 0b0000000001101111) == 0b0000000000000111) {
      driveState = DriveState::QuickStopActive;
    } else if ((m_RawStatusword & 0b0000000001001111) == 0b0000000000001111) {
      driveState = DriveState::FaultReactionActive;
    } else if ((m_RawStatusword & 0b0000000001001111) == 0b0000000000001000) {
      driveState = DriveState::Fault;
    }

    return driveState;
  }

  std::string Statusword::GetDriveStateString() const {

    DriveState driveState = GetDriveState();

    switch (driveState) {
      case DriveState::SwitchOnDisabled:
        return "switch on disabled";
        break;
      case DriveState::ReadyToSwitchOn:
        return "ready to switch on";
        break;
      case DriveState::SwitchedOn:
        return "switched on";
        break;
      case DriveState::OperationEnabled:
        return "operation enabled";
        break;
      case DriveState::QuickStopActive:
        return "quick stop active";
        break;
      case DriveState::Fault:
        return "fault";
        break;
      case DriveState::FaultReactionActive:
        return "fault reaction active";
      case DriveState::NotReadyToSwitchOn:
        return "not ready to switch on";
      default:
        return "N/A";
    }
  }

} // namespace Controller::Ethercat::DS402
