#include "EmployeeProcessor.h"
#include <iostream>

// argc: counts total command-line arguments
// argv: array of those argument strings
int main(int argc, char **argv)
{
    // Check if a filename has been provided
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    // Initialize EmployeeProcessor and attempt to load the file
    EmployeeProcessor ep;
    std::string filename = argv[1];
    if (!ep.loadFile(filename))
    {
        std::cerr << "Failed to load and process file: " << filename << std::endl;
        return 1;
    }

    // Core functionality

    // Calculate and display the average salary
    double averageSalary = ep.calculateAverageSalary();
    std::cout << "Average Salary: $" << averageSalary << std::endl
              << std::endl;

    // Identify and print the highest paid employee
    std::cout << "Highest Paid Employee:\n";
    ep.printHighestPaidEmployee();
    std::cout << std::endl;

    // Sort and print employees by ID
    std::cout << "Employees sorted by ID:" << std::endl;
    ep.sortAndPrintEmployeesByID();
    std::cout << std::endl;

    return 0;
}