#pragma once
#include "../../core/Log.hpp"
#include <string>

class Predicate {   
    public:
    virtual bool operator()(const Log& log) const = 0;
};
