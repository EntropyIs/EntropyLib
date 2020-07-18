#include "Vec2.h"

#include <cmath>

Entropy::Math::Vec2& Entropy::Math::Vec2::operator+=(const Vec2& right)
{
    I += right.I;
    J += right.J;
    return *this;
}

Entropy::Math::Vec2& Entropy::Math::Vec2::operator-=(const Vec2& right)
{
    I -= right.I;
    J -= right.J;
    return *this;
}

Entropy::Math::Vec2 Entropy::Math::operator+(const Vec2& left, const Vec2& right)
{
    return Vec2(left.I + right.I, left.J + right.J);
}

Entropy::Math::Vec2 Entropy::Math::operator-(const Vec2& left, const Vec2& right)
{
    return Vec2(left.I - right.I, left.J - right.J);
}

Entropy::Math::Vec2 Entropy::Math::operator*(const float left, const Vec2& right)
{
    return Vec2(left * right.I, left * right.J);
}

Entropy::Math::Vec2 Entropy::Math::operator*(const Vec2& left, const float right)
{
    return right * left;
}

float Entropy::Math::dot(const Vec2& left, const Vec2& right)
{
	return left.I * right.I + left.J * right.J;
}

float Entropy::Math::magnitude(const Vec2& vector)
{
    return std::sqrtf((vector.I * vector.I) + (vector.J * vector.J));
}

Entropy::Math::Vec2 Entropy::Math::normalize(const Vec2& vector)
{
    return Vec2();
}
