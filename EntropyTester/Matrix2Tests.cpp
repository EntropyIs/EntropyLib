#include <gtest/gtest.h>
#include <Matrix2.h>
#include <Matrix2Ext.h>
#include <Vector2.h>

#include "HelperFunctions.h"

using namespace Entropy::Math;



TEST(Matrix2, Constructor)
{
	Matrix2 empty;
	Matrix2 a(1, 2, 3, 4);

	EXPECT_TRUE(FLOAT_EQ(empty.r0c0, 1)); EXPECT_TRUE(FLOAT_EQ(empty.r0c1, 0));
	EXPECT_TRUE(FLOAT_EQ(empty.r1c0, 0)); EXPECT_TRUE(FLOAT_EQ(empty.r1c1, 1));

	EXPECT_TRUE(FLOAT_EQ(a.r0c0, 1)); EXPECT_TRUE(FLOAT_EQ(a.r0c1, 2));
	EXPECT_TRUE(FLOAT_EQ(a.r1c0, 3)); EXPECT_TRUE(FLOAT_EQ(a.r1c1, 4));
}

TEST(Matrix2, MatrixVectorMultiply)
{
	Matrix2 matrix( 2, -3, 4, 5);
	Vector2 vector(3, 9);

	Vector2 result = matrix * vector;

	ASSERT_FLOAT_EQ(result.i, -21);
	ASSERT_FLOAT_EQ(result.j, 57);
}

TEST(Matrix2, RoatationMatrixZero)
{
	Matrix2 op = RotationMatrix2(0.0f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, 1.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, 1.0f));
}

TEST(Matrix2, RoatationMatrixPI)
{
	Matrix2 op = RotationMatrix2(PI);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, -1.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, -1.0f));
}

TEST(Matrix2, RoatationMatrixPIOverTwo)
{
	Matrix2 op = RotationMatrix2(PI / 2.0f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, -1.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, 1.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, 0.0f));
}

TEST(Matrix2, RoatationMatrixPIOverFour)
{
	Matrix2 op = RotationMatrix2(PI / 4.0f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, SQRT2OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, -SQRT2OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, SQRT2OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, SQRT2OVER2));
}

TEST(Matrix2, RoatationMatrixNegitivePIOverFour)
{
	Matrix2 op = RotationMatrix2(-PI / 4.0f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, SQRT2OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, SQRT2OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, -SQRT2OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, SQRT2OVER2));
}

TEST(Matrix2, RoatationMatrixPIOverThree)
{
	Matrix2 op = RotationMatrix2(PI / 3.0f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, 0.5f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, -SQRT3OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, SQRT3OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, 0.5f));
}

TEST(Matrix2, RoatationMatrixNegitivePIOverThree)
{
	Matrix2 op = RotationMatrix2(-PI / 3.0f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, 0.5f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, SQRT3OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, -SQRT3OVER2));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, 0.5f));
}

TEST(Matrix2, ScaleMatrixByVector)
{
	Vector2 scale(2.0f, 2.0f);
	Matrix2 op = ScaleMatrix2(scale);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, 2.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, 2.0f));
}

TEST(Matrix2, ScaleMatrixByValues)
{
	Matrix2 op = ScaleMatrix2(2.0f, 1.5f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, 2.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, 1.5f));
}

TEST(Matrix2, UniformScaleMatrix)
{
	Matrix2 op = ScaleMatrix2(2.0f);
	EXPECT_TRUE(FLOAT_EQ(op.r0c0, 2.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r0c1, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c0, 0.0f));
	EXPECT_TRUE(FLOAT_EQ(op.r1c1, 2.0f));
}