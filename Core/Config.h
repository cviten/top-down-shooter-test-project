//
// Created by cviten on 12/2/22.
//

#ifndef TOP_DOWN_SHOOTER_CONFIG_H
#define TOP_DOWN_SHOOTER_CONFIG_H

#include <string>

#include "CoreTypes.h"

class Config {
    MappingType<std::string, std::string> parameters;
public:
    void loadConfig(const std::string& filename);
    std::string get(std::string key) const;
    SpeedType getAsSpeed(std::string key) const;
};


#endif //TOP_DOWN_SHOOTER_CONFIG_H
