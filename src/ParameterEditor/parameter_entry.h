
#ifndef PARAMETER_ENTRY_H
#define PARAMETER_ENTRY_H

#include <QString>
#include <QVariant>

// #include "parameter_entry.moc"

class ParameterEntry {
    Q_GADGET
    Q_PROPERTY(QString key READ key WRITE setKey)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:
    ParameterEntry();
    ParameterEntry(const QString& key, const QVariant& value, QObject* parent = nullptr);

    QString key() const;
    void setKey(const QString& key);

    QVariant value() const;
    void setValue(const QVariant& value);

signals:
    void valueChanged(const QVariant& value);
    void keyChanged(const QString& key);

private:
    QString m_key;
    QVariant m_value;
};

Q_DECLARE_METATYPE(ParameterEntry); // Add this line

#endif // PARAMETER_ENTRY_H