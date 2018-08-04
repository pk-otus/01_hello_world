cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(hello_world VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(hello_world VERSION 0.0.1)
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(HelloWorld_cli main.cpp)

add_library(HelloWorld lib.cpp)

add_executable(test_main_cli test_main.cpp)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(HelloWorld_cli test_main_cli PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -W3 
	)
else()
	set_target_properties(HelloWorld_cli test_main_cli PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
	)
endif()

set_target_properties(test_main_cli PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(HelloWorld_cli HelloWorld)

message(STATUS "Boost_LIBRARIES=" ${Boost_LIBRARIES})

target_link_libraries(test_main_cli
  ${Boost_LIBRARIES}
  HelloWorld
)

install(TARGETS HelloWorld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vvz.otus@gmail.com)

include (CPack)

enable_testing()

add_test(test_version_valid test_main_cli)
