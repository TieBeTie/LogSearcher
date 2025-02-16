#pragma once
#include "Predicate.hpp"
#include "../../core/FilterKey/LogLevel.hpp"

class LogLevelPredicate : public Predicate {
    public:
    LogLevelPredicate(const LogLevel& logLevel) : logLevel(logLevel) {}
    bool operator()(const Log& log) const override {
        return log.level == logLevel;
    }
    private:
    LogLevel logLevel;
};
