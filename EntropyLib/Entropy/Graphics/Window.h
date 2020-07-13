#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Entropy
{
	namespace Graphics
	{
		class __declspec(dllexport) Window
		{
		public:
			GLFWwindow* GLWindow;
			unsigned int Width, Height;

			Window(const char* title, const unsigned int width = 800, const unsigned int height = 600);

		private:
			void initializeGLFW();
			void initializeGLEW();

			static void framebuffer_size_callback(GLFWwindow* glWindow, int width, int height);
		};
	}
}
