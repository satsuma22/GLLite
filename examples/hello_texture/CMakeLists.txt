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

	set(GLLITE_DLL_PATH_DEBUG "${CMAKE_BINARY_DIR}/GLLite/Debug/GLLite.dll")
	set(GLLITE_DLL_PATH_RELEASE "${CMAKE_BINARY_DIR}/GLLite/Release/GLLite.dll")

	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different 
		"$<$<CONFIG:Debug>:${GLLITE_DLL_PATH_DEBUG}>"
    	"$<$<CONFIG:Release>:${GLLITE_DLL_PATH_RELEASE}>"
		$<TARGET_FILE_DIR:${PROJECT_NAME}>
	)
endif()

target_link_libraries(hello_texture PRIVATE GLLite)

