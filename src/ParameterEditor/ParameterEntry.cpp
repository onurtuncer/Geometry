#include "ParameterEntry.h"
#include <QRegularExpression>

ParameterEntry::ParameterEntry(){}

ParameterEntry::ParameterEntry(const QString& key, const QVariant& value, const int parameterType, const QString& path, QObject* parent)
   : m_key(key), m_value(value), m_type(parameterType), m_path(path) {}

QString ParameterEntry::Key() const {

    return m_key;
}

void ParameterEntry::SetKey(const QString& key) {

    if (m_key == key) return; 

    m_key = key;
    emit KeyChanged(m_key);
}

QVariant ParameterEntry::Value() const {

    return m_value;
}

void ParameterEntry::SetValue(const QVariant& value) {
    
    if (m_value == value) return; 

    m_value = value;
    emit ValueChanged(m_value);
}

int ParameterEntry::Type() const{

    return m_type;
}

QString ParameterEntry::Path() const{

    return m_path;
}

void ParameterEntry::ValueChanged(const QVariant& newValue) {
    // Emit the valueChanged signal
    emit ValueChanged(newValue);
}

void ParameterEntry::KeyChanged(const QString& newKey) {
    // Emit the keyChanged signal
    emit KeyChanged(newKey);
}

QString ParameterEntry::PrettyKey() const{

    QString originalString = m_key;
    QStringList parts = originalString.split('_');
    QString result;
    for (int i = 0; i < parts.size(); ++i) {
        QString part = parts.at(i);
        if (i == 0 || part.toLower() != "of") {
            // Capitalize first letter
            part[0] = part[0].toUpper();
        }
        result += part + " ";
    }
    // Remove trailing space
    result = result.trimmed();
    return result;
}