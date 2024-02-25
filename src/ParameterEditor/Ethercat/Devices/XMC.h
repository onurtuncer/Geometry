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

#ifndef _XMC_H__
#define _XMC_H__

#define RX_PDO_ID 0x6000
#define TX_PDO_ID 0x7000

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <mutex>
#include <string>
#include <yaml-cpp/yaml.h>
#include "Ethercat/Device.h"
#include "Ethercat/DS401/Configuration.h"

namespace Controller::Ethercat::Devices {

  class XMC : public Controller::Ethercat::Device {

  public:

    struct TxPdo {
      uint8 button_1 : 1,
            button_2 : 1,
            padding  : 6;
    } __attribute__((packed));

    struct RxPdo {
       uint8  led_1  : 1,
              led_2  : 1,
              led_3  : 1,
              led_4  : 1,
              led_5  : 1,
              led_6  : 1,
              led_7  : 1,
              led_8  : 1;
    } __attribute__((packed));

    public:
      static std::shared_ptr<XMC> DeviceFromFile(const std::string& configFile, const std::string& name, const uint32_t address);

      XMC(const std::string& name, const uint32_t address);
      virtual ~XMC() override = default;

    // pure virtual overrides
    public:
      bool Startup() override;
      void Shutdown() override;
      void UpdateWrite() override;
      void UpdateRead() override;
      PdoInfo GetCurrentPdoInfo() const override { return m_PdoInfo; }

    public:
      void StageCommand(const RxPdo& command);
      TxPdo GetReading() const;
      void GetReading(TxPdo& reading) const;

    public:
      bool LoadConfigFile(const std::string& fileName);
      bool LoadConfigNode(YAML::Node configNode);
      bool LoadConfiguration(const Controller::Ethercat::DS401::Configuration& configuration);

      Controller::Ethercat::DS401::Configuration GetConfiguration() const;

      uint8_t GetNumberOfDigitalInputs() {return m_Configuration.numberOfDigitalInputs;}
      uint8_t GetNumberOfDigitalOutputs() {return m_Configuration.numberOfDigitalOutputs;}
      uint8_t GetDigitalInputMappingStartIndex() {return m_Configuration.digitalInputMappingStartIndex;}
      uint8_t GetDigitalIOutputMappingStartIndex() {return m_Configuration.digitalOutputMappingStartIndex;}

    public:
      Controller::Ethercat::DS401::Configuration m_Configuration;

    public:
      void SetLed1(const bool value);
      void SetLed2(const bool value);
      void SetLed3(const bool value);
      void SetLed4(const bool value);
      void SetLed5(const bool value);
      void SetLed6(const bool value);
      void SetLed7(const bool value);
      void SetLed8(const bool value);

      bool GetButton1() const;
      bool GetButton2() const;

      void StageDigitalOutput(const uint8_t index, const bool value);
      bool ReadDigitalInput(const uint8_t index) const;

    private:
      void AutoConfigurePdoSizes();
      uint16_t GetTxPdoSize();
      uint16_t GetRxPdoSize();

      mutable std::mutex m_StagedCommandMutex;
      RxPdo m_StagedCommand;

      mutable std::mutex m_ReadingMutex;
      TxPdo m_Reading;

      PdoInfo m_PdoInfo;

      const uint8_t maximumNumberOfDigitalInputs{2};
      const uint8_t maximumNumberOfDigitalOutputs{8};
      const uint8_t maximumNumberOfAnalogInputs{0};
      const uint8_t maximumNumberofAnalogOutputs{0};
  };

} // namespace Controller::Ethercat::Devices

#endif // _XMC_H__
