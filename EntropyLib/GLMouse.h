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
		float sXOffset;
		float sYOffset;

		bool fisrtMouse;
		bool moveTrigger;
		bool scrollTrigger;

		GLMouse(GLFWwindow* window, unsigned int witdth, unsigned int height);

		void moveEvent(float xPos, float yPos);
		void scrollEvent(float xOffset, float yOffset);

		static void mouse_callback(GLFWwindow* window, double xPos, double yPos);
		static void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
	};
}
