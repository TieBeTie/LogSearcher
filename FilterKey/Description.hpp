#include "FilterKey.hpp"

class Description : public FilterKey {
public:
    Description(const std::string& key) : FilterKey(key) {}
}; 