#pragma once
namespace Entropy
{
	namespace Math
	{
		class __declspec(dllexport) Vector2
		{
		public:
			union {
				struct { float i, j; };
				struct { float x, y; };
				float data[2];
			};

			Vector2(float i = 0.0f, float j = 0.0f) : i(i), j(j) {}

			Vector2& operator+= (const Vector2& right);
			Vector2& operator-= (const Vector2& right);

			const bool operator==(const Vector2& right) const;
			const bool operator!=(const Vector2& right) const;
		};

		Vector2 __declspec(dllexport) operator+ (const Vector2& left, const Vector2& right);
		Vector2 __declspec(dllexport) operator- (const Vector2& left, const Vector2& right);
		Vector2 __declspec(dllexport) operator* (float left, const Vector2& right);
		Vector2 __declspec(dllexport) operator* (const Vector2& left, float right);
	}
}
	

