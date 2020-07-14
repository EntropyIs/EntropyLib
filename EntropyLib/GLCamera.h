#pragma once
#include "Matrix4Ext.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Entropy
{

	enum CameraMovement
	{
		CAMERA_FORWARD,
		CAMERA_BACKWARD,
		CAMERA_LEFT,
		CAMERA_RIGHT,
		CAMERA_UP,
		CAMERA_DOWN,
		WORLD_UP,
		WORLD_DOWN
	};

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

		float mouseSensitivity;
		float zoom;

		GLCamera(Math::Vector3 position = Math::Vector3(), Math::Vector3 up = Math::Vector3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);

		Math::Matrix4 getViewMatrix();

		void updatePosition(CameraMovement direction, float deltaTime, float velocity = 2.5f);
		void updateRotation(float xOffset, float yOffset, bool constrainPitch = true, float minPitch = -89.0f, float maxPitch = 89.0f);
		void updateFOV(float offset);

		void updateVectors();
	};
}