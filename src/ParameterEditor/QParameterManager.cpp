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

std::vector<std::string> QParameterManager::GetToolNames() const {

    std::vector<std::string> toolNames;
    std::vector<std::pair<std::string, Controller::WrappedParameter>> toolParameters = GetToolParameters();

    for (const auto& pair : toolParameters) {
        const std::string& paramName = pair.first;
        // Extract tool name
        std::size_t pos = paramName.find('.', 6); // Find the first '.' after "tools."
        if (pos != std::string::npos) {
            std::string toolName = paramName.substr(6, pos - 6); // Extract the tool name
            toolNames.push_back(toolName);
        }
    }
    
    // Sort the tool names alphabetically
    std::sort(toolNames.begin(), toolNames.end());
    return toolNames;
}

std::vector<std::pair<std::string, Controller::WrappedParameter>> QParameterManager::GetToolParameters() const {

    std::vector<std::pair<std::string, Controller::WrappedParameter>> toolParameters;

    for (const auto& pair : GetParameters()) {
        const std::string& paramName = pair.first;
        if (paramName.find("tools.") == 0) { // Check if the parameter key starts with "tools."
            toolParameters.emplace_back(paramName, pair.second);
        }
    }
    return toolParameters;
}