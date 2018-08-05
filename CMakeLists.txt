cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(hello_world VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(hello_world VERSION 0.0.1)
endif()

add_executable(HelloWorld_cli main.cpp)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(HelloWorld_cli PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -W3 
	)
else()
	set_target_properties(HelloWorld_cli PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
	)
endif()

add_subdirectory(VersionControl)

target_link_libraries(HelloWorld_cli version_control)

install(TARGETS HelloWorld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vvz.otus@gmail.com)

include (CPack)

enable_testing()

add_subdirectory(boost_test)
add_subdirectory(google_test)