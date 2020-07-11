#include "Matrix2Ext.h"

#include <cmath>

Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix(const Vector2 & scaleVector)
{
    return Matrix2(
        scaleVector.i, 0.0f,
        0.0f, scaleVector.j
    );
}

Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix(float sX, float sY)
{
    return Matrix2(
        sX, 0.0f,
        0.0f, sY
    );
}

Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix(float scale)
{
    return Matrix2(
        scale, 0.0f,
        0.0f, scale
    );
}

Entropy::Math::Matrix2 Entropy::Math::RotationMatrix(float angle)
{
    return Matrix2(
        cos(angle), -sin(angle),
        sin(angle), cos(angle)
    );
}