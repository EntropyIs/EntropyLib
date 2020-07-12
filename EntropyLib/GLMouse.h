#pragma once

#include <GLFW/glfw3.h>

namespace Entropy
{
	class __declspec(dllexport) GLMouse
	{
	public:
		GLFWwindow* window;
		float lastX;
		float lastY;
		float xOffset;
		float yOffset;

		GLMouse(GLFWwindow* window, unsigned int witdth, unsigned int height);

		float getLastX();
		float getLastY();
		float getXOffset();
		float getYOffset();

		void setLastX(float value);
		void setLastY(float value);
		void setXOffset(float value);
		void setYOffset(float value);

		static void mouse_callback(GLFWwindow* window, double xPos, double yPos);
	};

	
}
