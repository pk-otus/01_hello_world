cmake_minimum_required(VERSION 3.2)

project(google_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(googletest_main_cli googletest_main.cpp)

set_target_properties(googletest_main_cli PROPERTIES
INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(googletest_main_cli version_control ${GTEST_LIBRARIES})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(googletest_main_cli pthread)
endif()

add_test(gt_version_valid googletest_main_cli)