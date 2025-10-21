cmake_minimum_required(VERSION 3.15)
project(SubdirectoryTests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(../../bundle_static_library.cmake)

enable_testing()

# Add subdirectories
add_subdirectory(subdir_a)
add_subdirectory(subdir_b)
