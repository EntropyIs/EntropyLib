#include "GLCamera.h"
#include "Converters.h"

#include <cmath>

Entropy::GLCamera::GLCamera(Math::Vector3 position, Math::Vector3 up, float yaw, float pitch)
	: position(position), front(Math::Vector3(0.0f, 0.0f, -1.0f)), worldUp(up), yaw(yaw), pitch(pitch), movementSpeed(2.5f), mouseSensitivity(0.1f), zoom(45.0f)
{
	update();
}

void Entropy::GLCamera::update()
{
	Math::Vector3 direction;
	direction.i = cos(Math::radians(yaw)) * cos(Math::radians(pitch));
	direction.j = sin(Math::radians(pitch));
	direction.k = sin(Math::radians(yaw)) * cos(Math::radians(pitch));
	front = normalize(direction);

	right = normalize(cross(front, worldUp));
	up = normalize(cross(front, right));
}
