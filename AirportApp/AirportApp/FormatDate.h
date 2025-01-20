#pragma once
#include <string>
#include <optional>
#include <chrono>

using namespace std;

std::string formatDate(const std::optional<std::chrono::system_clock::time_point>& timePoint);

