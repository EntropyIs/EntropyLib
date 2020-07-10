#pragma once
#include "Vector2.h"
namespace Entropy
{
	namespace Math
	{
		class __declspec(dllexport) Matrix2
		{
		public:
			union
			{
				struct
				{
					float r0c0; float r1c0;
					float r0c1; float r1c1;
				};
				float data[4];
			};

			Matrix2(
				float r0c0 = 1, float r0c1 = 0,
				float r1c0 = 0, float r1c1 = 1) :
				r0c0(r0c0), r0c1(r0c1),
				r1c0(r1c0), r1c1(r1c1) {}
		};

		Vector2 __declspec(dllexport) operator* (const Matrix2& left, const Vector2& right);

		Matrix2 __declspec(dllexport) operator* (const Matrix2& left, const Matrix2& right);
		Matrix2 __declspec(dllexport) operator+ (const Matrix2& left, const Matrix2& right);
		Matrix2 __declspec(dllexport) operator- (const Matrix2& left, const Matrix2& right);

		Matrix2 __declspec(dllexport) ScaleMatrix(const Vector2& scaleVector);
		Matrix2 __declspec(dllexport) ScaleMatrix(float sX, float sY);
		Matrix2 __declspec(dllexport) TranslationMatrix(const Vector2& translationVevtor);
		Matrix2 __declspec(dllexport) TranslationMatrix(float dX, float dY);
		Matrix2 __declspec(dllexport) RotationMatrix(float angle);
	}
}


