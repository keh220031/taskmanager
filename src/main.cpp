#include <iostream>
#include "task_manager.h"

void printMenu() {
    std::cout << "\n=== Task Manager ===\n";
    std::cout << "1. Aufgabe hinzufuegen\n";
    std::cout << "2. Aufgaben anzeigen\n";
    std::cout << "3. Aufgabe loeschen\n";
    std::cout << "0. Beenden\n";
    std::cout << "Auswahl: ";
}

int main() {
    TaskManager manager("tasks.txt");
    manager.load();

    int choice;
    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            std::string title, description;
            std::cout << "Titel: ";
            std::getline(std::cin, title);
            std::cout << "Beschreibung: ";
            std::getline(std::cin, description);
            manager.addTask(title, description);
            std::cout << "Aufgabe hinzugefuegt.\n";

        } else if (choice == 2) {
            auto tasks = manager.getTasks();
            if (tasks.empty()) {
                std::cout << "Keine Aufgaben vorhanden.\n";
            } else {
                for (size_t i = 0; i < tasks.size(); ++i) {
                    std::cout << "[" << (i+1) << "] "
                              << tasks[i].title << " - "
                              << tasks[i].description << "\n";
                }
            }

        } else if (choice == 3) {
            auto tasks = manager.getTasks();
            if (tasks.empty()) {
                std::cout << "Keine Aufgaben vorhanden.\n";
            } else {
                for (size_t i = 0; i < tasks.size(); ++i) {
                    std::cout << "[" << (i+1) << "] " << tasks[i].title << "\n";
                }
                std::cout << "Nummer eingeben: ";
                int idx;
                std::cin >> idx;
                if (manager.deleteTask(idx - 1)) {
                    std::cout << "Aufgabe geloescht.\n";
                } else {
                    std::cout << "Ungueltige Nummer.\n";
                }
            }
        }
        manager.save();
    }
    return 0;
}