#include "Matrix4.h"

#include <cmath>

Entropy::Math::Matrix4 Entropy::Math::operator*(const Matrix4& left, const Matrix4& right)
{
	return Matrix4(
		left.r0c0 * right.r0c0 + left.r0c1 * right.r1c0 + left.r0c2 * right.r2c0 + left.r0c3 * right.r3c0,
		left.r0c0 * right.r0c1 + left.r0c1 * right.r1c1 + left.r0c2 * right.r2c1 + left.r0c3 * right.r3c1,
		left.r0c0 * right.r0c2 + left.r0c1 * right.r1c2 + left.r0c2 * right.r2c2 + left.r0c3 * right.r3c2,
		left.r0c0 * right.r0c3 + left.r0c1 * right.r1c3 + left.r0c2 * right.r2c3 + left.r0c3 * right.r3c3,
		left.r1c0 * right.r0c0 + left.r1c1 * right.r1c0 + left.r1c2 * right.r2c0 + left.r1c3 * right.r3c0,
		left.r1c0 * right.r0c1 + left.r1c1 * right.r1c1 + left.r1c2 * right.r2c1 + left.r1c3 * right.r3c1,
		left.r1c0 * right.r0c2 + left.r1c1 * right.r1c2 + left.r1c2 * right.r2c2 + left.r1c3 * right.r3c2,
		left.r1c0 * right.r0c3 + left.r1c1 * right.r1c3 + left.r1c2 * right.r2c3 + left.r1c3 * right.r3c3,
		left.r2c0 * right.r0c0 + left.r2c1 * right.r1c0 + left.r2c2 * right.r2c0 + left.r2c3 * right.r3c0,
		left.r2c0 * right.r0c1 + left.r2c1 * right.r1c1 + left.r2c2 * right.r2c1 + left.r2c3 * right.r3c1,
		left.r2c0 * right.r0c2 + left.r2c1 * right.r1c2 + left.r2c2 * right.r2c2 + left.r2c3 * right.r3c2,
		left.r2c0 * right.r0c3 + left.r2c1 * right.r1c3 + left.r2c2 * right.r2c3 + left.r2c3 * right.r3c3,
		left.r3c0 * right.r0c0 + left.r3c1 * right.r1c0 + left.r3c2 * right.r2c0 + left.r3c3 * right.r3c0,
		left.r3c0 * right.r0c1 + left.r3c1 * right.r1c1 + left.r3c2 * right.r2c1 + left.r3c3 * right.r3c1,
		left.r3c0 * right.r0c2 + left.r3c1 * right.r1c2 + left.r3c2 * right.r2c2 + left.r3c3 * right.r3c2,
		left.r3c0 * right.r0c3 + left.r3c1 * right.r1c3 + left.r3c2 * right.r2c3 + left.r3c3 * right.r3c3
	);
}

Entropy::Math::Matrix4 Entropy::Math::operator+(const Matrix4& left, const Matrix4& right)
{
	return Matrix4(
		left.r0c0 + right.r0c0, left.r0c1 + right.r0c1, left.r0c2 + right.r0c2, left.r0c3 + right.r0c3,
		left.r1c0 + right.r1c0, left.r1c1 + right.r1c1, left.r1c2 + right.r1c2, left.r1c3 + right.r1c3,
		left.r2c0 + right.r2c0, left.r2c1 + right.r2c1, left.r2c2 + right.r2c2, left.r2c3 + right.r2c3,
		left.r3c0 + right.r3c0, left.r3c1 + right.r3c1, left.r3c2 + right.r3c2, left.r3c3 + right.r3c3
	);
}

Entropy::Math::Matrix4 Entropy::Math::operator-(const Matrix4& left, const Matrix4& right)
{
	return Matrix4(
		left.r0c0 - right.r0c0, left.r0c1 - right.r0c1, left.r0c2 - right.r0c2, left.r0c3 - right.r0c3,
		left.r1c0 - right.r1c0, left.r1c1 - right.r1c1, left.r1c2 - right.r1c2, left.r1c3 - right.r1c3,
		left.r2c0 - right.r2c0, left.r2c1 - right.r2c1, left.r2c2 - right.r2c2, left.r2c3 - right.r2c3,
		left.r3c0 - right.r3c0, left.r3c1 - right.r3c1, left.r3c2 - right.r3c2, left.r3c3 - right.r3c3
	);
}
