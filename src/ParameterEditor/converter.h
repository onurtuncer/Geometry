#pragma once 

#include "ParameterEntry.h"
#include "JsonEntry.h"

ParameterEntry* convertToParameterEntry(const JsonEntry* jsonEntry) {
    
    ParameterEntry* parameterEntry = new ParameterEntry();
    parameterEntry->setKey(jsonEntry->key());
    parameterEntry->setValue(jsonEntry->value());
    parameterEntry->setType(jsonEntry->type());

    // If it's an object or array, recursively convert its children
    if (jsonEntry->isObject() || jsonEntry->isArray()) {
        QList<ParameterEntry*> childList;
        for (JsonEntry* child : jsonEntry->children()) {
            ParameterEntry* convertedChild = convertToParameterEntry(child);
            childList.append(convertedChild);
        }
        parameterEntry->setValue(QVariant::fromValue(childList));
    }

    return parameterEntry;
}

ParameterEntry* traverseAndConvert(const JsonEntry* root) {
    if (!root)
        return nullptr;

    return convertToParameterEntry(root);
}
