#include "Vector3.h"

Entropy::Math::Vector3 Entropy::Math::operator+(const Vector3& left, const Vector3& right)
{
	return Vector3(left.i + right.i, left.j + right.j, left.k + right.k);
}

Entropy::Math::Vector3 Entropy::Math::operator-(const Vector3& left, const Vector3& right)
{
	return Vector3(left.i - right.i, left.j - right.j, left.k - right.k);
}

Entropy::Math::Vector3 Entropy::Math::operator*(float left, const Vector3& right)
{
	return Vector3(left * right.i, left * right.j, left * right.k);
}

Entropy::Math::Vector3 Entropy::Math::operator*(const Vector3& left, float right)
{
	return Vector3(left.i * right, left.j * right, left.k * right);
}
