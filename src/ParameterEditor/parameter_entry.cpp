#include "parameter_entry.h"

/* ParameterEntry::ParameterEntry()
    : _type(Controller::ParameterType::Unknown
{}
 */
ParameterEntry::ParameterEntry(const QString& key, QWrappedParameter wrapped)
    : m_Key(key)
    , m_Wrapped(QWrappedParameter(wrapped))
{}

QString ParameterEntry::GetKey() const {

    return m_Key;
}

QVariant ParameterEntry::GetValue() const {

   return m_Wrapped.toQVariant();
}

Controller::ParameterType ParameterEntry::GetType() const {

    return m_Wrapped.GetType();
}

void ParameterEntry::SetKey(QString key){

    if (m_Key == key) return;
    m_Key = key;
}

void ParameterEntry::SetValue(QVariant value){

    m_Wrapped.fromQVariant(value);
}

bool ParameterEntry::isObject() const{

    return false;
}

bool ParameterEntry::isArray() const{

    return (m_Wrapped.GetType() == Controller::ParameterType::StringVector) ||
           (m_Wrapped.GetType() == Controller::ParameterType::DoubleVector) ;  // TODO need to add some more!
}

bool ParameterEntry::isValue() const{

    return !(isObject() || isArray());
}