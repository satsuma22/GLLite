#pragma once

#include <GL/glew.h>
#include <vector>

#include "utils.h"

// struct representing an element in the vertex buffer layout
struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;
	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:          return 4;
		case GL_UNSIGNED_INT:   return 4;
		case GL_UNSIGNED_BYTE:  return 1;
		}
		return 0;
	}
};

// abstract class representing a vertex buffer layout
class GLLITE_API VertexBufferLayout
{
public:
	VertexBufferLayout() : m_Stride(0) {}
	
	template<typename T>
	void Push(unsigned int count);

	inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride; }
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
};