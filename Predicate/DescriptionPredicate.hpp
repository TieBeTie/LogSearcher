#include "Predicate.hpp"
#include <string>

class DescriptionPredicate : public Predicate {
    public:
    bool operator()(const Log& log) const override {
        return log.description.getKey().find(filter) != std::string::npos;
    }
    private:
    std::string filter;
}; 