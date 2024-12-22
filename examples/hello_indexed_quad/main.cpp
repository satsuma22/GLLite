#include "window.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexarray.h"
#include "shader.h"

int main()
{
	Window window(800, 600, "OpenGL");

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f
	};

	unsigned int indeces[] = {
		0, 1, 2,
		2, 3, 0
	};

	Shader::ShaderDirectories.push_back("GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../../GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../../../GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../../../../GLLite/glsl/");

	Shader shader("basic.glvs", "basic.glfs");

	VertexArray va;
	VertexBuffer vb(vertices, sizeof(vertices));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);
	IndexArray ia;
	ia.SetData(indeces, 6);

	while (!window.IsClosed())
	{
		window.Clear();

		shader.Bind();
		va.Bind();
		glDrawElements(GL_TRIANGLES, ia.GetCount(), GL_UNSIGNED_INT, nullptr);
		va.Unbind();
		shader.Unbind();

		// swap the front and back buffers
		window.Update();
	}

	return 0;
}