#include "EmployeeProcessor.h"
#include <fstream>  // Include for file operations
#include <iostream> // Include for printing to console

bool EmployeeProcessor::loadFile(const std::string &filename)
{
    // Determine the file extension
    size_t pos = filename.rfind('.');
    if (pos == std::string::npos)
    {
        std::cerr << "Error: File extension not found for " << filename << std::endl;
        return false;
    }
    std::string ext = filename.substr(pos + 1);

    // Open and read the file content into a string, assuming the file size is manageable for available memory
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    // Parse the content based on the file extension
    if (ext == "json")
    {
        if (!parseJSON(content))
        {
            std::cerr << "Failed to parse JSON content from " << filename << std::endl;
            return false;
        }
    }
    else if (ext == "xml")
    {
        if (!parseXML(content))
        {
            std::cerr << "Failed to parse XML content from " << filename << std::endl;
            return false;
        }
    }
    else
    {
        std::cerr << "Unsupported file format: ." << ext << std::endl;
        return false;
    }
    return true;
}

bool EmployeeProcessor::parseJSON(const std::string &content)
{
    std::cout << "Parsing JSON..." << std::endl;
    return true;
}

bool EmployeeProcessor::parseXML(const std::string &content)
{
    std::cout << "Parsing XML content..." << std::endl;
    return true;
}

void EmployeeProcessor::printEmployees() const
{
    for (const auto &emp : employees)
    { // Loop through all employees
        std::cout << "Employee: " << emp.name
                  << ", ID: " << emp.id
                  << ", Department: " << emp.department
                  << ", Salary: $" << emp.salary << std::endl;
    }
}