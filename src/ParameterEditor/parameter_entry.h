
#ifndef PARAMETER_ENTRY_H
#define PARAMETER_ENTRY_H

#include <QString>
#include <QVariant>

class ParameterEntry {
    Q_GADGET
    Q_PROPERTY(QString key READ PrettyKey WRITE setKey)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int type READ type)
    Q_PROPERTY(QString path READ path)

    // enum ParameterType {
    //     Unknown = 0,
    //     Integer,
    //     UnsignedInt,
    //     Double,
    //     Float,
    //     Bool,
    //     Char,
    //     String,
    //     SignedChar,
    //     PairDoubleDouble,
    //     PairBoolDouble,
    //     PairStringString,
    //     RxPdoTypeEnum,
    //     TxPdoTypeEnum,
    //     ModeOfOperation,
    //     ModeOfOperationVector,
    //     DeviceType,
    //     Int32T,
    //     Int8T,
    //     DoubleVector,
    //     StringVector,
    //     UInt8T
    // };

public:
    ParameterEntry();
    ParameterEntry(const QString& key, const QVariant& value, const int parameterType, const QString& path = QString(), QObject* parent = nullptr);

    QString key() const;
    QString PrettyKey() const;
    void setKey(const QString& key);

    QVariant value() const;
    void setValue(const QVariant& value);

    int type() const;
    QString path() const;

signals:
    void valueChanged(const QVariant& value);
    void keyChanged(const QString& key);

private:
    QString  m_key;
    QVariant m_value;
    int      m_type;
    QString  m_path;
};

Q_DECLARE_METATYPE(ParameterEntry); // Add this line

#endif // PARAMETER_ENTRY_H