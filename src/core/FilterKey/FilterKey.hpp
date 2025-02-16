#pragma once
#include <string>

class FilterKey {
protected:
    std::string key;

public:
    FilterKey(const std::string& key) : key(key) {}
    virtual ~FilterKey() = default;

    const std::string& getKey() const {
        return key;
    }
}; 