cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

project(GLLite)

link_directories(
	"${CMAKE_SOURCE_DIR}/3rd/glew/lib/Release/x64/"
	"${CMAKE_SOURCE_DIR}/3rd/glfw/lib-vc2022/"
)

message(STATUS "GLFW lib dir: ${CMAKE_SOURCE_DIR}/3rd/glfw/lib-vc2022/")
message(STATUS "GLEW lib dir: ${CMAKE_SOURCE_DIR}/3rd/glew/lib/Release/x64/")

set(GLLITE_SOURCES 
	"src/window.cpp"
	"src/vertexbuffer.cpp"
	"src/vertexbufferlayout.cpp"
	"src/vertexarray.cpp"
	"src/shader.cpp"
	"src/texture.cpp"
	"src/indexarray.cpp"
	"src/camera.cpp"
)

set(GLLITE_HEADERS
	"include/window.h"
	"include/vertexbuffer.h"
	"include/vertexbufferlayout.h"
	"include/vertexarray.h"
	"include/shader.h"
	"include/texture.h"
	"include/indexarray.h"
	"include/camera.h"
	"include/utils.h"
)

set(GLLITE_SHADERS
	"glsl/basic.glvs"
	"glsl/basic.glfs"
)

set(GLLITE_BUILD_SHARED ${BUILD_SHARED_LIB})

if (GLLITE_BUILD_SHARED)
	message(STATUS "BUILDING SHARED LIBRARY FOR GLLITE")
	add_library(GLLite SHARED ${GLLITE_SOURCES} ${GLLITE_HEADERS} ${GLLITE_SHADERS})
	target_compile_definitions(GLLite PRIVATE "GLLITE_EXPORTS" "GLLITE_SHARED")
else()
	message(STATUS "BUILDING STATIC LIBRARY FOR GLLITE")
	add_library(GLLite STATIC ${GLLITE_SOURCES} ${GLLITE_HEADERS} ${GLLITE_SHADERS})
endif()

target_include_directories(GLLite PUBLIC
	"${CMAKE_SOURCE_DIR}/3rd/glew/include"
	"${CMAKE_SOURCE_DIR}/3rd/glfw/include"
	"${CMAKE_SOURCE_DIR}/3rd/glm/glm"
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)


target_compile_definitions(GLLite PUBLIC
	"GLEW_STATIC"
)

target_link_libraries(GLLite PUBLIC
	"glew32s"
	"glfw3"
	"opengl32"
)