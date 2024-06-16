#include "EmployeeProcessor.h"
#include <fstream>           // Include for file operations
#include <iostream>          // Include for printing to console
#include <nlohmann/json.hpp> // Include for JSON parsing
#include <tinyxml2.h>        // Include for XML parsing

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

// Parses JSON content into Employee objects. Expects a JSON with an "employees" array.
bool EmployeeProcessor::parseJSON(const std::string &content)
{
    try
    {
        auto json = nlohmann::json::parse(content); // Deserialize the JSON string into a json object
        for (const auto &item : json["employees"])  // Process each employee in the JSON array
        {
            Employee emp;
            emp.name = item["name"];
            emp.id = item["id"];
            emp.department = item["department"];
            emp.salary = item["salary"];
            employees.push_back(emp); // Add to the employee list
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return false;
    }
}

// Parses XML content into Employee objects. Expects an XML with a root <employees> element.
bool EmployeeProcessor::parseXML(const std::string &content)
{
    tinyxml2::XMLDocument doc;
    if (doc.Parse(content.c_str()) != tinyxml2::XML_SUCCESS)
    {                                                                      // Parse the XML content
        std::cerr << "XML parsing error: " << doc.ErrorStr() << std::endl; // Log parsing errors
        return false;
    }

    tinyxml2::XMLElement *root = doc.FirstChildElement("employees");
    if (!root)
    {
        std::cerr << "XML structure error: Missing <employees>." << std::endl; // Check for correct XML structure
        return false;
    }

    for (tinyxml2::XMLElement *e = root->FirstChildElement("employee"); e != nullptr; e = e->NextSiblingElement("employee"))
    {
        Employee emp;
        emp.name = e->FirstChildElement("name")->GetText();
        emp.id = atoi(e->FirstChildElement("id")->GetText());
        emp.department = e->FirstChildElement("department")->GetText();
        emp.salary = atof(e->FirstChildElement("salary")->GetText());
        employees.push_back(emp); // Add to the employee list
    }
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