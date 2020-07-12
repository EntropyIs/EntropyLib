#pragma once
#include "Matrix4Ext.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Entropy
{
	class __declspec(dllexport) GLCamera
	{
	public:
		// Camera Attributes
		Math::Vector3 position;
		Math::Vector3 front;
		Math::Vector3 up;
		Math::Vector3 right;
		Math::Vector3 worldUp;

		// Camera Modifiers
		float yaw;
		float pitch;

		float movementSpeed;
		float mouseSensitivity;
		float zoom;

		GLCamera(Math::Vector3 position = Math::Vector3(), Math::Vector3 up = Math::Vector3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);

		void update();
	};
}