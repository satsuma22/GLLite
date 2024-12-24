#include "image_renderer.h"

ImageRenderer::ImageRenderer()
{
	float vertices[] = {
		-1., -1., 0., 0., 0.,
		 1., -1., 0., 1., 0.,
		 1.,  1., 0., 1., 1.,
		-1., -1., 0., 0., 0.,
		 1.,  1., 0., 1., 1.,
		-1.,  1., 0., 0., 1.
	};

	Shader::ShaderDirectories.push_back("apps/image_renderer/");
	Shader::ShaderDirectories.push_back("../apps/image_renderer/");
	Shader::ShaderDirectories.push_back("../../apps/image_renderer/");
	Shader::ShaderDirectories.push_back("../../../apps/image_renderer/");
	Shader::ShaderDirectories.push_back("../../../../apps/image_renderer/");
	Shader::ShaderDirectories.push_back("../../../../../apps/image_renderer/");
	m_Shader = Shader("image.glvs", "image.glfs");

	m_VAO.Bind();
	m_VBO.SetData(vertices, sizeof(vertices));
	m_Layout.Push<float>(3);
	m_Layout.Push<float>(2);
	m_VAO.AddBuffer(m_VBO, m_Layout);
}

ImageRenderer::~ImageRenderer()
{
}

void ImageRenderer::SetImage(unsigned char* buffer, int width, int height)
{
	m_VAO.Bind();
	m_Shader.Bind();
	m_Texture.CreateFromBuffer(buffer, width, height);
	m_Texture.Bind();
}

void ImageRenderer::Draw() 
{
	m_Shader.SetUniform1i("texture_fs", 0);
	//m_Shader.SetUniform3f("color_fs", 1.0f, 0.0f, 0.0f);
	//m_Shader.SetUniform3f("normal_fs", 1.0f, 1.0f, 1.0f);
	
	m_Shader.Bind();
	m_Texture.Bind();
	m_VAO.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	m_VAO.Unbind();
	m_Texture.Unbind();
	m_Shader.Unbind();
}
