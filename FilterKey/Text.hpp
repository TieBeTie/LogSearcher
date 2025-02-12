#include "FilterKey.hpp"

class Text : public FilterKey {
public:
    Text(const std::string& key) : FilterKey(key) {}
}; 