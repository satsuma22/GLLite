cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_SHARED_LIB OFF CACHE BOOL "Enable shared libraries globally")

add_subdirectory(GLLite)
add_subdirectory(examples)