#pragma once

#include <GL/glew.h>
#include <vector>

// abstract class representing a vertex buffer in OpenGL
class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_ID;
};

