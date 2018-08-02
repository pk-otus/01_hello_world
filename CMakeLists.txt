cmake_minimum_required(VERSION 3.2)

project(HelloWorld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(HelloWorld_cli main.cpp)

add_library(HelloWorld lib.cpp)

add_executable(test_main_cli test_main.cpp)
add_executable(gttest_main_cli googletest_main.cpp)

set_target_properties(HelloWorld_cli test_main_cli gttest_main_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_main_cli PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

set_target_properties(gttest_main_cli PROPERTIES
  INCLUDE_DIRECTORIES "/home/travis/build/pk-otus/OTUS/build/googletest/googletest/include"
)

target_link_libraries(HelloWorld_cli HelloWorld)

message(STATUS "Boost_LIBRARIES=" ${Boost_LIBRARIES})

target_link_libraries(test_main_cli
  ${Boost_LIBRARIES}
  HelloWorld
)

target_link_libraries(gttest_main_cli
  HelloWorld
  gtest_main
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
add_test(gt_version_valid gttest_main_cli)