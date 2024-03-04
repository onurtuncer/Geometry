#ifndef QPARAMETERMANAGER_H
#define QPARAMETERMANAGER_H

#include <QObject>
#include "ParameterManager.h"
#include "QWrappedParameter.h"

class QParameterManager : public QObject, public Controller::ParameterManager {
    Q_OBJECT

public slots:
    void updateParameter(const QString& path, const QVariant& value);

signals:
    void parameterUpdated(const QString& path, const QVariant& value);
};

#endif // QPARAMETERMANAGER_H
