#pragma once
namespace Entropy
{
	namespace Math
	{
		struct __declspec(dllexport) Vector2
		{
			float i;
			float j;
			Vector2(float i = 0.0f, float j = 0.0f) : i(i), j(j) {}
		};

		Vector2 __declspec(dllexport) operator+ (const Vector2& left, const Vector2& right);
		Vector2 __declspec(dllexport) operator- (const Vector2& left, const Vector2& right);
		Vector2 __declspec(dllexport) operator* (float left, const Vector2& right);
		Vector2 __declspec(dllexport) operator* (const Vector2& left, float right);
	}
}
	

