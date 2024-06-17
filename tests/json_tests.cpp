#include <gtest/gtest.h>
#include "EmployeeProcessor.h"

class JSONTest : public ::testing::Test
{
protected:
    EmployeeProcessor ep;

    void SetUp() override
    {
    }
};

// Test loading and parsing valid JSON data
TEST_F(JSONTest, ParsesValidJSON)
{
    ASSERT_TRUE(ep.loadFile("tests/data/valid_employees.json"));
}

// Test loading invalid JSON data
TEST_F(JSONTest, HandlesInvalidJSON)
{
    ASSERT_FALSE(ep.loadFile("tests/data/invalid_employees.json"));
}

// Test handling of non-existent JSON files
TEST_F(JSONTest, HandlesNonExistentFile)
{
    ASSERT_FALSE(ep.loadFile("tests/data/non_existent.json"));
}