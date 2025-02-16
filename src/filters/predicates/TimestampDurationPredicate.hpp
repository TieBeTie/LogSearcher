#pragma once
#include "Predicate.hpp"
#include <string>

class TimestampDurationPredicate : public Predicate {
    public:
    TimestampDurationPredicate(const Timestamp& start, const Timestamp& end) 
        : start(start), end(end) {}
        
    bool operator()(const Log& log) const override {
        return start <= log.timestamp && log.timestamp <= end;
    }
    private:
    Timestamp start;
    Timestamp end;
}; 