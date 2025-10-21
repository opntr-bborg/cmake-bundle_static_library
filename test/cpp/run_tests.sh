#!/usr/bin/env bash

set -e

# Create build directory
BUILD_DIR="build"
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure
echo "Configuring..."
cmake ..

# Build
echo "Building..."
cmake --build .

# Run tests
echo "Running tests..."
ctest --output-on-failure

echo "All tests passed!"
