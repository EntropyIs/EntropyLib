#include "Matrix2.h"

Entropy::Math::Vector2 Entropy::Math::operator*(const Matrix2& left, const Vector2& right)
{
    return Vector2(
        left.r0c0 * right.i + left.r0c1 * right.j,
        left.r1c0 * right.i + left.r1c1 * right.j
    );
}
