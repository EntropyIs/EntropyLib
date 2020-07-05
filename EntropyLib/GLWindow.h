#pragma once

#include "GLKeys.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Entropy
{
	class __declspec(dllexport) GLWindow
	{
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
	};

	__declspec(dllexport) void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}
