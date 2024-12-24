#pragma once

#include "vertexarray.h"
#include "vertexbuffer.h"
#include "vertexbufferlayout.h"
#include "texture.h"
#include "shader.h"
#include "utils.h"

class ImageRenderer
{
public:
	ImageRenderer();
	~ImageRenderer();

	void SetImage(unsigned char* buffer, int width, int height);
	void Draw();
private:
	VertexArray m_VAO;
	VertexBuffer m_VBO;
	VertexBufferLayout m_Layout;
	Texture m_Texture;
	Shader m_Shader;
};