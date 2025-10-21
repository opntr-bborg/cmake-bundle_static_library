# Bundle Static Library Tests

This directory contains tests for the `bundle_static_library` CMake function.

## Test Coverage

The test suite verifies the following scenarios:

1. **Basic bundling** (`test_basic`): Bundle a single static library
2. **Direct dependencies** (`test_dependencies`): Bundle a library that depends on another static library
3. **Transitive dependencies** (`test_transitive`): Bundle a library with a chain of dependencies (lib_d -> lib_e -> lib_f)
4. **Multiple bundles** (`test_multiple_g` and `test_multiple_h`): Create multiple bundled libraries in the same project to verify unique target names

## Running Tests

### Using the test script:
```bash
cd test
./run_tests.sh
```

### Manual execution:
```bash
cd test
mkdir build && cd build
cmake ..
cmake --build .
ctest --output-on-failure
```

## Test Architecture

Each test consists of:
- Static libraries with simple functions that return known values
- Test executables that link against the bundled libraries
- Assertions to verify the correct values are returned

The tests verify that:
- Libraries are correctly bundled
- Transitive dependencies are included
- Multiple bundles can coexist
- The bundled libraries are linkable and functional
