#include "GLWindow.h"

#include <iostream>

namespace Entropy
{
	GLWindow::GLWindow(int width, int height, const char* title)
	{
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window." << std::endl;
			throw std::exception("Failed to create GLFW window.");
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	}

	GLWindow::~GLWindow()
	{
		glfwDestroyWindow(window);
	}

	void GLWindow::processEvents()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void GLWindow::render()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	bool GLWindow::getShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	bool GLWindow::getKeyPressed(Entropy::GLKeys key)
	{
		return glfwGetKey(window, key) == GLFW_PRESS;
	}

	void GLWindow::setShouldClose(bool value)
	{
		glfwSetWindowShouldClose(window, value);
	}

	void GLWindow::setWindowClearColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}