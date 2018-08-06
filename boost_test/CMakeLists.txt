cmake_minimum_required(VERSION 3.2)

project(boost_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(boosttest_main_cli boosttest_main.cpp)

set_target_properties(boosttest_main_cli PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(boosttest_main_cli version_control ${Boost_LIBRARIES} )

add_test(
	NAME boost_version_valid 
	COMMAND boosttest_main_cli)