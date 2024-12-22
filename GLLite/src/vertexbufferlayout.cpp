#include "vertexbufferlayout.h"

// templated push function for adding elements to the layout
template<typename T>
void VertexBufferLayout::Push(unsigned int count)
{
	// static_assert is a compile-time check that will fail if the condition is false
	static_assert(false);
}

// specialization of the templated push function for floats
template<>
void VertexBufferLayout::Push<float>(unsigned int count)
{
	m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

// specialization of the templated push function for unsigned ints
template<>
void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
	m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

// specialization of the templated push function for unsigned chars
template<>
void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
	m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}

