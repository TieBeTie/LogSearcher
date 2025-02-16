#include "../Log/LogsParser.hpp"
#include "../Predicate/Predicate.hpp"
#include <vector>
#include <list>

class LogSearcher {
    public:
    std::vector<Log> search(const std::vector<Log>& logs, const Predicate& predicate) {
        std::vector<Log> filteredLogs;
        for (const auto& log : logs) {
            bool passAll = true;
            for (auto &pred : predicates) {
                if (!(*pred)(log)) {
                    passAll = false;
                    break;
                }
            }
            if (passAll) {
                filteredLogs.push_back(log);
            }
        }
        return filteredLogs;
    }
    std::vector<Log> search(const std::string& logFile, const std::list<Predicate*>& predicates) {
        LogsParser parser;
        std::vector<Log> logs = parser.parse(logFile);
        std::vector<Log> filteredLogs;
        for (const auto& predicate : predicates) {
            filteredLogs = search(logs, *predicate);
        }
        return filteredLogs;
    }
}; 