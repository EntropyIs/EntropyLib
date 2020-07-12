#include "GLMouse.h"

Entropy::GLMouse::GLMouse(GLFWwindow* window, unsigned int witdth, unsigned int height)
{
	lastX = witdth / 2.0f;
	lastY = height / 2.0f;
	xOffset = 0.0f;
	yOffset = 0.0f;

	this->window = window;

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetWindowUserPointer(window, reinterpret_cast<void*>(this));
	glfwSetCursorPosCallback(window, mouse_callback);
}

float Entropy::GLMouse::getLastX()
{
	return lastX;
}

float Entropy::GLMouse::getLastY()
{
	return lastY;
}

float Entropy::GLMouse::getXOffset()
{
	return xOffset;
}

float Entropy::GLMouse::getYOffset()
{
	return yOffset;
}

void Entropy::GLMouse::setLastX(float value)
{
	lastX = value;
}

void Entropy::GLMouse::setLastY(float value)
{
	lastY = value;
}

void Entropy::GLMouse::setXOffset(float value)
{
	xOffset = value;
}

void Entropy::GLMouse::setYOffset(float value)
{
	yOffset = value;
}

void Entropy::GLMouse::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	GLMouse* mouse = reinterpret_cast<GLMouse*>(glfwGetWindowUserPointer);
	mouse->xOffset = (float) xPos - mouse->lastX;
	mouse->yOffset = mouse->lastY - (float) yPos;
	mouse->lastX = (float) xPos;
	mouse->lastY = (float) yPos;

	const float sensitivity = 0.1f;
	mouse->xOffset *= sensitivity;
	mouse->yOffset *= sensitivity;
}
