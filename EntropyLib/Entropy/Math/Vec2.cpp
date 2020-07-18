#include "Vec2.h"

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
    return Vec2();
}

Entropy::Math::Vec2 Entropy::Math::operator-(const Vec2& left, const Vec2& right)
{
    return Vec2();
}

Entropy::Math::Vec2 Entropy::Math::operator*(const float left, const Vec2& right)
{
    return Vec2();
}

Entropy::Math::Vec2 Entropy::Math::operator*(const Vec2& left, const float right)
{
    return Vec2();
}

float Entropy::Math::dot(const Vec2& left, const Vec2& right)
{
    return 0.0f;
}

Entropy::Math::Vec2 Entropy::Math::normalize(const Vec2& vector)
{
    return Vec2();
}
