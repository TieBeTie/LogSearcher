#include "FilterKey/FilterKey.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include "FilterKey/Timestamp.hpp"
#include "FilterKey/Description.hpp"
#include "FilterKey/Source.hpp"
#include "FilterKey/Target.hpp"
#include "FilterKey/LogLevel.hpp"

struct Log {
    Timestamp timestamp;
    LogLevel level;
    Description description;
    Source source;
    Target target;
}; 