CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17

all: EmpDataProcessor

EmpDataProcessor: src/main.cpp src/EmployeeProcessor.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp src/EmployeeProcessor.cpp -o EmpDataProcessor

clean:
	rm -f EmpDataProcessor