#pragma once

#include "vertexbuffer.h"
#include "vertexbufferlayout.h"

// class representing a vertex array
class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_ID;
};


