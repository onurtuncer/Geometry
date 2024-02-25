/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Written by SIMSOFT, Ankara, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact ertugrul.kalkan@simsoft.com.tr
  Contact hakan.sac@simsoft.com.tr
-------------------------------------------------------------------------------*/

#include "ProcessImage.h"
#include <iostream>

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::ProcessImage {

  auto IOType::VariableType::Parse(const rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("Name"):
          Name = std::string(node->value());
          break;
        case Hash::GenerateFNVHash("Comment"):
          SetComment(node->value());
          break;
        case Hash::GenerateFNVHash("DataType"): {
          break; // ! TODO : solve this issue sometime...
          auto str = std::string(node->value());
          std::cout << "variable :: " << str << std::endl;
          BaseDataType dataType;
          switch (Hash::GenerateFNVHash(str)) {
            case (Hash::GenerateFNVHash("BOOLEAN")):
              dataType = BaseDataType::BOOLEAN;
              break;
            case (Hash::GenerateFNVHash("INTEGER8")):
              dataType = BaseDataType::INTEGER8;
              break;
            case (Hash::GenerateFNVHash("INTEGER16")):
              dataType = BaseDataType::INTEGER16;
              break;
            case (Hash::GenerateFNVHash("INTEGEfloat")):
              dataType = BaseDataType::INTEGEfloat;
              break;
            case (Hash::GenerateFNVHash("UNSIGNED8")):
              dataType = BaseDataType::UNSIGNED8;
              break;
            case (Hash::GenerateFNVHash("UNSIGNED16")):
              dataType = BaseDataType::UNSIGNED16;
              break;
            case (Hash::GenerateFNVHash("UNSIGNED32")):
              dataType = BaseDataType::UNSIGNED32;
              break;
            case (Hash::GenerateFNVHash("REAL32")):
              dataType = BaseDataType::REAL32;
              break;
            case (Hash::GenerateFNVHash("VISIBLE_STRING")):
              dataType = BaseDataType::VISIBLE_STRING;
              break;
            case (Hash::GenerateFNVHash("OCTET_STRING")):
              dataType = BaseDataType::OCTET_STRING;
              break;
            case (Hash::GenerateFNVHash("UNICODE_STRING")):
              dataType = BaseDataType::UNICODE_STRING;
              break;
            case (Hash::GenerateFNVHash("TIME_OF_DAY")):
              dataType = BaseDataType::TIME_OF_DAY;
              break;
            case (Hash::GenerateFNVHash("TIME_DIFFERENCE")):
              dataType = BaseDataType::TIME_DIFFERENCE;
              break;
            case (Hash::GenerateFNVHash("DOMAIN")):
              dataType = BaseDataType::DOMAIN;
              break;
            case (Hash::GenerateFNVHash("INTEGER24")):
              dataType = BaseDataType::INTEGER24;
              break;
            case (Hash::GenerateFNVHash("REAL64")):
              dataType = BaseDataType::REAL64;
              break;
            case (Hash::GenerateFNVHash("INTEGEdouble")):
              dataType = BaseDataType::INTEGEdouble;
              break;
            case (Hash::GenerateFNVHash("UNSIGNED24")):
              dataType = BaseDataType::UNSIGNED24;
              break;
            case (Hash::GenerateFNVHash("UNSIGNED64")):
              dataType = BaseDataType::UNSIGNED64;
              break;
            case (Hash::GenerateFNVHash("BIT1")):
              dataType = BaseDataType::BIT1;
              break;
            case (Hash::GenerateFNVHash("BIT2")):
              dataType = BaseDataType::BIT2;
              break;
            case (Hash::GenerateFNVHash("BIT3")):
              dataType = BaseDataType::BIT3;
              break;
            case (Hash::GenerateFNVHash("BIT4")):
              dataType = BaseDataType::BIT4;
              break;
            case (Hash::GenerateFNVHash("BIT5")):
              dataType = BaseDataType::BIT5;
              break;
            case (Hash::GenerateFNVHash("BIT6")):
              dataType = BaseDataType::BIT6;
              break;
            case (Hash::GenerateFNVHash("BIT7")):
              dataType = BaseDataType::BIT7;
              break;
            case (Hash::GenerateFNVHash("BIT8")):
              dataType = BaseDataType::BIT8;
              break;
            default:
              throw new std::invalid_argument("Invalid node in ENI file");
              break;
          }
          SetDataType(dataType);
          break;
        }
        case Hash::GenerateFNVHash("BitSize"):
          BitSize = static_cast<int>(std::stoi(node->value()));
          break;
        case Hash::GenerateFNVHash("BitOffs"):
          BitOffs = static_cast<int>(std::stoi(node->value()));
          break;
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto IOType::VariableType::SetDataType(const BaseDataType type) noexcept -> void {
    m_hasDataType = true;
    m_DataType = type;
  }

  auto IOType::VariableType::GetDataType() noexcept -> std::optional<BaseDataType> {
    if(m_hasDataType) return m_DataType;
    return std::nullopt;
  }

  auto IOType::Parse(const rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("ByteSize"):
          ByteSize = static_cast<int>(std::stoi(node->value()));
          break;
        case Hash::GenerateFNVHash("Variable"): {
          VariableType variable;
          variable.Parse(node);
          AddVariable(variable);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto IOType::AddVariable(const VariableType& var) noexcept -> void {
    m_Variable.push_back(var);
  }
  
  auto IOType::GetVariableList() noexcept -> std::vector<VariableType>& {
    return m_Variable;
  }

  auto ProcessImage::Parse(const rapidxml::xml_node<> *n) -> void {
    for(rapidxml::xml_node<> *node = n->first_node(); node; node = node->next_sibling()) {
      auto nodeName = std::string(node->name());

      std::cout << "Node name = " << nodeName << std::endl;

      switch (Hash::GenerateFNVHash(nodeName)) {
        case Hash::GenerateFNVHash("Inputs"): {
          InputsType inputs;
          inputs.Parse(node);
          SetInputs(inputs);
          break;
        }  
        case Hash::GenerateFNVHash("Outputs"): {
          OutputsType outputs;
          outputs.Parse(node);
          SetOutputs(outputs);
          break;
        }
        default:
          throw new std::invalid_argument("Invalid node name in ENI file");
          break;
      } // switch
    }
  }

  auto ProcessImage::SetInputs(const InputsType& inputs) noexcept -> void {
    m_hasInputs = true;
    m_Inputs = inputs;
  }

  auto ProcessImage::GetInputs() noexcept -> std::optional<InputsType> {
    if(m_hasInputs) return m_Inputs;
    return std::nullopt;
  }

  auto ProcessImage::SetOutputs(const OutputsType& outputs) noexcept -> void {
    m_hasOutputs = true;
    m_Outputs = outputs;
  }

  auto ProcessImage::GetOutputs() noexcept -> std::optional<OutputsType> {
    if(m_hasOutputs) return m_Outputs;
    return std::nullopt;
  }

} // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::ProcessImage