#!/bin/bash

# Set default file paths
JSON_INPUT="data/employees.json"
XML_INPUT="data/employees.xml"
OUTPUT_DIR="output"

# Function to display usage
usage() {
    echo "Usage: $0 [-j <json_file>] [-x <xml_file>]"
    echo "  -j <json_file>   Specify the JSON input file (default: $JSON_INPUT)"
    echo "  -x <xml_file>    Specify the XML input file (default: $XML_INPUT)"
    exit 1
}

# Parse command-line options
while getopts "j:x:h" opt; do
  case $opt in
    j)
      JSON_INPUT=$OPTARG
      ;;
    x)
      XML_INPUT=$OPTARG
      ;;
    h)
      usage
      ;;
    \?)
      usage
      ;;
  esac
done

# Ensure output directory exists
mkdir -p $OUTPUT_DIR

# Build the project
echo "Building the project..."
make all

# Run tests
echo "Running tests..."
make tests

# Execute the application with JSON input
echo "Processing JSON input..."
./EmpDataProcessor $JSON_INPUT > "${OUTPUT_DIR}/json_output.txt"

# Execute the application with XML input
echo "Processing XML input..."
./EmpDataProcessor $XML_INPUT > "${OUTPUT_DIR}/xml_output.txt"

# Display outputs
echo "Results for JSON input stored in ${OUTPUT_DIR}/json_output.txt"
echo "Results for XML input stored in ${OUTPUT_DIR}/xml_output.txt"
