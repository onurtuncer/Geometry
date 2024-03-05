#include "parameter_entry.h"
#include <QRegularExpression>

ParameterEntry::ParameterEntry(){}

ParameterEntry::ParameterEntry(const QString& key, const QVariant& value, const int parameterType, const QString& path, QObject* parent)
   : m_key(key), m_value(value), m_type(parameterType), m_path(path) {}

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

int ParameterEntry::type() const{

    return m_type;
}

QString ParameterEntry::path() const{

    return m_path;
}

void ParameterEntry::valueChanged(const QVariant& newValue) {
    // Emit the valueChanged signal
    emit valueChanged(newValue);
}

void ParameterEntry::keyChanged(const QString& newKey) {
    // Emit the keyChanged signal
    emit keyChanged(newKey);
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

// QString ParameterEntry::PrettyKey() const {
//     QString originalString = m_key;
//     QStringList parts;
    
//     // Split by underscore
//     QStringList underscoreParts = originalString.split('_');
//     for (const QString& part : underscoreParts) {
//         // Split camel case words
//         QStringList camelCaseParts = part.split(QRegularExpression("(?=[A-Z])"));
//         for (const QString& camelPart : camelCaseParts) {
//             parts.append(camelPart);
//         }
//     }
    
//     QString result;
//     for (int i = 0; i < parts.size(); ++i) {
//         QString part = parts.at(i);
//         if (i == 0 || part.toLower() != "of") {
//             // Capitalize first letter
//             part[0] = part[0].toUpper();
//         } else {
//             // Convert "of" to lowercase if not the first word
//             part = part.toLower();
//         }
//         result += part;
//     }
//     return result;
// }

