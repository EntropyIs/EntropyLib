#include <gtest/gtest.h>
#include <Matrix4.h>

using namespace Entropy::Math;

TEST(Matrix4, Constructor)
{
	Matrix4 empty;
	Matrix4 a(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	EXPECT_FLOAT_EQ(empty.r0c0, 1); EXPECT_FLOAT_EQ(empty.r0c1, 0); EXPECT_FLOAT_EQ(empty.r0c2, 0); EXPECT_FLOAT_EQ(empty.r0c3, 0);
	EXPECT_FLOAT_EQ(empty.r1c0, 0); EXPECT_FLOAT_EQ(empty.r1c1, 1); EXPECT_FLOAT_EQ(empty.r1c2, 0); EXPECT_FLOAT_EQ(empty.r1c3, 0);
	EXPECT_FLOAT_EQ(empty.r2c0, 0); EXPECT_FLOAT_EQ(empty.r2c1, 0); EXPECT_FLOAT_EQ(empty.r2c2, 1); EXPECT_FLOAT_EQ(empty.r2c3, 0);
	EXPECT_FLOAT_EQ(empty.r3c0, 0); EXPECT_FLOAT_EQ(empty.r3c1, 0); EXPECT_FLOAT_EQ(empty.r3c2, 0); EXPECT_FLOAT_EQ(empty.r3c3, 1);

	EXPECT_FLOAT_EQ(a.r0c0,  1); EXPECT_FLOAT_EQ(a.r0c1,  2); EXPECT_FLOAT_EQ(a.r0c2,  3); EXPECT_FLOAT_EQ(a.r0c3,  4);
	EXPECT_FLOAT_EQ(a.r1c0,  5); EXPECT_FLOAT_EQ(a.r1c1,  6); EXPECT_FLOAT_EQ(a.r1c2,  7); EXPECT_FLOAT_EQ(a.r1c3,  8);
	EXPECT_FLOAT_EQ(a.r2c0,  9); EXPECT_FLOAT_EQ(a.r2c1, 10); EXPECT_FLOAT_EQ(a.r2c2, 11); EXPECT_FLOAT_EQ(a.r2c3, 12);
	EXPECT_FLOAT_EQ(a.r3c0, 13); EXPECT_FLOAT_EQ(a.r3c1, 14); EXPECT_FLOAT_EQ(a.r3c2, 15); EXPECT_FLOAT_EQ(a.r3c3, 16);
}

TEST(Matrix4, MatrixVectorMultiply)
{
	Matrix4 matrix(
		 2, -3,  4, -2,
		 5,  7, -2,  1,
		-9,  1,  0,  7,
		 6, -2,  3,  5
	);
	Vector4 vector(3, 9, 5, 7);

	Vector4 result = matrix * vector;

	ASSERT_FLOAT_EQ(result.i, -15);
	ASSERT_FLOAT_EQ(result.j, 75);
	ASSERT_FLOAT_EQ(result.k, 31);
	ASSERT_FLOAT_EQ(result.l, 50);
}

TEST(Matrix4, MatrixMatrixMultiply)
{
	Matrix4 a(
		1, 0, 0, 1,
		0, 1, 0, 2,
		0, 0, 1, 3,
		0, 0, 0, 1
	);

	Matrix4 b(
		2, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, 2, 0,
		0, 0, 0, 1
	);

	Matrix4 result = a * b;

	ASSERT_FLOAT_EQ(2, result.r0c0);
	ASSERT_FLOAT_EQ(0, result.r0c1);
	ASSERT_FLOAT_EQ(0, result.r0c2);
	ASSERT_FLOAT_EQ(1, result.r0c3);

	ASSERT_FLOAT_EQ(0, result.r1c0);
	ASSERT_FLOAT_EQ(2, result.r1c1);
	ASSERT_FLOAT_EQ(0, result.r1c2);
	ASSERT_FLOAT_EQ(2, result.r1c3);

	ASSERT_FLOAT_EQ(0, result.r2c0);
	ASSERT_FLOAT_EQ(0, result.r2c1);
	ASSERT_FLOAT_EQ(2, result.r2c2);
	ASSERT_FLOAT_EQ(3, result.r2c3);

	ASSERT_FLOAT_EQ(0, result.r3c0);
	ASSERT_FLOAT_EQ(0, result.r3c1);
	ASSERT_FLOAT_EQ(0, result.r3c2);
	ASSERT_FLOAT_EQ(1, result.r3c3);
}