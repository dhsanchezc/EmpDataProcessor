#include <gtest/gtest.h>
#include "EmployeeProcessor.h"

class XMLTest : public ::testing::Test
{
protected:
    EmployeeProcessor ep;

    void SetUp() override
    {
    }
};

// Test loading and parsing valid XML data
TEST_F(XMLTest, ParsesValidXML)
{
    ASSERT_TRUE(ep.loadFile("tests/data/valid_employees.xml"));
}

// Test loading invalid XML data
TEST_F(XMLTest, HandlesInvalidXML)
{
    ASSERT_FALSE(ep.loadFile("tests/data/invalid_employees.xml"));
}

// Test handling of non-existent XML files
TEST_F(XMLTest, HandlesNonExistentFile)
{
    ASSERT_FALSE(ep.loadFile("tests/data/non_existent.xml"));
}