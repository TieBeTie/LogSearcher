#include "FilterKey.hpp"

class Source : public FilterKey {
public:
    Source(const std::string& key) : FilterKey(key) {}
}; 