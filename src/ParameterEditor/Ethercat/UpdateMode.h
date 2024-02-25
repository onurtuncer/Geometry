/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef UPDATE_MODE_H
#define UPDATE_MODE_H

namespace Controller::Ethercat {

  /*!
   * Update Mode.
   * - NonStandalone:
   *   Communication update timing is handled externally.
   * - StandaloneEnforceRate:
   *   Create the necessary timeout such that the average update rate corresponds to
   *   target rate (compensate for updates that took too long).
   * - StandaloneEnforceStep:
   *   Create the necessary timeout such that the update time step correspnds to
   *   the target time step. No compensation for updates that took too long.
   */
  enum class UpdateMode { NonStandalone,
                          StandaloneEnforceRate,
                          StandaloneEnforceStep};

} // namespace Controller::Ethercat

#endif // UPDATE_MODE_H
