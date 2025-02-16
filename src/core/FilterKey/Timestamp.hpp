#pragma once
#include "FilterKey.hpp"
#include <string>
#include <chrono>

class Timestamp : public FilterKey {
public:
    Timestamp(const std::string& key) : FilterKey(key) {
        timestamp = std::chrono::system_clock::from_time_t(std::stoi(key));
    }

    bool operator>=(const Timestamp& other) const {
        return timestamp >= other.timestamp;
    }

    bool operator<=(const Timestamp& other) const {
        return timestamp <= other.timestamp;
    }

private:
    std::chrono::system_clock::time_point timestamp;
}; 