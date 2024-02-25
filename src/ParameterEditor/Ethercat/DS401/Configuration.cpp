/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include <algorithm>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include "Configuration.h"

namespace Controller::Ethercat::DS401 {

  std::ostream& operator<<(std::ostream& os, const Configuration& configuration) {

    os << std::boolalpha << std::left << std::setw(43) << std::setfill('-') << "|"
      << std::setw(43) << "| Config Run SDO verify timeout:"
      << "| " << std::setw(10) << configuration.configRunSdoVerifyTimeout
      << "|\n"
      << std::setw(43) << std::setfill('-') << "|" << std::setw(12) << "+"
      << "|\n"
      << std::setfill(' ') << std::noboolalpha << std::right;
    return os;
}

  /* bool Configuration::SanityCheck(bool silent) {

    bool success = true;
    std::string message = "";

    auto check_and_inform = [&message, &success](std::pair<bool, std::string> test) {

      if (test.first) {
        message += "\033[32m✓\t";
        message += test.second;
        message += "\033[m\n";
        success &= true;
      } else {
        message += "\033[31m❌\t";
        message += test.second;
        message += "\033[m\n";
        success = false;
      }
    };

    const std::vector<std::pair<bool, std::string>> sanity_tests = {
      {
        (numberOfAnalogInputs >= 0),
        "number_of_analog_inputs > 0"
      },
      {
        (numberOfDigitalInputs >= 0),
        "number_of_digital_inputs > 0"
      },
      {
        (numberOfAnalogOutputs >= 0),
        "number_of_analog_outputs > 0"
      },
      {
        (numberOfDigitalOutputs >= 0),
        "number_of_digital_outputs > 0"
      },
      {
        (configRunSdoVerifyTimeout > 0),
        "config_run_sdo_verify_timeout > 0"
      }
  };

  std::for_each(sanity_tests.begin(), sanity_tests.end(), check_and_inform);

  if (!silent) {
    std::cout << message << std::endl;
  }

  return success;
  } */

}  // namespace Controller::Ethercat::DS401
