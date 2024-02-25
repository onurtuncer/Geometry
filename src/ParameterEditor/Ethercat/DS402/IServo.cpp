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

// https://github.com/leggedrobotics/elmo_ethercat_sdk/tree/master/src/elmo_ethercat_sdk

#include "IServo.h"
#include "ObjectDictionary402.h"

namespace Controller::Ethercat::DS402 {

  // bool IServo::LoadConfigFile(const std::string& fileName) {
    
  //   ConfigurationParser configurationParser(fileName);
  //   return LoadConfiguration(configurationParser.GetConfiguration());
  // }


  bool IServo::LoadConfiguration() {

    try{
      m_ModeOfOperation = m_ParameterManagerPtr->GetParameter<std::vector<Ethercat::DS402::ModeOfOperation>>(m_ConfigPath + ".modesOfOperation").getValue()[0];
      m_RxPdoTypeEnum   = m_ParameterManagerPtr->GetParameter<Ethercat::DS402::RxPdoTypeEnum>(m_ConfigPath + ".rxPdoType").getValue();
      m_TxPdoTypeEnum   = m_ParameterManagerPtr->GetParameter<Ethercat::DS402::TxPdoTypeEnum>(m_ConfigPath + ".txPdoType").getValue();
      return true;
    } catch(...){

      return false;
    }
  }

  bool IServo::GetStatuswordViaSdo(Statusword& statusword) {

    uint16_t statuswordValue = 0;
    bool success = SendSdoRead(OD_INDEX_STATUSWORD, 0, false, statuswordValue);
    statusword.SetFromRawStatusword(statuswordValue);
    return success;
  }

  bool IServo::MapPdos(const RxPdoTypeEnum& rxPdoTypeEnum,
                       const TxPdoTypeEnum& txPdoTypeEnum) {
    
    bool success = true;

    // clear SM PDO mapping
    uint8_t uint8val;
    uint16_t uint16val;
    uint32_t uint32val;

    uint8val = 0x00;
    success &= SendSdoWrite(0x1C12, 0x00, FALSE, uint8val);

    uint8val = 0x00;
    success &= SendSdoWrite(0x1C13, 0x00, FALSE, uint8val);

    // set 1A00 PDO mapping
    uint8val = 0x00;
    success &= SendSdoWrite(0x1a00, 0x00, FALSE, uint8val);

    uint32val = 0x60410010;
    success &= SendSdoWrite(0x1a00, 0x01, FALSE, uint32val);

    uint32val = 0x60640020;
    success &= SendSdoWrite(0x1a00, 0x02, FALSE, uint32val);

    uint32val = 0x606c0020;
    success &= SendSdoWrite(0x1a00, 0x03, FALSE, uint32val);

    uint32val = 0x60770010;
    success &= SendSdoWrite(0x1a00, 0x04, FALSE, uint32val);

    uint32val = 0x60610008;
    success &= SendSdoWrite(0x1a00, 0x05, FALSE, uint32val);

    uint32val = 0x00000008;
    success &= SendSdoWrite(0x1a00, 0x06, FALSE, uint32val);

    uint8val = 0x06;
    success &= SendSdoWrite(0x1a00, 0x00, FALSE, uint8val);

    // set 1A01 PDO mapping
    uint8val = 0x00;
    success &= SendSdoWrite(0x1a01, 0x00, FALSE, uint8val);

    uint32val = 0x60410010;
    success &= SendSdoWrite(0x1a01, 0x01, FALSE, uint32val);

    uint32val = 0x60640020;
    success &= SendSdoWrite(0x1a01, 0x02, FALSE, uint32val);

    uint8val = 0x02;
    success &= SendSdoWrite(0x1a01, 0x00, FALSE, uint8val);

    // set 1A02 PDO mapping
    uint8val = 0x00;
    success &= SendSdoWrite(0x1a02, 0x00, FALSE, uint8val);

    uint32val = 0x60410010;
    success &= SendSdoWrite(0x1a02, 0x01, FALSE, uint32val);

    uint32val = 0x60640020;
    success &= SendSdoWrite(0x1a02, 0x02, FALSE, uint32val);

    uint32val = 0x606c0020;
    success &= SendSdoWrite(0x1a02, 0x03, FALSE, uint32val);

    uint32val = 0x60770010;
    success &= SendSdoWrite(0x1a02, 0x04, FALSE, uint32val);

    uint32val = 0x60610008;
    success &= SendSdoWrite(0x1a02, 0x05, FALSE, uint32val);

    uint32val = 0x00000008;
    success &= SendSdoWrite(0x1a02, 0x06, FALSE, uint32val);

    uint8val = 0x06;
    success &= SendSdoWrite(0x1a02, 0x00, FALSE, uint8val);

    // set 1A03 PDO mapping
    uint8val = 0x00;
    success &= SendSdoWrite(0x1a03, 0x00, FALSE, uint8val);

    uint32val = 0x60410010;
    success &= SendSdoWrite(0x1a03, 0x01, FALSE, uint32val);

    uint32val = 0x60640020;
    success &= SendSdoWrite(0x1a03, 0x02, FALSE, uint32val);

    uint32val = 0x606c0020;
    success &= SendSdoWrite(0x1a03, 0x03, FALSE, uint32val);

    uint32val = 0x60770010;
    success &= SendSdoWrite(0x1a03, 0x04, FALSE, uint32val);

    uint32val = 0x60610008;
    success &= SendSdoWrite(0x1a03, 0x05, FALSE, uint32val);

    uint32val = 0x00000008;
    success &= SendSdoWrite(0x1a03, 0x06, FALSE, uint32val);

    uint8val = 0x06;
    success &= SendSdoWrite(0x1a03, 0x00, FALSE, uint8val);

    // set 1600 PDO mapping
    uint8val = 0x00;
    success &= SendSdoWrite(0x1600, 0x00, FALSE, uint8val);

    uint32val = 0x60400010;
    success &= SendSdoWrite(0x1600, 0x01, FALSE, uint32val);

    uint32val = 0x607a0020;
    success &= SendSdoWrite(0x1600, 0x02, FALSE, uint32val);

    uint32val = 0x60b10020;
    success &= SendSdoWrite(0x1600, 0x03, FALSE, uint32val);

    uint32val = 0x60b20010;
    success &= SendSdoWrite(0x1600, 0x04, FALSE, uint32val);

    uint32val = 0x60600008;
    success &= SendSdoWrite(0x1600, 0x05, FALSE, uint32val);

    uint32val = 0x00000008;
    success &= SendSdoWrite(0x1600, 0x06, FALSE, uint32val);

    uint8val = 0x06;
    success &= SendSdoWrite(0x1600, 0x00, FALSE, uint8val);

    // set 1601 PDO mapping
    uint8val = 0x00;
    success &= SendSdoWrite(0x1601, 0x00, FALSE, uint8val);

    uint32val = 0x60400010;
    success &= SendSdoWrite(0x1601, 0x01, FALSE, uint32val);

    uint32val = 0x607a0020;
    success &= SendSdoWrite(0x1601, 0x02, FALSE, uint32val);

    uint8val = 0x02;
    success &= SendSdoWrite(0x1601, 0x00, FALSE, uint8val);


    // set 1602 PDO mapping
    uint8val = 0x00;
    success &= SendSdoWrite(0x1602, 0x00, FALSE, uint8val);

    uint32val = 0x60400010;
    success &= SendSdoWrite(0x1602, 0x01, FALSE, uint32val);

    uint32val = 0x60ff0020;
    success &= SendSdoWrite(0x1602, 0x02, FALSE, uint32val);

    uint32val = 0x60b10020;
    success &= SendSdoWrite(0x1602, 0x03, FALSE, uint32val);

    uint32val = 0x60600008;
    success &= SendSdoWrite(0x1602, 0x04, FALSE, uint32val);

    uint32val = 0x00000008;
    success &= SendSdoWrite(0x1602, 0x05, FALSE, uint32val);

    uint8val = 0x05;
    success &= SendSdoWrite(0x1602, 0x00, FALSE, uint8val);

    // set 1603 PDO mapping

    uint8val = 0x00;
    success &= SendSdoWrite(0x1603, 0x00, FALSE, uint8val);

    uint32val = 0x60400010;
    success &= SendSdoWrite(0x1603, 0x01, FALSE, uint32val);

    uint32val = 0x607a0020;
    success &= SendSdoWrite(0x1603, 0x02, FALSE, uint32val);

    uint32val = 0x60ff0020;
    success &= SendSdoWrite(0x1603, 0x03, FALSE, uint32val);

    uint32val = 0x60710010;
    success &= SendSdoWrite(0x1603, 0x04, FALSE, uint32val);

    uint32val = 0x60b10020;
    success &= SendSdoWrite(0x1603, 0x05, FALSE, uint32val);

    uint32val = 0x60b20010;
    success &= SendSdoWrite(0x1603, 0x06, FALSE, uint32val);

    uint32val = 0x60600008;
    success &= SendSdoWrite(0x1603, 0x07, FALSE, uint32val);

    uint32val = 0x00000008;
    success &= SendSdoWrite(0x1603, 0x08, FALSE, uint32val);

    uint8val = 0x08;
    success &= SendSdoWrite(0x1603, 0x00, FALSE, uint8val);

    success &= SendSdoWrite(OD_INDEX_HOMING_METHOD, 0x00, false, static_cast<int8_t>(m_ParameterManagerPtr->GetParameter<int8_t>(m_ConfigPath + ".homeMethod").getValue()));

    // success &= SendSdoWrite(OD_INDEX_HOMING_ACCELERATION, 0x00, false, static_cast<uint32_t>(m_Configuration.homingAcceleration));

    success &= SendSdoWrite(OD_INDEX_HOMING_SPEED, 0x01, false, static_cast<uint32_t>(m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + ".homeSpeed").getValue()));

    // success &= SendSdoWrite(OD_INDEX_HOME_OFFSET, 0x00, false, static_cast<int32_t>(m_Configuration.homeOffset));

    success &= SendSdoWrite(OD_INDEX_PROFILE_DECELERATION, 0x00, false, static_cast<uint32_t>(m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + ".profileDecel").getValue()));

    success &= SendSdoWrite(OD_INDEX_PROFILE_ACCELERATION, 0x00, false, static_cast<uint32_t>(m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + ".profileAcceleration").getValue()));

    success &= SendSdoWrite(OD_INDEX_PROFILE_VELOCITY, 0x00, false, static_cast<uint32_t>(m_ParameterManagerPtr->GetParameter<uint32_t>(m_ConfigPath + ".profileVelocity").getValue()));

    switch (rxPdoTypeEnum) {
      case RxPdoTypeEnum::RxPdoStandard: {
        uint16val = 0x1601;
        success &= SendSdoWrite(0x1C12, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C12, 0x00, FALSE, uint8val);

      } break;
      case Controller::Ethercat::DS402::RxPdoTypeEnum::RxPdoCSP: {

        uint16val = 0x1600;
        success &= SendSdoWrite(0x1C12, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C12, 0x00, FALSE, uint8val);
      } break;
      case RxPdoTypeEnum::RxPdoCSV: {

        uint16val = 0x1602;
        success &= SendSdoWrite(0x1C12, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C12, 0x00, FALSE, uint8val);

      } break;
      case RxPdoTypeEnum::RxPdoCSTCSPCSV: {

        uint16val = 0x1603;
        success &= SendSdoWrite(0x1C12, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C12, 0x00, FALSE, uint8val);

      } break;
      default: {

        uint16val = 0x1601;
        success &= SendSdoWrite(0x1C12, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C12, 0x00, FALSE, uint8val);
      } break;
    }    // switch

    switch (txPdoTypeEnum) {
      case TxPdoTypeEnum::TxPdoStandard: {

        uint16val = 0x1A01;
        success &= SendSdoWrite(0x1C13, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C13, 0x00,FALSE, uint8val);


      } break;
      case TxPdoTypeEnum::TxPdoCSP: {

        uint16val = 0x1A00;
        success &= SendSdoWrite(0x1C13, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C13, 0x00, FALSE, uint8val);

      } break;
      case TxPdoTypeEnum::TxPdoCSV: {

        uint16val = 0x1A02;
        success &= SendSdoWrite(0x1C13, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C13, 0x00, FALSE, uint8val);

      } break;
      case TxPdoTypeEnum::TxPdoCSTCSPCSV: {

        uint16val = 0x1A03;
        success &= SendSdoWrite(0x1C13, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C13, 0x00, FALSE, uint8val);

      } break;
      default: {

        uint16val = 0x1A01;
        success &= SendSdoWrite(0x1C13, 0x01, FALSE, uint16val);

        uint8val = 0x01;
        success &= SendSdoWrite(0x1C13, 0x00, FALSE, uint8val);
      } break;
    }    // switch

    return success;
  }

  void IServo::PreShutdown() {

    SetDriveStateViaSdo(DriveState::QuickStopActive);
    SetDriveStateViaSdo(DriveState::SwitchOnDisabled);
  }

  void IServo::Shutdown() {
    
    m_Bus->SetState(EC_STATE_INIT, m_Address);
  }

  void IServo::UpdateRead() {

    std::lock_guard<std::recursive_mutex> lock(m_Mutex);

    switch (m_TxPdoTypeEnum) {
      case TxPdoTypeEnum::TxPdoStandard: {
        IServo::TxPdoStandard txPdo{};
        m_Bus->ReadTxPdo(m_Address, txPdo);
        m_Reading->SetStatusword(txPdo.statusword);
        m_Reading->SetActualPosition(txPdo.actualPosition);
        break;
      }
      case TxPdoTypeEnum::TxPdoCSP: {
        IServo::TxPdoCSP txPdo{};
        // reading from the bus
        m_Bus->ReadTxPdo(m_Address, txPdo);
        {
          std::lock_guard<std::recursive_mutex> lock(m_ReadingMutex);
          m_Reading->SetStatusword(txPdo.statusword);
          m_Reading->SetActualPosition(txPdo.actualPosition);
          m_Reading->SetActualVelocity(txPdo.actualVelocity);
          m_Reading->SetActualCurrent(txPdo.actualTorque);
          m_Reading->SetModeOfOperationDisplay(txPdo.modeOfOperationDisplay);
        }
        break;
      }
      case TxPdoTypeEnum::TxPdoCSV: {
        IServo::TxPdoCSV txPdo{};
        // reading from the bus
        m_Bus->ReadTxPdo(m_Address, txPdo);
        {
          std::lock_guard<std::recursive_mutex> lock(m_ReadingMutex);
          m_Reading->SetStatusword(txPdo.statusword);
          m_Reading->SetActualCurrent(txPdo.actualTorque);
          m_Reading->SetActualVelocity(txPdo.actualVelocity);
          m_Reading->SetActualPosition(txPdo.actualPosition);
          m_Reading->SetModeOfOperationDisplay(txPdo.modeOfOperationDisplay);
        }
        break;
      }
      case TxPdoTypeEnum::TxPdoCSTCSPCSV: {
        IServo::TxPdoCSTCSPCSV txPdo{};
        // reading from the bus
        m_Bus->ReadTxPdo(m_Address, txPdo);
        {
          std::lock_guard<std::recursive_mutex> lock(m_ReadingMutex);
          m_Reading->SetStatusword(txPdo.statusword);
          m_Reading->SetActualCurrent(txPdo.actualTorque);
          m_Reading->SetActualVelocity(txPdo.actualVelocity);
          m_Reading->SetActualPosition(txPdo.actualPosition);
          m_Reading->SetModeOfOperationDisplay(txPdo.modeOfOperationDisplay);

          m_Reading->SetEthercatState(GetEcState());
        }
        break;
      }
      default:
        std::stringstream ss;
        ss << "[IServo::UpdateRead] Unsupported Tx Pdo type for '" << m_Name << "'" << std::endl
            << "  TxPdoTypeEnum: " << m_TxPdoTypeEnum << std::endl;
        CONTROLLER_CORE_ERROR(ss.str());
        m_Reading->AddError(ErrorType::TxPdoTypeError);
    } // switch 

    // if (!m_HasRead) {
    //   m_HasRead = true;
    // }

    // if (m_Reading.GetDriveState() == Controller::Ethercat::DS402::DriveState::FaultReactionActive) {
    //   std::stringstream ss;
    //   ss << "[SMB::UpdateRead] '" << m_Name << "' is in drive state 'FaultReactionActive'" << std::endl;
    //   CONTROLLER_CORE_ERROR(ss.str());
    // }

    // if (m_Reading.GetDriveState() == Controller::Ethercat::DS402::DriveState::Fault) {
    //   std::stringstream ss;
    //   ss << "[SMB::UpdateRemad] '" << m_Name << "' is in drive state 'Fault'" << std::endl;
    //   CONTROLLER_CORE_ERROR(ss.str());
    // }
  }

    void IServo::UpdateWrite() {

    std::lock_guard<std::recursive_mutex> lock(m_Mutex);

    if (m_ModeOfOperation == ModeOfOperation::NA) {
      m_Reading->AddError(ErrorType::ModeOfOperationError);
      std::stringstream ss;
      ss << "[IServo::UpdateWrite] Mode of operation for '" << m_Name << "' has not been set." << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      return;
    }

    if (m_ConductStateChange && m_HasRead) {
      EngagePdoStateMachine();
    }

    switch (m_RxPdoTypeEnum) {
      case RxPdoTypeEnum::RxPdoStandard: {
        IServo::RxPdoStandard rxPdo{};
        rxPdo.controlWord = m_Controlword.GetRawControlword();
        rxPdo.targetPosition = m_StagedCommand.GetTargetPositionRaw();

        m_Bus->WriteRxPdo(m_Address, rxPdo);
        break;
      }
      case RxPdoTypeEnum::RxPdoCSP: {
        IServo::RxPdoCSP rxPdo{};
        {
          std::lock_guard<std::recursive_mutex> lock(m_StagedCommandMutex);
          // rxPdo.controlWord = m_Controlword.GetRawControlword();
          rxPdo.targetPosition = m_StagedCommand.GetTargetPositionRaw();
          rxPdo.velocityOffset = m_StagedCommand.GetVelocityOffsetRaw();
          rxPdo.torqueOffset = m_StagedCommand.GetTorqueOffsetRaw();
          rxPdo.modeOfOperation = m_StagedCommand.GetModeOfOperationRaw();
          // Extra data
          rxPdo.controlWord = m_StagedCommand.GetControlWordRaw();
          rxPdo.modeOfOperation = static_cast<int8_t>(m_ModeOfOperation);
        }

        m_Bus->WriteRxPdo(m_Address, rxPdo);
        break;
      }
      case RxPdoTypeEnum::RxPdoCSV: {
        IServo::RxPdoCSV rxPdo{};
        {
          std::lock_guard<std::recursive_mutex> lock(m_StagedCommandMutex);
          rxPdo.targetVelocity = m_StagedCommand.GetTargetVelocityRaw();
          rxPdo.velocityOffset = m_StagedCommand.GetVelocityOffsetRaw();

          // Extra data
          rxPdo.controlWord = m_Controlword.GetRawControlword();
          rxPdo.targetVelocity = m_StagedCommand.GetTargetVelocityRaw();
          rxPdo.velocityOffset = m_StagedCommand.GetVelocityOffsetRaw();
          // rxPdo.modeOfOperation = static_cast<int8_t>(m_ModeOfOperation);
          rxPdo.modeOfOperation = m_StagedCommand.GetModeOfOperationRaw();
        }

        m_Bus->WriteRxPdo(m_Address, rxPdo);
        break;
      }
      case RxPdoTypeEnum::RxPdoCSTCSPCSV: {
        IServo::RxPdoCSTCSPCSV rxPdo{};
        {
          std::lock_guard<std::recursive_mutex> lock(m_StagedCommandMutex);
          rxPdo.targetPosition  = m_StagedCommand.GetTargetPositionRaw();
          rxPdo.targetTorque    = m_StagedCommand.GetTargetTorqueRaw();
          rxPdo.torqueOffset    = m_StagedCommand.GetTorqueOffsetRaw();
          rxPdo.targetVelocity  = m_StagedCommand.GetTargetVelocityRaw();
          rxPdo.velocityOffset  = m_StagedCommand.GetVelocityOffsetRaw();

          // Extra data
          // rxPdo.controlWord = m_Controlword.GetRawControlword();
          // rxPdo.controlWord = m_StagedCommand.GetControlWordRaw();
          rxPdo.modeOfOperation = m_StagedCommand.GetModeOfOperationRaw();
          rxPdo.controlWord = m_StagedCommand.GetControlWordRaw();
          // rxPdo.modeOfOperation = static_cast<int8_t>(m_ModeOfOperation);
        }

        m_Bus->WriteRxPdo(m_Address, rxPdo);
        break;
      }

      default:
        std::stringstream ss;
        ss << "[IServo::UpdateWrite] Unsupported Rx Pdo type for '" << m_Name << "'" << std::endl;
        CONTROLLER_CORE_ERROR(ss.str());
        AddErrorToReading(Controller::Ethercat::DS402::ErrorType::RxPdoTypeError);
    }
  }

  void IServo::StageCommand(const Command& command) {

    std::lock_guard<std::recursive_mutex> lock(m_Mutex);
    // m_StagedCommand = command;
    m_StagedCommand.SetControlWordRaw(command.GetControlWordRaw());
    m_StagedCommand.SetTargetPositionRaw(command.GetTargetPositionRaw());
    m_StagedCommand.SetTargetVelocityRaw(command.GetTargetVelocityRaw());
    m_StagedCommand.SetModeOfOperationRaw(command.GetModeOfOperationRaw());
  }

  Reading IServo::GetReading() const {

    std::lock_guard<std::recursive_mutex> lock(m_ReadingMutex);
    return *(m_Reading.get());
  }

   void IServo::AutoConfigurePdoSizes() {

    auto pdoSizes = m_Bus->GetHardwarePdoSizes(static_cast<uint16_t>(m_Address));
    m_PdoInfo.rxPdoSize = pdoSizes.first;
    m_PdoInfo.txPdoSize = pdoSizes.second;
  }

  Controlword IServo::GetNextStateTransitionControlword(const DriveState& requestedDriveState,
                                                        const DriveState& currentDriveState) {

    Controlword controlword;
    controlword.SetAllFalse();

    switch (requestedDriveState) {
      case DriveState::SwitchOnDisabled:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled: {
            std::stringstream ss;
            ss << "[IServo::GetNextStateTransitionControlword] "
               << "drive state has already been reached for '" << m_Name << "'" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
            break;
          }
          case DriveState::ReadyToSwitchOn:
            controlword.SetStateTransition7();
            break;
          case DriveState::SwitchedOn:
            controlword.SetStateTransition10();
            break;
          case DriveState::OperationEnabled:
            controlword.SetStateTransition9();
            break;
          case DriveState::QuickStopActive:
            controlword.SetStateTransition12();
            break;
          case DS402::DriveState::Fault:
            controlword.SetStateTransition15();
            break;
          default:
            std::stringstream ss;
            // ss << "[Yaskawa:: GetNextStateTransitionControlword] "
            //    << "PDO state transition not implemented for '" << m_Name << "'\n"
            //    << "Current: " << currentDriveState << "\n"
            //    << "Requested: " << requestedDriveState << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
        }
        break;

      case DriveState::ReadyToSwitchOn:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            controlword.SetStateTransition2();
            break;
          case DriveState::ReadyToSwitchOn: {
            std::stringstream ss;
            ss << "[IServo:: GetNextStateTransitionControlword] "
               << "drive state has already been reached for '" << m_Name << "'" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
            break;
          }
          case DriveState::SwitchedOn:
            controlword.SetStateTransition6();
            break;
          case DriveState::OperationEnabled:
            controlword.SetStateTransition8();
            break;
          case DriveState::QuickStopActive:
            controlword.SetStateTransition12();
            break;
          case DriveState::Fault: {
            controlword.SetStateTransition15();
            break;
          }
          default:
            std::stringstream ss;
            // ss << "[IServo:: GetNextStateTransitionControlword] "
            //    << "PDO state transition not implemented for '" << m_Name << "'\n"
            //    << "Current: " << currentDriveState << "\n"
            //    << "Requested: " << requestedDriveState << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
        }
        break;

      case DriveState::SwitchedOn:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            controlword.SetStateTransition2();
            break;
          case DriveState::ReadyToSwitchOn:
            controlword.SetStateTransition3();
            break;
          case DriveState::SwitchedOn: {
            std::stringstream ss;
            ss << "[IServo:: GetNextStateTransitionControlword] "
               << "drive state has already been reached for '" << m_Name << "'" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
            break;
          }
          case DriveState::OperationEnabled:
            controlword.SetStateTransition5();
            break;
          case DriveState::QuickStopActive:
            controlword.SetStateTransition12();
            break;
          case DriveState::Fault:
            controlword.SetStateTransition15();
            break;
          default:
            std::stringstream os;
            // os << "[Yaskawa:: GetNextStateTransitionControlword] "
            //    << "PDO state transition not implemented for '" << m_Name << "'\n"
            //    << "Current: " << currentDriveState << "\n"
            //    << "Requested: " << requestedDriveState << std::endl;
            CONTROLLER_CORE_ERROR(os.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
        }
        break;

      case DriveState::OperationEnabled:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            controlword.SetStateTransition2();
            break;
          case DriveState::ReadyToSwitchOn:
            controlword.SetStateTransition3();
            break;
          case DriveState::SwitchedOn:
            controlword.SetStateTransition4();
            break;
          case DriveState::OperationEnabled: {
            std::stringstream ss;
            ss << "[IServo:: GetNextStateTransitionControlword] "
               << "drive state has already been reached for '" << m_Name << "'" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
            break;
          }
          case DriveState::QuickStopActive:
            controlword.SetStateTransition12();
            break;
          case DriveState::Fault:
            controlword.SetStateTransition15();
            break;
          default:
            std::stringstream ss;
            // ss << "[Yaskawa:: GetNextStateTransitionControlword] "
            //    << "PDO state transition not implemented for '" << m_Name << "'\n"
            //    << "Current: " << currentDriveState << "\n"
            //    << "Requested: " << requestedDriveState << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
        }
        break;

      case DriveState::QuickStopActive:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            controlword.SetStateTransition2();
            break;
          case DriveState::ReadyToSwitchOn:
            controlword.SetStateTransition3();
            break;
          case DriveState::SwitchedOn:
            controlword.SetStateTransition4();
            break;
          case DriveState::OperationEnabled:
            controlword.SetStateTransition11();
            break;
          case DriveState::QuickStopActive: {
            std::stringstream os;
            os << "[IServo:: GetNextStateTransitionControlword] "
               << "drive state has already been reached for '" << m_Name << "'" << std::endl;
            CONTROLLER_CORE_ERROR(os.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
            break;
          }
          case DriveState::Fault:
            controlword.SetStateTransition15();
            break;
          default:
            std::stringstream ss;
            // ss << "[Iservo:: GetNextStateTransitionControlword] "
            //    << "PDO state transition not implemented for '" << m_Name << "'\n"
            //    << "Current: " << currentDriveState << "\n"
            //    << "Requested: " << requestedDriveState << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::PdoStateTransitionError);
        }
        break;

      default:
        std::stringstream ss;
        ss << "[IServo::GetNextStateTransitionControlword] "
           << "PDO state cannot be reached for '" << m_Name << "'" << std::endl;
        CONTROLLER_CORE_ERROR(ss.str());
        AddErrorToReading(ErrorType::PdoStateTransitionError);
    }

    return controlword;
  }

  uint16_t IServo::GetTxPdoSize() {return m_PdoInfo.txPdoSize;}

  uint16_t IServo::GetRxPdoSize() {return m_PdoInfo.rxPdoSize;}

  void IServo::GetReading(Reading& reading) const {

    std::lock_guard<std::recursive_mutex> lock(m_ReadingMutex);
    reading = *(m_Reading.get());
  }

   bool IServo::SetControlwordViaSdo(Controlword& controlword) {
    
    return SendSdoWrite(OD_INDEX_CONTROLWORD, 0, false, controlword.GetRawControlword());
  }

  bool IServo::SetDriveStateViaSdo(const DriveState& driveState) {
    
    bool success = true;
    Statusword currentStatusword;
    success &= GetStatuswordViaSdo(currentStatusword);
    DriveState currentDriveState = currentStatusword.GetDriveState();

    // do the adequate state changes (via sdo) depending on the requested and
    // current drive states
    switch (driveState) {
      // Target: switch on disabled
      // This is the lowest state in which the state machine can be brought over
      // EtherCAT
      case DriveState::SwitchOnDisabled:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            success &= true;
            break;
          case DriveState::ReadyToSwitchOn:
            success &= StateTransitionViaSdo(StateTransition::_7);
            break;
          case DriveState::SwitchedOn:
            success &= StateTransitionViaSdo(StateTransition::_10);
            break;
          case DriveState::OperationEnabled:
            success &= StateTransitionViaSdo(StateTransition::_9);
            break;
          case DriveState::QuickStopActive:
            success &= StateTransitionViaSdo(StateTransition::_12);
            break;
          case DriveState::Fault:
            success &= StateTransitionViaSdo(StateTransition::_15);
            break;
          default:
            std::stringstream ss;
            ss << "[Iservo:SetDriveStateViaSdo] State Transition not implemented" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::SdoStateTransitionError);
            success = false;
        }
        break;

      case DriveState::ReadyToSwitchOn:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            success &= StateTransitionViaSdo(StateTransition::_2);
            break;
          case DriveState::ReadyToSwitchOn:
            success &= true;
            break;
          case DriveState::SwitchedOn:
            success &= StateTransitionViaSdo(StateTransition::_6);
            break;
          case DriveState::OperationEnabled:
            success &= StateTransitionViaSdo(StateTransition::_8);
            break;
          case DriveState::QuickStopActive:
            success &= StateTransitionViaSdo(StateTransition::_12);
            success &= StateTransitionViaSdo(StateTransition::_2);
            break;
          case DriveState::Fault:
            success &= StateTransitionViaSdo(StateTransition::_15);
            success &= StateTransitionViaSdo(StateTransition::_2);
            break;
          default:
            std::stringstream ss;
            ss << "[Yaskawa::SetDriveStateViaSdo] State Transition not implemented" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::SdoStateTransitionError);
            success = false;
        }
        break;

      case DriveState::SwitchedOn:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            break;
          case Controller::Ethercat::DS402::DriveState::ReadyToSwitchOn:
            success &= StateTransitionViaSdo(StateTransition::_3);
            break;
          case DriveState::SwitchedOn:
            success &= true;
            break;
          case DriveState::OperationEnabled:
            success &= StateTransitionViaSdo(StateTransition::_5);
            break;
          case DriveState::QuickStopActive:
            success &= StateTransitionViaSdo(StateTransition::_12);
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            break;
          case DriveState::Fault:
            success &= StateTransitionViaSdo(StateTransition::_15);
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            break;
          default:
            std::stringstream ss;
            ss << "[Yaskawa::SetDriveStateViaSdo] State Transition not implemented" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::SdoStateTransitionError);
            success = false;
        }
        break;

      case DriveState::OperationEnabled:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            success &= StateTransitionViaSdo(StateTransition::_4);
            break;
          case DriveState::ReadyToSwitchOn:
            success &= StateTransitionViaSdo(StateTransition::_3);
            success &= StateTransitionViaSdo(StateTransition::_4);
            break;
          case DriveState::SwitchedOn:
            success &= StateTransitionViaSdo(Controller::Ethercat::DS402::StateTransition::_4);
            break;
          case Controller::Ethercat::DS402::DriveState::OperationEnabled:
            success &= true;
            break;
          case DriveState::QuickStopActive:
            success &= StateTransitionViaSdo(StateTransition::_12);
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            success &= StateTransitionViaSdo(StateTransition::_4);
            break;
          case DriveState::Fault:
            success &= StateTransitionViaSdo(StateTransition::_15);
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            success &= StateTransitionViaSdo(StateTransition::_4);
            break;
          default:
            std::stringstream ss;
            ss << "[Yaskawa::SetDriveStateViaSdo] State Transition not implemented" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::SdoStateTransitionError);
            success = false;
        }
        break;

      case DriveState::QuickStopActive:
        switch (currentDriveState) {
          case DriveState::SwitchOnDisabled:
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            success &= StateTransitionViaSdo(StateTransition::_4);
            success &= StateTransitionViaSdo(StateTransition::_11);
            break;
          case DriveState::ReadyToSwitchOn:
            success &= StateTransitionViaSdo(StateTransition::_3);
            success &= StateTransitionViaSdo(StateTransition::_4);
            success &= StateTransitionViaSdo(StateTransition::_11);
            break;
          case DriveState::SwitchedOn:
            success &= StateTransitionViaSdo(StateTransition::_4);
            success &= StateTransitionViaSdo(StateTransition::_11);
            break;
          case DriveState::OperationEnabled:
            success &= StateTransitionViaSdo(StateTransition::_11);
            break;
          case Controller::Ethercat::DS402::DriveState::QuickStopActive:
            success &= true;
            break;
          case DriveState::Fault:
            success &= StateTransitionViaSdo(StateTransition::_15);
            success &= StateTransitionViaSdo(StateTransition::_2);
            success &= StateTransitionViaSdo(StateTransition::_3);
            success &= StateTransitionViaSdo(StateTransition::_4);
            success &= StateTransitionViaSdo(StateTransition::_11);
            break;
          default:
            std::stringstream ss;
            ss << "[IServo::SetDriveStateViaSdo] State Transition not implemented" << std::endl;
            CONTROLLER_CORE_ERROR(ss.str());
            AddErrorToReading(ErrorType::SdoStateTransitionError);
            success = false;
        }
        break;

      default:
        std::stringstream ss;
        ss << "[IServo::SetDriveStateViaSdo] State Transition not implemented" << std::endl;
        AddErrorToReading(ErrorType::SdoStateTransitionError);
        success = false;
    }
    return success;
  }

  bool IServo::StateTransitionViaSdo(const StateTransition& stateTransition) {
    
    Controlword controlword;
    switch (stateTransition) {
      case StateTransition::_2:
        controlword.SetStateTransition2();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_3:
        controlword.SetStateTransition3();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_4:
        controlword.SetStateTransition4();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_5:
        controlword.SetStateTransition5();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_6:
        controlword.SetStateTransition6();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_7:
        controlword.SetStateTransition7();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_8:
        controlword.SetStateTransition8();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_9:
        controlword.SetStateTransition9();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_10:
        controlword.SetStateTransition10();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_11:
        controlword.SetStateTransition11();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_12:
        controlword.SetStateTransition12();
        return SetControlwordViaSdo(controlword);
        break;
      case StateTransition::_15:
        controlword.SetStateTransition15();
        return SetControlwordViaSdo(controlword);
        break;
      default:
        std::stringstream ss;
        ss << "[IServo::StateTransitionViaSdo] State Transition not implemented" << std::endl;
        AddErrorToReading(ErrorType::SdoStateTransitionError);
        return false;
    }
  }

  bool IServo::SetDriveStateViaPdo(const DriveState& driveState, const bool waitForState) {
    
    bool success = false;
    /*
    ** locking the mutex_
    ** This is not done with a lock_guard here because during the waiting time the
    ** mutex_ must be unlocked periodically such that PDO writing (and thus state
    ** changes) may occur at all!
    */
    m_Mutex.lock();

    m_StateChangeSuccessful = false;
    m_ConductStateChange = true;
    m_TargetDriveState = driveState;
    m_HasRead = false;
    m_DriveStateChangeTimePoint = std::chrono::steady_clock::now();

    // set a temporary time point to prevent getting caught in an infinite loop
    auto driveStateChangeStartTimePoint = std::chrono::steady_clock::now();

    if (!waitForState) {
      m_Mutex.unlock();
      return true;
    }

    while (true) {
      if (m_StateChangeSuccessful) {
        success = true;
        break;
      }

      if ((std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() -
                                                                 driveStateChangeStartTimePoint))
              .count() > m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".driveStateChangeMaxTimeout").getValue()) {
        break;
      }

      m_Mutex.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      m_Mutex.lock();
    }    // while

    m_Mutex.unlock();
    return success;
  }

  void IServo::EngagePdoStateMachine() {

    std::lock_guard<std::recursive_mutex> lock(m_Mutex);

    auto microsecondsSinceChange = (std::chrono::duration_cast<std::chrono::microseconds>(
                                        std::chrono::steady_clock::now() - m_DriveStateChangeTimePoint))
                                       .count();

    const DriveState currentDriveState = m_Reading->GetDriveState();

    if (currentDriveState == m_TargetDriveState) {
      ++m_NumberOfSuccessfulTargetStateReadings;
      if (m_NumberOfSuccessfulTargetStateReadings >= m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".minNumberOfSuccessfulTargetStateReadings").getValue()) {
        m_ConductStateChange = false;
        m_NumberOfSuccessfulTargetStateReadings = 0;
        m_StateChangeSuccessful = true;
        return;
      }
    } else if (microsecondsSinceChange > m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".driveStateChangeMinTimeout").getValue()) {
      m_Controlword = GetNextStateTransitionControlword(m_TargetDriveState, currentDriveState);
      m_DriveStateChangeTimePoint = std::chrono::steady_clock::now();
    }

    m_HasRead = false;
  }

  void IServo::AddErrorToReading(const ErrorType& errorType) {
    
    m_Mutex.lock();
    m_Reading->AddError(errorType);
    m_Mutex.unlock();
  }

}