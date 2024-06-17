# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17 -I$(GTEST_DIR)/googletest/include
LDFLAGS = -ltinyxml2

# Google Test Setup
GTEST_DIR = extern/googletest
GTEST_LIBS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread

# Main application
all: EmpDataProcessor

EmpDataProcessor: src/main.cpp EmployeeProcessor.o
	$(CXX) $(CXXFLAGS) src/main.cpp EmployeeProcessor.o -o EmpDataProcessor $(LDFLAGS)

EmployeeProcessor.o: src/EmployeeProcessor.cpp
	$(CXX) $(CXXFLAGS) -c src/EmployeeProcessor.cpp -o EmployeeProcessor.o

# Test targets
tests: test_main.o json_tests.o xml_tests.o core_functionality_tests.o EmployeeProcessor.o
	$(CXX) $(CXXFLAGS) test_main.o json_tests.o xml_tests.o core_functionality_tests.o EmployeeProcessor.o -o run_tests $(GTEST_LIBS) $(LDFLAGS)
	./run_tests

test_main.o: tests/test_main.cpp
	$(CXX) $(CXXFLAGS) -c tests/test_main.cpp -o test_main.o

json_tests.o: tests/json_tests.cpp
	$(CXX) $(CXXFLAGS) -c tests/json_tests.cpp -o json_tests.o

xml_tests.o: tests/xml_tests.cpp
	$(CXX) $(CXXFLAGS) -c tests/xml_tests.cpp -o xml_tests.o

core_functionality_tests.o: tests/core_functionality_tests.cpp
	$(CXX) $(CXXFLAGS) -c tests/core_functionality_tests.cpp -o core_functionality_tests.o

# Build Google Test
gtest:
	cd $(GTEST_DIR) && cmake . && make

clean:
	rm -f *.o EmpDataProcessor run_tests
	cd $(GTEST_DIR) && make clean