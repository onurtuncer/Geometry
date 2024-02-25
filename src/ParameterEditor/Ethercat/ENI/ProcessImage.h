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

#ifndef __PROCESSIMAGE_H__
#define __PROCESSIMAGE_H__

#include "BaseTypes.h"

namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::ProcessImage {

  using namespace Controller::Ethercat::EniParser::BaseTypes;

  struct IOType {

    struct VariableType : public Commentable {
    public:
      // mandatory
      std::string Name;
      // mandatory
      int         BitSize;
      // mandatory
      int         BitOffs;
    private:
      // optional
      BaseDataType  m_DataType;
      bool          m_hasDataType = false;
    public:
      auto Parse(const rapidxml::xml_node<> *n) -> void;

      auto SetDataType(const BaseDataType type) noexcept -> void;
      auto GetDataType() noexcept -> std::optional<BaseDataType>;
    };

  public:
    // mandatory
    int ByteSize;
  protected:
    // optional
    std::vector<VariableType> m_Variable;
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    auto AddVariable(const VariableType& var) noexcept -> void;
    auto GetVariableList() noexcept -> std::vector<VariableType>&;
  };


  class ProcessImage {
  public:
    struct InputsType  : public IOType {/*empty*/};
    struct OutputsType : public IOType {/*empty*/};
  private:
    InputsType        m_Inputs;
    bool              m_hasInputs = false;
    OutputsType       m_Outputs;
    bool              m_hasOutputs = false;
  public:
    auto Parse(const rapidxml::xml_node<> *n) -> void;

    auto SetInputs(const InputsType& inputs) noexcept -> void;
    auto GetInputs() noexcept -> std::optional<InputsType>;

    auto SetOutputs(const OutputsType& outputs) noexcept -> void;
    auto GetOutputs() noexcept -> std::optional<OutputsType>;
  };
} // namespace Controller::Ethercat::EniParser::EtherCATConfig::Config::ProcessImage

#endif // __PROCESSIMAGE_H__
