#pragma once
namespace Entropy
{
	namespace Math
	{
		struct __declspec(dllexport) Vector3
		{
			float i;
			float j;
			float k;
			Vector3(float i = 0.0f, float j = 0.0f, float k = 0.0f) : i(i), j(j), k(k) {}
		};

		Vector3 __declspec(dllexport) operator+ (const Vector3& left, const Vector3& right);
		Vector3 __declspec(dllexport) operator* (float left, const Vector3& right);
		Vector3 __declspec(dllexport) operator* (const Vector3& left, float right);
	}
	
}