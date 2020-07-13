#pragma once

#include "GLKeys.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Entropy
{
	class __declspec(dllexport) GLWindow
	{
	private:
		void initGLFW();
		void initGLEW();

	public:
		unsigned int VAO, VBO, EBO, EBO_SIZE, VBO_SIZE; //Graphics Buffers
		GLFWwindow* window;
		unsigned int width, height;

		GLWindow(unsigned int width, unsigned int height, const char* title);
		~GLWindow();

		void processEvents();

		void clear();
		void drawArrays();
		void drawElements();
		
		bool getShouldClose();
		bool getKeyPressed(GLKeys key);

		void setShouldClose(bool value);
		void setWindowClearColor(float red, float green, float blue, float alpha);

		void setVertexBufferData(unsigned int size, float* data);
		void setElementBufferData(unsigned int size, unsigned int* data);
		void setVertexAttributes(unsigned int index, int size, unsigned int type, unsigned int normalised, int stride, void* pointer);
	};

	__declspec(dllexport) void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}
