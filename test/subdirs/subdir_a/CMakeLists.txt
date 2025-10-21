# Subdirectory A libraries
add_library(subdir_a_lib1 STATIC lib1.cpp)
target_include_directories(subdir_a_lib1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(subdir_a_lib2 STATIC lib2.cpp)
target_include_directories(subdir_a_lib2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(subdir_a_lib2 PUBLIC subdir_a_lib1)

bundle_static_library(subdir_a_lib2 subdir_a_bundled)

# Test executable
add_executable(test_subdir_a test_subdir_a.cpp)
target_link_libraries(test_subdir_a subdir_a_bundled)
add_test(NAME test_subdir_a COMMAND test_subdir_a)
