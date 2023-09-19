cmake_minimum_required(VERSION 3.14)
project(my_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

enable_testing()

add_executable(mytest First_GTest.cpp)

target_link_libraries(
    mytest
    GTest::gtest_main
)

include(GoogleTest)
message("Included module: ${CMAKE_CURRENT_LIST_FILE}")
gtest_discover_tests(mytest)