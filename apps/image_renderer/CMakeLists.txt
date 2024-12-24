cmake_minimum_required(VERSION 3.28)

project(image_renderer)

link_directories(
	"${CMAKE_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

add_library(image_renderer STATIC image_renderer.h image_renderer.cpp)

if (BUILD_SHARED_LIB)
	message(STATUS "Setting SHARED=ON for image_renderer")
	target_compile_definitions(image_renderer PRIVATE GLLITE_SHARED)
endif()

target_include_directories(image_renderer INTERFACE ".")

target_link_libraries(image_renderer PRIVATE GLLite)

