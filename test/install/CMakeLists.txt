cmake_minimum_required(VERSION 3.15)
project(BundleStaticLibraryInstallTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add parent directory to module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../..")

# Include the bundle_static_library function
include(bundle_static_library)

# Create test libraries
add_library(mylib_a STATIC mylib_a.cpp)
target_include_directories(mylib_a PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>)

add_library(mylib_b STATIC mylib_b.cpp)
target_include_directories(mylib_b PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(mylib_b PUBLIC mylib_a)

# Bundle the libraries
bundle_static_library(mylib_b mylib_bundled)

# Install the bundled library using the exported variable
install(FILES ${mylib_bundled_LIBRARY_FILE}
        DESTINATION lib
        COMPONENT libraries)

# Or install using the property
get_target_property(BUNDLE_FILE mylib_bundled BUNDLE_LIBRARY_FILE)
message(STATUS "Bundled library file: ${BUNDLE_FILE}")

# Install headers
install(FILES mylib_a.h mylib_b.h
        DESTINATION include
        COMPONENT headers)
