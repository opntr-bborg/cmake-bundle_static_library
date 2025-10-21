#!/usr/bin/env bash
set -e

cd "$(dirname "$0")"

echo "Building install test..."
rm -rf build install_dir
mkdir -p build install_dir
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install_dir
make

echo ""
echo "Installing to install_dir..."
make install

echo ""
echo "Verifying installation..."
if [ -f "../install_dir/lib/libmylib_bundled.a" ]; then
    echo "SUCCESS: Bundled library installed correctly"
    ls -lh ../install_dir/lib/libmylib_bundled.a
else
    echo "FAILURE: Bundled library not found in install directory"
    echo "Contents of install_dir:"
    find ../install_dir
    exit 1
fi

echo ""
echo "Checking headers..."
if [ -f "../install_dir/include/mylib_a.h" ] && [ -f "../install_dir/include/mylib_b.h" ]; then
    echo "SUCCESS: Headers installed correctly"
else
    echo "WARNING: Headers not found"
fi

echo ""
echo "Install test passed!"
