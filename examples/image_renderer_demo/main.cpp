#include "image_renderer.h"
#include "window.h"

int main()
{
	Window window(800, 600, "Image Renderer");
	
	unsigned char* buffer = new unsigned char[4 * 800 * 600];

	for (int i = 0; i < 800 * 600; i++)
	{
		buffer[i * 4] = 255;
		buffer[i * 4 + 1] = 0;
		buffer[i * 4 + 2] = 0;
		buffer[i * 4 + 3] = 255;
	}

	ImageRenderer renderer;
	renderer.SetImage(buffer, 800, 600);

	while (!window.IsClosed())
	{
		window.Clear();
		renderer.Draw();
		window.Update();
	}

	delete[] buffer;

	return 0;
}