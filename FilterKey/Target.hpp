#include "FilterKey.hpp"

class Target : public FilterKey {
public:
    Target(const std::string& key) : FilterKey(key) {}
}; 