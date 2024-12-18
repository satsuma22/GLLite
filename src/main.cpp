#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

}