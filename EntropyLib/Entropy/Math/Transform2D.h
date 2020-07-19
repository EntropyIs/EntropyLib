#pragma once

#include "Vec3.h"
#include "Mat3.h"

namespace Entropy
{
	namespace Math
	{
		Vec3 __declspec(dllexport) operator* (const Mat3& left, const Vec3& right);
	}
}
