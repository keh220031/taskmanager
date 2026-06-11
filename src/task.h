#pragma once
#include <string>

// REQ-001: Task Datenstruktur
struct Task {
    std::string title;
    std::string description;

    Task(const std::string& t, const std::string& d)
        : title(t), description(d) {}
};