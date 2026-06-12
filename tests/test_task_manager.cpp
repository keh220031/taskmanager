#include <cassert>
#include <iostream>
#include "../src/task_manager.h"

int passed = 0;
int failed = 0;

#define ASSERT(expr, name) \
    if (expr) { std::cout << "[PASS] " << name << "\n"; passed++; } \
    else { std::cout << "[FAIL] " << name << "\n"; failed++; }

// REQ-001 Tests
void test_addTask_count() {
    TaskManager tm("test.txt");
    tm.addTask("Task A", "Desc A");
    ASSERT(tm.getTasks().size() == 1, "REQ-001: addTask erhoeht Anzahl");
}

void test_addTask_inhalt() {
    TaskManager tm("test.txt");
    tm.addTask("Mein Task", "Meine Desc");
    auto tasks = tm.getTasks();
    ASSERT(tasks[0].title == "Mein Task", "REQ-001: addTask speichert Titel");
    ASSERT(tasks[0].description == "Meine Desc", "REQ-001: addTask speichert Beschreibung");
}

void test_addTask_mehrere() {
    TaskManager tm("test.txt");
    tm.addTask("T1", "D1");
    tm.addTask("T2", "D2");
    tm.addTask("T3", "D3");
    ASSERT(tm.getTasks().size() == 3, "REQ-001: addTask mehrere Tasks");
}

// REQ-002 Tests
void test_getTasks_leer() {
    TaskManager tm("test.txt");
    ASSERT(tm.getTasks().empty(), "REQ-002: getTasks leer am Anfang");
}

void test_getTasks_alle() {
    TaskManager tm("test.txt");
    tm.addTask("A", "descA");
    tm.addTask("B", "descB");
    ASSERT(tm.getTasks().size() == 2, "REQ-002: getTasks gibt alle zurueck");
}

void test_deleteTask_gueltig() {
    TaskManager tm("test.txt");
    tm.addTask("Loeschen", "desc");
    bool result = tm.deleteTask(0);
    ASSERT(result == true, "REQ-002: deleteTask gibt true zurueck");
    ASSERT(tm.getTasks().empty(), "REQ-002: deleteTask entfernt Task");
}

void test_deleteTask_ungueltig() {
    TaskManager tm("test.txt");
    tm.addTask("Behalten", "desc");
    bool result = tm.deleteTask(-1);
    ASSERT(result == false, "REQ-002: deleteTask false bei ungueltigem Index");
}

void test_deleteTask_mitte() {
    TaskManager tm("test.txt");
    tm.addTask("Erste", "d1");
    tm.addTask("Zweite", "d2");
    tm.addTask("Dritte", "d3");
    tm.deleteTask(1);
    auto tasks = tm.getTasks();
    ASSERT(tasks.size() == 2, "REQ-002: deleteTask Mitte - Anzahl stimmt");
    ASSERT(tasks[0].title == "Erste", "REQ-002: deleteTask Mitte - Erste bleibt");
    ASSERT(tasks[1].title == "Dritte", "REQ-002: deleteTask Mitte - Dritte bleibt");
}

int main() {
    std::cout << "=== Unit Tests ===\n\n";

    test_addTask_count();
    test_addTask_inhalt();
    test_addTask_mehrere();
    test_getTasks_leer();
    test_getTasks_alle();
    test_deleteTask_gueltig();
    test_deleteTask_ungueltig();
    test_deleteTask_mitte();

    std::cout << "\n=== Ergebnis: " << passed << " bestanden, " << failed << " fehlgeschlagen ===\n";
    return failed > 0 ? 1 : 0;
}