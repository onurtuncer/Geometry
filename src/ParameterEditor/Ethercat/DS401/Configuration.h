/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef __CONFIGURATION_401_H__
#define __CONFIGURATION_401_H__

#include <cstdint>
#include <iostream>
#include <utility>

namespace Controller::Ethercat::DS401 {

  class Configuration {

   public:

    unsigned int configRunSdoVerifyTimeout{20000};
    uint8_t numberOfDigitalInputs{0};
    uint8_t numberOfDigitalOutputs{0};
    uint8_t numberOfAnalogInputs{0};
    uint8_t numberOfAnalogOutputs{0};
    uint8_t digitalInputMappingStartIndex{0};
    uint8_t digitalOutputMappingStartIndex{0};
    uint8_t analogInputMappingStartIndex{0};
    uint8_t analogOutputMappingStartIndex{0};

    // bool SanityCheck(bool silent = false);

   public:
    friend std::ostream& operator<<(std::ostream& os, const Configuration& configuration);
  };

} // namespace Controller::Ethercat::DS401

#endif // _CONFIGURATION_401_H__
