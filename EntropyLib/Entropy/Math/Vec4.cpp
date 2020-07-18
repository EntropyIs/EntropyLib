#include "Vec4.h"

#include <cmath>

Entropy::Math::Vec4& Entropy::Math::Vec4::operator+=(const Vec4& right)
{
    I += right.I;
    J += right.J;
    K += right.K;
    L += right.L;
    return *this;
}

Entropy::Math::Vec4& Entropy::Math::Vec4::operator-=(const Vec4& right)
{
    I -= right.I;
    J -= right.J;
    K -= right.K;
    L -= right.L;
    return *this;
}

Entropy::Math::Vec4 Entropy::Math::operator+(const Vec4& left, const Vec4& right)
{
    return Vec4(left.I + right.I, left.J + right.J, left.K + right.K, left.L + right.L);
}

Entropy::Math::Vec4 Entropy::Math::operator-(const Vec4& left, const Vec4& right)
{
    return Vec4(left.I - right.I, left.J - right.J, left.K - right.K, left.L - right.L);
}

Entropy::Math::Vec4 Entropy::Math::operator*(const float left, const Vec4& right)
{
    return Vec4(left * right.I, left * right.J, left * right.K, left * right.L);
}

Entropy::Math::Vec4 Entropy::Math::operator*(const Vec4& left, const float right)
{
    return right * left;
}

float Entropy::Math::dot(const Vec4& left, const Vec4& right)
{
    return left.I * right.I + left.J * right.J + left.K * right.K + left.L * right.L;
}

float Entropy::Math::magnitude(const Vec4& vector)
{
    return std::sqrtf((vector.I * vector.I) + (vector.J * vector.J) + (vector.K * vector.K) + (vector.L * vector.L));
}

Entropy::Math::Vec4 Entropy::Math::normalize(const Vec4& vector)
{
    return Vec4();
}
