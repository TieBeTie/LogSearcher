#include <string>

class FilterKey {
public:
    FilterKey(const std::string& key) : key(key) {}
    std::string getKey() const { return key; }
private:
    std::string key;
};