cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(pcd_write)

find_package(PCL 1.2 REQUIRED)
message(${PCL_ROOT})
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(write_obj pcd_write)
add_executable (${write_obj} src/pcd_write.cpp)
target_link_libraries (${write_obj} ${PCL_LIBRARIES})

set(concat_obj concatenate_pcd)
add_executable (${concat_obj} src/concatenate.cpp)
target_link_libraries (${concat_obj} ${PCL_LIBRARIES})
