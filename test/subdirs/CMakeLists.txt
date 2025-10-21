cmake_minimum_required(VERSION 3.15)
project(SubdirectoryTests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add parent directory to module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../..")

# Include the bundle_static_library function
include(bundle_static_library)

enable_testing()

# Add subdirectories
add_subdirectory(subdir_a)
add_subdirectory(subdir_b)
