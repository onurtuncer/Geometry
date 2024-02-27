#include "parameter_entry.h"

ParameterEntry::ParameterEntry(){}

ParameterEntry::ParameterEntry(const QString& key, const QVariant& value, QObject* parent)
   : m_key(key), m_value(value) {}

QString ParameterEntry::key() const {

    return m_key;
}

void ParameterEntry::setKey(const QString& key) {

    if (m_key == key) return; 

    m_key = key;
    emit keyChanged(m_key);
}

QVariant ParameterEntry::value() const {

    return m_value;
}

void ParameterEntry::setValue(const QVariant& value) {
    
    if (m_value == value) return; 

    m_value = value;
    emit valueChanged(m_value);
}

void ParameterEntry::valueChanged(const QVariant& newValue) {
    // Emit the valueChanged signal
    emit valueChanged(newValue);
}

void ParameterEntry::keyChanged(const QString& newKey) {
    // Emit the keyChanged signal
    emit keyChanged(newKey);
}
