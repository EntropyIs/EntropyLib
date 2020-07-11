#include "Matrix3.h"

Entropy::Math::Matrix3 Entropy::Math::operator*(const Matrix3& left, const Matrix3& right)
{
	return Matrix3(
		left.r0c0 * right.r0c0 + left.r0c1 * right.r1c0 + left.r0c2 * right.r2c0,
		left.r0c0 * right.r0c1 + left.r0c1 * right.r1c1 + left.r0c2 * right.r2c1,
		left.r0c0 * right.r0c2 + left.r0c1 * right.r1c2 + left.r0c2 * right.r2c2,
		left.r1c0 * right.r0c0 + left.r1c1 * right.r1c0 + left.r1c2 * right.r2c0,
		left.r1c0 * right.r0c1 + left.r1c1 * right.r1c1 + left.r1c2 * right.r2c1,
		left.r1c0 * right.r0c2 + left.r1c1 * right.r1c2 + left.r1c2 * right.r2c2,
		left.r2c0 * right.r0c0 + left.r2c1 * right.r1c0 + left.r2c2 * right.r2c0,
		left.r2c0 * right.r0c1 + left.r2c1 * right.r1c1 + left.r2c2 * right.r2c1,
		left.r2c0 * right.r0c2 + left.r2c1 * right.r1c2 + left.r2c2 * right.r2c2
	);
}

Entropy::Math::Matrix3 Entropy::Math::operator+(const Matrix3& left, const Matrix3& right)
{
	return Matrix3(
		left.r0c0 + right.r0c0, left.r0c1 + right.r0c1, left.r0c2 + right.r0c2,
		left.r1c0 + right.r1c0, left.r1c1 + right.r1c1, left.r1c2 + right.r1c2,
		left.r2c0 + right.r2c0, left.r2c1 + right.r2c1, left.r2c2 + right.r2c2
	);
}

Entropy::Math::Matrix3 Entropy::Math::operator-(const Matrix3& left, const Matrix3& right)
{
	return Matrix3(
		left.r0c0 - right.r0c0, left.r0c1 - right.r0c1, left.r0c2 - right.r0c2,
		left.r1c0 - right.r1c0, left.r1c1 - right.r1c1, left.r1c2 - right.r1c2,
		left.r2c0 - right.r2c0, left.r2c1 - right.r2c1, left.r2c2 - right.r2c2
	);
}
