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

#ifndef ISERVO_H
#define ISERVO_H

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <mutex>
#include <string>
#include "Command.h"
#include "ControlWord.h"
#include "StatusWord.h"
#include "DriveState.h"
#include "Reading.h"
#include "Error.h"
#include "ObjectDictionary402.h"
#include "Ethercat/ParametricDevice.h"  

#define RX_PDO_ID 0x6000
#define TX_PDO_ID 0x7000

namespace Controller::Ethercat::DS402 {

  class IServo : public ParametricDevice {

     public:

      /* TxPDO types */
       struct TxPdoStandard { // 0x1A01
        uint16_t statusword;
        int32_t actualPosition;
      } __attribute__((packed));

      struct TxPdoCSP { // 0x1A00
        uint16_t statusword;
        int32_t actualPosition;
        int32_t actualVelocity;
        int16_t actualTorque;
        uint8_t modeOfOperationDisplay;
        uint8_t padding;
      } __attribute__((packed));

      struct TxPdoCSV { // 0x1A02
        uint16_t statusword;
        int32_t actualPosition;
        int32_t actualVelocity;
        int16_t actualTorque;
        uint8_t modeOfOperationDisplay;
        uint8_t padding;
      } __attribute__((packed));

      struct TxPdoCSTCSPCSV { // 0x1A03
        uint16_t statusword;
        int32_t actualPosition;
        int32_t actualVelocity;
        int16_t actualTorque;
        uint8_t modeOfOperationDisplay;
        uint8_t padding;
      } __attribute__((packed));

      /* RxPDO types */

      struct RxPdoStandard { // 0x1601
        uint16_t controlWord;
        int32_t targetPosition;
      } __attribute__((packed));

      struct RxPdoCSP { // 0x1600
        uint16_t controlWord;
        int32_t targetPosition;
        int32_t velocityOffset;
        int16_t torqueOffset;
        uint8_t modeOfOperation;
        uint8_t padding;
      } __attribute__((packed));

      struct RxPdoCSV { // 0x1602
        uint16_t controlWord;
        int32_t targetVelocity;
        int32_t velocityOffset;
        uint8_t modeOfOperation;
        uint8_t padding;
      } __attribute__((packed));

      struct RxPdoCSTCSPCSV { // 0x1603
        uint16_t controlWord;
        int32_t targetPosition;
        int32_t targetVelocity;
        int16_t targetTorque;
        int32_t velocityOffset;
        int16_t torqueOffset;
        uint8_t modeOfOperation;
        uint8_t padding;
      } __attribute__((packed));

    public:
       IServo(const std::string& name, const uint32_t address, const std::string& configPath, std::shared_ptr<ParameterManager> pm)
          : ParametricDevice(pm, configPath){

        m_Address = address;
        m_Name = name;

        m_PdoInfo.rxPdoId = RX_PDO_ID;
        m_PdoInfo.txPdoId = TX_PDO_ID;

        m_Reading = std::make_unique<Ethercat::DS402::Reading>(configPath, pm);
      } 

      virtual ~IServo() = default;

      bool LoadConfiguration();

      virtual bool Startup() = 0;
      
      bool MapPdos(const RxPdoTypeEnum& rxPdoTypeEnum,
                   const TxPdoTypeEnum& txPdoTypeEnum);
      
      void PreShutdown();
      void Shutdown();
      void UpdateWrite();
      void UpdateRead();

      bool PutIntoOperation() {

        bool success;
        m_Bus->SetState(EC_STATE_OPERATIONAL, GetAddress());
        success = m_Bus->WaitForState(EC_STATE_OPERATIONAL, GetAddress(), 1000, 0.001);
        return success;
      }

      uint16_t GetEcState() {
        return m_Bus->GetEcState(m_Address);
      }

      PdoInfo GetCurrentPdoInfo() const override {return m_PdoInfo;}
      void StageCommand(const Command& command);
      Reading GetReading() const;
      void GetReading(Reading& reading) const;

      unsigned int GetChannelIndex() const {return m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".channelIndex").getValue();}
      unsigned int GetAxisIndex()    const {return m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".axisIndex").getValue();}
      char         GetAxisName()     const {return m_ParameterManagerPtr->GetParameter<char>(m_ConfigPath + "axisName").getValue();}

      int32_t  GetSlowJogSpeed() const {return m_ParameterManagerPtr->GetParameter<int32_t>(m_ConfigPath + "slowJogSpeed").getValue();}
      int32_t  GetFastJogSpeed() const {return m_ParameterManagerPtr->GetParameter<int32_t>(m_ConfigPath + "fastJogSpeed").getValue();}

      double GetJogTargetVelocity()     const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".jogTargetVelocity").getValue();}
      double GetJogTargetAcceleration() const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".jogTargetAcceleration").getValue();}
      double GetJogMaxVelocity()        const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".jogMaxVelocity").getValue();}
      double GetJogMaxAcceleration()    const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".jogMaxAcceleration").getValue();}
      double GetJogMaxJerk()            const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".jogMaxJerk").getValue();}

      double GetStepTargetVelocity()     const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".stepTargetVelocity").getValue();}
      double GetStepTargetAcceleration() const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".stepTargetAcceleration").getValue();}
      double GetStepMaxVelocity()        const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".stepMaxVelocity").getValue();}
      double GetStepMaxAcceleration()    const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".stepMaxAcceleration").getValue();}
      double GetStepMaxJerk()            const {return m_ParameterManagerPtr->GetParameter<double>(m_ConfigPath + ".stepMaxJerk").getValue();}

      uint32_t GetMaxProfileVelocity() const {return m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + "maxProfileVelocity").getValue();}
      uint32_t GetQuickStopDecel() const {return m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + "quickStopDecel").getValue();}
      uint32_t GetProfileDecel() const {return m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + "profileDecel").getValue();}
      uint32_t GetProfileAcceleration() const {return m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + "profileAcceleration").getValue();}
      uint32_t GetProfileVelocity() const {return m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + "profileVelocity").getValue();}

      int GetPositionScaleFactorNumerator()   const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".positionScaleFactorNumerator").getValue();}
      int GetPositionScaleFactorDenominator() const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".positionScaleFactorDenominator").getValue();}                                                    
      int GetStepScaleFactorNumerator()       const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".stepScaleFactorNumerator").getValue();}                                           
      int GetStepScaleFactorDenominator()     const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".stepScaleFactorDenominator").getValue();}                                               
      int GetVelocityScaleFactorNumerator()   const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".velocityScaleFactorNumerator").getValue();}                                
      int GetVelocityScaleFactorDenominator() const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".velocityScaleFactorDenominator").getValue();}

      int GetTorqueScaleFactor()  const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".torqueScaleFactor").getValue();}
      int GetCurrentScaleFactor() const {return m_ParameterManagerPtr->GetParameter<int>(m_ConfigPath + ".currentScaleFactor").getValue();}

      std::string GetAxisType() const {return m_ParameterManagerPtr->GetParameter<std::string>(m_ConfigPath + ".axisType").getValue();}

      std::pair<std::string, std::string> GetEncoderType() const {return m_ParameterManagerPtr->GetParameter<std::pair<std::string, std::string>>(m_ConfigPath + ".encoderType").getValue();}

      std::pair<bool, double> GetMaxPosition() const {return m_ParameterManagerPtr->GetParameter<std::pair<bool, double>>(m_ConfigPath + ".maxPosition").getValue();}
      std::pair<bool, double> GetMinPosition() const {return m_ParameterManagerPtr->GetParameter<std::pair<bool, double>>(m_ConfigPath + ".minPosition").getValue();}


    public:
      bool GetStatuswordViaSdo(Statusword& statusword);
      bool SetControlwordViaSdo(Controlword& controlword);
      bool SetDriveStateViaSdo(const DriveState& driveState);

    protected:
      bool StateTransitionViaSdo(const StateTransition& stateTransition);

    public:
      bool SetDriveStateViaPdo(const DriveState& driveState, const bool waitForState);
      void EngagePdoStateMachine();
      void AddErrorToReading(const ErrorType& errorType); 
      bool LastPdoStateChangeSuccessful() const {return m_StateChangeSuccessful;}
    
    protected:
      void AutoConfigurePdoSizes();
      uint16_t GetTxPdoSize();
      uint16_t GetRxPdoSize();
      Controlword GetNextStateTransitionControlword(const DriveState& requestedDriveState,
                                                    const DriveState& currentDriveState);
      
      bool IsAllowedModeCombination(const std::vector<ModeOfOperation> modes);
      std::pair<RxPdoTypeEnum, TxPdoTypeEnum> GetMixedPdoType(std::vector<ModeOfOperation> modes);
    
    public:
      void PrintErrorCode();
      void PrintDiagnosis();

    protected:
      Command m_StagedCommand;
      std::unique_ptr<Reading> m_Reading;
      RxPdoTypeEnum m_RxPdoTypeEnum{RxPdoTypeEnum::NA};
      TxPdoTypeEnum m_TxPdoTypeEnum{TxPdoTypeEnum::NA};
      Controlword m_Controlword;
      PdoInfo m_PdoInfo;
      bool m_HasRead{false};
      bool m_ConductStateChange{false};
      DriveState m_TargetDriveState{DriveState::NA};
      std::chrono::time_point<std::chrono::steady_clock> m_DriveStateChangeTimePoint;
      uint16_t m_NumberOfSuccessfulTargetStateReadings{0};
      std::atomic<bool> m_StateChangeSuccessful{false};

    protected:
      bool m_AllowModeChange{false};
      ModeOfOperation m_ModeOfOperation{ModeOfOperation::NA};

    protected:
      mutable std::recursive_mutex m_StagedCommandMutex;
      mutable std::recursive_mutex m_ReadingMutex;
      mutable std::recursive_mutex m_Mutex; 
  };

} // namespace Controller::Ethercat::DS402

#endif // ISERVO_H