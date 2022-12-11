//
// Created by cviten on 12/2/22.
//

#include "Config.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <locale>

#include "Util.h"

std::string toLowercase(std::string&& str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

void Config::loadConfig(const std::string& filename) {
    std::ifstream configFile(filename);
    if (configFile.is_open())
    {
        std::string line;
        while(getline(configFile, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                       line.end());
            if(line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            auto key = toLowercase(line.substr(0, delimiterPos));
            auto value = toLowercase(line.substr(delimiterPos + 1));
            parameters.insert({key, value});
        }

    }
    else {
        std::cerr << "Couldn't open config file for reading.\n";
    }
}

std::string Config::get(std::string key) const {
    return getValueOrDefault(parameters, toLowercase(std::move(key)));
}

SpeedType Config::getAsSpeed(std::string key) const {
    std::istringstream stream(get(key));
    SpeedType value;
    if(stream >> value) return value;
    std::cerr << "Couldn't parse value of " << key << " as speed or there is no value\n";
    return {};
}
