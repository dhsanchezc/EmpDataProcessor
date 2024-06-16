#ifndef EMPLOYEE_PROCESSOR_H
#define EMPLOYEE_PROCESSOR_H

#include <vector>
#include <string>

// Structure to hold employee data
struct Employee
{
    std::string name;
    int id;
    std::string department;
    double salary;
};

// Class to process employee data
class EmployeeProcessor
{
public:
    bool loadFile(const std::string &filename); // Load and parse data from a file
    void printEmployees() const;

private:
    std::vector<Employee> employees;
    bool parseJSON(const std::string &content);
    bool parseXML(const std::string &content);
};

#endif