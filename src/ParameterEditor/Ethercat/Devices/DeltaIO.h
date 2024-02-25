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

#ifndef DELTAIO_H
#define DELTAIO_H

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <mutex>
#include <string>
#include <yaml-cpp/yaml.h>
#include "Ethercat/ParametricDevice.h"
#include "Ethercat/DS401/Configuration.h"

#define RX_PDO_ID 0x6000
#define TX_PDO_ID 0x7000


namespace Controller::Ethercat::Devices {

  class DeltaIO : public Controller::Ethercat::ParametricDevice {

    public:
      // struct 1A00 {
      //   int AnalogInput1;
      //   int AnalogInput2;
      //   int AnalogInput3;
      //   int AnalogInput4;
      // } __attribute__((packed));

      // struct 1A10 {
      //   uint8_t DigitalInput1;
      //   uint8_t DigitalInput2;
      // } __attribute__((packed));

      // struct 1A20 {
      //   uint8_t DigitalInput3;
      //   uint8_t DigitalInput4;
      // } __attribute__((packed));

      struct TxPdo {
        uint8_t digitalInput_1   : 1,
                digitalInput_2   : 1,
                digitalInput_3   : 1,
                digitalInput_4   : 1,
                digitalInput_5   : 1,
                digitalInput_6   : 1,
                digitalInput_7   : 1,
                digitalInput_8   : 1;
       uint8_t  digitalInput_9   : 1,
                digitalInput_10  : 1,
                digitalInput_11  : 1,
                digitalInput_12  : 1,
                digitalInput_13  : 1,
                digitalInput_14  : 1,
                digitalInput_15  : 1,
                digitalInput_16  : 1;
        uint8_t digitalInput_17  : 1,
                digitalInput_18  : 1,
                digitalInput_19  : 1,
                digitalInput_20  : 1,
                digitalInput_21  : 1,
                digitalInput_22  : 1,
                digitalInput_23  : 1,
                digitalInput_24  : 1;
        uint8_t digitalInput_25  : 1,
                digitalInput_26  : 1,
                digitalInput_27  : 1,
                digitalInput_28  : 1,
                digitalInput_29  : 1,
                digitalInput_30  : 1,
                digitalInput_31  : 1,
                digitalInput_32  : 1;
        int16_t analogInput_1;
        int16_t analogInput_2;
        int16_t analogInput_3;
        int16_t analogInput_4;
#if IO_CONFIG == 1
#elif IO_CONFIG == 0
        int16_t analogInput_5;
        int16_t analogInput_6;
        int16_t analogInput_7;
        int16_t analogInput_8;
#elif IO_CONFIG == 2

        int16_t analogInput_5;
        int16_t analogInput_6;
        int16_t analogInput_7;
        int16_t analogInput_8;
#endif

      } __attribute__((packed));

      // struct 1600 {
      //   int AnalogOutput1;
      //   int AnalogOutput2;
      // }
      // | __attribute__((packed));

      // struct 1630 {
      //   uint8_t DigitalOutput1;
      //   uint8_t DigitalOutput2;
      // }
      // | __attribute__((packed));

      // struct 1640 {
      //   uint8_t DigitalOutput3;
      //   uint8_t DigitalOutput4;
      // }
      // | __attribute__((packed));

      struct RxPdo {

        uint8_t digitalOutput_1   : 1,
                digitalOutput_2   : 1,
                digitalOutput_3   : 1,
                digitalOutput_4   : 1,
                digitalOutput_5   : 1,
                digitalOutput_6   : 1,
                digitalOutput_7   : 1,
                digitalOutput_8   : 1;
       uint8_t  digitalOutput_9   : 1,
                digitalOutput_10  : 1,
                digitalOutput_11  : 1,
                digitalOutput_12  : 1,
                digitalOutput_13  : 1,
                digitalOutput_14  : 1,
                digitalOutput_15  : 1,
                digitalOutput_16  : 1;
//
        uint8_t digitalOutput_17  : 1,
                digitalOutput_18  : 1,
                digitalOutput_19  : 1,
                digitalOutput_20  : 1,
                digitalOutput_21  : 1,
                digitalOutput_22  : 1,
                digitalOutput_23  : 1,
                digitalOutput_24  : 1;
        uint8_t digitalOutput_25  : 1,
                digitalOutput_26  : 1,
                digitalOutput_27  : 1,
                digitalOutput_28  : 1,
                digitalOutput_29  : 1,
                digitalOutput_30  : 1,
                digitalOutput_31  : 1,
                digitalOutput_32  : 1;
//
        int16_t analogOutput_1;
        int16_t analogOutput_2;
        int16_t analogOutput_3;
        int16_t analogOutput_4;
#if IO_CONFIG == 1
#elif IO_CONFIG == 0
        int16_t analogOutput_5;
        int16_t analogOutput_6;
#elif IO_CONFIG == 2
        int16_t analogOutput_5;
        int16_t analogOutput_6;
        uint8_t digitalOutput_17  : 1,
                digitalOutput_18  : 1,
                digitalOutput_19  : 1,
                digitalOutput_20  : 1,
                digitalOutput_21  : 1,
                digitalOutput_22  : 1,
                digitalOutput_23  : 1,
                digitalOutput_24  : 1;
        uint8_t digitalOutput_25  : 1,
                digitalOutput_26  : 1,
                digitalOutput_27  : 1,
                digitalOutput_28  : 1,
                digitalOutput_29  : 1,
                digitalOutput_30  : 1,
                digitalOutput_31  : 1,
                digitalOutput_32  : 1;
#endif
        // int16_t analogOutput_7;
        // int16_t analogOutput_8;

            } __attribute__((packed));

  public:
   // static std::shared_ptr<DeltaIO> DeviceFromFile(const std::string& configFile, const std::string& name, const uint32_t address);
    static std::shared_ptr<DeltaIO> DeviceFromParameterManager(std::shared_ptr<ParameterManager> pm,
                                                               const std::string& configPath, 
                                                               const std::string& name, 
                                                               const uint32_t address);

    DeltaIO(const std::string& name, const uint32_t address, const std::string& configPath, std::shared_ptr<ParameterManager> pm);
    virtual ~DeltaIO() override = default;

    std::string GetName() const override { return m_Name; }

    bool Startup() override;
    void UpdateRead() override;
    void UpdateWrite() override;
    void Shutdown() override;
    PdoInfo GetCurrentPdoInfo() const override { return m_PdoInfo; }

  public:
      Controller::Ethercat::DS401::Configuration m_Configuration;

  public:
    void StageCommand(const RxPdo& command);
    TxPdo GetReading() const;
    void GetReading(TxPdo& reading) const;

  public:
   /*  bool LoadConfigFile(const std::string& fileName);
    bool LoadConfigNode(YAML::Node configNode); */
    bool LoadConfigurationFromParameterManager();
 /*    Controller::Ethercat::DS401::Configuration GetConfiguration() const; */

    void SetAnalogOutput1(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_1 = value;
    }

    void SetAnalogOutput2(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_2 = value;
    }

     void SetAnalogOutput3(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_3 = value;
    }
   
    void SetAnalogOutput4(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_4 = value;
    }
#if IO_CONFIG == 1
#elif IO_CONFIG == 0

     void SetAnalogOutput5(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_5 = value;
    }
    
    void SetAnalogOutput6(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_6 = value;
    }
 
  //  void SetAnalogOutput7(int16_t value) {

  //     std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
  //     m_StagedCommand.analogOutput_7 = value;
  //   }

  //   void SetAnalogOutput8(int16_t value) {

  //     std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
  //     m_StagedCommand.analogOutput_8 = value;
  //   }
#elif IO_CONFIG == 2
     void SetAnalogOutput5(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_5 = value;
    }
    
    void SetAnalogOutput6(int16_t value) {

      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      m_StagedCommand.analogOutput_6 = value;
    }
#endif

    int16_t GetAnalogInput1() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_1;
    }

    int16_t GetAnalogInput2() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_2;
    }

    int16_t GetAnalogInput3() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_3;
    }

    int16_t GetAnalogInput4() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_4;
    }    
#if IO_CONFIG == 1
#elif IO_CONFIG == 0

    int16_t GetAnalogInput5() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_5;
    }    
    
    int16_t GetAnalogInput6() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_6;
    }    
    
   int16_t GetAnalogInput7() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_7;
    }    

   int16_t GetAnalogInput8() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_8;
    }
  #elif IO_CONFIG == 2
      int16_t GetAnalogInput5() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_5;
    }    
    
    int16_t GetAnalogInput6() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_6;
    }    
       int16_t GetAnalogInput7() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_7;
    }    

   int16_t GetAnalogInput8() const {
      std::lock_guard<std::mutex> lock(m_ReadWriteMutex);
      return m_Reading.analogInput_8;
    }

#endif
    void SetDigitalOutput1(const bool value);
    void SetDigitalOutput2(const bool value);
    void SetDigitalOutput3(const bool value);
    void SetDigitalOutput4(const bool value);
    void SetDigitalOutput5(const bool value);
    void SetDigitalOutput6(const bool value);
    void SetDigitalOutput7(const bool value);
    void SetDigitalOutput8(const bool value);
    void SetDigitalOutput9(const bool value);
    void SetDigitalOutput10(const bool value);
    void SetDigitalOutput11(const bool value);
    void SetDigitalOutput12(const bool value);
    void SetDigitalOutput13(const bool value);
    void SetDigitalOutput14(const bool value);
    void SetDigitalOutput15(const bool value);
    void SetDigitalOutput16(const bool value);
    void SetDigitalOutput17(const bool value);
    void SetDigitalOutput18(const bool value);
    void SetDigitalOutput19(const bool value);
    void SetDigitalOutput20(const bool value);
    void SetDigitalOutput21(const bool value);
    void SetDigitalOutput22(const bool value);
    void SetDigitalOutput23(const bool value);
    void SetDigitalOutput24(const bool value);
    void SetDigitalOutput25(const bool value);
    void SetDigitalOutput26(const bool value);
    void SetDigitalOutput27(const bool value);
    void SetDigitalOutput28(const bool value);
    void SetDigitalOutput29(const bool value);
    void SetDigitalOutput30(const bool value);
    void SetDigitalOutput31(const bool value);
    void SetDigitalOutput32(const bool value);

    bool GetDigitalInput1() const;
    bool GetDigitalInput2() const;
    bool GetDigitalInput3() const;
    bool GetDigitalInput4() const;
    bool GetDigitalInput5() const;
    bool GetDigitalInput6() const;
    bool GetDigitalInput7() const;
    bool GetDigitalInput8() const;
    bool GetDigitalInput9() const;
    bool GetDigitalInput10() const;
    bool GetDigitalInput11() const;
    bool GetDigitalInput12() const;
    bool GetDigitalInput13() const;
    bool GetDigitalInput14() const;
    bool GetDigitalInput15() const;
    bool GetDigitalInput16() const;
    bool GetDigitalInput17() const;
    bool GetDigitalInput18() const;
    bool GetDigitalInput19() const;
    bool GetDigitalInput20() const;
    bool GetDigitalInput21() const;
    bool GetDigitalInput22() const;
    bool GetDigitalInput23() const;
    bool GetDigitalInput24() const;
    bool GetDigitalInput25() const;
    bool GetDigitalInput26() const;
    bool GetDigitalInput27() const;
    bool GetDigitalInput28() const;
    bool GetDigitalInput29() const;
    bool GetDigitalInput30() const;
    bool GetDigitalInput31() const;
    bool GetDigitalInput32() const;

    void StageDigitalOutput(const uint8_t index, const bool value);
    bool ReadDigitalInput(const uint8_t index) const;
    void StageAnalogOutput(const uint8_t index, const int16_t value);
    int16_t ReadAnalogInput(const uint8_t index) const;

    uint8_t GetNumberOfDigitalInputs(){return m_Configuration.numberOfDigitalInputs;}
    uint8_t GetNumberOfDigitalOutputs(){return m_Configuration.numberOfDigitalOutputs;}
    uint8_t GetNumberOfAnalogInputs(){return m_Configuration.numberOfAnalogInputs;}
    uint8_t GetNumberOfAnalogOutputs(){return m_Configuration.numberOfAnalogOutputs;}
    uint8_t GetDigitalInputMappingStartIndex(){return m_Configuration.digitalInputMappingStartIndex;}
    uint8_t GetDigitalOutputMappingStartIndex(){return m_Configuration.digitalOutputMappingStartIndex;}
    uint8_t GetAnalogInputMappingStartIndex(){return m_Configuration.analogInputMappingStartIndex;}
    uint8_t GetAnalogOutputMappingStartIndex(){return m_Configuration.analogOutputMappingStartIndex;}

  private:
    void AutoConfigurePdoSizes();
    uint16_t GetTxPdoSize();
    uint16_t GetRxPdoSize();

    mutable std::mutex m_ReadWriteMutex;
    
    RxPdo m_StagedCommand{0};
    TxPdo m_Reading;
    PdoInfo m_PdoInfo;

   private:
      const uint8_t m_MaximumNumberOfDigitalInputs{32};
      const uint8_t m_MaximumNumberOfDigitalOutputs{32};
      const int16_t m_MaximumNumberOfAnalogInputs{8};
      const int16_t m_MaximumNumberofAnalogOutputs{8};

  private:
    double m_AnalogOutputFactorVoltsToInteger{1};
    double m_AnalogInputFactorIntegerToVolts{1};
  
  };

}    // namespace Controller::Ethercat

#endif    // DELTAIO_H
