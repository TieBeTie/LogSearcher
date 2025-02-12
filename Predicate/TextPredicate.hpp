#include "Predicate.hpp"
#include <string>

class TextPredicate : public Predicate {
    public:
    bool operator()(const Log& log) const override {
        return log.text.getKey().find(filter) != std::string::npos;
    }
    private:
    std::string filter;
}; 