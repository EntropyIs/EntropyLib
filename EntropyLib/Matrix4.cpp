#include "Matrix4.h"

#include <cmath>

Entropy::Math::Vector4 Entropy::Math::operator*(const Matrix4& left, const Vector4& right)
{
    return Vector4(
        left.r0c0 * right.i + left.r0c1 * right.j + left.r0c2 * right.k + left.r0c3 * right.l,
        left.r1c0 * right.i + left.r1c1 * right.j + left.r1c2 * right.k + left.r1c3 * right.l,
        left.r2c0 * right.i + left.r2c1 * right.j + left.r2c2 * right.k + left.r2c3 * right.l,
        left.r3c0 * right.i + left.r3c1 * right.j + left.r3c2 * right.k + left.r3c3 * right.l
    );
}

Entropy::Math::Matrix4 Entropy::Math::TransformationMatrix(const Vector4& movementVector, const Vector4& rotationVector)
{
    return TransformationMatrix(movementVector.i, movementVector.j, movementVector.k, rotationVector.i, rotationVector.j, rotationVector.k);
}

Entropy::Math::Matrix4 Entropy::Math::TransformationMatrix(float dX, float dY, float dZ, float rX, float rY, float rZ)
{
    return Matrix4(
        cos(rY) * cos(rZ), -cos(rX) * sin(rZ) + sin(rX) * sin(rY) * cos(rZ), sin(rX) * sin(rY) + cos(rX) * sin(rY) * cos(rZ), dX,
        cos(rY) * sin(rZ), cos(rY) * cos(rZ) + sin(rX) * sin(rY) * sin(rZ), -sin(rX) * cos(rY) + cos(rX) * sin(rY) * sin(rZ), dY,
        -sin(rY), -sin(rX) * cos(rY), cos(rX) * cos(rY), dZ,
        0.0f, 0.0f, 0.0f, 1.0f
    );
}
