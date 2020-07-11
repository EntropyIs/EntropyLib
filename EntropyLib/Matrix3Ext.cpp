#include "Matrix3Ext.h"

#include <cmath>

Entropy::Math::Matrix3 Entropy::Math::ScaleMatrix(const Vector3& scaleVector)
{
    return Matrix3(
		scaleVector.i, 0.0f, 0.0f,
		0.0f, scaleVector.j, 0.0f,
		0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::ScaleMatrix(float sX, float sY)
{
    return Matrix3(
        sX, 0.0f, 0.0f,
        0.0f, sY, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::ScaleMatrix(float scale)
{
    return Matrix3(
        scale, 0.0f, 0.0f,
        0.0f, scale, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::TranslationMatrix(const Vector3& translationVector)
{
    return Matrix3(
        1.0f, 0.0f, translationVector.i,
        0.0f, 1.0f, translationVector.j,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::TranslationMatrix(float dX, float dY)
{
    return Matrix3(
        1.0f, 0.0f, dX,
        0.0f, 1.0f, dY,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Matrix3 Entropy::Math::ZRotationMatrix(float angle)
{
    return Matrix3(
        cos(angle), -sin(angle), 0.0f,
        sin(angle), cos(angle), 0.0f,
        0.0f, 0.0f, 1.0f
    );
}
