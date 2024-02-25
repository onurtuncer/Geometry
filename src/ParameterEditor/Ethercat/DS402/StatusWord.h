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

#ifndef STATUSWORD_H
#define STATUSWORD_H

#include "DriveState.h"

namespace Controller::Ethercat::DS402 {

  class Statusword {

    private:
      bool m_ReadyToSwitchOn{false};      // bit 0
      bool m_SwitchedOn{false};           // bit 1
      bool m_OperationEnabled{false};     // bit 2
      bool m_Fault{false};                // bit 3
      bool m_VoltageEnabled{false};       // bit 4
      bool m_QuickStop{false};            // bit 5
      bool m_SwitchOnDisabled{false};     // bit 6
      bool m_Warning{false};              // bit 7
      bool m_TargetReached{false};        // bit 10
      bool m_InternalLimitActive{false};  // bit 11
      bool m_FollowingError{false};       // bit 13, CSV mode

      // the raw statusword
      uint16_t m_RawStatusword{0};

    public:
      friend std::ostream& operator<<(std::ostream& os, const Statusword& statusword);
      void SetFromRawStatusword(uint16_t status);
      DriveState GetDriveState() const;
      std::string GetDriveStateString() const;
  };

} // namespace Controller::Ethercat::DS402

#endif // STATUSWORD_H
