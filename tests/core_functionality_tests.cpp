#include <gtest/gtest.h>
#include <sstream>
#include "EmployeeProcessor.h"

class CoreFunctionalityTest : public ::testing::Test {
protected:
    EmployeeProcessor ep;

    void SetUp() override {
        ASSERT_TRUE(ep.loadFile("tests/data/valid_employees.json"));
    }
};

// Test to calculate the average salary correctly.
TEST_F(CoreFunctionalityTest, CalculatesAverageSalary) {
    double expectedAverage = (50000 + 60000 + 45000) / 3.0;
    ASSERT_DOUBLE_EQ(ep.calculateAverageSalary(), expectedAverage);
}

// Test to identify the highest paid employee correctly.
TEST_F(CoreFunctionalityTest, IdentifiesHighestPaidEmployee) {
    std::ostringstream stream;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(stream.rdbuf());

    ep.printHighestPaidEmployee();

    std::cout.rdbuf(oldCoutStreamBuf);
    ASSERT_EQ(stream.str(), "Employee: Jane Smith, ID: 102, Department: Engineering, Salary: $60000\n");
}

// Test to ensure employees are sorted by ID correctly.
TEST_F(CoreFunctionalityTest, SortsEmployeesByID) {
    std::ostringstream stream;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(stream.rdbuf());

    ep.sortAndPrintEmployeesByID();

    std::cout.rdbuf(oldCoutStreamBuf);
    ASSERT_EQ(stream.str(),
        "Employee: John Doe, ID: 101, Department: HR, Salary: $50000\n"
        "Employee: Jane Smith, ID: 102, Department: Engineering, Salary: $60000\n"
        "Employee: Alice Johnson, ID: 103, Department: Marketing, Salary: $45000\n");
}
