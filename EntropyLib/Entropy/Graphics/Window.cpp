#include "Window.h"

#include <iostream>

Entropy::Graphics::Window::Window(const char* title, unsigned int width, unsigned int height, bool depthTest, bool stencilTest, bool faceCulling) : Width(width), Height(height), MouseDelta(width / 2.0f, height / 2.0f), MouseSensitivity(0.1f)
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
#endif // DEBUG
			glfwTerminate();
			throw std::exception("Failed to create GLFW Window.");
		}
		glfwMakeContextCurrent(GLWindow);
		glfwSetWindowUserPointer(GLWindow, reinterpret_cast<void*>(this));

		glfwSetFramebufferSizeCallback(GLWindow, framebuffer_size_callback);

		// Initialize GLEW
		initializeGLEW();

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
	}
	catch (std::exception e)
	{
		throw e;
	}
}

void Entropy::Graphics::Window::captureMouse()
{
	glfwSetCursorPosCallback(GLWindow, mouse_movement_callback);
	glfwSetScrollCallback(GLWindow, mouse_scroll_callback);

	glfwSetInputMode(GLWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Entropy::Graphics::Window::clear()
{
	glClearColor(clearColor.R, clearColor.G, clearColor.B, clearColor.A);
	if (depthTest == true && stencilTest == true)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	else if (depthTest == true && stencilTest == false)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else if (depthTest == false && stencilTest == true)
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
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
	return glfwGetKey(GLWindow, static_cast<int>(key)) == GLFW_PRESS;
}

void Entropy::Graphics::Window::setClearColor(float red, float green, float blue, float alpha)
{
	clearColor = Math::Vec4(red, green, blue, alpha);
}

void Entropy::Graphics::Window::setShouldClose(bool value)
{
	glfwSetWindowShouldClose(GLWindow, value);
}

void Entropy::Graphics::Window::enableDepthTest(bool value)
{
	depthTest = value;
}

void Entropy::Graphics::Window::enableStencilTest(bool value)
{
	stencilTest = value;
}

void Entropy::Graphics::Window::enableFaceCulling(bool value)
{
	faceCulling = value;
}

void Entropy::Graphics::Window::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	if (depthTest)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);

	if (stencilTest)
		glEnable(GL_STENCIL_TEST);
	else
		glDisable(GL_STENCIL_TEST);

	if (faceCulling)
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);
}

void Entropy::Graphics::Window::initializeGLFW()
{
	// Initialize and Configure GLFW
	if (!glfwInit())
	{
#ifdef _DEBUG
		std::cout << "Failed to initalize GLFW." << std::endl;
#endif // DEBUG
		throw std::exception("Failed to initialize GLFW.");
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
#endif // DEBUG
		throw std::exception("Failed to initialize GLEW.");
	}
}

void Entropy::Graphics::Window::framebuffer_size_callback(GLFWwindow* glWindow, int width, int height)
{
	Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glWindow));
	glViewport(0, 0, width, height);
	window->Width = width;
	window->Height = height;
}

void Entropy::Graphics::Window::mouse_movement_callback(GLFWwindow* glWindow, double xPos, double yPos)
{
	Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glWindow));

	if (window->MouseDelta.FirstMouse)
	{
		window->MouseDelta.LastX = (float)xPos;
		window->MouseDelta.LastY = (float)yPos;
		window->MouseDelta.FirstMouse = false;
	}

	window->MouseDelta.XOffset = ((float)xPos - window->MouseDelta.LastX) * window->MouseSensitivity;
	window->MouseDelta.YOffset = ((float)yPos - window->MouseDelta.LastY) * window->MouseSensitivity;
	window->MouseDelta.LastX = (float)xPos;
	window->MouseDelta.LastY = (float)yPos;

	window->MouseDelta.MoveTrigger = true;
}

void Entropy::Graphics::Window::mouse_scroll_callback(GLFWwindow* glWindow, double xOffset, double yOffset)
{
	Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glWindow));

	window->MouseDelta.ScrollXOffset = (float)xOffset;
	window->MouseDelta.ScrollYOffset = (float)yOffset;

	window->MouseDelta.ScrollTrigger = true;
}
