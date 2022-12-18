//
// Created by cviten on 12/18/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMELOG_H
#define TOP_DOWN_SHOOTER_GAMELOG_H

#include <vector>
#include <string_view>



class GameLog {
public:
    enum Severity { Fatal, Error, Warning, Info, Trace };
private:
    struct LogEntry
    {
        Severity level;
        std::string_view message;

        LogEntry(Severity level, const std::string_view& message);
    };

    Severity outputLevel = Info;
    std::vector<LogEntry> entries;
    bool immediateOutput = true;
public:

    static std::string_view getLevelString(Severity level);

    void setImmediateOutput(bool immediate) {
        GameLog::immediateOutput = immediate;
    }

    void setCurrentLevel(Severity level) { outputLevel = level;}
    Severity getCurrentLevel() const {
        return outputLevel;
    }

    void operator()(Severity level, std::string_view msg);
};


#endif //TOP_DOWN_SHOOTER_GAMELOG_H
