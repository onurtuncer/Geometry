
#ifndef DEVICE_TYPES_H
#define DEVICE_TYPES_H

namespace Controller::Ethercat::Devices {


      enum class SlaveType {
          XMC,
          SMB,
          Yaskawa,
          Beckhoff,
          DeltaIO,
          NA
      };

};

#endif // DEVICE_TYPES_H

