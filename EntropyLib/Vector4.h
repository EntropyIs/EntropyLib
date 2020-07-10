#pragma once
namespace Entropy
{
	namespace Math
	{
		class __declspec(dllexport) Vector4
		{
		public:
			union {
				struct { float i, j, k, l; };
				struct { float x, y, z, w; };
				struct { float r, g, b, a; };
				float data[4];
			};

			Vector4(float i = 0.0f, float j = 0.0f, float k = 0.0f, float l = 0.0f) : i(i), j(j), k(k), l(l) {}

			Vector4& operator+= (const Vector4& right);
			Vector4& operator-= (const Vector4& right);

			const bool operator==(const Vector4& right) const;
			const bool operator!=(const Vector4& right) const;
		};

		Vector4 __declspec(dllexport) operator+ (const Vector4& left, const Vector4& right);
		Vector4 __declspec(dllexport) operator- (const Vector4& left, const Vector4& right);
		Vector4 __declspec(dllexport) operator* (float left, const Vector4& right);
		Vector4 __declspec(dllexport) operator* (const Vector4& left, float right);
	}
}
