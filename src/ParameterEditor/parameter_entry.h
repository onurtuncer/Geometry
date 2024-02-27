
#ifndef PARAMETER_ENTRY_H
#define PARAMETER_ENTRY_H

#include <QString>
#include <QVariant>

// #include "parameter_entry.moc"

class ParameterEntry {
    Q_GADGET
    Q_PROPERTY(QString key READ PrettyKey WRITE setKey)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int type READ type)

public:
    ParameterEntry();
    ParameterEntry(const QString& key, const QVariant& value, const int parameterType, QObject* parent = nullptr);

    QString key() const;
    QString PrettyKey() const;
    void setKey(const QString& key);

    QVariant value() const;
    void setValue(const QVariant& value);

    int type() const;

signals:
    void valueChanged(const QVariant& value);
    void keyChanged(const QString& key);

private:
    QString  m_key;
    QVariant m_value;
    int      m_type;
};

Q_DECLARE_METATYPE(ParameterEntry); // Add this line

#endif // PARAMETER_ENTRY_H