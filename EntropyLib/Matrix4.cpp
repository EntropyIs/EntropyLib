#include "Matrix4.h"

Entropy::Math::Vector4 Entropy::Math::operator*(const Matrix4& left, const Vector4& right)
{
    return Vector4(
        left.r0c0 * right.i + left.r0c1 * right.j + left.r0c2 * right.k + left.r0c3 * right.l,
        left.r1c0 * right.i + left.r1c1 * right.j + left.r1c2 * right.k + left.r1c3 * right.l,
        left.r2c0 * right.i + left.r2c1 * right.j + left.r2c2 * right.k + left.r2c3 * right.l,
        left.r3c0 * right.i + left.r3c1 * right.j + left.r3c2 * right.k + left.r3c3 * right.l
    );
}
