# SpengerMed Task Manager

**Sprache:** C++17  
**Team:** 3 Personen

## Anforderungen

| ID      | Beschreibung                        | Person   | Branch              |
|---------|-------------------------------------|----------|---------------------|
| REQ-001 | Aufgabe hinzufügen (addTask)        | Person 1 | feature/add-task    |
| REQ-002 | Aufgaben anzeigen + löschen         | Person 2 | feature/tasks       |
| REQ-003 | Tests für alle Anforderungen        | Person 3 | feature/tests       |

## Aufgabenverteilung

| Person   | Zuständigkeit                                          |
|----------|--------------------------------------------------------|
| Person 1 | task.h, task_manager.h, task_manager.cpp (addTask)     |
| Person 2 | task_manager.cpp (getTasks, deleteTask), main.cpp      |
| Person 3 | tests/test_task_manager.cpp (alle Unit-Tests)          |

## Build & Run

```bash
make all
./taskmanager
```

## Tests

```bash
make test
```