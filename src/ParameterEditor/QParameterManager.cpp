#include "QParameterManager.h"

QParameterManager* QParameterManager::m_instance = nullptr;

QParameterManager::QParameterManager(QObject *parent) : QObject(parent) {
    // Constructor implementation, if needed
}

QParameterManager* QParameterManager::instance() {
    if (!m_instance) {
        m_instance = new QParameterManager();
    }
    return m_instance;
}

void QParameterManager::updateParameter(const QString& path, const QVariant& value, const int type) {

    QWrappedParameter qWrappedValue;
    qWrappedValue.fromQVariantAndType(value, type);
    Controller::ParameterManager::UpdateParameter(path.toStdString(), qWrappedValue.toWrappedParameter());
    emit parameterUpdated(path, value);
}
