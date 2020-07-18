#include "Vec3.h"

#include <cmath>

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
    return Vec3(left * right.I, left * right.J, left * right.K);
}

Entropy::Math::Vec3 Entropy::Math::operator*(const Vec3& left, const float right)
{
    return right * left;
}

float Entropy::Math::dot(const Vec3& left, const Vec3& right)
{
    return left.I * right.I + left.J * right.J + left.K * right.K;
}

Entropy::Math::Vec3 Entropy::Math::cross(const Vec3& left, const Vec3& right)
{
    return Vec3();
}

float Entropy::Math::magnitude(const Vec3& vector)
{
    return std::sqrtf((vector.I * vector.I) + (vector.J * vector.J) + (vector.K * vector.K));
}

Entropy::Math::Vec3 Entropy::Math::normalize(const Vec3& vector)
{
    float mag = magnitude(vector);
    return Vec3(vector.I / mag, vector.J / mag, vector.K / mag);
}
