#include "window.h"
#include <iostream>


// Constructor
Window::Window(int width, int height, const char* title)
	: m_width(width), m_height(height), m_title(title)
{
	Init();
	Create();
}

// Destructor
Window::~Window()
{
	Destroy();
}

// Clear the window
void Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// Update the window
void Window::Update() const
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

// Check if the window is closed
bool Window::IsClosed() const
{
	return glfwWindowShouldClose(m_window);
}

// Get the width of the window
int Window::GetWidth() const
{
	return m_width;
}

// Get the height of the window
int Window::GetHeight() const
{
	return m_height;
}


// Get status of a key
int Window::GetKey(int key) const
{
	return glfwGetKey(m_window, key);
}

// Initialize the window
void Window::Init()
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		exit(-1);
	}
}

// Create the window
void Window::Create()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
	if (!m_window)
	{
		std::cerr << "Failed to create window" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(m_window);
	//glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		exit(-1);
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	glClearColor(.8f, .8f, .8f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
}

// Destroy the window
void Window::Destroy()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

