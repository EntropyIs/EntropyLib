#include "Vec3.h"

Entropy::Math::Vec3& Entropy::Math::Vec3::operator+=(const Vec3& right)
{
    I += right.I;
    J += right.J;
    K += right.K;
    return *this;
}

Entropy::Math::Vec3& Entropy::Math::Vec3::operator-=(const Vec3& right)
{
    I -= right.I;
    J -= right.J;
    K -= right.K;
    return *this;
}

Entropy::Math::Vec3 Entropy::Math::operator+(const Vec3& left, const Vec3& right)
{
    return Vec3(left.I + right.I, left.J + right.J, left.K + right.K);
}

Entropy::Math::Vec3 Entropy::Math::operator-(const Vec3& left, const Vec3& right)
{
    return Vec3(left.I - right.I, left.J - right.J, left.K - right.K);
}

Entropy::Math::Vec3 Entropy::Math::operator*(const float left, const Vec3& right)
{
    return Vec3();
}

Entropy::Math::Vec3 Entropy::Math::operator*(const Vec3& left, const float right)
{
    return Vec3();
}

float Entropy::Math::dot(const Vec3& left, const Vec3& right)
{
    return 0.0f;
}

Entropy::Math::Vec3 Entropy::Math::cross(const Vec3& left, const Vec3& right)
{
    return Vec3();
}

Entropy::Math::Vec3 Entropy::Math::normalize(const Vec3& vector)
{
    return Vec3();
}
