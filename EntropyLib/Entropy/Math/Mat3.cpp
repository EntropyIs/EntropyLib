#include "Mat3.h"

Entropy::Math::Mat3 Entropy::Math::operator+(const Mat3& left, const Mat3& right)
{
    return Mat3(
        left.R0C0 + right.R0C0, left.R1C0 + right.R1C0, left.R2C0 + right.R2C0,
        left.R0C1 + right.R0C1, left.R1C1 + right.R1C1, left.R2C1 + right.R2C1,
        left.R0C2 + right.R0C2, left.R1C2 + right.R1C2, left.R2C2 + right.R2C2
    );
}

Entropy::Math::Mat3 Entropy::Math::operator-(const Mat3& left, const Mat3& right)
{
    return Mat3(
        left.R0C0 - right.R0C0, left.R1C0 - right.R1C0, left.R2C0 - right.R2C0,
        left.R0C1 - right.R0C1, left.R1C1 - right.R1C1, left.R2C1 - right.R2C1,
        left.R0C2 - right.R0C2, left.R1C2 - right.R1C2, left.R2C2 - right.R2C2
    );
}

Entropy::Math::Mat3 Entropy::Math::operator*(const Mat3& left, const Mat3& right)
{
    return Mat3(
		left.R0C0 * right.R0C0 + left.R0C1 * right.R1C0 + left.R0C2 * right.R2C0,
		left.R1C0 * right.R0C0 + left.R1C1 * right.R1C0 + left.R1C2 * right.R2C0,
		left.R2C0 * right.R0C0 + left.R2C1 * right.R1C0 + left.R2C2 * right.R2C0,
        left.R0C0 * right.R0C1 + left.R0C1 * right.R1C1 + left.R0C2 * right.R2C1,
        left.R1C0 * right.R0C1 + left.R1C1 * right.R1C1 + left.R1C2 * right.R2C1,
        left.R2C0 * right.R0C1 + left.R2C1 * right.R1C1 + left.R2C2 * right.R2C1,
        left.R0C0 * right.R0C2 + left.R0C1 * right.R1C2 + left.R0C2 * right.R2C2,
        left.R1C0 * right.R0C2 + left.R1C1 * right.R1C2 + left.R1C2 * right.R2C2,
        left.R2C0 * right.R0C2 + left.R2C1 * right.R1C2 + left.R2C2 * right.R2C2
    );
}
