cmake_minimum_required(VERSION 3.28)

project(image_renderer)

link_directories(
	"${CMAKE_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

add_executable(image_renderer main.cpp image_renderer.h image_renderer.cpp)

target_link_libraries(image_renderer PRIVATE GLLite)