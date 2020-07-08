#pragma once
#include "Vector4.h"
namespace Entropy
{
	namespace Math
	{
		struct __declspec(dllexport) Matrix4
		{
			float r0c0; float r0c1; float r0c2; float r0c3;
			float r1c0; float r1c1; float r1c2; float r1c3;
			float r2c0; float r2c1; float r2c2; float r2c3;
			float r3c0; float r3c1; float r3c2; float r3c3;

			Matrix4(
				float r0c0 = 1, float r0c1 = 0, float r0c2 = 0, float r0c3 = 0,
				float r1c0 = 0, float r1c1 = 1, float r1c2 = 0, float r1c3 = 0,
				float r2c0 = 0, float r2c1 = 0, float r2c2 = 1, float r2c3 = 0,
				float r3c0 = 0, float r3c1 = 0, float r3c2 = 0, float r3c3 = 1) :
				r0c0(r0c0), r0c1(r0c1), r0c2(r0c2), r0c3(r0c3),
				r1c0(r1c0), r1c1(r1c1), r1c2(r1c2), r1c3(r1c3),
				r2c0(r2c0), r2c1(r2c1), r2c2(r2c2), r2c3(r2c3), 
				r3c0(r3c0), r3c1(r3c1), r3c2(r3c2), r3c3(r3c3) {}
		};

		Vector4 __declspec(dllexport) operator* (const Matrix4& left, const Vector4& right);
		
		Matrix4 __declspec(dllexport) operator* (const Matrix4& left, const Matrix4& right);
		Matrix4 __declspec(dllexport) operator+ (const Matrix4& left, const Matrix4& right);
		Matrix4 __declspec(dllexport) operator- (const Matrix4& left, const Matrix4& right);


		Matrix4 __declspec(dllexport) ScaleMatrix(const Vector4& scaleVector);
		Matrix4 __declspec(dllexport) ScaleMatrix(float sX, float sY, float sZ);
		Matrix4 __declspec(dllexport) TranslationMatrix(const Vector4& translationVevtor);
		Matrix4 __declspec(dllexport) TranslationMatrix(float dX, float dY, float dZ);
		Matrix4 __declspec(dllexport) RotationAboutXYZMatrix(const Vector4& rotationVector);
		Matrix4 __declspec(dllexport) RotationAboutXYZMatrix(float rX, float rY, float rZ);
		Matrix4 __declspec(dllexport) RotationAboutXMatrix(float rX);
		Matrix4 __declspec(dllexport) RotationAboutYMatrix(float rY);
		Matrix4 __declspec(dllexport) RotationAboutZMatrix(float rZ);
		Matrix4 __declspec(dllexport) RotationAboutAxisMatrix(const Vector4& axis, float angle);
	}
}


