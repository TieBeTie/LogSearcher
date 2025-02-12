#include "../FilterKey/FilterKey.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include "../FilterKey/Timestamp.hpp"
#include "../FilterKey/Text.hpp"
#include "../FilterKey/Description.hpp"
#include "../FilterKey/Source.hpp"
#include "../FilterKey/Target.hpp"

struct Log {
    Timestamp timestamp;
    Text text;
    Description description;
    Source source;
    Target target;
};