/* ----------------------------------------------------------------------------*
  Copyright 2024 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef PARAMETRIC_DEVICE_H_
#define PARAMETRIC_DEVICE_H_

#include <memory>
#include "Core/Parameter/Parameter.h"
#include "Core/Parameter/ParameterManager.h"
#include "Device.h"

namespace Controller::Ethercat {

class ParametricDevice : public Device {

   public:
    ParametricDevice(std::shared_ptr<ParameterManager> pm, const std::string& path)
        : m_ParameterManagerPtr(pm), m_ConfigPath(path){
            m_ParameterManagerPtr = pm;

        }
     virtual ~ParametricDevice() = default;
    
    protected:
    /*  template typename<T>
     T GetParameter(){
        auto fullPath = m_configPath + "." + name;
        return m_ParameterManagerPtr->GetParameter<T>.getValue();
     } */
    
    protected:
      std::shared_ptr<ParameterManager> m_ParameterManagerPtr;
      std::string m_ConfigPath;

  }; // namespace Controller::Ethercat

}

#endif // PARAMETRIC_DEVICE_H_