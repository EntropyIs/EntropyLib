#pragma once

#include "GLKeys.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Entropy
{
	class __declspec(dllexport) GLWindow
	{
	private:
		unsigned int VAO, VBO, EBO; //Graphics Buffers

		void initGLFW();
		void initGLEW();

	public:
		GLFWwindow* window;

		GLWindow(int width, int height, const char* title);
		~GLWindow();

		void processEvents();
		void render();
		
		bool getShouldClose();
		bool getKeyPressed(GLKeys key);

		void setShouldClose(bool value);
		void setWindowClearColor(float red, float green, float blue, float alpha);

		void setVertexData(float* data);
	};

	__declspec(dllexport) void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}
