#include "GLMouse.h"

Entropy::GLMouse::GLMouse(GLFWwindow* window, unsigned int witdth, unsigned int height)
{
	lastX = witdth / 2.0f;
	lastY = height / 2.0f;
	xOffset = 0.0f;
	yOffset = 0.0f;
	sXOffset = 0.0f;
	sYOffset = 0.0f;

	fisrtMouse = true;

	this->window = window;

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetWindowUserPointer(window, reinterpret_cast<void*>(this));
	glfwSetCursorPosCallback(window, mouse_callback);
}

void Entropy::GLMouse::moveEvent(float xPos, float yPos)
{
	if (fisrtMouse)
	{
		lastX = xPos;
		lastY = yPos;
		fisrtMouse = false;
	}

	xOffset = xPos - lastX;
	yOffset = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	const float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;
	moveTrigger = true;
}

void Entropy::GLMouse::scrollEvent(float xOffset, float yOffset)
{
	sXOffset = xOffset;
	sYOffset = yOffset;
	scrollTrigger = true;
}

void Entropy::GLMouse::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	GLMouse* mouse = reinterpret_cast<GLMouse*>(glfwGetWindowUserPointer(window));
	mouse->moveEvent((float)xPos, (float)yPos);
}

void Entropy::GLMouse::scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{
	GLMouse* mouse = reinterpret_cast<GLMouse*>(glfwGetWindowUserPointer(window));
	mouse->scrollEvent((float)xOffset, (float)yOffset);
}
