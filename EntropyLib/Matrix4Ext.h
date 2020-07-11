#pragma once

#include "Matrix4.h"
#include "Vector4.h"

namespace Entropy
{
	namespace Math
	{
		Vector4 __declspec(dllexport) operator* (const Matrix4& left, const Vector4& right);

		Matrix4 __declspec(dllexport) ScaleMatrix(const Vector4& scaleVector);
		Matrix4 __declspec(dllexport) ScaleMatrix(float sX, float sY);
		Matrix4 __declspec(dllexport) ScaleMatrix(float sX, float sY, float sZ);

		Matrix4 __declspec(dllexport) TranslationMatrix(const Vector4& translationVevtor);
		Matrix4 __declspec(dllexport) TranslationMatrix(float dX, float dY);
		Matrix4 __declspec(dllexport) TranslationMatrix(float dX, float dY, float dZ);

		Matrix4 __declspec(dllexport) RotationAboutXYZMatrix(const Vector4& rotationVector);
		Matrix4 __declspec(dllexport) RotationAboutXYZMatrix(float rX, float rY, float rZ);

		Matrix4 __declspec(dllexport) RotationAboutXMatrix(float rX);
		Matrix4 __declspec(dllexport) RotationAboutYMatrix(float rY);
		Matrix4 __declspec(dllexport) RotationAboutZMatrix(float rZ);

		Matrix4 __declspec(dllexport) RotationAboutAxisMatrix(const Vector4& axis, float angle);
	}
}
