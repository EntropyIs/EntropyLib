#include "Matrix3Ext.h"

#include <cmath>

Entropy::Math::Vec3 Entropy::Math::operator*(const Mat3& left, const Vec3& right)
{
    return Vec3(
        left.R0C0 * right.I + left.R0C1 * right.J + left.R0C2 * right.K,
        left.R1C0 * right.I + left.R1C1 * right.J + left.R1C2 * right.K,
        left.R2C0 * right.I + left.R2C1 * right.J + left.R2C2 * right.K
    );
}

Entropy::Math::Mat3 Entropy::Math::ScaleMat3(const Vec3& scaleVector)
{
    return Mat3(
		scaleVector.I, 0.0f, 0.0f,
		0.0f, scaleVector.K, 0.0f,
		0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Mat3 Entropy::Math::ScaleMat3(float sX, float sY)
{
    return Mat3(
        sX, 0.0f, 0.0f,
        0.0f, sY, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Mat3 Entropy::Math::ScaleMat3(float scale)
{
    return Mat3(
        scale, 0.0f, 0.0f,
        0.0f, scale, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Mat3 Entropy::Math::TranslationMat3(const Vec3& translationVector)
{
    return Mat3(
        1.0f, 0.0f, translationVector.I,
        0.0f, 1.0f, translationVector.J,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Mat3 Entropy::Math::TranslationMat3(float dX, float dY)
{
    return Mat3(
        1.0f, 0.0f, dX,
        0.0f, 1.0f, dY,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Mat3 Entropy::Math::ZRotationMat3(float angle)
{
    return Mat3(
        cos(angle), -sin(angle), 0.0f,
        sin(angle), cos(angle), 0.0f,
        0.0f, 0.0f, 1.0f
    );
}
