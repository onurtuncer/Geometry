#pragma once

#include <vector>
#include <string>
#include <json.hpp>
#include "Core/ParameterManager.h"

namespace Controller {

// To manage shared parameters between different channeles based on id"

class ServoParameters {
public:
    std::string id;
    ParameterManager parameters;

    // Deserialize from JSON
    static ServoParameters fromJson(const nlohmann::json& json) {
        ServoParameters servo;
        servo.id = json.at("id").get<std::string>();
        const auto& paramJson = json.at("parameters");
        for (auto it = paramJson.begin(); it != paramJson.end(); ++it) {
            servo.parameters.setParameter(it.key(), it.value());
        }
        return servo;
    }

    // Serialize to JSON
    nlohmann::json toJson() const {
        nlohmann::json json;
        json["id"] = id;
        json["parameters"] = parameters.toJson();
        return json;
    }
};

} // namespace Controller
