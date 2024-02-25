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
#include "XMC.h"

namespace Controller::Ethercat::Devices {

   std::shared_ptr<XMC> XMC::DeviceFromFile(const std::string& configFile, const std::string& name, const uint32_t address) {

     auto xmc = std::make_shared<XMC>(name, address);

     if (!xmc->LoadConfigFile(configFile)) {

       std::stringstream ss;

       ss << "[XMC::DeviceFromFile] loading config file '" << configFile
          << "' for '" << name << "' not successful." << std::endl;

      throw std::runtime_error("[XMC::DeviceFromFile] config file loading error");
    }

    return xmc;
  }

  XMC::XMC(const std::string& name, const uint32_t address) {

    m_Address = address;
    m_Name = name;

    m_PdoInfo.rxPdoId = RX_PDO_ID;
    m_PdoInfo.txPdoId = TX_PDO_ID;
    m_PdoInfo.moduleId = 0x00123456;
  }

  bool XMC::Startup() {

    AutoConfigurePdoSizes();

    bool success = true;

    success &= m_Bus->WaitForState(EC_STATE_PRE_OP, m_Address, 50, 0.05);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    success &= m_Bus->WaitForState(EC_STATE_OPERATIONAL, m_Address, 50, 0.05);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return success;
  }

  void XMC::Shutdown() {

    m_Bus->SetState(EC_STATE_INIT, m_Address);
  }

  void XMC::UpdateWrite() {

    RxPdo rxPdo{};
    std::lock_guard<std::mutex> stagedCmdLock(m_StagedCommandMutex);
    rxPdo = m_StagedCommand;
    m_Bus->WriteRxPdo(m_Address, rxPdo);
  }

  void XMC::UpdateRead() {

    TxPdo txPdo{};
    m_Bus->ReadTxPdo(m_Address, txPdo);
    m_Reading = txPdo;
  }


  void XMC::StageCommand(const RxPdo& command) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand = command;
  }

  XMC::TxPdo XMC::GetReading() const {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    return m_Reading;
  }

  void XMC::GetReading(TxPdo& reading) const {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    reading = m_Reading;
  }

  bool XMC::LoadConfigFile(const std::string& fileName) {

    Controller::Ethercat::DS401::ConfigurationParser configurationParser(fileName);
    return LoadConfiguration(configurationParser.GetConfiguration());
  }

  bool XMC::LoadConfiguration(const Controller::Ethercat::DS401::Configuration& configuration) {

    m_Configuration = configuration;

    std::stringstream ss;
    ss << "[IO Device] Sanity check for '" << m_Name << "':" << std::endl;
    CONTROLLER_CORE_ERROR(ss.str());
    auto non_const_config = const_cast<Controller::Ethercat::DS401::Configuration&>(configuration);
    return non_const_config.SanityCheck();
  }

  Controller::Ethercat::DS401::Configuration XMC::GetConfiguration() const { return m_Configuration; }

  bool XMC::LoadConfigNode(YAML::Node configNode) {

    Controller::Ethercat::DS401::ConfigurationParser configurationParser(configNode);
    return LoadConfiguration(configurationParser.GetConfiguration());
  }

  void XMC::AutoConfigurePdoSizes() {

    auto pdoSizes = m_Bus->GetHardwarePdoSizes(static_cast<uint16_t>(m_Address));
    m_PdoInfo.rxPdoSize = pdoSizes.first;
    m_PdoInfo.txPdoSize = pdoSizes.second;
  }

  uint16_t XMC::GetTxPdoSize() {

    return m_PdoInfo.txPdoSize;
  }

  uint16_t XMC::GetRxPdoSize() {

    return m_PdoInfo.rxPdoSize;
  }

  void XMC::SetLed1(const bool value) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand.led_1 = value;
  }

  void XMC::SetLed2(const bool value) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand.led_2 = value;
  }

  void XMC::SetLed3(const bool value) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand.led_3 = value;
  }

  void XMC::SetLed4(const bool value) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand.led_4 = value;
  }

  void XMC::SetLed5(const bool value) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand.led_5 = value;
  }

  void XMC::SetLed6(const bool value) {
    m_StagedCommand.led_6 = value;
  }

  void XMC::SetLed7(const bool value) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand.led_7 = value;
  }

  void XMC::SetLed8(const bool value) {

    std::lock_guard<std::mutex> lock(m_StagedCommandMutex);
    m_StagedCommand.led_8 = value;
  }

  bool XMC::GetButton1() const {

    std::lock_guard<std::mutex> lock(m_ReadingMutex);
    auto reading = GetReading();
    char buffer[1];
    memcpy(buffer, &reading, sizeof(reading));
    auto bit0_value = (buffer[0] & (1 << 0)) >> 0;
    return bool(bit0_value);
  }

  bool XMC::GetButton2() const  {

    std::lock_guard<std::mutex> lock(m_ReadingMutex);
    auto reading = GetReading();
    char buffer[1];
    memcpy(buffer, &reading, sizeof(reading));
    auto bit1_value = (buffer[0] & (1 << 1)) >> 1;
    return bool(bit1_value);
  }

  void XMC::StageDigitalOutput(const uint8_t index, const bool value) {

    switch(index){
      case(1): SetLed1(value); break;
      case(2): SetLed2(value); break;
      case(3): SetLed3(value); break;
      case(4): SetLed4(value); break;
      case(5): SetLed5(value); break;
      case(6): SetLed6(value); break;
      case(7): SetLed7(value); break;
      case(8): SetLed8(value); break;
      default:
        CONTROLLER_CORE_ERROR("[XMC] Digital output index out of bounds");
        break;
    } // switch
  }

  bool XMC::ReadDigitalInput(const uint8_t index) const {

    bool result;

    switch(index){
      case(1): result = GetButton1(); break;
      case(2): result = GetButton2(); break;
      default:
      CONTROLLER_CORE_ERROR("[XMC] Digital output index out of bounds");
      break;
    } // switch
    return result;
  }

} // namespace Controller::Ethercat::Devices
