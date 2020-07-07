#pragma once
#include "Vector2.h"
#include "Vector3.h"

namespace Entropy
{
	namespace Math
	{
		struct __declspec(dllexport) Vector4
		{
			float i;
			float j;
			float k;
			float l;

			Vector4(float i = 0.0f, float j = 0.0f, float k = 0.0f, float l = 0.0f) : i(i), j(j), k(k), l(l) {}

			Vector4& operator= (const Vector4& right);
			Vector4& operator+= (const Vector4& right);
			Vector4& operator-= (const Vector4& right);

			const bool operator==(const Vector4& right) const;
			const bool operator!=(const Vector4& right) const;

			operator Vector2() const;
			operator Vector3() const;
		};

		Vector4 __declspec(dllexport) operator+ (const Vector4& left, const Vector4& right);
		Vector4 __declspec(dllexport) operator- (const Vector4& left, const Vector4& right);
		Vector4 __declspec(dllexport) operator* (float left, const Vector4& right);
		Vector4 __declspec(dllexport) operator* (const Vector4& left, float right);
	}
}
