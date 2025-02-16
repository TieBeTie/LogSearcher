#pragma once
#include "../parsing/LogsParser.hpp"
#include "../filters/predicates/Predicate.hpp"
#include <vector>
#include <list>

class LogSearcher {
    public:
    std::vector<Log> search(const std::vector<Log>& logs, const std::list<Predicate*>& predicates) {
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
        return search(parser.parse(logFile), predicates);
    }
    private:
    std::list<Predicate*> predicates;
}; 