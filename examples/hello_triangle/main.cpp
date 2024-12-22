#include "window.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "shader.h"

int main()
{
	Window window(800, 600, "OpenGL");

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	Shader::ShaderDirectories.push_back("GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../../GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../../../GLLite/glsl/");
	Shader::ShaderDirectories.push_back("../../../../GLLite/glsl/");
	
	Shader shader("basic.glvs", "basic.glfs");

	VertexArray va;
	va.Bind();
	VertexBuffer vb(vertices, sizeof(vertices));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);

	while (!window.IsClosed())
	{
		window.Clear();

		shader.Bind();
		va.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		va.Unbind();
		shader.Unbind();

		window.Update();
	}

	return 0;
}