/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN
  Use of this software is restricted to MILTEKSAN
  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Written by Bites, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#include <sstream>
#include "Core/Log/Log.h"
#include "Ethercat/DS401/ConfigurationParser.h"
#include "DeltaIO.h"


namespace Controller::Ethercat::Devices {

 /*  std::shared_ptr<DeltaIO> DeltaIO::DeviceFromFile(const std::string& configFile, const std::string& name, const uint32_t address) {

    auto delta = std::make_shared<DeltaIO>(name, address);

    if (!delta->LoadConfigFile(configFile)) {

      std::stringstream ss;
      ss << "[DeltaIO::DeviceFromFile] loading config file '" << configFile << "' for '" << name
                                                              << "' not successful." << std::endl;
      throw std::runtime_error("[DeltaIO::DeviceFromFile] config file loading error");
   }

   return delta;
 } */

  std::shared_ptr<DeltaIO> DeltaIO::DeviceFromParameterManager(std::shared_ptr<ParameterManager> pm,
                                                               const std::string& configPath,
                                                               const std::string& name, 
                                                               const uint32_t address) {

    auto delta = std::make_shared<DeltaIO>(name, address, configPath, pm);

    if (!delta->LoadConfigurationFromParameterManager()) {

      std::stringstream ss;
      ss << "[DeltaIO::DeviceFromFile] loading configuration '" <<  "' for '" << name
                                                              << "' not successful." << std::endl;
      throw std::runtime_error("[DeltaIO::DeviceFromFile] configuration load error");
   }

   return delta;
 }

  DeltaIO::DeltaIO(const std::string& name, const uint32_t address, const std::string& configPath, std::shared_ptr<ParameterManager> pm) 
  : ParametricDevice(pm, configPath){

    m_Address = address;
    m_Name = name;

    m_PdoInfo.rxPdoId = RX_PDO_ID;
    m_PdoInfo.txPdoId = TX_PDO_ID;
    m_PdoInfo.moduleId = 0x00222222;
  }

  auto DeltaIO::Startup() -> bool {

    AutoConfigurePdoSizes();

    bool success = true;

    success &= m_Bus->WaitForState(EC_STATE_PRE_OP, m_Address, 50, 0.05);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    unsigned int timeOut = 20000;
    // clear SM PDO mapping
    uint8_t uint8val;
    uint16_t uint16val;
    uint32_t uint32val;

    // uint8val = 0x00;
    success &= SendSdoWrite(0x1C12, 0x00, FALSE, 0x00);

    // uint8val = 0x00;
    success &= SendSdoWrite(0x1C13, 0x00, FALSE, 0x00);

    // uint8val = 0x00;
    success &= SendSdoWrite(0x1b00, 0x00, FALSE, 0x00);

    // uint8val = 0x00;
    success &= SendSdoWrite(0x1b01, 0x00, FALSE, 0x00); 

//mekay mapping ;  2 digital input , 1 anaolog handweel
    success &= SendSdoWrite(0x1a00, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1a00, 0x01, FALSE, 0x60000108);
    success &= SendSdoWrite(0x1a00, 0x02, FALSE, 0x60000208);
    success &= SendSdoWrite(0x1a00, 0x00, FALSE, 0x02);

    success &= SendSdoWrite(0x1a10, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1a10, 0x01, FALSE, 0x60200108);
    success &= SendSdoWrite(0x1a10, 0x02, FALSE, 0x60200208);
    success &= SendSdoWrite(0x1a10, 0x00, FALSE, 0x02);

    success &= SendSdoWrite(0x1620, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1620, 0x01, FALSE, 0x70400108);
    success &= SendSdoWrite(0x1620, 0x02, FALSE, 0x70400208);
    success &= SendSdoWrite(0x1620, 0x00, FALSE, 0x02);


    #if IO_CONFIG == 1

    success &= SendSdoWrite(0x1a30, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1a30, 0x01, FALSE, 0x20602210);
    success &= SendSdoWrite(0x1a30, 0x02, FALSE, 0x20602310);
    success &= SendSdoWrite(0x1a30, 0x03, FALSE, 0x20602410);
    success &= SendSdoWrite(0x1a30, 0x04, FALSE, 0x20602510);
    success &= SendSdoWrite(0x1a30, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1630, 0x01, FALSE, 0x20602b10);
    success &= SendSdoWrite(0x1630, 0x02, FALSE, 0x20602c10);
    success &= SendSdoWrite(0x1630, 0x03, FALSE, 0x20602d10);
    success &= SendSdoWrite(0x1630, 0x04, FALSE, 0x20602e10);
    success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1c12, 0x01, FALSE, 0x1b01);
    success &= SendSdoWrite(0x1c12, 0x02, FALSE, 0x1620);
    success &= SendSdoWrite(0x1c12, 0x03, FALSE, 0x1630);
    success &= SendSdoWrite(0x1c12, 0x00, FALSE, 0x03);

    success &= SendSdoWrite(0x1c13, 0x01, FALSE, 0x1b00);
    success &= SendSdoWrite(0x1c13, 0x02, FALSE, 0x1a00);
    success &= SendSdoWrite(0x1c13, 0x03, FALSE, 0x1a10);
    success &= SendSdoWrite(0x1c13, 0x04, FALSE, 0x1a30);
    success &= SendSdoWrite(0x1c13, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x8000, 0x01, FALSE, 0x67);
    success &= SendSdoWrite(0x8020, 0x01, FALSE, 0x67);
    success &= SendSdoWrite(0x8040, 0x01, FALSE, 0x6c);
    success &= SendSdoWrite(0x8060, 0x01, FALSE, 0x07);

    #elif IO_CONFIG == 2

    success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1630, 0x01, FALSE, 0x70600108);
    success &= SendSdoWrite(0x1630, 0x02, FALSE, 0x70600208);
    success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x02);

    success &= SendSdoWrite(0x1a40, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1a40, 0x01, FALSE, 0x20800d10);
    success &= SendSdoWrite(0x1a40, 0x02, FALSE, 0x20800e10);
    success &= SendSdoWrite(0x1a40, 0x03, FALSE, 0x20800f10);
    success &= SendSdoWrite(0x1a40, 0x04, FALSE, 0x20801010);
    success &= SendSdoWrite(0x1a40, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1640, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1640, 0x01, FALSE, 0x20800b10);
    success &= SendSdoWrite(0x1640, 0x02, FALSE, 0x20800c10);
    success &= SendSdoWrite(0x1640, 0x00, FALSE, 0x02);

    success &= SendSdoWrite(0x1a50, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1a50, 0x01, FALSE, 0x20a02210);
    success &= SendSdoWrite(0x1a50, 0x02, FALSE, 0x20a02310);
    success &= SendSdoWrite(0x1a50, 0x03, FALSE, 0x20a02410);
    success &= SendSdoWrite(0x1a50, 0x04, FALSE, 0x20a02510);
    success &= SendSdoWrite(0x1a50, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1650, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1650, 0x01, FALSE, 0x20a02b10);
    success &= SendSdoWrite(0x1650, 0x02, FALSE, 0x20a02c10);
    success &= SendSdoWrite(0x1650, 0x03, FALSE, 0x20a02d10);
    success &= SendSdoWrite(0x1650, 0x04, FALSE, 0x20a02e10);
    success &= SendSdoWrite(0x1650, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1c12, 0x01, FALSE, 0x1b01);
    success &= SendSdoWrite(0x1c12, 0x02, FALSE, 0x1620);
    success &= SendSdoWrite(0x1c12, 0x03, FALSE, 0x1630);
    success &= SendSdoWrite(0x1c12, 0x04, FALSE, 0x1640);
    success &= SendSdoWrite(0x1c12, 0x05, FALSE, 0x1650);
    success &= SendSdoWrite(0x1c12, 0x00, FALSE, 0x05);

    success &= SendSdoWrite(0x1c13, 0x01, FALSE, 0x1b00);
    success &= SendSdoWrite(0x1c13, 0x02, FALSE, 0x1a00);
    success &= SendSdoWrite(0x1c13, 0x03, FALSE, 0x1a10);
    success &= SendSdoWrite(0x1c13, 0x04, FALSE, 0x1a40);
    success &= SendSdoWrite(0x1c13, 0x05, FALSE, 0x1a50);
    success &= SendSdoWrite(0x1c13, 0x00, FALSE, 0x05);

    success &= SendSdoWrite(0x8000, 0x01, FALSE, 0x67);
    success &= SendSdoWrite(0x8020, 0x01, FALSE, 0x67);
    success &= SendSdoWrite(0x8040, 0x01, FALSE, 0x6c);
    success &= SendSdoWrite(0x8060, 0x01, FALSE, 0x6c);
    success &= SendSdoWrite(0x8080, 0x01, FALSE, 0x0b);
    success &= SendSdoWrite(0x80a0, 0x01, FALSE, 0x07);



    #elif IO_CONFIG == 0

    success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1630, 0x01, FALSE, 0x70600108);
    success &= SendSdoWrite(0x1630, 0x02, FALSE, 0x70600208);
    success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x02);

    success &= SendSdoWrite(0x1a40, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1a40, 0x01, FALSE, 0x20800d10);
    success &= SendSdoWrite(0x1a40, 0x02, FALSE, 0x20800e10);
    success &= SendSdoWrite(0x1a40, 0x03, FALSE, 0x20800f10);
    success &= SendSdoWrite(0x1a40, 0x04, FALSE, 0x20801010);
    success &= SendSdoWrite(0x1a40, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1640, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1640, 0x01, FALSE, 0x20800b10);
    success &= SendSdoWrite(0x1640, 0x02, FALSE, 0x20800c10);
    success &= SendSdoWrite(0x1640, 0x00, FALSE, 0x02);

    success &= SendSdoWrite(0x1a50, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1a50, 0x01, FALSE, 0x20a02210);
    success &= SendSdoWrite(0x1a50, 0x02, FALSE, 0x20a02310);
    success &= SendSdoWrite(0x1a50, 0x03, FALSE, 0x20a02410);
    success &= SendSdoWrite(0x1a50, 0x04, FALSE, 0x20a02510);
    success &= SendSdoWrite(0x1a50, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1650, 0x00, FALSE, 0x00);
    success &= SendSdoWrite(0x1650, 0x01, FALSE, 0x20a02b10);
    success &= SendSdoWrite(0x1650, 0x02, FALSE, 0x20a02c10);
    success &= SendSdoWrite(0x1650, 0x03, FALSE, 0x20a02d10);
    success &= SendSdoWrite(0x1650, 0x04, FALSE, 0x20a02e10);
    success &= SendSdoWrite(0x1650, 0x00, FALSE, 0x04);

    success &= SendSdoWrite(0x1c12, 0x01, FALSE, 0x1b01);
    success &= SendSdoWrite(0x1c12, 0x02, FALSE, 0x1620);
    success &= SendSdoWrite(0x1c12, 0x03, FALSE, 0x1630);
    success &= SendSdoWrite(0x1c12, 0x04, FALSE, 0x1640);
    success &= SendSdoWrite(0x1c12, 0x05, FALSE, 0x1650);
    success &= SendSdoWrite(0x1c12, 0x00, FALSE, 0x05);

    success &= SendSdoWrite(0x1c13, 0x01, FALSE, 0x1b00);
    success &= SendSdoWrite(0x1c13, 0x02, FALSE, 0x1a00);
    success &= SendSdoWrite(0x1c13, 0x03, FALSE, 0x1a10);
    success &= SendSdoWrite(0x1c13, 0x04, FALSE, 0x1a40);
    success &= SendSdoWrite(0x1c13, 0x05, FALSE, 0x1a50);
    success &= SendSdoWrite(0x1c13, 0x00, FALSE, 0x05);

    success &= SendSdoWrite(0x8000, 0x01, FALSE, 0x67);
    success &= SendSdoWrite(0x8020, 0x01, FALSE, 0x67);
    success &= SendSdoWrite(0x8040, 0x01, FALSE, 0x6c);
    success &= SendSdoWrite(0x8060, 0x01, FALSE, 0x6c);
    success &= SendSdoWrite(0x8080, 0x01, FALSE, 0x0b);
    success &= SendSdoWrite(0x80a0, 0x01, FALSE, 0x07);


    // success &= SendSdoWrite(0x1a30, 0x00, FALSE, 0x00);
    // success &= SendSdoWrite(0x1a30, 0x01, FALSE, 0x20600d10);
    // success &= SendSdoWrite(0x1a30, 0x02, FALSE, 0x20600e10);
    // success &= SendSdoWrite(0x1a30, 0x03, FALSE, 0x20600f10);
    // success &= SendSdoWrite(0x1a30, 0x04, FALSE, 0x20601010);
    // success &= SendSdoWrite(0x1a30, 0x00, FALSE, 0x04);

    // success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x00);
    // success &= SendSdoWrite(0x1630, 0x01, FALSE, 0x20600b10);
    // success &= SendSdoWrite(0x1630, 0x02, FALSE, 0x20600c10);
    // success &= SendSdoWrite(0x1630, 0x00, FALSE, 0x02);


    // success &= SendSdoWrite(0x1a40, 0x00, FALSE, 0x00);
    // success &= SendSdoWrite(0x1a40, 0x01, FALSE, 0x20802210);
    // success &= SendSdoWrite(0x1a40, 0x02, FALSE, 0x20802310);
    // success &= SendSdoWrite(0x1a40, 0x03, FALSE, 0x20802410);
    // success &= SendSdoWrite(0x1a40, 0x04, FALSE, 0x20802510);
    // success &= SendSdoWrite(0x1a40, 0x00, FALSE, 0x04);

    // success &= SendSdoWrite(0x1640, 0x00, FALSE, 0x00);
    // success &= SendSdoWrite(0x1640, 0x01, FALSE, 0x20802b10);
    // success &= SendSdoWrite(0x1640, 0x02, FALSE, 0x20802c10);
    // success &= SendSdoWrite(0x1640, 0x03, FALSE, 0x20802d10);
    // success &= SendSdoWrite(0x1640, 0x04, FALSE, 0x20802e10);
    // // success &= SendSdoWrite(0x1640, 0x05, FALSE, 0x20802010); // 31
    // // success &= SendSdoWrite(0x1640, 0x06, FALSE, 0x20802110); // 32
    // // success &= SendSdoWrite(0x1640, 0x05, FALSE, 0x20802110);
    // success &= SendSdoWrite(0x1640, 0x00, FALSE, 0x04);

    // success &= SendSdoWrite(0x1c12, 0x01, FALSE, 0x1b01);
    // success &= SendSdoWrite(0x1c12, 0x02, FALSE, 0x1620);
    // success &= SendSdoWrite(0x1c12, 0x03, FALSE, 0x1630);
    // success &= SendSdoWrite(0x1c12, 0x04, FALSE, 0x1640);
    // // success &= SendSdoWrite(0x1c12, 0x05, FALSE, 0x1650);
    // success &= SendSdoWrite(0x1c12, 0x00, FALSE, 0x04);

    // success &= SendSdoWrite(0x1c13, 0x01, FALSE, 0x1b00);
    // success &= SendSdoWrite(0x1c13, 0x02, FALSE, 0x1a00);
    // success &= SendSdoWrite(0x1c13, 0x03, FALSE, 0x1a10);
    // success &= SendSdoWrite(0x1c13, 0x04, FALSE, 0x1a30);
    // success &= SendSdoWrite(0x1c13, 0x05, FALSE, 0x1a40);
    // success &= SendSdoWrite(0x1c13, 0x00, FALSE, 0x05);

    // success &= SendSdoWrite(0x8000, 0x01, FALSE, 0x67);
    // success &= SendSdoWrite(0x8020, 0x01, FALSE, 0x67);
    // success &= SendSdoWrite(0x8040, 0x01, FALSE, 0x6d);
    // success &= SendSdoWrite(0x8060, 0x01, FALSE, 0x0b);
    // success &= SendSdoWrite(0x8080, 0x01, FALSE, 0x07);

#endif



   
    // success &= m_Bus->WaitForState(EC_STATE_SAFE_OP, m_Address, 50, 0.05);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return success;
  }

  auto DeltaIO::UpdateWrite() -> void {

    RxPdo rxPdo{};
    std::lock_guard<std::mutex> stagedCmdLock(m_ReadWriteMutex);

    rxPdo = m_StagedCommand;

    m_Bus->WriteRxPdo(m_Address, rxPdo);
  }

  auto DeltaIO::UpdateRead() -> void {

    TxPdo txPdo{};
    m_Bus->ReadTxPdo(m_Address, txPdo);
    m_Reading = txPdo;
    

  }

  auto DeltaIO::Shutdown() -> void {
    // Do nothing
  }

  void DeltaIO::StageCommand(const RxPdo& command) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand = command;
  }

  DeltaIO::TxPdo DeltaIO::GetReading() const {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    return m_Reading;
  }

  void DeltaIO::GetReading(TxPdo& reading) const {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    reading = m_Reading;
  }

 /*  bool DeltaIO::LoadConfigFile(const std::string& fileName) {

    Controller::Ethercat::DS401::ConfigurationParser configurationParser(fileName);
    return LoadConfiguration(configurationParser.GetConfiguration());
  } */

  bool DeltaIO::LoadConfigurationFromParameterManager() {

    try{

        m_Configuration.configRunSdoVerifyTimeout       = m_ParameterManagerPtr->GetParameter<unsigned int>(m_ConfigPath + ".configRunSdoVerifyTimeOut").getValue();
        m_Configuration.numberOfDigitalInputs           = m_ParameterManagerPtr->GetParameter<uint8_t>(m_ConfigPath + ".numberOfDigitalInputs").getValue();
        m_Configuration.numberOfDigitalOutputs          = m_ParameterManagerPtr->GetParameter<uint8_t>(m_ConfigPath + ".numberOfDigitalOutputs").getValue();
        m_Configuration.numberOfAnalogInputs            = m_ParameterManagerPtr->GetParameter<uint8_t>(m_ConfigPath + ".numberOfAnalogInputs").getValue();
        m_Configuration.numberOfAnalogOutputs           = m_ParameterManagerPtr->GetParameter<uint8_t>(m_ConfigPath + ".numberOfAnalogOutputs").getValue();
        m_Configuration.digitalInputMappingStartIndex   = m_ParameterManagerPtr->GetParameter<uint8_t>(m_ConfigPath + ".digitalInputMappingStartIndex").getValue();
        m_Configuration.analogInputMappingStartIndex    = m_ParameterManagerPtr->GetParameter<uint8_t>(m_ConfigPath + ".analogInputMappingStartIndex").getValue();
        m_Configuration.analogOutputMappingStartIndex   = m_ParameterManagerPtr->GetParameter<uint8_t>(m_ConfigPath + ".analogOutputMappingStartIndex").getValue();

       return true;

    }catch(...){
      return false;
    }
    
  }

  // Controller::Ethercat::DS401::Configuration DeltaIO::GetConfiguration() const { return m_Configuration; }

  // bool DeltaIO::LoadConfigNode(YAML::Node configNode) {

  //   Controller::Ethercat::DS401::ConfigurationParser configurationParser(configNode);
  //   return LoadConfiguration(configurationParser.GetConfiguration());
  // }

  void DeltaIO::AutoConfigurePdoSizes() {

    auto pdoSizes = m_Bus->GetHardwarePdoSizes(static_cast<uint16_t>(m_Address));
    m_PdoInfo.rxPdoSize = pdoSizes.first;
    m_PdoInfo.txPdoSize = pdoSizes.second;
  }

  uint16_t DeltaIO::GetTxPdoSize() {

    return m_PdoInfo.txPdoSize;
  }

  uint16_t DeltaIO::GetRxPdoSize() {

    return m_PdoInfo.rxPdoSize;
  }

  void DeltaIO::SetDigitalOutput1(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_1 = value;
  }

  void DeltaIO::SetDigitalOutput2(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_2 = value;
  }

  void DeltaIO::SetDigitalOutput3(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_3 = value;
  }

  void DeltaIO::SetDigitalOutput4(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_4 = value;
  }

  void DeltaIO::SetDigitalOutput5(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_5 = value;
  }

  void DeltaIO::SetDigitalOutput6(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_6 = value;
  }

  void DeltaIO::SetDigitalOutput7(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_7 = value;
  }

  void DeltaIO::SetDigitalOutput8(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_8 = value;
  }

  void DeltaIO::SetDigitalOutput9(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_9 = value;
  }

  void DeltaIO::SetDigitalOutput10(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_10 = value;
  }

  void DeltaIO::SetDigitalOutput11(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_11 = value;
  }

  void DeltaIO::SetDigitalOutput12(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_12 = value;
  }

  void DeltaIO::SetDigitalOutput13(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_13 = value;
  }

  void DeltaIO::SetDigitalOutput14(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_14 = value;
  }

  void DeltaIO::SetDigitalOutput15(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_15 = value;
  }

  void DeltaIO::SetDigitalOutput16(const bool value) {

    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_16 = value;
  }
  #if IO_CONFIG == 2 || IO_CONFIG == 0
  void DeltaIO::SetDigitalOutput17(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_17 = value;
  }

void DeltaIO::SetDigitalOutput18(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_18 = value;
  }

  void DeltaIO::SetDigitalOutput19(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_19 = value;
  }

  void DeltaIO::SetDigitalOutput20(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_20 = value;
  }

  void DeltaIO::SetDigitalOutput21(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_21 = value;
  }

  void DeltaIO::SetDigitalOutput22(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_22 = value;
  }

  void DeltaIO::SetDigitalOutput23(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_23 = value;
  }

  void DeltaIO::SetDigitalOutput24(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_24 = value;
  }

  void DeltaIO::SetDigitalOutput25(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_25 = value;
  }

  void DeltaIO::SetDigitalOutput26(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_26 = value;
  }

  void DeltaIO::SetDigitalOutput27(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_27 = value;
  }

  void DeltaIO::SetDigitalOutput28(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_28 = value;
  }

  void DeltaIO::SetDigitalOutput29(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_29 = value;
  }

  void DeltaIO::SetDigitalOutput30(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_30 = value;
  }

  void DeltaIO::SetDigitalOutput31(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_31 = value;
  }

  void DeltaIO::SetDigitalOutput32(const bool value) {
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    m_StagedCommand.digitalOutput_32 = value;
  }
#elif IO_CONFIG == 0
#elif IO_CONFIG == 1
#endif
  bool DeltaIO::GetDigitalInput1() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_1;
    return result;
  }

  bool DeltaIO::GetDigitalInput2() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_2;
    return result;
  }

  bool DeltaIO::GetDigitalInput3() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_3;
    return result;
  }

  bool DeltaIO::GetDigitalInput4() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_4;
    return result;
  }

  bool DeltaIO::GetDigitalInput5() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_5;
    return result;
  }

  bool DeltaIO::GetDigitalInput6() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_6;
    return result;
  }

  bool DeltaIO::GetDigitalInput7() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_7;
    return result;
  }

  bool DeltaIO::GetDigitalInput8() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_8;
    return result;
  }

  bool DeltaIO::GetDigitalInput9() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_9;
    return result;
  }

  bool DeltaIO::GetDigitalInput10() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_10;
    return result;
  }

  bool DeltaIO::GetDigitalInput11() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_11;
    return result;
  }

  bool DeltaIO::GetDigitalInput12() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_12;
    return result;
  }

  bool DeltaIO::GetDigitalInput13() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_13;
    return result;
  }

  bool DeltaIO::GetDigitalInput14() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_14;
    return result;
  }

  bool DeltaIO::GetDigitalInput15() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_15;
    return result;
  }

  bool DeltaIO::GetDigitalInput16() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_16;
    return result;
  }

  bool DeltaIO::GetDigitalInput17() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_17;
    return result;
  }

  bool DeltaIO::GetDigitalInput18() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_18;
    return result;
  }

  bool DeltaIO::GetDigitalInput19() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_19;
    return result;
  }

  bool DeltaIO::GetDigitalInput20() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_20;
    return result;
  }

  bool DeltaIO::GetDigitalInput21() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_21;
    return result;
  }

  bool DeltaIO::GetDigitalInput22() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_22;
    return result;
  }

  bool DeltaIO::GetDigitalInput23() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_23;
    return result;
  }

  bool DeltaIO::GetDigitalInput24() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_24;
    return result;
  }

  bool DeltaIO::GetDigitalInput25() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_25;
    return result;
  }

  bool DeltaIO::GetDigitalInput26() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_26;
    return result;
  }

  bool DeltaIO::GetDigitalInput27() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_27;
    return result;
  }

  bool DeltaIO::GetDigitalInput28() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_28;
    return result;
  }

  bool DeltaIO::GetDigitalInput29() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_29;
    return result;
  }

  bool DeltaIO::GetDigitalInput30() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_30;
    return result;
  }

  bool DeltaIO::GetDigitalInput31() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_31;
    return result;
  }

  bool DeltaIO::GetDigitalInput32() const {

    bool result;
    std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
    result = (bool)m_Reading.digitalInput_32;
    return result;
  }

  void DeltaIO::StageDigitalOutput(const uint8_t index, const bool value) {

    switch(index){
      case(1):  SetDigitalOutput1(value); break;
      case(2):  SetDigitalOutput2(value); break;
      case(3):  SetDigitalOutput3(value); break;
      case(4):  SetDigitalOutput4(value); break;
      case(5):  SetDigitalOutput5(value); break;
      case(6):  SetDigitalOutput6(value); break;
      case(7):  SetDigitalOutput7(value); break;
      case(8):  SetDigitalOutput8(value); break;
      case(9):  SetDigitalOutput9(value); break;
      case(10): SetDigitalOutput10(value); break;
      case(11): SetDigitalOutput11(value); break;
      case(12): SetDigitalOutput12(value); break;
      case(13): SetDigitalOutput13(value); break;
      case(14): SetDigitalOutput14(value); break;
      case(15): SetDigitalOutput15(value); break;
      case(16): SetDigitalOutput16(value); break;
    #if IO_CONFIG == 2 
      case(17): SetDigitalOutput17(value); break;
      case(18): SetDigitalOutput18(value); break;
      case(19): SetDigitalOutput19(value); break;
      case(20): SetDigitalOutput20(value); break;
      case(21): SetDigitalOutput21(value); break;
      case(22): SetDigitalOutput22(value); break;
      case(23): SetDigitalOutput23(value); break;
      case(24): SetDigitalOutput24(value); break;
      case(25): SetDigitalOutput25(value); break;
      case(26): SetDigitalOutput26(value); break;
      case(27): SetDigitalOutput27(value); break;
      case(28): SetDigitalOutput28(value); break;
      case(29): SetDigitalOutput29(value); break;
      case(30): SetDigitalOutput30(value); break;
      case(31): SetDigitalOutput31(value); break;
      case(32): SetDigitalOutput32(value); break;
    #elif IO_CONFIG == 0
      case(17): SetDigitalOutput17(value); break;
      case(18): SetDigitalOutput18(value); break;
      case(19): SetDigitalOutput19(value); break;
      case(20): SetDigitalOutput20(value); break;
      case(21): SetDigitalOutput21(value); break;
      case(22): SetDigitalOutput22(value); break;
      case(23): SetDigitalOutput23(value); break;
      case(24): SetDigitalOutput24(value); break;
      case(25): SetDigitalOutput25(value); break;
      case(26): SetDigitalOutput26(value); break;
      case(27): SetDigitalOutput27(value); break;
      case(28): SetDigitalOutput28(value); break;
      case(29): SetDigitalOutput29(value); break;
      case(30): SetDigitalOutput30(value); break;
      case(31): SetDigitalOutput31(value); break;
      case(32): SetDigitalOutput32(value); break;
    #elif IO_CONFIG == 1
    #endif
      default:
        CONTROLLER_CORE_ERROR("[DeltaIO] Digital input index out of bounds");
        break;
    } // switch
  }

  bool DeltaIO::ReadDigitalInput(const uint8_t index) const {

    bool result;

    switch(index){
      case(1):  result = GetDigitalInput1(); break;
      case(2):  result = GetDigitalInput2(); break;
      case(3):  result = GetDigitalInput3(); break;
      case(4):  result = GetDigitalInput4(); break;
      case(5):  result = GetDigitalInput5(); break;
      case(6):  result = GetDigitalInput6(); break;
      case(7):  result = GetDigitalInput7(); break;
      case(8):  result = GetDigitalInput8(); break;
      case(9):  result = GetDigitalInput9(); break;
      case(10): result = GetDigitalInput10(); break;
      case(11): result = GetDigitalInput11(); break;
      case(12): result = GetDigitalInput12(); break;
      case(13): result = GetDigitalInput13(); break;
      case(14): result = GetDigitalInput14(); break;
      case(15): result = GetDigitalInput15(); break;
      case(16): result = GetDigitalInput16(); break;
      case(17): result = GetDigitalInput17(); break;
      case(18): result = GetDigitalInput18(); break;
      case(19): result = GetDigitalInput19(); break;
      case(20): result = GetDigitalInput20(); break;
      case(21): result = GetDigitalInput21(); break;
      case(22): result = GetDigitalInput22(); break;
      case(23): result = GetDigitalInput23(); break;
      case(24): result = GetDigitalInput24(); break;
      case(25): result = GetDigitalInput25(); break;
      case(26): result = GetDigitalInput26(); break;
      case(27): result = GetDigitalInput27(); break;
      case(28): result = GetDigitalInput28(); break;
      case(29): result = GetDigitalInput29(); break;
      case(30): result = GetDigitalInput30(); break;
      case(31): result = GetDigitalInput31(); break;
      case(32): result = GetDigitalInput32(); break;
      default:
      CONTROLLER_CORE_ERROR("[DeltaIO] Digital output index out of bounds");
      break;
    } // switch
    return result;
  }


  void DeltaIO::StageAnalogOutput(const uint8_t index, const int16_t value) {

    switch(index){
      case(1):  SetAnalogOutput1(value); break;
      case(2):  SetAnalogOutput2(value); break;
      case(3):  SetAnalogOutput3(value); break;
      case(4):  SetAnalogOutput4(value); break;
#if IO_CONFIG == 1
#elif IO_CONFIG == 0
      case(5):  SetAnalogOutput5(value); break;
      case(6):  SetAnalogOutput6(value); break;
      // case(7):  SetAnalogOutput7(value); break;
      //  case(8):  SetAnalogOutput8(value); break;

#elif IO_CONFIG == 2
      case(5):  SetAnalogOutput5(value); break;
      case(6):  SetAnalogOutput6(value); break;
#endif
      default:
        CONTROLLER_CORE_ERROR("[DeltaIO] Analog output index out of bounds");
        break;
    } // switch
  }


  int16_t DeltaIO::ReadAnalogInput(const uint8_t index) const {

    int16_t result;
    switch(index){
      case(1):  result = GetAnalogInput1(); break;
      case(2):  result = GetAnalogInput2(); break;
      case(3):  result = GetAnalogInput3(); break;
      case(4):  result = GetAnalogInput4(); break;
#if IO_CONFIG == 1
#elif IO_CONFIG == 0
      case(5):  result = GetAnalogInput5(); break;
      case(6):  result = GetAnalogInput6(); break;
      case(7):  result = GetAnalogInput7(); break;
      case(8):  result = GetAnalogInput8(); break;
#elif IO_CONFIG == 2
      case(5):  result = GetAnalogInput5(); break;
      case(6):  result = GetAnalogInput6(); break;
      case(7):  result = GetAnalogInput7(); break;
      case(8):  result = GetAnalogInput8(); break;
#endif
      default:
      CONTROLLER_CORE_ERROR("[DeltaIO] Analog input index out of bounds");
      break;
    } // switch

    // std::cout << "index; " << (uint16_t)index << " result: " << result << "\n";

    return result;
  }



}    // namespace Controller::Ethercat::Devices
