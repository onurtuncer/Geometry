/* ----------------------------------------------------------------------------*
  Copyright 2023 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef _CONFIGURATION_402_H__
#define _CONFIGURATION_402_H__

#include "ModeOfOperation.h"
#include "PDOType.h"

#include <cstdint>
#include <utility>
#include <vector>

namespace Controller::Ethercat::DS402 {

  class Configuration {
  public:
    RxPdoTypeEnum rxPdoType{RxPdoTypeEnum::NA};
    std::vector<ModeOfOperation> modesOfOperation;
    TxPdoTypeEnum txPdoType{TxPdoTypeEnum::NA};
    unsigned int configRunSdoVerifyTimeout{20000};
    bool printDebugMessages{true};
    unsigned int driveStateChangeMinTimeout{20000};
    unsigned int minNumberOfSuccessfulTargetStateReadings{10};
    unsigned int driveStateChangeMaxTimeout{300000};
    bool forceAppendEqualError{true};
    bool forceAppendEqualFault{false};
    unsigned int errorStorageCapacity{100};
    unsigned int faultStorageCapacity{100};
    int32_t positionEncoderResolution{1};
    bool useRawCommands{false};
    std::pair<double, double> gearRatio{1.0, 1.0};
    std::pair<std::string, std::string> encoderType{"absolute", "multiturn"};

    double motorConstant{1};
    double workVoltage{48.0};
    int polePairs{0};
    double speedConstant{0};
    double nominalCurrentA{0};
    double torqueConstantNmA{0};
    double maxCurrentA{0};
    std::pair<bool, double> minPosition{false,0};
    std::pair<bool, double> maxPosition{false,0};
    
    int32_t slowJogSpeed{0};
    uint32_t fastJogSpeed{0};
    uint32_t maxProfileVelocity{0};
    uint32_t quickStopDecel{10000};
    uint32_t profileDecel{100};
    uint32_t  profileAcceleration{100};
    uint32_t  profileVelocity{500};  
    uint32_t followErrorWindow{2000};
    int8_t  homeMethod{28};
    uint32_t homeSpeed{500};
    uint32_t homingAcceleration{50};
    int32_t homeOffset{0};


    double currentPGainSI{1.171880};
    double currentIGainSI{3906.250};
    double positionPGainSI{1.5};
    double positionIGainSI{0.78};
    double positionDGainSI{0.016};
    double velocityPGainSI{0.02};
    double velocityIGainSI{0.5};

    unsigned int channelIndex{0};
    unsigned int trajectoryIndex{0};
    int positionScaleFactorNumerator{1};
    int positionScaleFactorDenominator{1};

    int velocityScaleFactorNumerator{1};
    int velocityScaleFactorDenominator{1};

    int stepScaleFactorNumerator{1};
    int stepScaleFactorDenominator{1};

    int torqueScaleFactor{1};
    int currentScaleFactor{1};

    char axisName;
    std::string axisType;

    double stepTargetVelocity{0};
    double stepTargetAcceleration{0};
    double stepMaxVelocity{0};
    double stepMaxAcceleration{0};
    double stepMaxJerk{0};

    double jogTargetVelocity{0};
    double jogTargetAcceleration{0};
    double jogMaxVelocity{0};
    double jogMaxAcceleration{0};
    double jogMaxJerk{0};




    bool SanityCheck(bool silent = false) const;

    std::pair<RxPdoTypeEnum, TxPdoTypeEnum> GetPdoTypeSolution() const;

  public:
    friend std::ostream& operator<<(std::ostream& os, const Configuration& configuration);
  };

}    // namespace Controller::Ethercat::DS402

#endif    // _CONFIGURATION_402_H__
