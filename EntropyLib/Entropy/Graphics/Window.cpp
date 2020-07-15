#include "Window.h"

#include <iostream>

Entropy::Graphics::Window::Window(const char* title, const unsigned int width, const unsigned int height) : Width(width), Height(height)
{
	// Initialize GLFW
	try
	{
		initializeGLFW();

		// Initialize OpenGL Window
		GLWindow = glfwCreateWindow(Width, Height, title, NULL, NULL);
		if (GLWindow == NULL)
		{
#ifdef _DEBUG
			std::cout << "Failed to create GLFW Window." << std::endl;
#endif // _DEBUG
			glfwTerminate();
			throw "Failed to create GLFW Window.";
		}
		glfwMakeContextCurrent(GLWindow);
		glfwSetWindowUserPointer(GLWindow, reinterpret_cast<void*>(this));
		glfwSetFramebufferSizeCallback(GLWindow, framebuffer_size_callback);

		// Initialize GLEW
		initializeGLEW();
		glEnable(GL_DEPTH_TEST);
	}
	catch (std::exception e)
	{
		throw;
	}
}

void Entropy::Graphics::Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Entropy::Graphics::Window::processEvents()
{
	glfwSwapBuffers(GLWindow);
	glfwPollEvents();
}

bool Entropy::Graphics::Window::getShouldClose()
{
	return glfwWindowShouldClose(GLWindow);
}

bool Entropy::Graphics::Window::getKeyPressed(GLKeys key)
{
	return glfwGetKey(GLWindow, key) == GLFW_PRESS;
}

void Entropy::Graphics::Window::setWindowClearColor(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
}

void Entropy::Graphics::Window::setShouldClose(bool value)
{
	glfwSetWindowShouldClose(GLWindow, value);
}

void Entropy::Graphics::Window::initializeGLFW()
{
	// Initialize and Configure GLFW
	if (!glfwInit())
	{
#ifdef _DEBUG
		std::cout << "Failed to initalize GLFW." << std::endl;
#endif // _DEBUG
		throw "Failed to initialize GLFW.";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void Entropy::Graphics::Window::initializeGLEW()
{
	// Initialize GLEW
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
#ifdef _DEBUG
		std::cout << "Failed to initialize GLEW.\n" << glewGetErrorString(error);
#endif // _DEBUG
		throw "Failed to initialize GLEW.";
	}
}

void Entropy::Graphics::Window::framebuffer_size_callback(GLFWwindow* glWindow, int width, int height)
{
	Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glWindow));
	glViewport(0, 0, width, height);
	window->Width = width;
	window->Height = height;
}
