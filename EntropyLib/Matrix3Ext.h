#pragma once

#include "Matrix3.h"
#include "Entropy/Math/Vec3.h"
#include "Entropy/Math/Vec2.h"

namespace Entropy
{
	namespace Math
	{
		Vec3 __declspec(dllexport) operator* (const Matrix3& left, const Vec3& right);
		
		Matrix3 __declspec(dllexport) ScaleMatrix3(const Vec3& scaleVector);
		Matrix3 __declspec(dllexport) ScaleMatrix3(float sX, float sY);
		Matrix3 __declspec(dllexport) ScaleMatrix3(float scale);

		Matrix3 __declspec(dllexport) TranslationMatrix3(const Vec3& translationVector);
		Matrix3 __declspec(dllexport) TranslationMatrix3(float dX, float dY);

		Matrix3 __declspec(dllexport) ZRotationMatrix3(float angle);
	}
}
