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
		// Initalize OpenGL Window
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

		// Generate Object Buffers
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		// Set GlDepthTest
		glEnable(GL_DEPTH_TEST);
	}

	GLWindow::~GLWindow()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void GLWindow::processEvents()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void GLWindow::clear()
	{
		//Clear Window
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void GLWindow::drawElements()
	{
		//Render Objects
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, EBO_SIZE, GL_UNSIGNED_INT, 0);
	}

	void GLWindow::drawArrays()
	{
		//Render Vertices
		glDrawArrays(GL_TRIANGLES, 0, VBO_SIZE);
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

	void GLWindow::setVertexBufferData(unsigned int size, float* data)
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		VBO_SIZE = size / sizeof(float);
	}

	void GLWindow::setElementBufferData(unsigned int size, unsigned int* data)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		EBO_SIZE = size / sizeof(unsigned int);
	}

	void GLWindow::setVertexAttributes(unsigned int index, int size, unsigned int type, unsigned int normalised, int stride, void* pointer)
	{
		glVertexAttribPointer(index, size, type, normalised, stride, pointer);
		glEnableVertexAttribArray(index);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}