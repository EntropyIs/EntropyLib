#include "InstanceBuffer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Entropy::Graphics::InstanceBuffer::InstanceBuffer(unsigned int count, size_t elementSize, const void* data)
{
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, count * elementSize, data, GL_STATIC_DRAW);
}
