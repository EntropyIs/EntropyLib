#include "Vector4.h"

#include<cmath>

Entropy::Math::Vector4& Entropy::Math::Vector4::operator+=(const Vector4& right)
{
	i += right.i;
	j += right.j;
	k += right.k;
	l += right.l;
	return *this;
}

Entropy::Math::Vector4& Entropy::Math::Vector4::operator-=(const Vector4& right)
{
	i -= right.i;
	j -= right.j;
	k -= right.k;
	l -= right.l;
	return *this;
}

const bool Entropy::Math::Vector4::operator==(const Vector4& right) const
{
	return i == right.i && j == right.j && k == right.k && l == right.l;
}

const bool Entropy::Math::Vector4::operator!=(const Vector4& right) const
{
	return !(*this == right);
}

const float Entropy::Math::Vector4::magnitude() const
{
	return sqrt(i*i+j*j+k*k+l*l);
}

Entropy::Math::Vector4 Entropy::Math::Vector4::unit()
{
	float magnitude = this->magnitude();
	return Vector4(i / magnitude, j / magnitude, k / magnitude, l / magnitude);
}

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

Entropy::Math::Vector4 Entropy::Math::normalize(const Vector4& vector)
{
	float magnitude = vector.magnitude();
	return Vector4(vector.i / magnitude, vector.j / magnitude, vector.k / magnitude, vector.l / magnitude);
}
