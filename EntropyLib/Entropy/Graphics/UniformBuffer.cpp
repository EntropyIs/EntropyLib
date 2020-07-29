#include "UniformBuffer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Entropy::Graphics::UniformBuffer::UniformBuffer(unsigned int size, const void* data)
{
	glGenBuffers(1, &UBO);
	glBindBuffer(GL_UNIFORM_BUFFER, UBO);
	glBufferData(GL_UNIFORM_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBufferRange(GL_UNIFORM_BUFFER, 0, UBO, 0, size);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Entropy::Graphics::UniformBuffer::setSubData(unsigned int offset, unsigned int size, const void* data)
{
	glBindBuffer(GL_UNIFORM_BUFFER, UBO);
	glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
