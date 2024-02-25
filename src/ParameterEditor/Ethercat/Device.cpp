/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#include "Device.h"

namespace Controller::Ethercat {

  void Device::SetTimeStep(double timeStep) {

    m_TimeStep = timeStep;
  }

} // namespace Controller::Ethercat
