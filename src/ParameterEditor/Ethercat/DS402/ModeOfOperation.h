/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Writtten by Bites, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#ifndef MODE_OF_OPERATION_H_
#define MODE_OF_OPERATION_H_

namespace Controller::Ethercat::DS402 {

  enum class ModeOfOperation : int8_t {
    NA = 0,
    ProfiledPositionMode = 1,
    ProfiledVelocityMode = 3,
    ProfiledTorqueMode = 4,
    HomingMode = 6,
    CyclicSynchronousPositionMode = 8 ,
    CyclicSynchronousVelocityMode = 9,
    CyclicSynchronousTorqueMode = 10
  };

} // namespace Controller::Ethercat::DS402

#endif // MODE_OF_OPERATION_H_
