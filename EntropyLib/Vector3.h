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

			Vector3(float i = 0.0f, float j = 0.0f, float k = 0.0f) : i(i), j(j), k(k) {}

			Vector3& operator+= (const Vector3& right);
			Vector3& operator-= (const Vector3& right);

			const bool operator==(const Vector3& right) const;
			const bool operator!=(const Vector3& right) const;

			float dot(const Vector3& other);
			Vector3 cross(const Vector3& other);

			Vector3 unit();

			float magnitude();

		};

		Vector3 __declspec(dllexport) operator+ (const Vector3& left, const Vector3& right);
		Vector3 __declspec(dllexport) operator- (const Vector3& left, const Vector3& right);
		Vector3 __declspec(dllexport) operator* (float left, const Vector3& right);
		Vector3 __declspec(dllexport) operator* (const Vector3& left, float right);
	}
	
}