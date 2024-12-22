cmake_minimum_required(VERSION 3.28)

project(hello_triangle)

link_directories(
	"${CMAKE_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

add_executable(hello_triangle main.cpp)

if (${BUILD_SHARED_LIB})
	target_compile_definitions(hello_triangle PRIVATE GLLITE_SHARED)
endif()

target_link_libraries(hello_triangle PRIVATE GLLite)