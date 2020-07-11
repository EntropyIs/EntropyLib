#pragma once

#include "Matrix4.h"
#include "Vector4.h"

namespace Entropy
{
	namespace Math
	{
		Vector4 __declspec(dllexport) operator* (const Matrix4& left, const Vector4& right);

		//Transformations
		Matrix4 __declspec(dllexport) ScaleMatrix4(const Vector4& scaleVector);
		Matrix4 __declspec(dllexport) ScaleMatrix4(float sX, float sY);
		Matrix4 __declspec(dllexport) ScaleMatrix4(float sX, float sY, float sZ);

		Matrix4 __declspec(dllexport) TranslationMatrix4(const Vector4& translationVevtor);
		Matrix4 __declspec(dllexport) TranslationMatrix4(float dX, float dY);
		Matrix4 __declspec(dllexport) TranslationMatrix4(float dX, float dY, float dZ);

		Matrix4 __declspec(dllexport) RotationAboutXYZMatrix4(const Vector4& rotationVector);
		Matrix4 __declspec(dllexport) RotationAboutXYZMatrix4(float rX, float rY, float rZ);

		Matrix4 __declspec(dllexport) RotationAboutXMatrix4(float rX);
		Matrix4 __declspec(dllexport) RotationAboutYMatrix4(float rY);
		Matrix4 __declspec(dllexport) RotationAboutZMatrix4(float rZ);

		Matrix4 __declspec(dllexport) RotationAboutAxisMatrix4(const Vector4& axis, const float angle);

		//Projections
		Matrix4 __declspec(dllexport) Ortho(float left, float right, float top, float bottom, float zNear, float zFar);
		Matrix4 __declspec(dllexport) Perspective(float fov, float aspectRatio, float zNear, float zFar);
	}
}
