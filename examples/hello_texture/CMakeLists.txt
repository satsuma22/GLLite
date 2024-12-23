cmake_minimum_required(VERSION 3.28)

project(hello_texture)

link_directories(
	"${CMAKE_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

add_executable(hello_texture main.cpp)

if (BUILD_SHARED_LIB)
	message(STATUS "Setting SHARED=ON for hello_texture")
	target_compile_definitions(hello_texture PRIVATE GLLITE_SHARED)
endif()

target_link_libraries(hello_texture PRIVATE GLLite)