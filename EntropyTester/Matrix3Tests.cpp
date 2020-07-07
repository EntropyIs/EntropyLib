#include <gtest/gtest.h>
#include <Matrix3.h>

using namespace Entropy::Math;

TEST(Matrix3, Constructor)
{
	Matrix3 empty;
	Matrix3 a(1, 2, 3, 4, 5, 6, 7, 8, 9);

	EXPECT_FLOAT_EQ(empty.r0c0, 1); EXPECT_FLOAT_EQ(empty.r0c1, 0); EXPECT_FLOAT_EQ(empty.r0c2, 0);
	EXPECT_FLOAT_EQ(empty.r1c0, 0); EXPECT_FLOAT_EQ(empty.r1c1, 1); EXPECT_FLOAT_EQ(empty.r1c2, 0);
	EXPECT_FLOAT_EQ(empty.r2c0, 0); EXPECT_FLOAT_EQ(empty.r2c1, 0); EXPECT_FLOAT_EQ(empty.r2c2, 1);

	EXPECT_FLOAT_EQ(a.r0c0, 1); EXPECT_FLOAT_EQ(a.r0c1, 2); EXPECT_FLOAT_EQ(a.r0c2, 3);
	EXPECT_FLOAT_EQ(a.r1c0, 4); EXPECT_FLOAT_EQ(a.r1c1, 5); EXPECT_FLOAT_EQ(a.r1c2, 6);
	EXPECT_FLOAT_EQ(a.r2c0, 7); EXPECT_FLOAT_EQ(a.r2c1, 8); EXPECT_FLOAT_EQ(a.r2c2, 9);
}

TEST(Matrix3, MatrixVectorMultiply)
{
	Matrix3 matrix(
		 2, -3,  4,
		 5,  7, -2,
		-9,  1,  0
	);
	Vector3 vector(3, 9, 5);

	Vector3 result = matrix * vector;

	ASSERT_FLOAT_EQ(result.i, -1);
	ASSERT_FLOAT_EQ(result.j, 68);
	ASSERT_FLOAT_EQ(result.k, -18);
}