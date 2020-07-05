#include "Vector4.h"

Entropy::Math::Vector4 Entropy::Math::operator+(const Vector4& left, const Vector4& right)
{
	return Vector4(left.i + right.i, left.j + right.j, left.k + right.k, left.l + right.l);
}

Entropy::Math::Vector4 Entropy::Math::operator-(const Vector4& left, const Vector4& right)
{
	return Vector4(left.i - right.i, left.j - right.j, left.k - right.k, left.l - right.l);
}

Entropy::Math::Vector4 Entropy::Math::operator*(float scalar, const Vector4& vector)
{
	return Vector4(scalar * vector.i, scalar * vector.j, scalar * vector.k, scalar * vector.l);
}

Entropy::Math::Vector4 Entropy::Math::operator*(const Vector4& vector, float scalar)
{
	return scalar * vector;
}
