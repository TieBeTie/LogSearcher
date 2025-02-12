#include "Log.hpp"
#include <vector>
#include <fstream>
#include <sstream>

class LogsParser {
    public:
    std::vector<Log> parse(const std::string& logFile) {
        std::ifstream file(logFile);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string timestamp;
            std::string text;
            std::string description;
            std::string source;
            std::string target;
            std::getline(ss, timestamp, ' ');
            std::getline(ss, text, ' ');
            std::getline(ss, description, ' ');
            std::getline(ss, source, ' ');
            std::getline(ss, target, ' ');
            Log log(Timestamp(timestamp), Text(text), Description(description), Source(source), Target(target));
            logs.emplace_back(log);
        }
        return logs;
    }
    private:
    std::vector<Log> logs;
}; 