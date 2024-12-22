#include "indexarray.h"

#include <GL/glew.h>

IndexArray::IndexArray()
	: m_Count(0)
{
	glGenBuffers(1, &m_ID);
}

IndexArray::~IndexArray()
{
	glDeleteBuffers(1, &m_ID);
}

void IndexArray::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexArray::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexArray::SetData(const unsigned int* data, unsigned int count)
{
	m_Count = count;
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

