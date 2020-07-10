#include "Vector2.h"

Entropy::Math::Vector2& Entropy::Math::Vector2::operator+=(const Vector2& right)
{
	i += right.i;
	j += right.j;
	return *this;
}

Entropy::Math::Vector2& Entropy::Math::Vector2::operator-=(const Vector2& right)
{
	i -= right.i;
	j -= right.j;
	return *this;
}

const bool Entropy::Math::Vector2::operator==(const Vector2& right) const
{
	return i == right.i && j == right.j;
}

const bool Entropy::Math::Vector2::operator!=(const Vector2& right) const
{
	return !(*this == right);
}

Entropy::Math::Vector2 Entropy::Math::operator+(const Vector2& left, const Vector2& right)
{
	return Vector2(left.i + right.i, left.j + right.j);
}

Entropy::Math::Vector2 Entropy::Math::operator-(const Vector2& left, const Vector2& right)
{
	return Vector2(left.i - right.i, left.j - right.j);
}

Entropy::Math::Vector2 Entropy::Math::operator*(float scalar, const Vector2& vector)
{
	return Vector2(scalar * vector.i, scalar * vector.j);
}

Entropy::Math::Vector2 Entropy::Math::operator*(const Vector2& vector, float scalar)
{
	return scalar * vector;
}
