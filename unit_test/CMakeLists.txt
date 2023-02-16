cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)

# Begin PCL Need
find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
# End PCL Need

# Begin GTest Need
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
# End GTest Need

add_executable(
  hello_test
  hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)
gtest_discover_tests(hello_test)

set(target_pcl test_pcl)
set(src ${CMAKE_CURRENT_SOURCE_DIR}/PCL_utility_test.cpp)
add_executable(${target_pcl})
target_sources(${target_pcl} PRIVATE ${src})
message(${PROJECT_SOURCE_DIR})
target_include_directories(${target_pcl} PRIVATE ${PROJECT_SOURCE_DIR})
# Link 3rd lib
target_link_libraries(
    ${target_pcl}
    ${PCL_LIBRARIES}
    GTest::gtest_main
)
gtest_discover_tests(${target_pcl})

file(GLOB test_files "*.pcd")
file(INSTALL ${test_files} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
