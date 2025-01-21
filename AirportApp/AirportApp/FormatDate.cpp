#include "FormatDate.h"
#include <iostream>
#include <iomanip>
#include <optional>
#include <chrono>
#include <string>
#include <sstream>

using namespace std;

std::string formatDate(const std::optional<std::chrono::system_clock::time_point>& timePoint) {
    if (!timePoint) {
        return "N/A";
    }

    std::time_t time = std::chrono::system_clock::to_time_t(*timePoint);

    if (time == -1) {
        return "Invalid date/time";
    }

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}