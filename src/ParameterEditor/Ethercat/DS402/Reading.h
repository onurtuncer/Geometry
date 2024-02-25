/* ----------------------------------------------------------------------------*
  Copyright 2022-2024 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef READING_H_
#define READING_H_

#include <chrono>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include "DriveState.h"
#include "Error.h"
#include "StatusWord.h"
#include "Core/Parameter/ParameterManager.h"

namespace Controller::Ethercat::DS402 {

  using ReadingClock = std::chrono::steady_clock;
  using ReadingDuration = std::chrono::duration<double, std::milli>;
  using ReadingTimePoint = std::chrono::time_point<ReadingClock>;

  /*!
   * An alias for a pair of ErrorType and time point
   */
  using ErrorPair = std::pair<ErrorType, ReadingTimePoint>;
  using FaultPair = std::pair<uint16_t, ReadingTimePoint>;
  using ErrorTimePairDeque = std::deque<std::pair<ErrorType, double>>;
  using FaultTimePairDeque = std::deque<std::pair<uint16_t, double>>;

  class Reading {

   public:
    /*!
     * raw get methods
     */
    int32_t GetActualPositionRaw() const;
    int32_t GetActualVelocityRaw() const;
    uint16_t GetStatuswordRaw() const;
    int16_t GetActualCurrentRaw() const;
    uint16_t GetAnalogInputRaw() const;
    uint8_t GetModeOfOperationDisplayRaw() const;

    /*!
     * User units get methods
     */
    double GetActualPosition() const;
    double GetActualPositionMm() const;
    double GetActualVelocity() const;
    double GetActualCurrent() const;
    double GetActualTorque() const;
    double GetAnalogInput() const;
    double GetAgeOfLastReadingInMicroseconds() const;

    void SetEthercatState(uint16_t ethercatState ) { m_EthercatState = ethercatState;} 
    uint16_t GetEthercatState() const { return m_EthercatState;}

    /*!
     * Other get methods
     */
    Statusword GetStatusword() const;    
    DriveState GetDriveState() const;
    /*!
     * set methods (only raw)
     */
    void SetActualPosition(int32_t actualPosition);
    void SetDigitalInputs(int32_t digitalInputs);
    void SetActualVelocity(int32_t actualVelocity);
    void SetStatusword(uint16_t statusword);
    void SetActualCurrent(int16_t actualCurrent);
    void SetModeOfOperationDisplay(uint8_t modeOfOperationDisplay);
    void SetTimePointNow();

    void SetPositionFactor(double positionFactor=1);
    void SetPositionFactorIntegerToRad(double positionFactor=1);
    void SetPositionFactorRadToInteger(double positionFactor=1);
    void SetPositionFactorMmToInteger(double positionFactor=1);
    void SetPositionFactorIntegerToMm(double positionFactor=1);
    void SetPositionFactorRadToDeg(double displayFactor=1);
    void SetStepScaleFactor(double stepScaleFactor=1);
    void SetPositionDisplayFactor(double positionDisplayFactor=1);

    double GetPositionFactor() {return m_PositionFactor;}
    double GetPositionFactorIntegerToRad() {return m_PositionFactorIntegerToRad;}
    double GetPositionFactorRadToInteger() {return m_PositionFactorRadToInteger;}
    double GetPositionFactorMmToInteger() {return m_PositionFactorMmToInteger;}
    double GetPositionFactorIntegerToMm() {return m_PositionFactorIntegerToMm;}
    double GetPositionFactorRadToDeg(){return m_PositionFactorRadToDeg;}
    double GetStepScaleFactor(){return m_StepScaleFactor;}
    double GetPositionDisplayFactor(){return m_PositionDisplayFactor;}

    void SetVelocityFactorIntegerPerSecToRadPerSec(double velocityFactor);
    void SetCurrentFactorIntegerToAmp(double currentFactor);
    void SetTorqueFactorIntegerToNm(double torqueFactor);

   protected:
    int32_t m_ActualPosition{0};
    int32_t m_ActualVelocity{0};
    uint16_t m_Statusword{0};
    int16_t m_ActualCurrent{0};
    uint8_t m_ModeOfOperationDisplay{0};

    double m_PositionDisplayFactor{1.0}; // TODO Add these factors to configurator
    double m_PositionFactor{1.0};
    double m_PositionFactorIntegerToRad{1.0};
    double m_PositionFactorRadToInteger{1.0};
    double m_PositionFactorMmToInteger{1.0};
    double m_PositionFactorIntegerToMm{1.0};
    double m_PositionFactorRadToDeg{1.0};
    double m_StepScaleFactor{1.0};

    double m_VelocityFactorIntegerPerSecToRadPerSec{1.0};
    double m_CurrentFactorIntegerToAmp{1.0};
    double m_TorqueFactorIntegerToNm{1.0};

    uint16_t m_EthercatState;
    ReadingTimePoint m_LastReadingTimePoint;

   public:

    double GetAgeOfLastErrorInMicroseconds() const;
    double GetAgeOfLastFaultInMicroseconds() const;
    ErrorTimePairDeque GetErrors() const;
    FaultTimePairDeque GetFaults() const;
    ErrorType GetLastError() const;
    uint16_t GetLastFault() const;
    void AddError(ErrorType errorType);
    void AddFault(uint16_t faultCode);
    Reading() = default;
    bool HasUnreadError() const;
    bool HasUnreadFault() const;
    void ConfigureReading();

    /*!
     * The configuration constructor
     * @param errorStorageCapacity	the number of errors that are stored
     * @param faultStorageCapacity	the number of faults that are stored
     * @param forceAppendEqualError	true if a new errer shall be appended even
     * though it is equal to the last one
     * @param forceAppendEqualFault	true if a new fault shall be appended even
     * though it is equal to the last one
     */
   
    Reading(const std::string& configPath, std::shared_ptr<ParameterManager> pm) 
      : m_ConfigPath(configPath), m_ParameterManagerPtr(pm){};
    Reading(unsigned int errorStorageCapacity, unsigned int faultStorageCapacity, bool forceAppendEqualError, bool forceAppendEqualFault);

   private:
    std::deque<ErrorPair> m_Errors;
    std::deque<FaultPair> m_Faults;

    ErrorPair m_LastError;
    FaultPair m_LastFault;

    mutable bool m_HasUnreadError{false};
    mutable bool m_HasUnreadFault{false};

    /*!
     * paramaters changeable with a Configuration object
     */
    unsigned int m_ErrorStorageCapacity{25};
    unsigned int m_FaultStorageCapacity{25};
    bool m_ForceAppendEqualError{false};
    bool m_ForceAppendEqualFault{false};
  private:
   std::string m_ConfigPath;
   std::shared_ptr<ParameterManager> m_ParameterManagerPtr;
  };


} // namespace Controller::Ethercat::DS402

// stream operator in global namespace
std::ostream& operator<<(std::ostream& os, const Controller::Ethercat::DS402::Reading& reading);

#endif // READING_H_