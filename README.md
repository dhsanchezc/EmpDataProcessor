# EmpDataProcessor

## Overview
This application processes employee data from JSON and XML files, extracting information about employees and performing basic data manipulation.

## Features
- Load and parse JSON and XML files.
- Print basic employee data to the console.
- Calculate average salary, identify the highest paid employee, and sort employees by ID.

## Dependencies
Before building and running the project, you need to install the following libraries:
- **g++**: The GNU C++ compiler.
- **CMake**: Used for building the project.
- **TinyXML-2**: Used for parsing XML files.
- **nlohmann/json**: Used for parsing JSON files.
- **Google Test**: Used for running unit tests to validate the functionality (use the `setup.sh` script for this task).

## Setup
To simplify the setup process, a setup script (`setup.sh`) is provided in the root directory. This script automates the setup of Google Test and ensures all submodules are properly initialized.

### Running the Setup Script
Execute the following command in the terminal from the project's root directory:

```
./setup.sh
```

This script will:
- Initialize and update the Google Test submodule.
- Build the Google Test library necessary for running tests.
- Ensure all other project dependencies are correctly set up.

## Building the Project
To build the project, run the following command in the root directory:

```
make
```

This will compile both EmpDataProcessor and the test suite.

## Running the Application
To run the application and process data files, use:

```
./EmpDataProcessor <filename>
```

Replace <filename> with the path to a valid JSON or XML file containing employee data. You can use the files `./data/employees.json` and `./data/employees.xml` for testing.

## Using the Run Script
The `run.sh` script simplifies the execution of the application. To use the script, simply run the following command from the project's root directory:

```
./run.sh
```

This script will execute the application with predefined settings or files, as specified within the script.

## Running Tests
After building the project, you can run the integrated tests to ensure all functionalities are working as expected:

```
make tests
```

This command executes the test suite compiled during the build process, validating both the basic functionalities and error handling using the dummy files in `tests/data/`.