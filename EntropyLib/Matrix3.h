#pragma once
#include "Vector3.h"

namespace Entropy
{
	namespace Math
	{
		struct __declspec(dllexport) Matrix3
		{
			float r0c0; float r0c1; float r0c2;
			float r1c0; float r1c1; float r1c2;
			float r2c0; float r2c1; float r2c2;

			Matrix3(
				float r0c0=1, float r0c1 =0, float r0c2 =0,
				float r1c0=0, float r1c1 =1, float r1c2 =0,
				float r2c0=0, float r2c1 =0, float r2c2 =1) :
				r0c0(r0c0), r0c1(r0c1), r0c2(r0c2),
				r1c0(r1c0), r1c1(r1c1), r1c2(r1c2), 
				r2c0(r2c0), r2c1(r2c1), r2c2(r2c2){}
		};
		Vector3 operator* (const Matrix3& left, const Vector3& right);
	}
}

