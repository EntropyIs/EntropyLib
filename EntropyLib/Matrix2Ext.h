#pragma once

#include "Matrix2.h"
#include "Vector2.h"

namespace Entropy
{
	namespace Math
	{
		Vector2 __declspec(dllexport) operator* (const Matrix2& left, const Vector2& right);

		Matrix2 __declspec(dllexport) ScaleMatrix(const Vector2 & scaleVector);
		Matrix2 __declspec(dllexport) ScaleMatrix(float sX, float sY);
		Matrix2 __declspec(dllexport) ScaleMatrix(float scale);

		Matrix2 __declspec(dllexport) RotationMatrix(float angle);
	}
}