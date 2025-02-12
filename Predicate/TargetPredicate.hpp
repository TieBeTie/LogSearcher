#include "Predicate.hpp"
#include <string>

class TargetPredicate : public Predicate {
    public:
    bool operator()(const Log& log) const override {
        return log.target.getKey().find(filter) != std::string::npos;
    }
    private:
    std::string filter;
}; 