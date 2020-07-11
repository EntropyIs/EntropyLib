#pragma once

#include "Matrix3.h"
#include "Vector3.h"
#include "Vector2.h"

namespace Entropy
{
	namespace Math
	{
		Matrix3 __declspec(dllexport) ScaleMatrix(const Vector3& scaleVector);
		Matrix3 __declspec(dllexport) ScaleMatrix(float sX, float sY);
		Matrix3 __declspec(dllexport) ScaleMatrix(float scale);

		Matrix3 __declspec(dllexport) TranslationMatrix(const Vector3& translationVector);
		Matrix3 __declspec(dllexport) TranslationMatrix(float dX, float dY);

		Matrix3 __declspec(dllexport) ZRotationMatrix(float angle);
	}
}
