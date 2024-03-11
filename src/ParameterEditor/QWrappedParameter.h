#ifndef QWRAPPEDPARAMETER_H
#define QWRAPPEDPARAMETER_H

#include <memory>
#include "Parameter.h"
#include <QVariant>
#include <QDebug> 

namespace Ctrl = Controller;
namespace Ethercat = Controller::Ethercat;
namespace Devices = Controller::Ethercat::Devices;
namespace DS402 = Controller::Ethercat::DS402;

class QWrappedParameter {

public:
    QWrappedParameter() {}
    QWrappedParameter(Ctrl::WrappedParameter wrappedParameter) : m_parameter(wrappedParameter) {}

    Ctrl::ParameterType GetType() const { return m_parameter.GetType();}

    Ctrl::WrappedParameter toWrappedParameter() const {return m_parameter;}
    static QWrappedParameter fromWrappedParameter(Ctrl::WrappedParameter wrappedParameter) { return QWrappedParameter(wrappedParameter);}

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
                    QString convertedValue = QString::fromUtf8(value.c_str(), value.length());
                    list.append(convertedValue);
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

  static QWrappedParameter fromQVariantAndType(const QVariant& variant, const int type) {

    Ctrl::WrappedParameter wrappedParameter;

    switch (static_cast<Ctrl::ParameterType>(type)) {
        case Ctrl::ParameterType::Bool:
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<bool>(variant.toBool()));
            break;
        case Ctrl::ParameterType::Integer:
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<int>(variant.toInt()));
            break;
        case Ctrl::ParameterType::UnsignedInt:
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<unsigned int>(variant.toUInt()));
            break;
        case Ctrl::ParameterType::Double:
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<double>(variant.toDouble()));
            break;
        case Ctrl::ParameterType::Float:
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<float>(variant.toFloat()));
            break;
        case Ctrl::ParameterType::Char:
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<char>(variant.toChar().toLatin1()));
            break;
        case Ctrl::ParameterType::String:
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<std::string>(variant.toString().toStdString()));
            break;
        case Ctrl::ParameterType::PairDoubleDouble: {
            QVariantList list = variant.toList();
            auto pair = std::make_pair(list[0].toDouble(), list[1].toDouble());
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<std::pair<double, double>>(pair));
            break;
        }
        case Ctrl::ParameterType::PairBoolDouble: {
          QVariantList list = variant.toList();
          auto pair = std::make_pair(list[0].toBool(), list[1].toDouble());
          wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<std::pair<bool, double>>(pair));
          break;
       }
       case Ctrl::ParameterType::PairStringString: {
            QVariantList list = variant.toList();
            auto pair = std::make_pair(list[0].toString().toStdString(), list[1].toString().toStdString());
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<std::pair<std::string, std::string>>(pair));
            break;
        }
        case Ctrl::ParameterType::DoubleVector: {
            QVariantList list = variant.toList();
            std::vector<double> vector;
            for (const QVariant& item : list) {
                vector.push_back(item.toDouble());
            }
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<std::vector<double>>(vector));
            break;
        }
        case Ctrl::ParameterType::StringVector: {
            QVariantList list = variant.toList();
            std::vector<std::string> vector;
            for (const QVariant& item : list) {
                vector.push_back(item.toString().toStdString());
            }
            wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<std::vector<std::string>>(vector));
            break;
        }
        case Ctrl::ParameterType::RxPdoTypeEnum: {
          wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<DS402::RxPdoTypeEnum>(static_cast<DS402::RxPdoTypeEnum>(variant.toInt())));
          break;
       }
       case Ctrl::ParameterType::TxPdoTypeEnum: {
          wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<DS402::TxPdoTypeEnum>(static_cast<DS402::TxPdoTypeEnum>(variant.toInt())));
          break;
       }
       case Ctrl::ParameterType::ModeOfOperation: {
          wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<DS402::ModeOfOperation>(static_cast<DS402::ModeOfOperation>(variant.toInt())));
          break;
       }
       case Ctrl::ParameterType::DeviceType: {
          wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<Devices::SlaveType>(static_cast<Ctrl::Ethercat::Devices::SlaveType>(variant.toInt())));
          break;
       }
       case Ctrl::ParameterType::ModeOfOperationVector: {
          QVariantList list = variant.toList();
          std::vector<DS402::ModeOfOperation> vector;
          for (const QVariant& item : list) {
            vector.push_back(static_cast<DS402::ModeOfOperation>(item.toInt()));
          }
          wrappedParameter = Ctrl::WrappedParameter(Ctrl::Parameter<std::vector<DS402::ModeOfOperation>>(vector));
          break;
        }
        // Handle other parameter types here
        default:
            qDebug() << "Unsupported parameter type, with type enumaration:" << type;
            break;
    }

    return QWrappedParameter(wrappedParameter);
}

private:
    Ctrl::WrappedParameter m_parameter; //TODO replace this with a shared ptr
};


#endif // QWRAPPEDPARAMETER_H