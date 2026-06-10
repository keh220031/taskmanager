CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC      = src/main.cpp src/task_manager.cpp
TEST_SRC = tests/test_task_manager.cpp src/task_manager.cpp

TARGET      = taskmanager
TEST_TARGET = run_tests

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)