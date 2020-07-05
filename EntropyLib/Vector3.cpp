#include "Vector3.h"

Entropy::Math::Vector3 Entropy::Math::operator+(const Vector3& left, const Vector3& right)
{
	return Vector3(left.i + right.i, left.j + right.j, left.k + right.k);
}

Entropy::Math::Vector3 Entropy::Math::operator-(const Vector3& left, const Vector3& right)
{
	return Vector3(left.i - right.i, left.j - right.j, left.k - right.k);
}

Entropy::Math::Vector3 Entropy::Math::operator*(float scalar, const Vector3& vector)
{
	return Vector3(scalar * vector.i, scalar * vector.j, scalar * vector.k);
}

Entropy::Math::Vector3 Entropy::Math::operator*(const Vector3& vector, float scalar)
{
	return scalar * vector;
}
