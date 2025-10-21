cmake_minimum_required(VERSION 3.15)
project(BundleStaticLibraryCTests C)

# Include the bundle_static_library function
include(../bundle_static_library.cmake)

enable_testing()

# Test: C library bundling
add_library(c_lib_a STATIC c_lib_a.c)
target_include_directories(c_lib_a PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(c_lib_b STATIC c_lib_b.c)
target_include_directories(c_lib_b PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(c_lib_b PUBLIC c_lib_a)

bundle_static_library(c_lib_b c_lib_b_bundled)

# Test executable
add_executable(test_c_bundled test_c_bundled.c)
target_link_libraries(test_c_bundled c_lib_b_bundled)
add_test(NAME test_c_bundled COMMAND test_c_bundled)
