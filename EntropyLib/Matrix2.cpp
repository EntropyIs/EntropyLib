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

/**
 * Scale Matrix
 * @param   
 */
Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix(const Vector2& scaleVector)
{
    return Matrix2(
        scaleVector.i, 0.0f,
        0.0f, scaleVector.j
    );
}

/**
 * Scale Matrix
 * @param   sX, scale x component.
 * @param   sY, scale y component.
 */
Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix(float sX, float sY)
{
    return Matrix2(
        sX, 0.0f,
        0.0f, sY
    );
}

/**
 * Uniform Scale Matrix
 * @param   scale, scale to apply.
 */
Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix(float scale)
{
    return Matrix2(
        scale, 0.0f,
        0.0f, scale
    );
}

/**
 * 2D Roation Matrix;
 * @param   angle, angle of rotation in radians.
 */
Entropy::Math::Matrix2 Entropy::Math::RotationMatrix(float angle)
{
    return Matrix2(
        cos(angle), -sin(angle),
        sin(angle), cos(angle)
    );
}
