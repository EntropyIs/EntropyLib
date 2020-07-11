#include "Matrix3Ext.h"

#include <cmath>

Entropy::Math::Vector3 Entropy::Math::operator*(const Matrix3& left, const Vector3& right)
{
    return Vector3(
        left.r0c0 * right.i + left.r0c1 * right.j + left.r0c2 * right.k,
        left.r1c0 * right.i + left.r1c1 * right.j + left.r1c2 * right.k,
        left.r2c0 * right.i + left.r2c1 * right.j + left.r2c2 * right.k
    );
}

Entropy::Math::Matrix3 Entropy::Math::ScaleMatrix3(const Vector3& scaleVector)
{
    return Matrix3(
		scaleVector.i, 0.0f, 0.0f,
		0.0f, scaleVector.j, 0.0f,
		0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::ScaleMatrix3(float sX, float sY)
{
    return Matrix3(
        sX, 0.0f, 0.0f,
        0.0f, sY, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::ScaleMatrix3(float scale)
{
    return Matrix3(
        scale, 0.0f, 0.0f,
        0.0f, scale, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::TranslationMatrix3(const Vector3& translationVector)
{
    return Matrix3(
        1.0f, 0.0f, translationVector.i,
        0.0f, 1.0f, translationVector.j,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::TranslationMatrix3(float dX, float dY)
{
    return Matrix3(
        1.0f, 0.0f, dX,
        0.0f, 1.0f, dY,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::ZRotationMatrix3(float angle)
{
    return Matrix3(
        cos(angle), -sin(angle), 0.0f,
        sin(angle), cos(angle), 0.0f,
        0.0f, 0.0f, 1.0f
    );
}
