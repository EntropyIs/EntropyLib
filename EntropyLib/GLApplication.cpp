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