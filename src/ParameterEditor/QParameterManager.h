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
    static QParameterManager* instance();

    Q_INVOKABLE void updateParameter(const QString& path, const QVariant& value, const int type);

  signals:
    void parameterUpdated(const QString& path, const QVariant& value);

 private:
     QParameterManager(QObject *parent = nullptr);
    static QParameterManager* m_instance;
};

#endif // QPARAMETERMANAGER_H