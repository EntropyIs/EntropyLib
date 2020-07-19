#pragma once

#include "Entropy/Math/Mat2.h"
#include "Entropy/Math/Vec2.h"

namespace Entropy
{
	namespace Math
	{
		Vec2 __declspec(dllexport) operator* (const Mat2& left, const Vec2& right);

		Mat2 __declspec(dllexport) ScaleMatrix2(const Vec2 & scaleVector);
		Mat2 __declspec(dllexport) ScaleMatrix2(float sX, float sY);
		Mat2 __declspec(dllexport) ScaleMatrix2(float scale);

		Mat2 __declspec(dllexport) RotationMatrix2(float angle);
	}
}