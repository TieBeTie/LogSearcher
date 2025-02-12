#include "Predicate.hpp"
#include <string>

class SourcePredicate : public Predicate {
    public:
    bool operator()(const Log& log) const override {
        return log.source.getKey().find(filter) != std::string::npos;
    }
    private:
    std::string filter;
}; 