#include "Mat2.h"

Entropy::Math::Mat2 Entropy::Math::operator+(const Mat2& left, const Mat2& right)
{
    return Mat2(
        left.R0C0 + right.R0C0, left.R1C0 + right.R1C0,
        left.R0C1 + right.R0C1, left.R1C1 + right.R1C1
    );
}

Entropy::Math::Mat2 Entropy::Math::operator-(const Mat2& left, const Mat2& right)
{
    return Mat2(
        left.R0C0 - right.R0C0, left.R1C0 - right.R1C0,
        left.R0C1 - right.R0C1, left.R1C1 - right.R1C1
    );
}

Entropy::Math::Mat2 Entropy::Math::operator*(const Mat2& left, const Mat2& right)
{
    return Mat2(
        left.R0C0 * right.R0C0 + left.R0C1 * right.R1C0, left.R1C0 * right.R0C0 + left.R1C1 * right.R1C0,
        left.R0C0 * right.R0C1 + left.R0C1 * right.R1C1, left.R1C0 * right.R0C1 + left.R1C1 * right.R1C1
    );
}
