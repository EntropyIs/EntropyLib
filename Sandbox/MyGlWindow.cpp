#include "MyGlWindow.h"

#include <iostream>
#include <exception>

MyGlWindow::MyGlWindow(int width, int height, const char* title)
{
	// Initalize GL
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create window;
	createWindow(width, height, title);

	// Load all OpenGL Function Pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD." << std::endl;
		glfwTerminate();
		throw std::exception("Failed to initialize GLAD.");
	}
}

MyGlWindow::~MyGlWindow()
{
	glfwTerminate();
}

void MyGlWindow::processEvents()
{
	glfwSwapBuffers(glWindow);
	glfwPollEvents();
}

bool MyGlWindow::getShouldClose()
{
	return glfwWindowShouldClose(glWindow);
}

bool MyGlWindow::getKeyPressed(GLKeys key)
{
	return glfwGetKey(glWindow, key) == GLFW_PRESS;
}

void MyGlWindow::setWindowShouldClose(bool value)
{
	glfwSetWindowShouldClose(glWindow, value);
}

void MyGlWindow::setWindowClearColor(GLfloat red, GLfloat blue, GLfloat green, GLfloat alpha)
{
	glClearColor(red, green, blue, alpha);
}

void MyGlWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void MyGlWindow::createWindow(int width, int height, const char* title)
{
	glWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (glWindow == NULL)
	{
		std::cout << "Failed to create GLFW window." << std::endl;
		glfwTerminate();
		throw std::exception("Failed to create GLFW window.");
	}
	glfwSetFramebufferSizeCallback(glWindow, framebuffer_size_callback);
	glfwMakeContextCurrent(glWindow);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
