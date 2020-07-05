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
		};

		Vector3 operator+ (const Vector3& left, const Vector3& right)
		{
			return Vector3();
		}
	}
	
}