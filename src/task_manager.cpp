#include "task_manager.h"

TaskManager::TaskManager(const std::string& filename) : filename_(filename) {}

// REQ-001: Aufgabe hinzufuegen - Person 1
void TaskManager::addTask(const std::string& title, const std::string& description) {
    tasks_.emplace_back(title, description);
}

// REQ-002: wird von Person 2 implementiert
std::vector<Task> TaskManager::getTasks() const {
    return tasks_;
}

// REQ-002: wird von Person 2 implementiert
bool TaskManager::deleteTask(int index) {
    return false;
}

bool TaskManager::load() {
    return false;
}

bool TaskManager::save() const {
    return false;
}