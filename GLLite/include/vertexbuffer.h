#pragma once

#include <GL/glew.h>
#include <vector>

#include "utils.h"

// abstract class representing a vertex buffer in OpenGL
class GLLITE_API VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_ID;
};

