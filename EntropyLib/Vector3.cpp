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

float Entropy::Math::Vector3::magnitude()
{
	return std::sqrt(i * i + j * j + k * k);
}
