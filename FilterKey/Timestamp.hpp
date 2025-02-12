#include "FilterKey.hpp"

class Timestamp : public FilterKey {
public:
    Timestamp(const std::string& key) : FilterKey(key) {
        year = std::stoi(key.substr(0, 4));
        month = std::stoi(key.substr(5, 2));
        day = std::stoi(key.substr(8, 2));
        hour = std::stoi(key.substr(11, 2));
        minute = std::stoi(key.substr(14, 2));
        second = std::stoi(key.substr(17, 2));
    }
    int getYear() const {
        return year;
    }
    int getMonth() const {
        return month;
    }   
    int getDay() const {    
        return day;
    }
    int getHour() const {
        return hour;
    }
    int getMinute() const {
        return minute;
    }
    int getSecond() const {
        return second;
    }
private:
    int year, month, day, hour, minute, second;
}; 