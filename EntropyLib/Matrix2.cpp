#include "Matrix2.h"

#include <cmath>

Entropy::Math::Vector2 Entropy::Math::operator*(const Matrix2& left, const Vector2& right)
{
    return Vector2(
        left.r0c0 * right.i + left.r0c1 * right.j,
        left.r1c0 * right.i + left.r1c1 * right.j
    );
}

Entropy::Math::Matrix2 Entropy::Math::operator*(const Matrix2& left, const Matrix2& right)
{
    return Matrix2(
        left.r0c0 * right.r0c0 + left.r0c1 * right.r1c0,
        left.r0c0 * right.r0c1 + left.r0c1 * right.r1c1,
        left.r1c0 * right.r0c0 + left.r1c1 * right.r1c0,
        left.r1c0 * right.r0c1 + left.r1c1 * right.r1c1
    );
}

Entropy::Math::Matrix2 Entropy::Math::operator+(const Matrix2& left, const Matrix2& right)
{
    return Matrix2(
        left.r0c0 + right.r0c0, left.r0c1 + right.r0c1,
        left.r1c0 + right.r1c0, left.r1c1 + right.r1c1
    );
}

Entropy::Math::Matrix2 Entropy::Math::operator-(const Matrix2& left, const Matrix2& right)
{
    return Matrix2(
        left.r0c0 - right.r0c0, left.r0c1 - right.r0c1,
        left.r1c0 - right.r1c0, left.r1c1 - right.r1c1
    );
}
