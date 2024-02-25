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

#ifndef IO_DEVICE_BASE
#define IO_DEVICE_BASE

namespace Controller::Ethercat::Devices {

    class IODeviceBase : public Controller::Ethercat::ParametricDevice {

        IODeviceBase(const std::string& name, const uint32_t address);
        virtual ~IODeviceBase() override = default;

        public:
            // bool LoadConfigFile(const std::string& fileName);
            // bool LoadConfigNode(YAML::Node configNode);
            bool LoadConfigurationFromParameterManager();

            // Controller::Ethercat::DS401::Configuration GetConfiguration() const;

            uint8_t GetNumberOfDigitalInputs() {return m_Configuration.numberOfDigitalInputs;}
            uint8_t GetNumberOfDigitalOutputs() {return m_Configuration.numberOfDigitalOutputs;}
            uint8_t GetDigitalInputMappingStartIndex() {return m_Configuration.digitalInputMappingStartIndex;}
            uint8_t GetDigitalIOutputMappingStartIndex() {return m_Configuration.digitalOutputMappingStartIndex;}

            virtual void StageDigitalOutput(const uint8_t index, const bool value) = 0;
            virtual bool ReadDigitalInput(const uint8_t index) const = 0;

        public:
            Controller::Ethercat::DS401::Configuration m_Configuration;

    };

} // Controller::Ethercat::Devices


#endif // IO_DEVICE_BASE