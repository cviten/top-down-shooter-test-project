//
// Created by cviten on 12/18/22.
//

#include "GameLog.h"

#include <iostream>

GameLog::LogEntry::LogEntry(GameLog::Severity level, const std::string_view& message) : level(level),
                                                                                        message(message) {}

std::string_view GameLog::getLevelString(GameLog::Severity level) {
    switch (level) {
        case Fatal:
            return "[Fatal]";
        case Error:
            return "[Error]";;
        case Warning:
            return "[Warning]";;
        case Info:
            return "[Info]";;
        case Trace:
            return "[Trace]";;
    }
}

void GameLog::operator()(GameLog::Severity level, std::string_view msg) {
    entries.emplace_back(level, msg);
    if(immediateOutput)
        std::clog << getLevelString(level) << " " << msg << "\n";
}
