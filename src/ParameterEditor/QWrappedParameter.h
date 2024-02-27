#ifndef QWRAPPEDPARAMETER_H
#define QWRAPPEDPARAMETER_H

#include <memory>
#include "Parameter.h"
#include <QVariant>
#include <QDebug> 

// Namespace aliases
namespace Ctrl = Controller;
namespace Ethercat = Controller::Ethercat;
namespace Devices = Controller::Ethercat::Devices;
namespace DS402 = Controller::Ethercat::DS402;

class QWrappedParameter {

public:
    QWrappedParameter() {}
    QWrappedParameter(Ctrl::WrappedParameter wrappedParameter) : m_parameter(wrappedParameter) {}

    Ctrl::ParameterType GetType() const { return m_parameter.GetType();}

    QVariant toQVariant() const {

        QVariant variant;

        switch (GetType()) {
            case Ctrl::ParameterType::Bool:
                variant.setValue(m_parameter.GetParameter<bool>().getValue());
                break;
            case Ctrl::ParameterType::Integer:
                variant.setValue(m_parameter.GetParameter<int>().getValue());
                break;
            case Ctrl::ParameterType::UnsignedInt:
                variant.setValue(m_parameter.GetParameter<unsigned int>().getValue());
                break;
            case Ctrl::ParameterType::Double:
                variant.setValue(m_parameter.GetParameter<double>().getValue());
                break;
            case Ctrl::ParameterType::Float:
                variant.setValue(m_parameter.GetParameter<float>().getValue());
                break;
            case Ctrl::ParameterType::Char:
                variant.setValue(m_parameter.GetParameter<char>().getValue());
                break;
            case Ctrl::ParameterType::String:
                variant.setValue(QString::fromStdString(m_parameter.GetParameter<std::string>().getValue()));
                break;
            case Ctrl::ParameterType::PairDoubleDouble: {
                auto pair = m_parameter.GetParameter<std::pair<double, double>>().getValue();
                QVariantList list;
                list.append(pair.first);
                list.append(pair.second);
                variant.setValue(list);
                break;
            }
            case Ctrl::ParameterType::PairStringString: {
                auto pair = m_parameter.GetParameter<std::pair<std::string, std::string>>().getValue();
                QVariantList list;
                list.append(QString::fromStdString(pair.first));
                list.append(QString::fromStdString(pair.second));
                variant.setValue(list);
                break;
            }
            case Ctrl::ParameterType::SignedChar:
                variant.setValue(m_parameter.GetParameter<signed char>().getValue());
                break;
            case Ctrl::ParameterType::ModeOfOperation:
                variant.setValue(static_cast<int>(m_parameter.GetParameter<DS402::ModeOfOperation>().getValue()));
                break;
            case Ctrl::ParameterType::ModeOfOperationVector: {
                auto vector = m_parameter.GetParameter<std::vector<DS402::ModeOfOperation>>().getValue();
                QVariantList list;
                for (const auto& mode : vector) {
                    list.append(static_cast<int>(mode));
                }
                variant.setValue(list);
                break;
            }
            case Ctrl::ParameterType::PairBoolDouble: {
                auto pair = m_parameter.GetParameter<std::pair<bool, double>>().getValue();
                QVariantList list;
                list.append(pair.first);
                list.append(pair.second);
                variant.setValue(list);
                break;
            }
            case Ctrl::ParameterType::RxPdoTypeEnum:
                variant.setValue(static_cast<int>(m_parameter.GetParameter<DS402::RxPdoTypeEnum>().getValue()));
                break;
            case Ctrl::ParameterType::TxPdoTypeEnum:
                variant.setValue(static_cast<int>(m_parameter.GetParameter<DS402::TxPdoTypeEnum>().getValue()));
                break;
            case Ctrl::ParameterType::DeviceType:
                variant.setValue(static_cast<int>(m_parameter.GetParameter<Devices::SlaveType>().getValue()));
                break;
            case Ctrl::ParameterType::Int32T:
                variant.setValue(m_parameter.GetParameter<int32_t>().getValue());
                break;
            case Ctrl::ParameterType::Int8T:
                variant.setValue(m_parameter.GetParameter<int8_t>().getValue());
                break;
            case Ctrl::ParameterType::DoubleVector: {
                auto vector = m_parameter.GetParameter<std::vector<double>>().getValue();
                QVariantList list;
                for (const auto& value : vector) {
                    list.append(value);
                }
                variant.setValue(list);
                break;
            }
            case Ctrl::ParameterType::StringVector: {
                auto vector = m_parameter.GetParameter<std::vector<std::string>>().getValue();
                QVariantList list;
                for (const auto& value : vector) {
                    list.append(QString::fromStdString(value));
                }
                variant.setValue(list);
                break;
            }
            case Ctrl::ParameterType::UInt8T:
                variant.setValue(m_parameter.GetParameter<uint8_t>().getValue());
                break;
            default:
                qDebug() << "Unsupported parameter type";
                break;
        }

        return variant;
    }

   void fromQVariant(const QVariant& variant) {

    switch (GetType()) {
        case Controller::ParameterType::Bool:
            m_parameter = Controller::WrappedParameter(Controller::Parameter<bool>(variant.toBool()));
            break;
        case Controller::ParameterType::Integer:
            m_parameter = Controller::WrappedParameter(Controller::Parameter<int>(variant.toInt()));
            break;
        case Controller::ParameterType::UnsignedInt:
            m_parameter = Controller::WrappedParameter(Controller::Parameter<unsigned int>(variant.toUInt()));
            break;
        case Controller::ParameterType::Double:
            m_parameter = Controller::WrappedParameter(Controller::Parameter<double>(variant.toDouble()));
            break;
        case Controller::ParameterType::Float:
            m_parameter = Controller::WrappedParameter(Controller::Parameter<float>(variant.toFloat()));
            break;
        case Controller::ParameterType::Char:
            m_parameter = Controller::WrappedParameter(Controller::Parameter<char>(variant.toChar().toLatin1()));
            break;
        case Controller::ParameterType::String:
            m_parameter = Controller::WrappedParameter(Controller::Parameter<std::string>(variant.toString().toStdString()));
            break;
        case Controller::ParameterType::PairDoubleDouble: {
            QVariantList list = variant.toList();
            auto pair = std::make_pair(list[0].toDouble(), list[1].toDouble());
            m_parameter = Controller::WrappedParameter(Controller::Parameter<std::pair<double, double>>(pair));
            break;
        }
        case Controller::ParameterType::PairStringString: {
            QVariantList list = variant.toList();
            auto pair = std::make_pair(list[0].toString().toStdString(), list[1].toString().toStdString());
            m_parameter = Controller::WrappedParameter(Controller::Parameter<std::pair<std::string, std::string>>(pair));
            break;
        }
        // Handle other parameter types here
        default:
            qDebug() << "Unsupported parameter type";
            break;
    }
  }

private:
    Ctrl::WrappedParameter m_parameter; //TODO replace this with a shared ptr
};

Q_DECLARE_METATYPE(Controller::WrappedParameter)

#endif // QWRAPPEDPARAMETER_H


// #ifndef QWRAPPEDPARAMETER_H
// #define QWRAPPEDPARAMETER_H

// #include <memory>
// #include "Parameter.h"
// #include <QVariant>

// class QWrappedParameter {

//   public:
//     QWrappedParameter() {}
//     QWrappedParameter(Controller::WrappedParameter wrappedParameter) : m_parameter(wrappedParameter) {}

//     QVariant toQVariant() {
        
//         QVariant variant;

//         switch (m_parameter.GetType()) {
//             case Controller::ParameterType::Bool:
//                 variant.setValue(m_parameter.GetParameter<bool>().getValue());
//                 break;
//             case Controller::ParameterType::Integer:
//                 variant.setValue(m_parameter.GetParameter<int>().getValue());
//                 break;
//             case Controller::ParameterType::UnsignedInt:
//                 variant.setValue(m_parameter.GetParameter<unsigned int>().getValue());
//                 break;
//             case Controller::ParameterType::Double:
//                 variant.setValue(m_parameter.GetParameter<double>().getValue());
//                 break;
//             case Controller::ParameterType::Float:
//                 variant.setValue(m_parameter.GetParameter<float>().getValue());
//                 break;
//             case Controller::ParameterType::Char:
//                 variant.setValue(m_parameter.GetParameter<char>().getValue());
//                 break;
//             case Controller::ParameterType::String:
//                 variant.setValue(QString::fromStdString(m_parameter.GetParameter<std::string>().getValue()));
//                 break;
//             case Controller::ParameterType::PairDoubleDouble: {
//                 auto pair = m_parameter.GetParameter<std::pair<double, double>>().getValue();
//                 QVariantList list;
//                 list.append(pair.first);
//                 list.append(pair.second);
//                 variant.setValue(list);
//                 break;
//             }
//             case Controller::ParameterType::PairStringString: {
//                 auto pair = m_parameter.GetParameter<std::pair<std::string, std::string>>().getValue();
//                 QVariantList list;
//                 list.append(QString::fromStdString(pair.first));
//                 list.append(QString::fromStdString(pair.second));
//                 variant.setValue(list);
//                 break;
//             }
//             case Controller::ParameterType::SignedChar:
//                 variant.setValue(m_parameter.GetParameter<signed char>().getValue());
//                 break;
//             case Controller::ParameterType::ModeOfOperation:
//                 variant.setValue(static_cast<int>(m_parameter.GetParameter<Controller::Ethercat::DS402::ModeOfOperation>().getValue()));
//                 break;
//             case Controller::ParameterType::ModeOfOperationVector: {
//                 auto vector = m_parameter.GetParameter<std::vector<Controller::Ethercat::DS402::ModeOfOperation>>().getValue();
//                 QVariantList list;
//                 for (const auto& mode : vector) {
//                     list.append(static_cast<int>(mode));
//                 }
//                 variant.setValue(list);
//                 break;
//             }
//             case Controller::ParameterType::PairBoolDouble: {
//                 auto pair = m_parameter.GetParameter<std::pair<bool, double>>().getValue();
//                 QVariantList list;
//                 list.append(pair.first);
//                 list.append(pair.second);
//                 variant.setValue(list);
//                 break;
//             }
//             case Controller::ParameterType::RxPdoTypeEnum:
//                 variant.setValue(static_cast<int>(m_parameter.GetParameter<Controller::Ethercat::DS402::RxPdoTypeEnum>().getValue()));
//                 break;
//             case Controller::ParameterType::TxPdoTypeEnum:
//                 variant.setValue(static_cast<int>(m_parameter.GetParameter<Controller::Ethercat::DS402::TxPdoTypeEnum>().getValue()));
//                 break;
//             case Controller::ParameterType::DeviceType:
//                 variant.setValue(static_cast<int>(m_parameter.GetParameter<Controller::Ethercat::Devices::SlaveType>().getValue()));
//                 break;
//             case Controller::ParameterType::Int32T:
//                 variant.setValue(m_parameter.GetParameter<int32_t>().getValue());
//                 break;
//             case Controller::ParameterType::Int8T:
//                 variant.setValue(m_parameter.GetParameter<int8_t>().getValue());
//                 break;
//             case Controller::ParameterType::DoubleVector: {
//                 auto vector = m_parameter.GetParameter<std::vector<double>>().getValue();
//                 QVariantList list;
//                 for (const auto& value : vector) {
//                     list.append(value);
//                 }
//                 variant.setValue(list);
//                 break;
//             }
//             case Controller::ParameterType::StringVector: {
//                 auto vector = m_parameter.GetParameter<std::vector<std::string>>().getValue();
//                 QVariantList list;
//                 for (const auto& value : vector) {
//                     list.append(QString::fromStdString(value));
//                 }
//                 variant.setValue(list);
//                 break;
//             }
//             case Controller::ParameterType::UInt8T:
//                 variant.setValue(m_parameter.GetParameter<uint8_t>().getValue());
//                 break;
//             default:
//                 qDebug() << "Unsupported parameter type";
//                 break;
//         }

//         return variant;
//     }

//     // void fromQVariant(const QVariant& variant) {

//     //     switch (variant.type()) {
//     //         case QVariant::Bool:
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<bool>(variant.toBool()));
//     //             break;
//     //         case QVariant::Int:
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<int>(variant.toInt()));
//     //             break;
//     //         case QVariant::UInt:
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<unsigned int>(variant.toUInt()));
//     //             break;
//     //         case QVariant::Double:
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<double>(variant.toDouble()));
//     //             break;
//     //         case QVariant::String:
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<std::string>(variant.toString().toStdString()));
//     //             break;
//     //         case QVariant::Char:
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<char>(variant.toChar().toLatin1()));
//     //             break;
//     //         case QVariant::List: {
//     //             QVariantList list = variant.toList();
//     //             std::vector<double> vector;
//     //             for (const auto& item : list) {
//     //                 vector.push_back(item.toDouble());
//     //             }
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<std::vector<double>>(vector));
//     //             break;
//     //         }
//     //         case QVariant::StringList: {
//     //             QStringList stringList = variant.toStringList();
//     //             std::vector<std::string> vector;
//     //             for (const auto& str : stringList) {
//     //                 vector.push_back(str.toStdString());
//     //             }
//     //             m_parameter = Controller::WrappedParameter(Controller::Parameter<std::vector<std::string>>(vector));
//     //             break;
//     //         }
//     //         // Handle other QVariant types here
//     //         default:
//     //             qDebug() << "Unsupported QVariant type";
//     //             break;
//     //     }
//     // }

//     void fromQVariant(const QVariant& variant) {
//     switch (m_parameter.GetType()) {
//         case Controller::ParameterType::Bool:
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<bool>(variant.toBool()));
//             break;
//         case Controller::ParameterType::Integer:
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<int>(variant.toInt()));
//             break;
//         case Controller::ParameterType::UnsignedInt:
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<unsigned int>(variant.toUInt()));
//             break;
//         case Controller::ParameterType::Double:
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<double>(variant.toDouble()));
//             break;
//         case Controller::ParameterType::Float:
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<float>(variant.toFloat()));
//             break;
//         case Controller::ParameterType::Char:
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<char>(variant.toChar().toLatin1()));
//             break;
//         case Controller::ParameterType::String:
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<std::string>(variant.toString().toStdString()));
//             break;
//         case Controller::ParameterType::PairDoubleDouble: {
//             QVariantList list = variant.toList();
//             auto pair = std::make_pair(list[0].toDouble(), list[1].toDouble());
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<std::pair<double, double>>(pair));
//             break;
//         }
//         case Controller::ParameterType::PairStringString: {
//             QVariantList list = variant.toList();
//             auto pair = std::make_pair(list[0].toString().toStdString(), list[1].toString().toStdString());
//             m_parameter = Controller::WrappedParameter(Controller::Parameter<std::pair<std::string, std::string>>(pair));
//             break;
//         }
//         // Handle other parameter types here
//         default:
//             qDebug() << "Unsupported parameter type";
//             break;
//     }
// }




// private:
//     Controller::WrappedParameter m_parameter; //TODO replace this with a shared ptr
// };

//  Q_DECLARE_METATYPE(Controller::WrappedParameter)

// #endif // QWRAPPEDPARAMETER_H