#pragma once
#include "Vector2.h"

namespace Entropy
{
	namespace Math
	{
		struct __declspec(dllexport) Matrix2
		{
			float r0c0; float r0c1;
			float r1c0; float r1c1;

			Matrix2(
				float r0c0 = 1, float r0c1 = 0,
				float r1c0 = 0, float r1c1 = 1) :
				r0c0(r0c0), r0c1(r0c1),
				r1c0(r1c0), r1c1(r1c1) {}
		};

		Vector2 operator* (const Matrix2& left, const Vector2& right);
	}
}


