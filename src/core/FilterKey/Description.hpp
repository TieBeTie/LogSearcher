#pragma once
#include "FilterKey.hpp"
#include <string>

class Description : public FilterKey {
public:
    Description(const std::string& key) : FilterKey(key) {}
}; 