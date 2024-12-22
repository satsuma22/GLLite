#pragma once

#include "vertexbuffer.h"
#include "vertexbufferlayout.h"

#include "utils.h"

// class representing a vertex array
class GLLITE_API VertexArray
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


