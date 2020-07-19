#pragma once

#include "Entropy/Math/Mat3.h"
#include "Entropy/Math/Vec3.h"
#include "Entropy/Math/Vec2.h"

namespace Entropy
{
	namespace Math
	{
		Vec3 __declspec(dllexport) operator* (const Mat3& left, const Vec3& right);
		
		Mat3 __declspec(dllexport) ScaleMat3(const Vec3& scaleVector);
		Mat3 __declspec(dllexport) ScaleMat3(float sX, float sY);
		Mat3 __declspec(dllexport) ScaleMat3(float scale);

		Mat3 __declspec(dllexport) TranslationMat3(const Vec3& translationVector);
		Mat3 __declspec(dllexport) TranslationMat3(float dX, float dY);

		Mat3 __declspec(dllexport) ZRotationMat3(float angle);
	}
}
