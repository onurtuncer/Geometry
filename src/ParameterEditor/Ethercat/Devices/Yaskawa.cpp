/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN
  Use of this software is restricted to MILTEKSAN
  Provides context to visitor pattern implementation such that variable/function
  names and values can be passed alongside within the correct scope
  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Written by Bites, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#include "Yaskawa.h"
#include "Core/Log/Log.h"
#include <sstream>

namespace Controller::Ethercat::Devices {

  std::shared_ptr<Yaskawa> Yaskawa::DeviceFromParameterManager(std::shared_ptr<ParameterManager> pm,
                                                               const std::string& configPath,
                                                               const std::string& name,
                                                               const uint32_t address
                                                               ) {

    auto yaskawa = std::make_shared<Yaskawa>(name, address, configPath, pm);
    yaskawa->LoadConfiguration();
    return yaskawa;
  }

  Yaskawa::Yaskawa(const std::string& name, const uint32_t address, const std::string& configPath, std::shared_ptr<ParameterManager> pm) 
    : IServo(name, address, configPath, pm) {
    
    m_PdoInfo.moduleId = 0x00333333;
  }

  bool Yaskawa::Startup() {

    bool success = true;

    m_Bus->SetState(EC_STATE_PRE_OP, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    m_Bus->WaitForState(EC_STATE_PRE_OP, 0);

    // PDO mapping

    auto rxPdoType = m_ParameterManagerPtr->GetParameter<Ethercat::DS402::RxPdoTypeEnum>(m_ConfigPath + ".rxPdoType").getValue();
    auto txPdoType = m_ParameterManagerPtr->GetParameter<Ethercat::DS402::TxPdoTypeEnum>(m_ConfigPath + ".txPdoType").getValue();

    success &= MapPdos(rxPdoType, txPdoType);

    // Set Interpolation
    success &= SendSdoWrite(OD_INDEX_INTERPOLATION_TIME_PERIOD,
                              0x01,
                              false,
                              static_cast<uint8_t>(2));

    success &= SendSdoWrite(OD_INDEX_INTERPOLATION_TIME_PERIOD,
                              0x02,
                              false,
                              static_cast<int8_t>(-3));


    // // Set initial mode of operation
    // success &= SendSdoWrite(OD_INDEX_MODES_OF_OPERATION,
    //                           0x00,
    //                           false,
    //                           static_cast<int8_t>(m_Configuration.modesOfOperation[0]));

    AutoConfigurePdoSizes();

    if (!success) {
      std::stringstream ss;
      ss << "[Yaskawa::PreStartupOnlineConfiguration] hardware configuration of '" << m_Name << "' not successful!"
         << std::endl;
      CONTROLLER_CORE_ERROR(ss.str());
      AddErrorToReading(DS402::ErrorType::ConfigurationError);
    }

    return success;
  }

}    // namespace Controller::Ethercat::Devices