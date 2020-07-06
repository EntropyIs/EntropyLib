#pragma once
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
		};

		Vector4 __declspec(dllexport) operator+ (const Vector4& left, const Vector4& right);
		Vector4 __declspec(dllexport) operator- (const Vector4& left, const Vector4& right);
		Vector4 __declspec(dllexport) operator* (float left, const Vector4& right);
		Vector4 __declspec(dllexport) operator* (const Vector4& left, float right);
	}
}
