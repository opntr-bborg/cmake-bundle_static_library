cmake_minimum_required(VERSION 3.15)
project(BundleStaticLibraryTests CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the bundle_static_library function
include(../bundle_static_library.cmake)

enable_testing()

# Test 1: Basic single library bundling
add_library(lib_a STATIC lib_a.cpp)
target_include_directories(lib_a PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

bundle_static_library(lib_a lib_a_bundled)

# Test 2: Library with dependencies
add_library(lib_b STATIC lib_b.cpp)
target_include_directories(lib_b PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(lib_c STATIC lib_c.cpp)
target_include_directories(lib_c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_c PUBLIC lib_b)

bundle_static_library(lib_c lib_c_bundled)

# Test 3: Transitive dependencies (lib_d -> lib_e -> lib_f)
add_library(lib_f STATIC lib_f.cpp)
target_include_directories(lib_f PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(lib_e STATIC lib_e.cpp)
target_include_directories(lib_e PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_e PUBLIC lib_f)

add_library(lib_d STATIC lib_d.cpp)
target_include_directories(lib_d PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_d PUBLIC lib_e)

bundle_static_library(lib_d lib_d_bundled)

# Test 4: Multiple bundles in the same project (to test unique target names)
add_library(lib_g STATIC lib_g.cpp)
target_include_directories(lib_g PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(lib_h STATIC lib_h.cpp)
target_include_directories(lib_h PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

bundle_static_library(lib_g lib_g_bundled)
bundle_static_library(lib_h lib_h_bundled)

# Test executables that link against bundled libraries
add_executable(test_basic test_basic.cpp)
target_link_libraries(test_basic lib_a_bundled)
add_test(NAME test_basic COMMAND test_basic)

add_executable(test_dependencies test_dependencies.cpp)
target_link_libraries(test_dependencies lib_c_bundled)
add_test(NAME test_dependencies COMMAND test_dependencies)

add_executable(test_transitive test_transitive.cpp)
target_link_libraries(test_transitive lib_d_bundled)
add_test(NAME test_transitive COMMAND test_transitive)

add_executable(test_multiple_g test_multiple_g.cpp)
target_link_libraries(test_multiple_g lib_g_bundled)
add_test(NAME test_multiple_g COMMAND test_multiple_g)

add_executable(test_multiple_h test_multiple_h.cpp)
target_link_libraries(test_multiple_h lib_h_bundled)
add_test(NAME test_multiple_h COMMAND test_multiple_h)
