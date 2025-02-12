#include "Predicate.hpp"
#include <string>

class TimestampDurationPredicate : public Predicate {
    public:
    bool operator()(const Log& log) const override {
        return start.getYear() <= log.timestamp.getYear() && log.timestamp.getYear() <= end.getYear() &&
               start.getMonth() <= log.timestamp.getMonth() && log.timestamp.getMonth() <= end.getMonth() &&
               start.getDay() <= log.timestamp.getDay() && log.timestamp.getDay() <= end.getDay() &&
               start.getHour() <= log.timestamp.getHour() && log.timestamp.getHour() <= end.getHour() &&
               start.getMinute() <= log.timestamp.getMinute() && log.timestamp.getMinute() <= end.getMinute() &&
               start.getSecond() <= log.timestamp.getSecond() && log.timestamp.getSecond() <= end.getSecond();
    }
    private:
    Timestamp start;
    Timestamp end;
}; 