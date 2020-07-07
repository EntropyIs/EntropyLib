#include <gtest/gtest.h>
#include <Matrix2.h>
#include <Vector2.h>

using namespace Entropy::Math;

TEST(Matrix2, Constructor)
{
	Matrix2 empty;
	Matrix2 a(1, 2, 3, 4);

	EXPECT_FLOAT_EQ(empty.r0c0, 1); EXPECT_FLOAT_EQ(empty.r0c1, 0);
	EXPECT_FLOAT_EQ(empty.r1c0, 0); EXPECT_FLOAT_EQ(empty.r1c1, 1);

	EXPECT_FLOAT_EQ(a.r0c0, 1); EXPECT_FLOAT_EQ(a.r0c1, 2);
	EXPECT_FLOAT_EQ(a.r1c0, 3); EXPECT_FLOAT_EQ(a.r1c1, 4);
}

TEST(Matrix2, MatrixVectorMultiply)
{
	Matrix2 matrix( 2, -3, 4, 5);
	Vector2 vector(3, 9);

	Vector2 result = matrix * vector;

	ASSERT_FLOAT_EQ(result.i, -21);
	ASSERT_FLOAT_EQ(result.j, 57);
}