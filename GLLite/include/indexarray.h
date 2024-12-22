#pragma once

#include <vector>

#include "utils.h"

// class representing an index array (Element Buffer Object) in openGL
class GLLITE_API IndexArray
{
public:
	IndexArray();
	~IndexArray();
	// bind the index array
	void Bind() const;
	// unbind the index array
	void Unbind() const;
	// set the data of the index array
	void SetData(const unsigned int* data, unsigned int count);
	// get the count of the index array
	inline unsigned int GetCount() const { return m_Count; }
private:
	unsigned int m_ID;
	unsigned int m_Count;
};
