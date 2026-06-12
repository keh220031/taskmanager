#pragma once
#include <vector>
#include <string>
#include "task.h"

class TaskManager {
public:
    explicit TaskManager(const std::string& filename);

    void addTask(const std::string& title, const std::string& description);  // REQ-001
    std::vector<Task> getTasks() const;    // REQ-002
    bool deleteTask(int index);            // REQ-002

    bool load();
    bool save() const;

private:
    std::string filename_;
    std::vector<Task> tasks_;
};