#include "texture.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glew.h>

Texture::Texture()
	: m_Id(0), m_LocalBuffer(nullptr), m_Width(0), m_Height(0)
{
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_Id);
	delete[] m_LocalBuffer;
}

void Texture::CreateFromBuffer(unsigned char* buffer, int height, int width)
{
	m_Height = height;
	m_Width = width;
	glGenTextures(1, &m_Id);
	glBindTexture(GL_TEXTURE_2D, m_Id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_Id);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

