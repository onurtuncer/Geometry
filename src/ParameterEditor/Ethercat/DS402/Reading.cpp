/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <numbers>
#include "Reading.h"

std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::Reading& reading) {

  os << std::left 
     << std::setw(30) << "Actual Position:" << reading.GetActualPosition() << "\n"
     << std::setw(30) << "Actual Velocity:" << reading.GetActualVelocity()
     << "\n"
     << std::setw(30) << "Actual Torque:" << reading.GetActualTorque() << "\n"
     << std::setw(30) << "Actual Current:" << reading.GetActualCurrent() << "\n"
     << "\n"
     << std::setw(30) << "\nStatusword:"
     << "\n"
     << reading.GetStatusword() << std::right;
  return os;
}

namespace Controller::Ethercat::DS402 {

  DriveState Reading::GetDriveState() const {
    return GetStatusword().GetDriveState();
  }

  double Reading::GetAgeOfLastReadingInMicroseconds() const {

    ReadingDuration readingDuration = ReadingClock::now() - m_LastReadingTimePoint;
    return readingDuration.count();
  }

  /*!
   * Raw get methods
   */
  int32_t Reading::GetActualPositionRaw() const { 
    return m_ActualPosition; }

  int32_t Reading::GetActualVelocityRaw() const {
    return m_ActualVelocity;
  }

  uint16_t Reading::GetStatuswordRaw() const {
    return m_Statusword;
  }

  int16_t Reading::GetActualCurrentRaw() const {
    return m_ActualCurrent;
  }
  uint8_t Reading::GetModeOfOperationDisplayRaw() const {
    return m_ModeOfOperationDisplay;
  }

  /*!
   * User unit get methods
   */
  double Reading::GetActualPosition() const {
        return static_cast<double>(m_ActualPosition) / m_PositionFactor * m_PositionDisplayFactor;
  }

  double Reading::GetActualPositionMm() const {
      return static_cast<double>(m_ActualPosition) / m_PositionFactorMmToInteger;
  }

  double Reading::GetActualVelocity() const {
    return static_cast<double>(m_ActualVelocity) / m_VelocityFactorIntegerPerSecToRadPerSec;
  }

  double Reading::GetActualCurrent() const {
    return static_cast<double>(m_ActualCurrent) / m_CurrentFactorIntegerToAmp;
  }

  double Reading::GetActualTorque() const {
    return static_cast<double>(m_ActualCurrent) / m_TorqueFactorIntegerToNm;
  }

  /*!
   * Other readings
   */
  Statusword Reading::GetStatusword() const {

    Statusword statusword;
    statusword.SetFromRawStatusword(m_Statusword);
    return statusword;
  }

  /*!
   * Raw set methods
   */
  void Reading::SetActualPosition(int32_t actualPosition) {
    m_ActualPosition = actualPosition;
  }
  void Reading::SetModeOfOperationDisplay(uint8_t modeOfOperationDisplay) {
    m_ModeOfOperationDisplay = modeOfOperationDisplay;
  }

  void Reading::SetActualVelocity(int32_t actualVelocity) {
    m_ActualVelocity = actualVelocity;
  }

  void Reading::SetStatusword(uint16_t statusword) {
    m_Statusword = statusword;
    
  }

  void Reading::SetActualCurrent(int16_t actualCurrent) {
    m_ActualCurrent = actualCurrent;
  }

  void Reading::SetTimePointNow() {
    m_LastReadingTimePoint = ReadingClock::now();
  }

  void Reading::SetPositionFactor(double positionFactor) {
    m_PositionFactor = positionFactor;
  }
  void Reading::SetPositionDisplayFactor(double positionDisplayFactor) {
    m_PositionDisplayFactor = positionDisplayFactor;
  }
  void Reading::SetPositionFactorRadToDeg(double displayFactor) {
    m_PositionFactorRadToDeg = displayFactor;
  }

  void Reading::SetPositionFactorIntegerToRad(double positionFactor) {
    m_PositionFactorIntegerToRad = positionFactor;
  }

    void Reading::SetPositionFactorRadToInteger(double positionFactor) {
    m_PositionFactorRadToInteger = positionFactor;
  }
  
  void Reading::SetPositionFactorIntegerToMm(double positionFactor) {
    m_PositionFactorIntegerToMm = positionFactor;
  }

  void Reading::SetPositionFactorMmToInteger(double positionFactor) {
    m_PositionFactorMmToInteger = positionFactor;
  }

  void Reading::SetStepScaleFactor(double stepScaleFactor) {
    m_StepScaleFactor = stepScaleFactor;
  }

  void Reading::SetVelocityFactorIntegerPerSecToRadPerSec(double velocityFactor) {
    m_VelocityFactorIntegerPerSecToRadPerSec = velocityFactor;
  }

  void Reading::SetCurrentFactorIntegerToAmp(double currentFactor) {
    m_CurrentFactorIntegerToAmp = currentFactor;
  }

  void Reading::SetTorqueFactorIntegerToNm(double torqueFactor) {
    m_TorqueFactorIntegerToNm = torqueFactor;
  }

  double Reading::GetAgeOfLastErrorInMicroseconds() const {
    ReadingDuration errorDuration = ReadingClock::now() - m_LastError.second;
    return errorDuration.count();
  }

  double Reading::GetAgeOfLastFaultInMicroseconds() const {
    ReadingDuration faultDuration = ReadingClock::now() - m_LastFault.second;
    return faultDuration.count();
  }

  void Reading::AddError(ErrorType errorType) {

    ErrorPair errorPair;
    errorPair.first = errorType;
    errorPair.second = ReadingClock::now();

    if (m_LastError.first == errorType) {
      if (m_ForceAppendEqualError) {
        m_Errors.push_front(errorPair);
      } else {
        m_Errors.pop_front();
        m_Errors.push_front(errorPair);
      }
    } else {
      m_Errors.push_front(errorPair);
    }

    m_LastError = errorPair;

    if (m_Errors.size() > m_ErrorStorageCapacity) {
      m_Errors.pop_back();
    }
    m_HasUnreadError = true;
  }

  void Reading::AddFault(uint16_t faultCode) {

    FaultPair faultPair;
    faultPair.first = faultCode;
    faultPair.second = ReadingClock::now();
    if (m_LastFault.first == faultCode) {
      if (m_ForceAppendEqualFault) {
        m_Faults.push_front(faultPair);
      } else {
        m_Faults.pop_front();
        m_Faults.push_front(faultPair);
      }
    } else {
      m_Faults.push_front(faultPair);
    }
    m_LastFault = faultPair;
    if (m_Faults.size() > m_FaultStorageCapacity) {
      m_Faults.pop_back();
    }

    m_HasUnreadFault = true;
  }

  ErrorTimePairDeque Reading::GetErrors() const {

    ReadingTimePoint now = ReadingClock::now();
    ErrorTimePairDeque errors;
    errors.resize(m_Errors.size());
    ReadingDuration duration;

    for (unsigned int i = 0; i < m_Errors.size(); i++) {
      errors[i].first = m_Errors[i].first;
      duration = now - m_Errors[i].second;
      errors[i].second = duration.count();
    }
    m_HasUnreadError = false;
    return errors;
  }

  FaultTimePairDeque Reading::GetFaults() const {

    ReadingTimePoint now = ReadingClock::now();
    FaultTimePairDeque faults;
    faults.resize(m_Faults.size());
    ReadingDuration duration;
    for (unsigned int i = 0; i < m_Faults.size(); i++) {
      faults[i].first = m_Faults[i].first;
      duration = now - m_Faults[i].second;
      faults[i].second = duration.count();
    }
    m_HasUnreadFault = false;
    return faults;
  }

  ErrorType Reading::GetLastError() const {

    m_HasUnreadError = false;
    return m_LastError.first;
  }

  uint16_t Reading::GetLastFault() const {

    // return 0 if no fault occured
    if (!m_HasUnreadFault) {
      return 0;
    }
    m_HasUnreadFault = false;
    return m_LastFault.first;
  }

  bool Reading::HasUnreadError() const {

    return m_HasUnreadError;
  }

  bool Reading::HasUnreadFault() const {

    return m_HasUnreadFault;
  }

  void Reading::ConfigureReading() {

    m_ErrorStorageCapacity = m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".errorStorageCapacity").getValue();
    m_FaultStorageCapacity = m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".faultStorageCapacity").getValue();
    m_ForceAppendEqualError = m_ParameterManagerPtr->GetParameter<bool>(m_ConfigPath + ".forceAppendEqualError").getValue();
    m_ForceAppendEqualFault = m_ParameterManagerPtr->GetParameter<bool>(m_ConfigPath + ".forceAppendEqualFault").getValue();

    double currentFactor = m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".nominalCurrentA").getValue()/ 1000.0;

    m_CurrentFactorIntegerToAmp = currentFactor;

     m_PositionFactorIntegerToRad = 
        static_cast<double>(2.0 * std::numbers::pi) /
        static_cast<double>( m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".positionScaleFactorNumerator").getValue()
                            /m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".positionScaleFactorDenominator").getValue());
    
    m_PositionFactorRadToInteger = 1.0 / m_PositionFactorIntegerToRad;

    m_PositionFactorMmToInteger = static_cast<double>(m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".positionScaleFactorNumerator").getValue()/m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".positionScaleFactorDenominator").getValue());

    m_PositionFactorIntegerToMm = 1.0 / m_PositionFactorMmToInteger;

    m_TorqueFactorIntegerToNm = m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".nominalCurrentA").getValue() 
                              * m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".torqueConstantNmA").getValue() / 1000.0;
}

} // namespace Controller::Ethercat::DS402
