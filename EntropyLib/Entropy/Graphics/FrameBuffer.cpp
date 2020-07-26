#include "FrameBuffer.h"

Entropy::Graphics::FrameBuffer::FrameBuffer(bool depthTest, bool stencilTest, bool faceCulling) : depthTest(depthTest), stencilTest(stencilTest), faceCulling(faceCulling)
{
	glGenFramebuffers(1, &fbo);
}

Entropy::Graphics::FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &fbo);
}

void Entropy::Graphics::FrameBuffer::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}
