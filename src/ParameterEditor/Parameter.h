/* ----------------------------------------------------------------------------*
  Copyright 2023 MILTEKSAN

  Written by Melina Aero, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
-------------------------------------------------------------------------------*/

#ifndef PARAMETER_H
#define PARAMETER_H

#include <any>
#include <string>
#include <vector>
#include <type_traits>
#include <functional> // For reference wrapper
#include <string_view>
#include "json.hpp"

#include "Ethercat/DS402/PDOType.h"
#include "Ethercat/DS402/ModeOfOperation.h"
#include "Ethercat/Devices/DeviceTypes.h"

#include <memory>

// #include <QMetaType>

namespace Controller{

    enum class ParameterType {
        Unknown = 0,
        Integer = 1,
        UnsignedInt = 2,
        Double = 3,
        Float = 4,
        Bool = 5 ,
        Char,
        String,
        SignedChar,
        PairDoubleDouble,
        PairBoolDouble,
        PairStringString,
        RxPdoTypeEnum,
        TxPdoTypeEnum,
        ModeOfOperation,
        ModeOfOperationVector,
        DeviceType,
        Int32T,
        Int8T,
        DoubleVector,
        StringVector,
        UInt8T
    };
    
    constexpr std::string_view parameterTypeToStringHelper(const ParameterType type) {
        switch (type) {
            case ParameterType::Integer: return "int";
            case ParameterType::UnsignedInt: return "unsigned int";
            case ParameterType::Double: return "double";
            case ParameterType::Float: return "float";
            case ParameterType::Bool: return "bool";
            case ParameterType::String: return "string";
             case ParameterType::Char: return "char";
            case ParameterType::PairDoubleDouble: return "pair<double, double>";
            case ParameterType::PairStringString: return "pair<string, string>";
            case ParameterType::SignedChar: return "signedChar";
            case ParameterType::ModeOfOperation: return "modeOfOperation";
            case ParameterType::ModeOfOperationVector: return "modeOfOperationVector";
            case ParameterType::PairBoolDouble: return "pair<bool, double>";
            case ParameterType::RxPdoTypeEnum: return "rxPdoTypeEnum";
            case ParameterType::TxPdoTypeEnum: return "txPdoTypeEnum";
            case ParameterType::DeviceType: return "deviceType";
            case ParameterType::Int32T: return "int32_t";
            case ParameterType::Int8T: return "int8_t";
            case ParameterType::DoubleVector: return "vectorOfDouble";
            case ParameterType::StringVector: return "vectorOfString";
            case ParameterType::UInt8T: return "uint8_t";
            default: return "unknown";
        }
    }

    inline const std::string parameterTypeToString(const ParameterType type){

        auto sv = parameterTypeToStringHelper(type);
        std::string str(sv.begin(), sv.end());
        return str;
    }

   constexpr ParameterType stringToParameterTypeHelper(const std::string_view str) {
    return (str == "int") ? ParameterType::Integer :
           (str == "unsigned int") ? ParameterType::UnsignedInt : 
           (str == "double") ? ParameterType::Double :
           (str == "float") ? ParameterType::Float :
           (str == "bool") ? ParameterType::Bool :
           (str == "string") ? ParameterType::String :
           (str == "char") ? ParameterType::Char :
           (str == "pair<double, double>") ? ParameterType::PairDoubleDouble :
           (str == "pair<string, string>") ? ParameterType::PairStringString :
           (str == "signedChar") ? ParameterType::SignedChar :
           (str == "modeOfOperation") ? ParameterType::ModeOfOperation :
           (str == "modeOfOperationVector") ? ParameterType::ModeOfOperationVector :
           (str == "pair<bool, double>") ? ParameterType::PairBoolDouble :
           (str == "rxPdoTypeEnum") ? ParameterType::RxPdoTypeEnum :
           (str == "txPdoTypeEnum") ? ParameterType::TxPdoTypeEnum :
           (str == "deviceType") ? ParameterType::DeviceType :
           (str == "int32_t") ? ParameterType::Int32T :
           (str == "int8_t") ? ParameterType::Int8T : 
           (str == "vectorOfDouble") ? ParameterType::DoubleVector :
           (str == "vectorOfString") ? ParameterType::StringVector :
           (str == "uint8_t") ? ParameterType::UInt8T :
           ParameterType::Unknown;
    }

    constexpr ParameterType stringToParameterType(const std::string_view str) {
        return stringToParameterTypeHelper(str);
    }

    template <typename T>
    struct always_false : std::false_type {};

    template <>
    struct always_false<std::any> : std::false_type {};

    template <typename T>
    static ParameterType inferParameterType() {
        if constexpr (std::is_same_v<T, int>) {
            return ParameterType::Integer;
        } else if constexpr (std::is_same_v<T, int8_t>){
            return ParameterType::Int8T;
        } else if constexpr (std::is_same_v<T , int32_t>) {
            return ParameterType::Int32T;
        } else if constexpr (std::is_same_v<T, float>) {
            return ParameterType::Float;
        } else if constexpr (std::is_same_v<T, double>) {
            return ParameterType::Double;
        } else if constexpr (std::is_same_v<T, bool>) {
            return ParameterType::Bool;
        } else if constexpr (std::is_same_v<T, char>) {
            return ParameterType::Char;
        } else if constexpr (std::is_same_v<T, std::string>) {
            return ParameterType::String;
        } else if constexpr (std::is_same_v<T, std::pair<double, double>>) {
            return ParameterType::PairDoubleDouble;
        } else if constexpr (std::is_same_v<T, std::pair<bool, double>>) {
            return ParameterType::PairBoolDouble;
        } else if constexpr (std::is_same_v<T, unsigned int>) {
            return ParameterType::UnsignedInt;
        } else if constexpr (std::is_same_v<T, std::pair<std::string, std::string>>) {
            return ParameterType::PairStringString;
        } else if constexpr (std::is_same_v<T, Ethercat::DS402::RxPdoTypeEnum>) {
            return ParameterType::RxPdoTypeEnum;
        } else if constexpr (std::is_same_v<T, Ethercat::DS402::TxPdoTypeEnum>) {
            return ParameterType::TxPdoTypeEnum;
        } else if constexpr (std::is_same_v<T, Ethercat::DS402::ModeOfOperation>) {
            return ParameterType::ModeOfOperation;
        } else if constexpr (std::is_same_v<T, std::vector<Ethercat::DS402::ModeOfOperation>>) {
            return ParameterType::ModeOfOperationVector; 
        }  else if constexpr (std::is_same_v<T, signed char>) {
            return ParameterType::SignedChar;
        }  else if constexpr (std::is_same_v<T, Ethercat::Devices::SlaveType>) {
            return ParameterType::DeviceType;
        } else if constexpr (std::is_same_v<T , std::vector<double>>) {
            return ParameterType::DoubleVector;
        } else if constexpr (std::is_same_v<T , std::vector<std::string>>) {
            return ParameterType::StringVector;
        } else if constexpr (std::is_same_v<T, uint8_t>){
            return ParameterType::UInt8T;
        } else if constexpr (std::is_same_v<T , std::any>) {
            return ParameterType::Unknown;    
        } else {
           static_assert(always_false<T>::value, "Unsupported parameter type while trying to inter type");
            return ParameterType::Unknown;
        }
    }

    template <typename T>
    class Parameter {
        private:
            T value;

        public:
            Parameter() : value(T()) {}
            Parameter(const T& defaultValue) : value(defaultValue) {}

            T getValue() const {
                return value;
            }

            void setValue(const T& newValue) {
                value = newValue;
            }

            ParameterType getType() const {

                 return inferParameterType<T>();       
            };
    };

    class WrappedParameter : public std::enable_shared_from_this<WrappedParameter>{

        public:
            WrappedParameter() : m_Type(ParameterType::Unknown) {}  // Default constructor [NEVER Omit this!!!]
            WrappedParameter(std::any param, ParameterType type) : m_Type(type), m_TypeErasedParameter(param) {/*empty*/}
            template< typename T>
            WrappedParameter(Parameter<T> param) : m_Type(param.getType()), m_TypeErasedParameter(param) {/*empty*/}
           
            ParameterType GetType() const {return m_Type;}

            std::shared_ptr<WrappedParameter> GetSharedPtr() {  // A shared ptr must exist beforehand
                return shared_from_this();
            }

            template<typename T>
            Parameter<T> GetParameter() const {

                ParameterType inferredType = inferParameterType<T>();
                if (inferredType != m_Type) throw std::runtime_error("Type mistmatch while unwrapping paramater");
                return std::any_cast<Parameter<T>>(m_TypeErasedParameter);            
            }

            template<typename T>
            T Value() {

              return GetParameter<T>().getValue();  
            }

        private:
            std::any      m_TypeErasedParameter;
            ParameterType m_Type;
    };

    using WrappedParameterRef = std::reference_wrapper<const WrappedParameter>;

    inline nlohmann::json WrappedToJson(WrappedParameter& wrapped) {

        nlohmann::json result;

        ParameterType paramType = wrapped.GetType();

        // Add type information to the JSON
        result["type"] = parameterTypeToString(paramType);

        switch (paramType) {
            case ParameterType::Integer: 
                 result["value"] = wrapped.Value<int>(); break;
            case ParameterType::UnsignedInt: 
                 result["value"] = wrapped.Value<unsigned int>(); break;
            case ParameterType::Double:
                 result["value"] = wrapped.Value<double>(); break;
            case ParameterType::Float:
                 result["value"] = wrapped.Value<float>(); break;
            case ParameterType::Bool:
                 result["value"] = wrapped.Value<bool>(); break;
            case ParameterType::Char:
                 result["value"] = wrapped.Value<char>(); break;
            case ParameterType::Int32T:
                 result["value"] = wrapped.Value<int32_t>(); break;
             case ParameterType::Int8T:
                 result["value"] = wrapped.Value<int8_t>(); break;
            case ParameterType::String:
                 result["value"] = wrapped.Value<std::string>(); break;
            case ParameterType::SignedChar:
                 result["value"] = wrapped.Value<char>(); break;
            case ParameterType::PairDoubleDouble:
                 result["value"] = wrapped.Value<std::pair<double, double>>(); break;
            case ParameterType::PairBoolDouble:
                 result["value"] = wrapped.Value<std::pair<bool, double>>(); break;
            case ParameterType::PairStringString:
                 result["value"] = wrapped.Value<std::pair<std::string, std::string>>(); break;
            case ParameterType::RxPdoTypeEnum:
                 result["value"] = wrapped.Value<Ethercat::DS402::RxPdoTypeEnum>(); break;
            case ParameterType::TxPdoTypeEnum:
                  result["value"] = wrapped.Value<Ethercat::DS402::TxPdoTypeEnum>(); break;
            case ParameterType::ModeOfOperation:
                result["value"] = wrapped.Value<Ethercat::DS402::ModeOfOperation>(); break;
            case ParameterType::ModeOfOperationVector: {
                auto modeOfOperationVector = wrapped.Value<std::vector<Ethercat::DS402::ModeOfOperation>>();
                nlohmann::json modeOfOperationArray;

                for (const auto& mode : modeOfOperationVector) {
                    modeOfOperationArray.push_back(static_cast<int>(mode));
                }

                 result["value"] = modeOfOperationArray; break;
            }
             case ParameterType::DeviceType:
                 result["value"] = wrapped.Value<Ethercat::Devices::SlaveType>(); break;
            case ParameterType::DoubleVector: 
                 result["value"] = wrapped.Value<std::vector<double>>(); break;
            case ParameterType::StringVector:
                 result["value"] = wrapped.Value<std::vector<std::string>>(); break;       
            case ParameterType::UInt8T:
                 result["value"] = wrapped.Value<uint8_t>(); break;             
            default:  
                throw std::runtime_error("Trying to serialize unsupported parameter type into JSON");
        } // switch

        return result;
    }

    template<typename T>
    inline WrappedParameter FromJsonToWrapped(const nlohmann::json& value){

        return WrappedParameter(Parameter<T>(value.get<T>()));
    }

    template<>
    inline WrappedParameter FromJsonToWrapped<Ethercat::DS402::TxPdoTypeEnum>(const nlohmann::json& value){

        return WrappedParameter(Parameter<Ethercat::DS402::TxPdoTypeEnum>(static_cast<Ethercat::DS402::TxPdoTypeEnum>(value.get<int>())));
    }    

    template<>
    inline WrappedParameter FromJsonToWrapped<Ethercat::DS402::RxPdoTypeEnum>(const nlohmann::json& value){

        return WrappedParameter(Parameter<Ethercat::DS402::RxPdoTypeEnum>(static_cast<Ethercat::DS402::RxPdoTypeEnum>(value.get<int>())));
    } 

    template<>
    inline WrappedParameter FromJsonToWrapped<Ethercat::DS402::ModeOfOperation>(const nlohmann::json& value){

        return WrappedParameter(Parameter<Ethercat::DS402::ModeOfOperation>(static_cast<Ethercat::DS402::ModeOfOperation>(value.get<int>())));
    }       

    template <ParameterType Type>
    struct ParameterTypeToType {};

    template <>
    struct ParameterTypeToType<ParameterType::Integer> {
        using type = int;
    };

    template <>
    struct ParameterTypeToType<ParameterType::Double> {
        using type = double;
    };

    template <>
    struct ParameterTypeToType<ParameterType::Float> {
        using type = float;
    };

    template <>
    struct ParameterTypeToType<ParameterType::Bool> {
        using type = bool;
    };

    template <>
    struct ParameterTypeToType<ParameterType::UnsignedInt> {
        using type = unsigned int;
    };

    template <>
    struct ParameterTypeToType<ParameterType::Char> {
        using type = char;
    };

    template <>
    struct ParameterTypeToType<ParameterType::Int32T> {
        using type = int32_t;
    };

     template <>
    struct ParameterTypeToType<ParameterType::Int8T> {
        using type = int8_t;
    };

    template <>
    struct ParameterTypeToType<ParameterType::String> {
        using type = std::string;
    };

    template <>
    struct ParameterTypeToType<ParameterType::SignedChar> {
        using type = char;
    };

    template <>
    struct ParameterTypeToType<ParameterType::PairDoubleDouble> {
        using type = std::pair<double,double>;
    };

    template <>
    struct ParameterTypeToType<ParameterType::PairBoolDouble> {
        using type = std::pair<bool,double>;
    };

    template <>
    struct ParameterTypeToType<ParameterType::PairStringString> {
        using type = std::pair<std::string, std::string>;
    };

    template <>
    struct ParameterTypeToType<ParameterType::RxPdoTypeEnum> {
        using type = Ethercat::DS402::RxPdoTypeEnum;
    };

    template <>
    struct ParameterTypeToType<ParameterType::TxPdoTypeEnum> {
        using type = Ethercat::DS402::RxPdoTypeEnum;
    };

    template <>
    struct ParameterTypeToType<ParameterType::ModeOfOperation> {
        using type = Ethercat::DS402::ModeOfOperation;
    };

    template <>
    struct ParameterTypeToType<ParameterType::ModeOfOperationVector> {
        using type = std::vector<Ethercat::DS402::ModeOfOperation>;
    };

    template <>
    struct ParameterTypeToType<ParameterType::DeviceType> {
        using type = Ethercat::Devices::SlaveType;
    };

    template <>
    struct ParameterTypeToType<ParameterType::DoubleVector> {
        using type = std::vector<double>;
    };

    template <>
    struct ParameterTypeToType<ParameterType::StringVector> {
        using type = std::vector<std::string>;
    };

     template <>
    struct ParameterTypeToType<ParameterType::UInt8T> {
        using type = uint8_t;
    };
               
    template <ParameterType Type>
    using ParameterTypeToType_t = typename ParameterTypeToType<Type>::type;

    template <ParameterType Type>
    inline ParameterTypeToType_t<Type> createInstance() {
        if constexpr (std::is_same_v<ParameterTypeToType_t<Type>, std::string>) {
            // Handle special case for std::string if needed
            return "DefaultString";
        } else {
            // Default initialization for other types
            return ParameterTypeToType_t<Type>{};
        }
    }

    template <ParameterType Type>
    inline typename ParameterTypeToType_t<Type>::type TypeFromParameterType() {
    return typename ParameterTypeToType_t<Type>::type{};     
    }

    template <ParameterType Type>
    inline WrappedParameter ObtainWrappedFromJson(nlohmann::json value){

        return FromJsonToWrapped<decltype(createInstance<Type>())>(value);
    }

    template<>
    inline WrappedParameter ObtainWrappedFromJson<ParameterType::ModeOfOperationVector>(nlohmann::json value){

        const auto& modeOfOperationArray = value["value"];
        std::vector<Ethercat::DS402::ModeOfOperation> modeOfOperationVector;

        for (const auto& mode : modeOfOperationArray) {
                            modeOfOperationVector.push_back(static_cast<Ethercat::DS402::ModeOfOperation>(mode.get<int>()));
        }

            return WrappedParameter(Parameter<std::vector<Ethercat::DS402::ModeOfOperation>>(modeOfOperationVector));
    }

} // namespace Controller

#endif // PARAMETER_H_