# EmpDataProcessor

## Overview
This application processes employee data from JSON and XML files, extracting information about employees and performing basic data manipulation.

## Features
- Load and parse JSON and XML files.
- Print basic employee data to the console.

## Dependencies
Before building and running the project, you need to install the following libraries:
- **TinyXML-2**: Used for parsing XML files.
- **nlohmann/json**: Used for parsing JSON files.

## Building the Project
To build the project, run the following command in the root directory:

```
make
```

## Running the Application
To run the application and process data files, use:

```
./EmpDataProcessor <filename>
```