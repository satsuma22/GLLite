cmake_minimum_required(VERSION 3.28)

project(hello_indexed_quad)

link_directories(
	"${CMAKE_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

add_executable(hello_indexed_quad main.cpp)

if (BUILD_SHARED_LIB)
	message(STATUS "Setting SHARED=ON for hello_indexed_quad")
	target_compile_definitions(hello_indexed_quad PRIVATE GLLITE_SHARED)
endif()

target_link_libraries(hello_indexed_quad PRIVATE GLLite)