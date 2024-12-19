cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

project(GLLite)

link_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

set(GLLITE_SOURCES 
	"src/main.cpp"
	"src/window.cpp"
	"src/vertexbuffer.cpp"
	"src/vertexbufferlayout.cpp"
	"src/vertexarray.cpp"
)

set(GLLITE_HEADERS
	"src/window.h"
	"src/vertexbuffer.h"
	"src/vertexbufferlayout.h"
	"src/vertexarray.h"
)

add_executable(GLLite ${GLLITE_SOURCES} ${GLLITE_HEADERS})

target_include_directories(GLLite PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glew/include"
	"${CMAKE_CURRENT_SOURCE_DIR}/3rd/glfw/include"
)

target_compile_definitions(GLLite PRIVATE
	"GLEW_STATIC"
)

target_link_libraries(GLLite PRIVATE
	"glew32s"
	"glfw3"
	"opengl32"
)