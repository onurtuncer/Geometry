
#ifndef TOOL_TABLE_ENTRY_H
#define TOOL_TABLE_ENTRY_H

#include <QString>
#include <QVariant>

class ToolTableEntry {
    Q_GADGET
    Q_PROPERTY(QString key READ PrettyKey WRITE SetKey)
    Q_PROPERTY(QVariant value READ Value WRITE SetValue NOTIFY ValueChanged)
    Q_PROPERTY(int type READ Type)
    Q_PROPERTY(QString path READ Path)

public:
    ToolTableEntry();
    ToolTableEntry(const QString& key, const QVariant& value, const int parameterType, const QString& path = QString(), QObject* parent = nullptr);

    QString Key() const;
    QString PrettyKey() const;
    void SetKey(const QString& key);

    QVariant Value() const;
    void SetValue(const QVariant& value);

    int Type() const;
    QString Path() const;

signals:
    void ValueChanged(const QVariant& value);
    void KeyChanged(const QString& key);

private:
    QString  m_key;
    QVariant m_value;
    int      m_type;
    QString  m_path;
};

Q_DECLARE_METATYPE(ToolTableEntry); // Add this line

#endif // TOOL_TABLE_ENTRY_H