#include "QParameterManager.h"
#include <iostream>

QParameterManager* QParameterManager::m_instance = nullptr;

QParameterManager::QParameterManager(QObject *parent) : QObject(parent) {

    connect(this, &QParameterManager::ParameterUpdated, this, &QParameterManager::SendParameterJSON);
}

QParameterManager* QParameterManager::Instance() {
    
    if (!m_instance) {
        m_instance = new QParameterManager();
    }
    return m_instance;
}

void QParameterManager::UpdateParameter(const QString& path, const QVariant& value, const int type) {

   // QWrappedParameter qWrappedValue;
    auto qWrappedValue = QWrappedParameter::fromQVariantAndType(value, type);
    Controller::ParameterManager::UpdateParameter(path.toStdString(), qWrappedValue.toWrappedParameter());
    emit ParameterUpdated(path, value);
}

void QParameterManager::SendParameterJSON(){

    auto json = Serialize();
    std::cout << json.dump(4) << std::endl; // Output JSON to the console with an indent of 4 spaces
}