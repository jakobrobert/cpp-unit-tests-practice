cmake_minimum_required(VERSION 3.10)

project(cpp-unit-tests-practice)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

add_subdirectory(lib)
add_subdirectory(test)
