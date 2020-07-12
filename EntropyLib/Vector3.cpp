#include "Vector3.h"

#include <cmath>

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

Entropy::Math::Vector3 Entropy::Math::cross(const Vector3& left, const Vector3& right)
{
	return Vector3(
		left.j * right.k - left.k * right.j,
		left.k * right.i - left.i * right.k,
		left.i * right.j - left.j * right.i);
}

float Entropy::Math::dot(const Vector3& left, const Vector3& right)
{
	return left.i * right.i + left.j * right.j + left.k * right.k;
}

Entropy::Math::Vector3 Entropy::Math::normalize(const Vector3& vector)
{
	float magnitude = vector.magnitude();
	return Vector3(vector.i / magnitude, vector.j / magnitude, vector.k / magnitude);
}

Entropy::Math::Vector3& Entropy::Math::Vector3::operator+=(const Vector3& right)
{
	i += right.i;
	j += right.j;
	k += right.k;
	return *this;
}

Entropy::Math::Vector3& Entropy::Math::Vector3::operator-=(const Vector3& right)
{
	i -= right.i;
	j -= right.j;
	k -= right.k;
	return *this;
}

const bool Entropy::Math::Vector3::operator==(const Vector3& right) const
{
	return i == right.i && j == right.j && k == right.k;
}

const bool Entropy::Math::Vector3::operator!=(const Vector3& right) const
{
	return !(*this == right);
}

float Entropy::Math::Vector3::dot(const Vector3& other)
{
	return i * other.i + j * other.j + k * other.k;
}

Entropy::Math::Vector3 Entropy::Math::Vector3::cross(const Vector3& other)
{
	return Vector3(j * other.k - k * other.j, -1 * (i * other.k - k * other.i), i * other.j - j * other.i);
}

Entropy::Math::Vector3 Entropy::Math::Vector3::unit()
{
	float r = magnitude();
	return Vector3(i / r, j / r, k / r);
}

const float Entropy::Math::Vector3::magnitude() const
{
	return std::sqrt(i * i + j * j + k * k);
}
