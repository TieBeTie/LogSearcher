#include "Predicate.hpp"
#include <string>

class TimestampPredicate : public Predicate {
    public:
    bool operator()(const Log& log) const override {
        return log.timestamp.getKey().find(filter) != std::string::npos;
    }
    private:
    std::string filter;
}; 