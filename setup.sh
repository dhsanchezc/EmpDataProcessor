#!/bin/bash
echo "Setting up the project..."

# Initialize and update submodules (Google Test)
git submodule update --init --recursive

# Optionally build Google Test here or guide the user to do so
echo "Building Google Test..."
cd extern/googletest
cmake .
make
cd ../..

echo "Setup complete."