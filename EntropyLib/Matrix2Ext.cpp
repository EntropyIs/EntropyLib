#include "Matrix2Ext.h"

#include <cmath>

Entropy::Math::Vec2 Entropy::Math::operator*(const Mat2& left, const Vec2& right)
{
    return Vec2(
        left.R0C0 * right.I + left.R0C1 * right.J,
        left.R1C0 * right.I + left.R1C1 * right.J
    );
}

Entropy::Math::Mat2 Entropy::Math::ScaleMatrix2(const Vec2 & scaleVector)
{
    return Mat2(
        scaleVector.I, 0.0f,
        0.0f, scaleVector.J
    );
}

Entropy::Math::Mat2 Entropy::Math::ScaleMatrix2(float sX, float sY)
{
    return Mat2(
        sX, 0.0f,
        0.0f, sY
    );
}

Entropy::Math::Mat2 Entropy::Math::ScaleMatrix2(float scale)
{
    return Mat2(
        scale, 0.0f,
        0.0f, scale
    );
}

Entropy::Math::Mat2 Entropy::Math::RotationMatrix2(float angle)
{
    return Mat2(
        cos(angle), -sin(angle),
        sin(angle), cos(angle)
    );
}