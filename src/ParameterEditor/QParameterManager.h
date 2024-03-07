#ifndef QPARAMETERMANAGER_H
#define QPARAMETERMANAGER_H

#include <QObject>
#include <QtQml>
#include "ParameterManager.h"
#include "QWrappedParameter.h"

class QParameterManager : public QObject, public Controller::ParameterManager {
    Q_OBJECT
    QML_ELEMENT

public:
    static QParameterManager* Instance();

    Q_INVOKABLE void UpdateParameter(const QString& path, const QVariant& value, const int type);

signals:
    void ParameterUpdated(const QString& path, const QVariant& value);

public slots:
    void SendParameterJSON();

private:
    QParameterManager(QObject *parent = nullptr);
    static QParameterManager* m_instance;
};

#endif // QPARAMETERMANAGER_H