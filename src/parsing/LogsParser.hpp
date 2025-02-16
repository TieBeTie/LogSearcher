#include "../core/Log.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include "../core/FilterKey/Timestamp.hpp"
#include "../core/FilterKey/Description.hpp"
#include "../core/FilterKey/Source.hpp"
#include "../core/FilterKey/Target.hpp"

class LogsParser {
    public:
    std::vector<Log> parse(const std::string& logFile) {
        std::ifstream file(logFile);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string level, timestamp, description, source, target;
            std::getline(ss, level, ' ');
            std::getline(ss, timestamp, ' ');
            std::getline(ss, description, ' ');
            std::getline(ss, source, ' ');
            std::getline(ss, target, ' ');
            Log log(Timestamp(timestamp), LogLevel(level), Description(description), Source(source), Target(target));
            logs.emplace_back(log);
        }
        return logs;
    }
    private:
    std::vector<Log> logs;
}; 