#include "GLApplication.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Entropy
{
	GLApplication::GLApplication()
	{
	}

	GLApplication::~GLApplication()
	{
		glfwTerminate();
	}

	void GLApplication::initializeGLFW()
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

	void GLApplication::initializeGLEW()
	{
		// Initialize GLEW
		GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			std::cout << "Failed to initialize GLEW.\n" << glewGetErrorString(error);
			throw std::exception("Failed to initialize GLEW.");
		}
	}
}