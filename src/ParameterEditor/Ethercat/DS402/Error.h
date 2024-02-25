/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef ERROR_TYPE_H_
#define ERROR_TYPE_H_

namespace Controller::Ethercat::DS402 {

  enum class ErrorType {
   ConfigurationError,
   SdoWriteError,
   SdoReadError,
   ErrorReadingError,
   SdoStateTransitionError,
   PdoMappingError,
   RxPdoMappingError,
   TxPdoMappingError,
   RxPdoTypeError,
   TxPdoTypeError,
   PdoStateTransitionError,
   ModeOfOperationError
  };

} // Controller::Ethercat::DS402

#endif // ERROR_TYPE_H_
