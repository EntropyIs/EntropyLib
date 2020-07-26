#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Entropy
{
	namespace Graphics
	{
		class __declspec(dllexport) FrameBuffer
		{
		private:
			unsigned int fbo;

			bool depthTest;
			bool stencilTest;
			bool faceCulling;

		public:
			FrameBuffer(bool depthTest, bool stencilTest, bool faceCulling);
			~FrameBuffer();

			void bind();
		};
	}
}