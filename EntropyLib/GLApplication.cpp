#include "GLApplication.h"

#include <glad/glad.h>
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
		// Initalize and Configure GLFW
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
		std::cout << "initialized GLFW." << std::endl;
	}

	void GLApplication::initializeGLAD()
	{
		// Initalize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD." << std::endl;
			glfwTerminate();
			throw std::exception("Failed to initialize GLAD.");
		}
		std::cout << "initialized GLAD." << std::endl;
	}
}