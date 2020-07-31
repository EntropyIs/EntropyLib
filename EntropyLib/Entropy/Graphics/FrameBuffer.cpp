#include "FrameBuffer.h"

Entropy::Graphics::FrameBuffer::FrameBuffer(unsigned int width, unsigned int height, bool depthTest, bool stencilTest, bool faceCulling) : Width(width), Height(height), depthTest(depthTest), stencilTest(stencilTest), faceCulling(faceCulling)
{
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	glGenTextures(1, &ColorBuffer);
	glBindTexture(GL_TEXTURE_2D, ColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ColorBuffer, 0);

	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		throw std::exception("Framebuffer is not complete");

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Entropy::Graphics::FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &fbo);
}

void Entropy::Graphics::FrameBuffer::bind()
{
	glViewport(0, 0, Width, Height); // set viewport size
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	if (depthTest)
		glEnable(GL_DEPTH_TEST);
	if (stencilTest)
		glEnable(GL_STENCIL_TEST);
	if (faceCulling)
		glEnable(GL_CULL_FACE);
}

void Entropy::Graphics::FrameBuffer::clear()
{
	glClearColor(clearColor.R, clearColor.G, clearColor.B, clearColor.A);
	if (depthTest == true && stencilTest == true)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	else if (depthTest == true && stencilTest == false)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else if (depthTest == false && stencilTest == true)
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
}

void Entropy::Graphics::FrameBuffer::setClearColor(float red, float green, float blue, float alpha)
{
	clearColor = Math::Vec4(red, green, blue, alpha);
}

void Entropy::Graphics::FrameBuffer::enableDepthTest(bool value)
{
	depthTest = value;
}

void Entropy::Graphics::FrameBuffer::enableStencilTest(bool value)
{
	stencilTest = value;
}

void Entropy::Graphics::FrameBuffer::enableFaceCulling(bool value)
{
	faceCulling = value;
}
