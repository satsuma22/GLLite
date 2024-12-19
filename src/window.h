#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// An abstract class that creates a window and initializes OPENGL
class Window
{
public:
	// Constructor
	Window(int width, int height, const char* title);
	// Destructor
	~Window();
	// Clear the window
	void Clear() const;
	// Update the window
	void Update() const;
	// Check if the window is closed
	bool IsClosed() const;
	// Get the width of the window
	int GetWidth() const;
	// Get the height of the window
	int GetHeight() const;
private:
	// The width of the window
	int m_width;
	// The height of the window
	int m_height;
	// The title of the window
	const char* m_title;
	// The window
	GLFWwindow* m_window;
	// Initialize the window
	void Init();
	// Create the window
	void Create();
	// Destroy the window
	void Destroy();
};