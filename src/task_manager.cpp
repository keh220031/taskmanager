#include "task_manager.h"
#include <fstream>

TaskManager::TaskManager(const std::string& filename) : filename_(filename) {}

// REQ-001: von Person 1
void TaskManager::addTask(const std::string& title, const std::string& description) {
    tasks_.emplace_back(title, description);
}

// REQ-002: Aufgaben zurueckgeben - Person 2
std::vector<Task> TaskManager::getTasks() const {
    return tasks_;
}

// REQ-002: Aufgabe loeschen - Person 2
bool TaskManager::deleteTask(int index) {
    if (index < 0 || index >= static_cast<int>(tasks_.size())) {
        return false;
    }
    tasks_.erase(tasks_.begin() + index);
    return true;
}

bool TaskManager::load() {
    std::ifstream file(filename_);
    if (!file.is_open()) return false;
    std::string line;
    while (std::getline(file, line)) {
        auto sep = line.find('|');
        if (sep != std::string::npos) {
            tasks_.emplace_back(line.substr(0, sep), line.substr(sep + 1));
        }
    }
    return true;
}

bool TaskManager::save() const {
    std::ofstream file(filename_);
    if (!file.is_open()) return false;
    for (const auto& t : tasks_) {
        file << t.title << "|" << t.description << "\n";
    }
    return true;
}