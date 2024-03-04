#include "QParameterManager.h"

void QParameterManager::updateParameter(const QString& path, const QVariant& value) {

    QWrappedParameter wrappedValue;
    wrappedValue.fromQVariant(value);

    Controller::ParameterManager::UpdateParameter(path.toStdString(), wrappedValue.toWrappedParameter());

    emit parameterUpdated(path, value);
}