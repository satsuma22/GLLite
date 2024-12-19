#include "window.h"

int main()
{
	Window window(800, 600, "OpenGL");

	while (!window.IsClosed())
	{
		window.Clear();
		window.Update();
	}

	return 0;
}