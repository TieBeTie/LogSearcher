#pragma once
#include "FilterKey.hpp"
#include <string>

class Source : public FilterKey {
public:
    Source(const std::string& key) : FilterKey(key) {}
}; 