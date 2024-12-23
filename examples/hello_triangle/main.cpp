#include "window.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "shader.h"
#include "camera.h"

static void ProcessInput(Window& window, Camera& camera, float delta)
{
	if (window.GetKey(GLFW_KEY_W) == GLFW_PRESS)
		camera.MoveCamera(Camera::FORWARD, delta);
	if (window.GetKey(GLFW_KEY_S) == GLFW_PRESS)
		camera.MoveCamera(Camera::BACKWARD, delta);
	if (window.GetKey(GLFW_KEY_A) == GLFW_PRESS)
		camera.MoveCamera(Camera::LEFT, delta);
	if (window.GetKey(GLFW_KEY_D) == GLFW_PRESS)
		camera.MoveCamera(Camera::RIGHT, delta);
	if (window.GetKey(GLFW_KEY_LEFT) == GLFW_PRESS)
		camera.MoveCamera(Camera::LEFT_SPIN, delta);
	if (window.GetKey(GLFW_KEY_RIGHT) == GLFW_PRESS)
		camera.MoveCamera(Camera::RIGHT_SPIN, delta);
	if (window.GetKey(GLFW_KEY_UP) == GLFW_PRESS)
		camera.MoveCamera(Camera::UP_SPIN, delta);
	if (window.GetKey(GLFW_KEY_DOWN) == GLFW_PRESS)
		camera.MoveCamera(Camera::DOWN_SPIN, delta);
}

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
	
	Camera camera(glm::vec3(0, 0, 4), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));

	Shader shader("basic.glvs", "basic.glfs");

	VertexArray va;
	va.Bind();
	VertexBuffer vb(vertices, sizeof(vertices));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);

	float delta = 0.0f;
	float lastTime = glfwGetTime();

	while (!window.IsClosed())
	{
		float currentTime = glfwGetTime();
		delta = currentTime - lastTime;
		lastTime = currentTime;

		ProcessInput(window, camera, delta);

		window.Clear();

		glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
		shader.SetUniformMat4f("u_MVP", mvp);

		shader.Bind();
		va.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		va.Unbind();
		shader.Unbind();

		window.Update();
	}

	return 0;
}