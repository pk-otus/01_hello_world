cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(version_control VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(version_control VERSION 0.0.1)
endif()

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_library(version_control version_control.cpp)

