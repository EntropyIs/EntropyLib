#include "Transform2D.h"

#include <cmath>

Entropy::Math::Vec3 Entropy::Math::operator*(const Mat3& left, const Vec3& right)
{
    return Vec3(
        left.R0C0 * right.I + left.R0C1 * right.J + left.R0C2 * right.K,
        left.R1C0 * right.I + left.R1C1 * right.J + left.R1C2 * right.K,
        left.R2C0 * right.I + left.R2C1 * right.J + left.R2C2 * right.K
    );
}

Entropy::Math::Mat3 Entropy::Math::Scale(float scale)
{
    return Scale(scale, scale);
}

Entropy::Math::Mat3 Entropy::Math::Scale(const Vec3& scale)
{
    return Scale(scale.I, scale.J);
}

Entropy::Math::Mat3 Entropy::Math::Scale(const Vec2& scale)
{
    return Scale(scale.I, scale.J);
}

Entropy::Math::Mat3 Entropy::Math::Scale(float sX, float sY)
{
    return Mat3(
          sX, 0.0f, 0.0f,
        0.0f,   sY, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Entropy::Math::Mat3 Entropy::Math::Translate(const Vec3& translation)
{
    return Translate(translation.I, translation.Y);
}

Entropy::Math::Mat3 Entropy::Math::Translate(const Vec2& translation)
{
    return Translate(translation.I, translation.Y);
}

Entropy::Math::Mat3 Entropy::Math::Translate(float dX, float dY)
{
    return Mat3(
    1.0f, 0.0f, 0.0f, 
    0.0f, 1.0f, 0.0f, 
      dX,   dY, 1.0f
    );
}

Entropy::Math::Mat3 Entropy::Math::Roatate(float angle)
{
    return Mat3(
         cosf(angle), sinf(angle), 0.0f,
        -sinf(angle), cosf(angle), 0.0f,
                0.0f,        0.0f, 1.0f
    );
}
