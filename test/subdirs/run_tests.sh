#!/usr/bin/env bash
set -e

cd "$(dirname "$0")"

echo "Building subdirectory tests..."
rm -rf build
mkdir build
cd build
cmake ..
make

echo ""
echo "Running tests..."
ctest --output-on-failure

echo ""
echo "Verifying bundled libraries are in correct subdirectories..."
if [ -f "subdir_a/libsubdir_a_bundled.a" ] && [ -f "subdir_b/libsubdir_b_bundled.a" ]; then
    echo "SUCCESS: Bundled libraries found in correct subdirectories"
else
    echo "FAILURE: Bundled libraries not in correct locations"
    echo "Expected files:"
    echo "  subdir_a/libsubdir_a_bundled.a"
    echo "  subdir_b/libsubdir_b_bundled.a"
    echo ""
    echo "Actual bundled library locations:"
    find . -name "*bundled.a"
    exit 1
fi

echo ""
echo "All subdirectory tests passed!"
