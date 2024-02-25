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

#include <iomanip>
#include "Command.h"

namespace Controller::Ethercat::DS402 {

  Command::Command(const Command& other) {

    m_TargetPositionUU = other.m_TargetPositionUU;
    m_TargetVelocityUU = other.m_TargetVelocityUU;
    m_TargetTorqueUU = other.m_TargetTorqueUU;
    m_TargetCurrentUU = other.m_TargetCurrentUU;
    m_MaxTorqueUU = other.m_MaxTorqueUU;
    m_MaxCurrentUU = other.m_MaxCurrentUU;
    m_TorqueOffsetUU = other.m_TorqueOffsetUU;

    m_TargetPosition = other.m_TargetPosition;
    m_TargetVelocity = other.m_TargetVelocity;
    m_TargetTorque = other.m_TargetTorque;
    m_TargetCurrent = other.m_TargetCurrent;
    m_MaxTorque = other.m_MaxTorque;
    m_MaxCurrent = other.m_MaxCurrent;
    m_TorqueOffset = other.m_TorqueOffset;

    m_PositionFactorRadToInteger = other.m_PositionFactorRadToInteger;
    m_VelocityFactorRadPerSecToIntegerPerSec = other.m_VelocityFactorRadPerSecToIntegerPerSec;
    m_TorqueFactorNmToInteger = other.m_TorqueFactorNmToInteger;
    m_CurrentFactorAToInteger = other.m_CurrentFactorAToInteger;

    m_ModeOfOperation = other.m_ModeOfOperation;

    m_UseRawCommands = other.m_UseRawCommands;
    m_TargetTorqueCommandUsed = other.m_TargetTorqueCommandUsed;
  }

  Command& Command::operator=(const Command& other) {

    m_TargetPositionUU = other.m_TargetPositionUU;
    m_TargetVelocityUU = other.m_TargetVelocityUU;
    m_TargetTorqueUU = other.m_TargetTorqueUU;
    m_TargetCurrentUU = other.m_TargetCurrentUU;
    m_MaxTorqueUU = other.m_MaxTorqueUU;
    m_MaxCurrentUU = other.m_MaxCurrentUU;
    m_TorqueOffsetUU = other.m_TorqueOffsetUU;

    m_TargetPosition = other.m_TargetPosition;
    m_TargetVelocity = other.m_TargetVelocity;
    m_TargetTorque = other.m_TargetTorque;
    m_TargetCurrent = other.m_TargetCurrent;
    m_MaxTorque = other.m_MaxTorque;
    m_MaxCurrent = other.m_MaxCurrent;
    m_TorqueOffset = other.m_TorqueOffset;

    m_PositionFactorRadToInteger = other.m_PositionFactorRadToInteger;
    m_VelocityFactorRadPerSecToIntegerPerSec = other.m_VelocityFactorRadPerSecToIntegerPerSec;
    m_TorqueFactorNmToInteger = other.m_TorqueFactorNmToInteger;
    m_CurrentFactorAToInteger = other.m_CurrentFactorAToInteger;

    m_ModeOfOperation = other.m_ModeOfOperation;


    m_UseRawCommands = other.m_UseRawCommands;
    m_TargetTorqueCommandUsed = other.m_TargetTorqueCommandUsed;

    return *this;
  }

  std::ostream& operator<<(std::ostream& os, Command& command) {

    using std::setfill;
    using std::setw;

    os << std::left << std::setw(25) << "Target Position:" << command.m_TargetPositionUU << "\n"
       << std::setw(25) << "Target Velocity:" << command.m_TargetVelocityUU << "\n"
       << std::setw(25) << "Target Torque:" << command.m_TargetTorqueUU << "\n"
       << std::setw(25) << "Target Current:" << command.m_TargetCurrentUU << "\n"
       << std::setw(25) << "Maximum Torque:" << command.m_MaxTorqueUU << "\n"
       << std::setw(25) << "Maximum Current:" << command.m_MaxCurrentUU << "\n"
       << std::setw(25) << "Position Offset:" << command.m_PositionOffset << "\n"
        << std::setw(25) << "Velocity Offset:" << command.m_VelocityOffset << "\n"
       << std::setw(25) << "Torque Offset:" << command.m_TorqueOffsetUU << "\n"
       << std::right;

    return os;
  }

  /*!
   * Raw set methods
   */

  void Command::SetControlWordRaw(uint16_t controlWord) {
    m_ControlWord = controlWord;
  }
  void Command::SetTargetPositionRaw(int32_t targetPosition) {
    m_TargetPosition = targetPosition;
  }

  void Command::SetTargetVelocityRaw(int32_t targetVelocity) {
    m_TargetVelocity = targetVelocity;
  }

  void Command::SetTargetCurrentRaw(int16_t targetCurrent) {
    m_TargetCurrent = targetCurrent;
  }

  void Command::SetPositionOffsetRaw(int32_t positionOffset) {
    m_PositionOffset = positionOffset;
  }
  void Command::SetVelocityOffsetRaw(int32_t velocityOffset) {
    m_VelocityOffset = velocityOffset;
  }
  void Command::SetTorqueOffsetRaw(int16_t torqueOffset) {
    m_TorqueOffset = torqueOffset;
  }

  /*!
   * user unit set methods
   */
  void Command::SetControlWord(uint16_t controlWord) {
    m_ControlWord = controlWord;
  }
  void Command::SetTargetPosition(double targetPosition) {

    m_TargetPositionUU = targetPosition;
  }



  void Command::SetTargetVelocity(double targetVelocity) {

    m_TargetVelocityUU = targetVelocity;
  }

  void Command::SetTargetTorque(double targetTorque) {
    // lock for thread safety
    std::lock_guard<std::mutex> lockGuard(m_TargetTorqueCommandMutex);
    m_TargetTorqueUU = targetTorque;
    m_TargetTorqueCommandUsed = true;
  }

  void Command::SetTargetCurrent(double targetCurrent) {
    // lock for thread safety
    std::lock_guard<std::mutex> lockGuard(m_TargetTorqueCommandMutex);
    m_TargetCurrentUU = targetCurrent;
    m_TargetTorqueCommandUsed = false;
  }

  void Command::SetPositionOffset(double positionOffset) {
    m_PositionOffset = positionOffset;
  }
  void Command::SetVelocityOffset(double velocityOffset) {
    m_VelocityOffset = velocityOffset;
  }

  void Command::SetTorqueOffset(double torqueOffset) {
    m_TorqueOffsetUU = torqueOffset;
  }

  void Command::SetMaxCurrent(double maxCurrent) {
    m_MaxCurrentUU = maxCurrent;
  }

  void Command::SetMaxTorque(double maxTorque) {
    m_MaxTorqueUU = maxTorque;
  }

  /*!
   * factors set methods
   */
  void Command::SetPositionFactorMmToInteger(double factor) {
    m_PositionFactorMmToInteger = factor;
  }

  void Command::SetPositionFactorRadToInteger(double factor) {
    m_PositionFactorRadToInteger = factor;
  }

  void Command::SetVelocityFactorRadPerSecToIntegerPerSec(double factor) {
    m_VelocityFactorRadPerSecToIntegerPerSec = factor;
  }

  void Command::SetTorqueFactorNmToInteger(double factor) {
    m_TorqueFactorNmToInteger = factor;
  }

  void Command::SetCurrentFactorAToInteger(double factor) {
    m_CurrentFactorAToInteger = factor;
  }

  /*!
   * other set methods
   */
  void Command::SetUseRawCommands(bool useRawCommands) {
    m_UseRawCommands = useRawCommands;
  }
  void Command::SetModeOfOperation(ModeOfOperation modeOfOperation) {
    m_ModeOfOperation = modeOfOperation;
  }
  void Command::SetModeOfOperationRaw(uint8_t modeOfOperation) {
    m_ModeOfOperationRaw = modeOfOperation;
  }


  /*
   * get methods (raw units)
   */
  uint16_t Command::GetControlWordRaw() const {
    return m_ControlWord;
  }
  int32_t Command::GetTargetPositionRaw() const {
    return m_TargetPosition;
  }
  int32_t Command::GetTargetVelocityRaw() const {
    return m_TargetVelocity;
  }
  int16_t Command::GetTargetTorqueRaw() const {
    return m_TargetTorque;
  }
  int16_t Command::GetTargetCurrentRaw() const {
    return m_TargetCurrent;
  }
  uint16_t Command::GetMaxTorqueRaw() const {
    return m_MaxTorque;
  }
  uint16_t Command::GetMaxCurrentRaw() const {
    return m_MaxCurrent;
  }
  int16_t Command::GetTorqueOffsetRaw() const {
    return m_TorqueOffset;
  }
  int32_t Command::GetPositionOffsetRaw() const {
    return m_PositionOffset;
  }
  int32_t Command::GetVelocityOffsetRaw() const {
    return m_VelocityOffset;
  }
  uint8_t Command::GetModeOfOperationRaw() const {
    return m_ModeOfOperationRaw;
  }

  /*
   * get methods (user units)
   */
  uint16_t Command::GetControlWord() const {
    return m_ControlWord;
  }
  double Command::GetTargetPosition() const {
    return m_TargetPositionUU;
  }
  double Command::GetTargetVelocity() const {
    return m_TargetVelocityUU;
  }
  double Command::GetTargetTorque() const {
    return m_TargetTorqueUU;
  }
  double Command::GetTargetCurrent() const {
    return m_TargetCurrentUU;
  }
  double Command::GetMaxTorque() const {
    return m_MaxTorqueUU;
  }
  double Command::GetMaxCurrent() const {
    return m_MaxCurrentUU;
  }
  double Command::GetTorqueOffset() const {
    return m_TorqueOffsetUU;
  }
  double Command::GetPositionOffset() const {
    return m_PositionOffset;
  }
  double Command::GetVelocityOffset() const {
    return m_VelocityOffset;
  }

  void Command::DoUnitConversion() {

    if (!m_UseRawCommands) {

      m_TargetPosition = static_cast<int32_t>(m_PositionFactorRadToInteger * m_TargetPositionUU);
      m_TargetVelocity = static_cast<int32_t>(m_VelocityFactorRadPerSecToIntegerPerSec * m_TargetVelocityUU);
      m_TargetTorque= static_cast<int16_t>(m_TorqueFactorNmToInteger * m_TargetTorqueUU);
      {
        std::lock_guard<std::mutex> lockGuard(m_TargetTorqueCommandMutex);
        if (m_TargetTorqueCommandUsed) {
          m_TargetCurrent = static_cast<int16_t>(m_TorqueFactorNmToInteger * m_TargetTorqueUU);
        } else {
          m_TargetCurrent = static_cast<int16_t>(m_CurrentFactorAToInteger * m_TargetCurrentUU);
        }
      }
      m_MaxTorque = static_cast<uint16_t>(m_TorqueFactorNmToInteger * m_MaxTorqueUU);
      m_MaxCurrent = static_cast<uint16_t>(m_CurrentFactorAToInteger * m_MaxCurrentUU);
      m_TorqueOffset = static_cast<int16_t>(m_TorqueFactorNmToInteger * m_TorqueOffsetUU);
      m_PositionOffset = static_cast<int32_t>(m_PositionFactorRadToInteger * m_PositionOffset);
      m_VelocityOffset = static_cast<int32_t>(m_VelocityFactorRadPerSecToIntegerPerSec * m_VelocityOffset);
    }
  }

  /// other get methods
  ModeOfOperation Command::GetModeOfOperation() const {
    return m_ModeOfOperation;
  }


} // namespace Controller::Ethercat::DS402
