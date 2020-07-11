#include <gtest/gtest.h>
#include <Matrix3Ext.h>

#include "HelperFunctions.h"

using namespace Entropy::Math;

TEST(Matrix3, Constructor)
{
	Matrix3 empty;
	Matrix3 a(1, 2, 3, 4, 5, 6, 7, 8, 9);

	FLOAT_EQ(empty.r0c0, 1); FLOAT_EQ(empty.r0c1, 0); FLOAT_EQ(empty.r0c2, 0);
	FLOAT_EQ(empty.r1c0, 0); FLOAT_EQ(empty.r1c1, 1); FLOAT_EQ(empty.r1c2, 0);
	FLOAT_EQ(empty.r2c0, 0); FLOAT_EQ(empty.r2c1, 0); FLOAT_EQ(empty.r2c2, 1);

	FLOAT_EQ(a.r0c0, 1); FLOAT_EQ(a.r0c1, 2); FLOAT_EQ(a.r0c2, 3);
	FLOAT_EQ(a.r1c0, 4); FLOAT_EQ(a.r1c1, 5); FLOAT_EQ(a.r1c2, 6);
	FLOAT_EQ(a.r2c0, 7); FLOAT_EQ(a.r2c1, 8); FLOAT_EQ(a.r2c2, 9);
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

TEST(Matrix3, TranslationMatrix)
{
	Matrix3 translator = TranslationMatrix(4.0, 8.0);
	FLOAT_EQ(translator.r0c0, 1.0f);
	FLOAT_EQ(translator.r0c1, 0.0f);
	FLOAT_EQ(translator.r0c2, 4.0f);
	FLOAT_EQ(translator.r1c0, 0.0f);
	FLOAT_EQ(translator.r1c1, 1.0f);
	FLOAT_EQ(translator.r1c2, 8.0f);
	FLOAT_EQ(translator.r2c0, 0.0f);
	FLOAT_EQ(translator.r2c1, 0.0f);
	FLOAT_EQ(translator.r2c2, 1.0f);

	Vector3 victim(-3.0f, 8.0f, 1.0f);
	Vector3 victimPrime = translator * victim;

	FLOAT_EQ(victimPrime.i, 1.0f);
	FLOAT_EQ(victimPrime.j, 16.0f);
}

TEST(Matrix3, RoatationMatrixZero)
{
	Matrix3 op = ZRotationMatrix(0.0f);
	FLOAT_EQ(op.r0c0, 1.0f);
	FLOAT_EQ(op.r0c1, 0.0f);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, 0.0f);
	FLOAT_EQ(op.r1c1, 1.0f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, RoatationMatrixPI)
{
	Matrix3 op = ZRotationMatrix(PI);
	FLOAT_EQ(op.r0c0, -1.0f);
	FLOAT_EQ(op.r0c1, 0.0f);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, 0.0f);
	FLOAT_EQ(op.r1c1, -1.0f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, RoatationMatrixPIOverTwo)
{
	Matrix3 op = ZRotationMatrix(PI / 2.0f);
	FLOAT_EQ(op.r0c0, 0.0f);
	FLOAT_EQ(op.r0c1, -1.0f);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, 1.0f);
	FLOAT_EQ(op.r1c1, 0.0f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, RoatationMatrixPIOverFour)
{
	Matrix3 op = ZRotationMatrix(PI / 4.0f);
	FLOAT_EQ(op.r0c0, SQRT2OVER2);
	FLOAT_EQ(op.r0c1, -SQRT2OVER2);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, SQRT2OVER2);
	FLOAT_EQ(op.r1c1, SQRT2OVER2);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, RoatationMatrixNegitivePIOverFour)
{
	Matrix3 op = ZRotationMatrix(-PI / 4.0f);
	FLOAT_EQ(op.r0c0, SQRT2OVER2);
	FLOAT_EQ(op.r0c1, SQRT2OVER2);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, -SQRT2OVER2);
	FLOAT_EQ(op.r1c1, SQRT2OVER2);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, RoatationMatrixPIOverThree)
{
	Matrix3 op = ZRotationMatrix(PI / 3.0f);
	FLOAT_EQ(op.r0c0, 0.5f);
	FLOAT_EQ(op.r0c1, -SQRT3OVER2);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, SQRT3OVER2);
	FLOAT_EQ(op.r1c1, 0.5f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, RoatationMatrixNegitivePIOverThree)
{
	Matrix3 op = ZRotationMatrix(-PI / 3.0f);
	FLOAT_EQ(op.r0c0, 0.5f);
	FLOAT_EQ(op.r0c1, SQRT3OVER2);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, -SQRT3OVER2);
	FLOAT_EQ(op.r1c1, 0.5f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, ScaleMatrixByVector)
{
	Vector3 scale(2.0f, 3.0f, 1.0);
	Matrix3 op = ScaleMatrix(scale);
	FLOAT_EQ(op.r0c0, 2.0f);
	FLOAT_EQ(op.r0c1, 0.0f);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, 0.0f);
	FLOAT_EQ(op.r1c1, 3.0f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, ScaleMatrixByValues)
{
	Matrix3 op = ScaleMatrix(7.0f, 5.5f);
	FLOAT_EQ(op.r0c0, 7.0f);
	FLOAT_EQ(op.r0c1, 0.0f);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, 0.0f);
	FLOAT_EQ(op.r1c1, 5.5f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3, UniformScaleMatrix)
{
	Matrix3 op = ScaleMatrix(2.0f);
	FLOAT_EQ(op.r0c0, 2.0f);
	FLOAT_EQ(op.r0c1, 0.0f);
	FLOAT_EQ(op.r0c2, 0.0f);
	FLOAT_EQ(op.r1c0, 0.0f);
	FLOAT_EQ(op.r1c1, 2.0f);
	FLOAT_EQ(op.r1c2, 0.0f);
	FLOAT_EQ(op.r2c0, 0.0f);
	FLOAT_EQ(op.r2c1, 0.0f);
	FLOAT_EQ(op.r2c2, 1.0f);
}