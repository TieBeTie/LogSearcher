#pragma once
#include "FilterKey.hpp"
#include <string>

enum class LogLevelType {
    Debug,
    Info,
    Warning,
    Error,
    Critical
};

class LogLevel : public FilterKey {
public:
    LogLevel(const std::string& key) : FilterKey(key) {
        if (key == "Debug") level = LogLevelType::Debug;
        else if (key == "Info") level = LogLevelType::Info;
        else if (key == "Warning") level = LogLevelType::Warning;
        else if (key == "Error") level = LogLevelType::Error;
        else if (key == "Critical") level = LogLevelType::Critical;
        else level = LogLevelType::Info; // default
    }
    LogLevel(LogLevelType level) : FilterKey(levelToString(level)), level(level) {}
    LogLevelType getLevel() const { return level; }

    bool operator==(const LogLevel& other) const {
        return level == other.level;
    }

private:
    LogLevelType level;
    
    static std::string levelToString(LogLevelType lvl) {
        switch(lvl) {
            case LogLevelType::Debug: return "Debug";
            case LogLevelType::Info: return "Info";
            case LogLevelType::Warning: return "Warning";
            case LogLevelType::Error: return "Error";
            case LogLevelType::Critical: return "Critical";
            default: return "Info";
        }
    }
}; 