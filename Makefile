CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17
LDFLAGS = -ltinyxml2

all: EmpDataProcessor

EmpDataProcessor: src/main.cpp src/EmployeeProcessor.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp src/EmployeeProcessor.cpp -o EmpDataProcessor $(LDFLAGS)

clean:
	rm -f EmpDataProcessor