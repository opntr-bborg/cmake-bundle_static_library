# Subdirectory B libraries
add_library(subdir_b_lib1 STATIC lib1.cpp)
target_include_directories(subdir_b_lib1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(subdir_b_lib2 STATIC lib2.cpp)
target_include_directories(subdir_b_lib2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(subdir_b_lib2 PUBLIC subdir_b_lib1)

bundle_static_library(subdir_b_lib2 subdir_b_bundled)

# Test executable
add_executable(test_subdir_b test_subdir_b.cpp)
target_link_libraries(test_subdir_b subdir_b_bundled)
add_test(NAME test_subdir_b COMMAND test_subdir_b)
