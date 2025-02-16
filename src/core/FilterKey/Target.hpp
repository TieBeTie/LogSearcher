#pragma once
#include "FilterKey.hpp"
#include <string>

class Target : public FilterKey {
public:
    Target(const std::string& key) : FilterKey(key) {}
}; 