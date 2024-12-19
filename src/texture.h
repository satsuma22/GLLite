#pragma once

#include <string>
#include <vector>
#include <GL/glew.h>

class Texture
{
public:
	Texture();
	~Texture();

	void CreateFromBuffer(unsigned char* buffer, int height, int width);

	void Bind(unsigned int slot = 0) const;
	void Unbind();

	inline int GetHeight() const { return m_Height; }
	inline int GetWidth() const { return m_Width; }

private:
	unsigned int m_Id;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height;
};