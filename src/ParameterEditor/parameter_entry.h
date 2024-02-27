#ifndef PARAMETERENTRY_H
#define PARAMETERENTRY_H

#include <memory>
#include "Parameter.h"
#include "QWrappedParameter.h"

class ParameterEntry {

    Q_GADGET
    Q_PROPERTY(QString key READ GetKey WRITE SetKey)
    Q_PROPERTY(QVariant value READ GetValue WRITE SetValue)
    //TODO add type 

public:
    ParameterEntry();
    ParameterEntry(const QString& key, QWrappedParameter wrapped);

    QString GetKey() const;
    void SetKey(QString key);

    QVariant GetValue() const;
    void SetValue(QVariant value);

    Controller::ParameterType GetType() const;

    Q_INVOKABLE bool isObject() const;
    Q_INVOKABLE bool isArray() const;
    Q_INVOKABLE bool isValue() const;

private:
    QString                 m_Key;
    QWrappedParameter       m_Wrapped;
};

Q_DECLARE_METATYPE(ParameterEntry)

#endif // PARAMETERENTRY_H