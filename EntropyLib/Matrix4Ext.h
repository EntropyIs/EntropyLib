#pragma once

#include "Entropy/Math/Mat4.h"
#include "Entropy/Math/Vec4.h"
#include "Entropy/Math/Vec3.h"

namespace Entropy
{
	namespace Math
	{
		Vec4 __declspec(dllexport) operator* (const Mat4& left, const Vec4& right);

		//Transformations
		Mat4 __declspec(dllexport) ScaleMat4(const Vec4& scaleVector);
		Mat4 __declspec(dllexport) ScaleMat4(float sX, float sY);
		Mat4 __declspec(dllexport) ScaleMat4(float sX, float sY, float sZ);

		Mat4 __declspec(dllexport) TranslationMatrix4(const Vec4& translationVevtor);
		Mat4 __declspec(dllexport) TranslationMatrix4(float dX, float dY);
		Mat4 __declspec(dllexport) TranslationMatrix4(float dX, float dY, float dZ);

		Mat4 __declspec(dllexport) RotationAboutXYZMatrix4(const Vec4& rotationVector);
		Mat4 __declspec(dllexport) RotationAboutXYZMatrix4(float rX, float rY, float rZ);

		Mat4 __declspec(dllexport) RotationAboutXMatrix4(float rX);
		Mat4 __declspec(dllexport) RotationAboutYMatrix4(float rY);
		Mat4 __declspec(dllexport) RotationAboutZMatrix4(float rZ);

		Mat4 __declspec(dllexport) RotationAboutAxisMatrix4(const Vec4& axis, const float angle);

		//Projections
		Mat4 __declspec(dllexport) Ortho(float left, float right, float top, float bottom, float zNear, float zFar);
		Mat4 __declspec(dllexport) Perspective(float fov, float aspectRatio, float zNear, float zFar);

		Mat4 __declspec(dllexport) LookAt(Vec3 cameraPos, Vec3 cameraTarget, Vec3 cameraUp);
	}
}
