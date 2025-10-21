# Bundle Static Library

A CMake function to bundle a static library and all its static library dependencies into a single combined static library.

## Origin

This project is based on [Cristian Adam's bundle_static_library.cmake](https://github.com/cristianadam/cristianadam.github.io/blob/e0217bcf45c9a95ae59a270ec5a7d987f1ceb74d/_posts/2019-12-08-libraries.md) ([gist](https://gist.github.com/cristianadam/ef920342939a89fae3e8a85ca9459b49)).

**Original Author:** Cristian Adam
**License:** MIT License

## Improvements

This fork includes the following enhancements:

- **macOS support**: Uses `libtool -static` instead of `ar -M` which is not supported on macOS
- **Variable scope fix**: Corrects recursive dependency collection to preserve accumulated library list
- **Dependency tracking**: Adds proper `DEPENDS` clauses so bundled libraries rebuild when sources change
- **Unique target names**: Fixes target name collision allowing multiple bundles in the same project
- **C language support**: Works with pure C projects, not just C++
- **Comprehensive tests**: Test suites for both C and C++ to verify functionality

## Features

- Recursively collects all static library dependencies
- Handles transitive dependencies
- Resolves CMake target aliases
- Supports multiple toolchains:
  - macOS: `libtool`
  - GCC/Clang: `ar` with MRI scripts
  - MSVC: `lib.exe`
- Works with both C and C++ projects
- Proper dependency tracking for incremental builds

## Usage

```cmake
include(bundle_static_library.cmake)

# Create your libraries
add_library(mylib STATIC src1.cpp src2.cpp)
add_library(dependency STATIC dep.cpp)
target_link_libraries(mylib PUBLIC dependency)

# Bundle them into a single library
bundle_static_library(mylib mylib_bundled)

# Use the bundled library
add_executable(myapp main.cpp)
target_link_libraries(myapp mylib_bundled)
```

## Platform Support

- macOS
- Linux with GCC/Clang
- Windows with MSVC

## Testing

### C++ Tests

```bash
cd test
./run_tests.sh
```

Tests cover:
- Basic single library bundling
- Direct dependencies
- Transitive dependency chains
- Multiple bundle targets in the same project

### C Tests

```bash
cd test_c
./run_tests.sh
```

Verifies support for pure C projects.

## Requirements

- CMake 3.15 or higher
- Platform-specific archiver tools:
  - macOS: `libtool` (included with Xcode Command Line Tools)
  - Linux: `ar` (included with binutils)
  - Windows: `lib.exe` (included with MSVC)

## How It Works

1. Recursively traverses the dependency tree of the target library
2. Collects all static libraries (including transitive dependencies)
3. Uses the platform-specific archiver to combine all `.a`/`.lib` files
4. Creates an imported library target pointing to the combined archive
5. Preserves interface include directories from the original target

## License

MIT License - See LICENSE file for details

Copyright (c) 2019 Cristian Adam

Modifications and improvements contributed by multiple authors.
