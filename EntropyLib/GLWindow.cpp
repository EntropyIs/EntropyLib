#include "GLWindow.h"

#include <iostream>

namespace Entropy
{
	void GLWindow::initGLFW()
	{
		// Initialize and Configure GLFW
		if (!glfwInit())
		{
			std::cout << "Failed to initalize GLFW." << std::endl;
			throw std::exception("Failed to initialize GLFW.");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	}

	void GLWindow::initGLEW()
	{
		// Initialize GLEW
		GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			std::cout << "Failed to initialize GLEW.\n" << glewGetErrorString(error);
			throw std::exception("Failed to initialize GLEW.");
		}
	}

	GLWindow::GLWindow(int width, int height, const char* title)
	{
		initGLFW();
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window." << std::endl;
			glfwTerminate();
			throw std::exception("Failed to create GLFW window.", 10015);
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		initGLEW();
	}

	GLWindow::~GLWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
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

	void GLWindow::setVertexData(float* data)
	{
		
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}