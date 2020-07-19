#include "Mat4.h"

Entropy::Math::Mat4 Entropy::Math::operator+(const Mat4& left, const Mat4& right)
{
    return Mat4(
        left.R0C0 + right.R0C0, left.R1C0 + right.R1C0, left.R2C0 + right.R2C0, left.R3C0 + right.R3C0,
        left.R0C1 + right.R0C1, left.R1C1 + right.R1C1, left.R2C1 + right.R2C1, left.R3C1 + right.R3C1,
        left.R0C2 + right.R0C2, left.R1C2 + right.R1C2, left.R2C2 + right.R2C2, left.R3C2 + right.R3C2,
        left.R0C3 + right.R0C3, left.R1C3 + right.R1C3, left.R2C3 + right.R2C3, left.R3C3 + right.R3C3
    );
}

Entropy::Math::Mat4 Entropy::Math::operator-(const Mat4& left, const Mat4& right)
{
    return Mat4(
        left.R0C0 - right.R0C0, left.R1C0 - right.R1C0, left.R2C0 - right.R2C0, left.R3C0 - right.R3C0,
        left.R0C1 - right.R0C1, left.R1C1 - right.R1C1, left.R2C1 - right.R2C1, left.R3C1 - right.R3C1,
        left.R0C2 - right.R0C2, left.R1C2 - right.R1C2, left.R2C2 - right.R2C2, left.R3C2 - right.R3C2,
        left.R0C3 - right.R0C3, left.R1C3 - right.R1C3, left.R2C3 - right.R2C3, left.R3C3 - right.R3C3
    );
}

Entropy::Math::Mat4 Entropy::Math::operator*(const Mat4& left, const Mat4& right)
{
    return Mat4(
    );
}
