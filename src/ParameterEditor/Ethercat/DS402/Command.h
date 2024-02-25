/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Writtten by Bites, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#ifndef COMMAND_H__
#define COMMAND_H__

#include <cstdint>
#include <iostream>
#include <mutex>
#include <string>

#include "ModeOfOperation.h"

namespace Controller::Ethercat::DS402 {

  class Command {
    public:
      Command() = default;
      Command(const Command& other);
      virtual ~Command() = default;

      Command& operator=(const Command& other);

      /*!
       * Set raw commands
       * This requires the "SET_USE_RAW_COMMANDS" variable of the config file to be
       * set to "true"
       */
      void SetControlWordRaw(uint16_t controlWord);
      void SetTargetPositionRaw(int32_t targetPosition);
      void SetTargetVelocityRaw(int32_t targetVelocity);
      void SetTargetCurrentRaw(int16_t targetCurrent);
      void SetPositionOffsetRaw(int32_t positionOffset);
      void SetVelocityOffsetRaw(int32_t velocityOffset);
      void SetTorqueOffsetRaw(int16_t torqueOffset);


      /// set factors
      void SetPositionFactorMmToInteger(double factor);
      void SetPositionFactorRadToInteger(double factor);
      void SetVelocityFactorRadPerSecToIntegerPerSec(double factor);
      void SetTorqueFactorNmToInteger(double factor);
      void SetCurrentFactorAToInteger(double factor);

      /// set user units
      void SetControlWord(uint16_t controlWord);
      void SetTargetPosition(double targetPosition);
      void SetTargetVelocity(double targetVelocity);
      void SetTargetTorque(double targetTorque);
      void SetTargetCurrent(double targetCurrent);
      void SetPositionOffset(double positionOffset);
      void SetVelocityOffset(double velocityOffset);
      void SetTorqueOffset(double torqueOffset);

      /// other
      void SetUseRawCommands(bool useRawCommands);
      void SetModeOfOperation(ModeOfOperation modeOfOperation);
      void SetModeOfOperationRaw(uint8_t modeOfOperation);

      /// get (raw)
      uint16_t GetControlWordRaw() const;
      int32_t GetTargetPositionRaw() const;
      int32_t GetTargetVelocityRaw() const;
      int16_t GetTargetTorqueRaw() const;
      int16_t GetTargetCurrentRaw() const;
      uint16_t GetMaxTorqueRaw() const;
      uint16_t GetMaxCurrentRaw() const;
      int16_t GetTorqueOffsetRaw() const;
      int32_t GetPositionOffsetRaw() const;
      int32_t GetVelocityOffsetRaw() const;
      uint8_t GetModeOfOperationRaw() const;


      /// get (user units)
      uint16_t GetControlWord() const;
      double GetTargetPosition() const;
            double GetTargetVelocity() const;
      double GetTargetTorque() const;
      double GetTargetCurrent() const;
      double GetMaxTorque() const;
      double GetMaxCurrent() const;
      double GetTorqueOffset() const;
      double GetPositionOffset() const;
      double GetVelocityOffset() const;

      ModeOfOperation GetModeOfOperation() const;

      /// Convert the units
      void DoUnitConversion();

      /// only works if commands in user units (A, Nm, rad/s,..) are used
      friend std::ostream& operator<<(std::ostream& os, Command& command);

      // Set command max current/torque
      void SetMaxCurrent(double maxCurrent);
      void SetMaxTorque(double maxTorque);

     private:

      double m_ControlWordUU{0};
      double m_TargetPositionUU{0};
      double m_TargetVelocityUU{0};
      double m_TargetTorqueUU{0};
      double m_TargetCurrentUU{0};
      double m_MaxTorqueUU{0};
      double m_MaxCurrentUU{0};
      double m_TorqueOffsetUU{0};
      double m_PositionOffsetUU{0};
      double m_VelocityOffsetUU{0};

      int16_t m_ControlWord{0};
      int32_t m_TargetPosition{0};
      int32_t m_TargetVelocity{0};
      int16_t m_TargetTorque{0};
      int16_t m_TargetCurrent{0};
      uint16_t m_MaxTorque{0};
      uint16_t m_MaxCurrent{0};
      int16_t m_TorqueOffset{0};
      int32_t m_PositionOffset{0};
      int32_t m_VelocityOffset{0};

      std::mutex m_TargetTorqueCommandMutex;

      double m_PositionFactorMmToInteger{1};
      double m_PositionFactorRadToInteger{1};
      double m_VelocityFactorRadPerSecToIntegerPerSec{1};
      double m_TorqueFactorNmToInteger{1};
      double m_CurrentFactorAToInteger{1};

      ModeOfOperation m_ModeOfOperation{ModeOfOperation::NA};
      uint8_t m_ModeOfOperationRaw{0};

      /*!
       * set this to true if raw commands have been used and therefore no unit
       * conversion should be done
       */
      bool m_UseRawCommands{false};
      bool m_TargetTorqueCommandUsed{false};
  };

} // namespace Controller::Ethercat::DS402

#endif // COMMAND_H__
