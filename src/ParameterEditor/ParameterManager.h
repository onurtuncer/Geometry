
#ifndef PARAMETER_MANAGER_H
#define PARAMETER_MANAGER_H

#include <set>
#include <unordered_map>
#include "json.hpp"
#include "Parameter.h"

namespace Controller {

  class ParameterManager {

  public:
    template<typename T>
    void AddParameter(const std::string& name, const Parameter<T>& parameter) {

        m_WrappedMap[name] = WrappedParameter(parameter, inferParameterType<T>());
    }

    template<typename T>
    Parameter<T> GetParameter(const std::string& name) const {

        auto wrapped = GetWrappedParameter(name);
        return wrapped.GetParameter<T>();
    }

    WrappedParameter GetWrappedParameter(const std::string& name) const {

          auto it = m_WrappedMap.find(name);
          
          if (it != m_WrappedMap.end() ) {

            return it->second; 
          } else {
              throw std::runtime_error("Parameter not found");
          }
    }

    void FlushAllParameters(){

        m_WrappedMap.clear();
    }

    nlohmann::json Serialize(){

        auto map = m_WrappedMap;

        using namespace Controller;

        std::map<std::string, nlohmann::json> intermediateMap;

        for (auto it = map.begin(); it != map.end(); ++it) {
            intermediateMap[it->first] = WrappedToJson(it->second); 
        }
        auto result = serializeIntermediateMapToJson(intermediateMap);
        return result;
    }

    void Deserialize(const nlohmann::json& node) {

        FlushAllParameters();
        TraverseJSON(m_WrappedMap, node);
    }

    std::vector<std::pair<std::string, WrappedParameter>> GetParameters() const {
        
        std::vector<std::pair<std::string, WrappedParameter>> parameters;
        for (const auto& pair : m_WrappedMap) {
            parameters.emplace_back(pair.first, pair.second);
        }
        return parameters;
    }

    void UpdateParameter(const std::string& path, const WrappedParameter& value) {
        
      m_WrappedMap[path] = value;
   }

    private:
       void TraverseJSON(std::unordered_map<std::string, WrappedParameter>& result, const nlohmann::json& node, const std::string& parentKey = "") {

        auto isLeafNode = [](const nlohmann::json& node) {
            return node.is_object() && node.size() == 2 && node.contains("type") && node.contains("value");
        };

        if (isLeafNode(node)) {

            std::string path = parentKey.empty() ? "" : parentKey;

            auto wrapped = ProcessLeafNode(node, path);
            // std::cout << "Found leaf with path: " << path << std::endl;
            result[path] = wrapped;

        } else if (node.is_object() ) {
            for (auto it = node.begin(); it != node.end(); ++it) {
                std::string currentKey = parentKey.empty() ? it.key() : parentKey + "." + it.key();
                TraverseJSON(result, it.value(), currentKey);
            }
        } else if (node.is_array()) {
            for (size_t i = 0; i < node.size(); ++i) {
                std::string currentKey = parentKey.empty() ? std::to_string(i) : parentKey + "." + std::to_string(i);
                TraverseJSON(result, node[i], currentKey);
            }
        }
    }

        WrappedParameter ProcessLeafWithStringValue(const nlohmann::json& leaf, ParameterType type){

        // std::cout << "Process leaf string value" << "\n";

        nlohmann::json valueJson = leaf["value"];
 
        switch(type){
             case ParameterType::Unknown: {
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
             }
            case ParameterType::String:
                return WrappedParameter(Parameter<std::string>(valueJson.get<std::string>()));
            case ParameterType::SignedChar:
                return WrappedParameter(Parameter<signed char>(valueJson.get<signed char>()));    
            default:
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
        } // switch
    }

    WrappedParameter ProcessLeafWithArrayValue(const nlohmann::json& leaf, ParameterType type){

        // std::cout << "Process leaf with array vale" << "\n";

        const nlohmann::json& arrayJson = leaf["value"];
        // std::cout << "Array Value: " << arrayJson.dump() << " Type: " <<  parameterTypeToString(type) << std::endl; 
        switch(type){

            case ParameterType::Unknown: {
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
            }
            case ParameterType::ModeOfOperationVector: {

                auto modeOfOperationArray = arrayJson.get<std::vector<int>>();
                std::vector<Ethercat::DS402::ModeOfOperation> modeOfOperationVector;

                for (const auto& mode : modeOfOperationArray) {
                    modeOfOperationVector.push_back(static_cast<Ethercat::DS402::ModeOfOperation>(mode));
                }
                return WrappedParameter(Parameter<std::vector<Ethercat::DS402::ModeOfOperation>>(modeOfOperationVector));
            }
            case ParameterType::DoubleVector:   
                return WrappedParameter(Parameter<std::vector<double>>(arrayJson.get<std::vector<double>>()));
            case ParameterType::StringVector:
                return WrappedParameter(Parameter<std::vector<std::string>>(arrayJson.get<std::vector<std::string>>()));
            case ParameterType::PairDoubleDouble:
                return WrappedParameter(Parameter<std::pair<double, double>>(arrayJson.get<std::pair<double, double>>()));
            case ParameterType::PairStringString:
                return WrappedParameter(Parameter<std::pair<std::string, std::string>>(arrayJson.get<std::pair<std::string, std::string>>()));
            case ParameterType::PairBoolDouble:
                return WrappedParameter(Parameter<std::pair<bool, double>>(arrayJson.get<std::pair<bool, double>>()));
            default:
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
          } // switch 
    }

    WrappedParameter ProcessLeafWithNumericValue(const nlohmann::json& leaf, ParameterType type){

        // std::cout << "Process leaf with numeric vale" << "\n";

        nlohmann::json valueJson = leaf["value"];
        switch (type) {
            case ParameterType::Unknown: {
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
            }
            case ParameterType::Integer:
                return WrappedParameter(Parameter<int>(valueJson.get<int>()));
            case ParameterType::Float:
                return WrappedParameter(Parameter<float>(valueJson.get<float>()));
            case ParameterType::Double:
                return WrappedParameter(Parameter<double>(valueJson.get<double>()));
              case ParameterType::Char:
                return WrappedParameter(Parameter<char>(valueJson.get<char>()));
            case ParameterType::Int32T:
                return WrappedParameter(Parameter<int32_t>(valueJson.get<int32_t>()));
             case ParameterType::Int8T:
                return WrappedParameter(Parameter<int32_t>(valueJson.get<int8_t>()));
            case ParameterType::UnsignedInt:
                return WrappedParameter(Parameter<unsigned int>(valueJson.get<unsigned int>()));
            case ParameterType::DeviceType:
                return WrappedParameter(Parameter<Ethercat::Devices::SlaveType>(valueJson.get<Ethercat::Devices::SlaveType>()));
            case ParameterType::RxPdoTypeEnum:
                return WrappedParameter(Parameter<Ethercat::DS402::RxPdoTypeEnum>(valueJson.get<Ethercat::DS402::RxPdoTypeEnum>()));
            case ParameterType::TxPdoTypeEnum:
                return WrappedParameter(Parameter<Ethercat::DS402::TxPdoTypeEnum>(valueJson.get<Ethercat::DS402::TxPdoTypeEnum>()));
            case ParameterType::ModeOfOperation:
                return WrappedParameter(Parameter<Ethercat::DS402::ModeOfOperation>(valueJson.get<Ethercat::DS402::ModeOfOperation>()));
            default:
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
        } // switch
    }

    WrappedParameter ProcessLeafWithBooleanValue(const nlohmann::json& leaf, ParameterType type){

         nlohmann::json valueJson = leaf["value"];

         switch (type){
            case ParameterType::Unknown: {
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
            }
            case ParameterType::Bool:
                return WrappedParameter(Parameter<bool>(valueJson.get<bool>()));
             default:
                throw std::runtime_error("Unsupported parameter type during deserialization");
                return WrappedParameter();
         } // switch

    }

    WrappedParameter ProcessLeafNode(const nlohmann::json& leaf, const std::string& path) {

        // std::cout << "Path: " << path << std::endl;

        std::string type = leaf["type"].get<std::string>();
        auto parameterType = stringToParameterType(type);

        if (leaf["value"].is_string()) {
            return ProcessLeafWithStringValue(leaf, parameterType);       
        } else if (leaf["value"].is_array()) {
            return ProcessLeafWithArrayValue(leaf, parameterType);     
        } else if (leaf["value"].is_number()) {
            return ProcessLeafWithNumericValue(leaf, parameterType);
        } else if (leaf["value"].is_boolean()) {
            return ProcessLeafWithBooleanValue(leaf, parameterType);
        } else return WrappedParameter();
    }
    
    nlohmann::json serializeIntermediateMapToJson(const std::map<std::string, nlohmann::json>& inputMap) {

            nlohmann::json resultJson;

            std::vector<std::string> sortedKeys;
            for (const auto& entry : inputMap) {
                sortedKeys.push_back(entry.first);
            }
            std::sort(sortedKeys.begin(), sortedKeys.end());

            for (const auto& sortedKey : sortedKeys) {

                const auto& entry = inputMap.at(sortedKey);
                std::vector<std::string> keys;
                size_t start = 0, end;

                while ((end = sortedKey.find('.', start)) != std::string::npos) {
                    keys.push_back(sortedKey.substr(start, end - start));
                    start = end + 1;
                }
                keys.push_back(sortedKey.substr(start));

                nlohmann::json* currentJson = &resultJson;
                for (const auto& key : keys) {
                    currentJson = &((*currentJson)[key]);
                }

                *currentJson = entry;
            }

            return resultJson;
        }


    private:
      std::unordered_map<std::string, WrappedParameter> m_WrappedMap;  // TODO 
    };
  
} // namespace Controller

#endif // PARAMETER_MANAGER_H