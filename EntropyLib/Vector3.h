#pragma once
namespace Entropy
{
	namespace Math
	{
		class __declspec(dllexport) Vector3
		{
		public:
			union {
				struct { float i, j, k; };
				struct { float x, y, z; };
				struct { float r, g, b; };
				float data[3];
			};

			Vector3() : i(0.0f), j(0.0f), k(0.0f) {}
			Vector3(float i , float j, float k = 0.0f) : i(i), j(j), k(k) {}
			Vector3(float value) : i(value), j(value), k(value) {}

			Vector3& operator+= (const Vector3& right);
			Vector3& operator-= (const Vector3& right);

			const bool operator==(const Vector3& right) const;
			const bool operator!=(const Vector3& right) const;

			const float magnitude() const;
		};

		Vector3 __declspec(dllexport) operator+ (const Vector3& left, const Vector3& right);
		Vector3 __declspec(dllexport) operator- (const Vector3& left, const Vector3& right);
		Vector3 __declspec(dllexport) operator* (float left, const Vector3& right);
		Vector3 __declspec(dllexport) operator* (const Vector3& left, float right);

		Vector3 __declspec(dllexport) cross(const Vector3& left, const Vector3& right);
		float __declspec(dllexport) dot(const Vector3& left, const Vector3& right);

		Vector3 __declspec(dllexport) normalize(const Vector3& vector);
	}
	
}