#pragma once

#include "Matrix3.h"
#include "Vector3.h"
#include "Vector2.h"

namespace Entropy
{
	namespace Math
	{
		Vector3 __declspec(dllexport) operator* (const Matrix3& left, const Vector3& right);
		
		Matrix3 __declspec(dllexport) ScaleMatrix3(const Vector3& scaleVector);
		Matrix3 __declspec(dllexport) ScaleMatrix3(float sX, float sY);
		Matrix3 __declspec(dllexport) ScaleMatrix3(float scale);

		Matrix3 __declspec(dllexport) TranslationMatrix3(const Vector3& translationVector);
		Matrix3 __declspec(dllexport) TranslationMatrix3(float dX, float dY);

		Matrix3 __declspec(dllexport) ZRotationMatrix3(float angle);
	}
}
