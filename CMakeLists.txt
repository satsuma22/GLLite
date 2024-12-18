cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

project(GLLite)

link_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

add_executable(GLLite "src/main.cpp")

target_include_directories(GLLite PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glew/include"
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glfw/include"
)

target_link_libraries(GLLite PRIVATE
	"glew32s"
	"glfw3"
	"opengl32"
)