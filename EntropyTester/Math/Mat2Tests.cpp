#include <gtest/gtest.h>
#include <Entropy/Math/Mat2.h>

using namespace Entropy;

TEST(MAT2, ConstructionEmpty)
{
	Math::Mat2 testMatrix;

	EXPECT_FLOAT_EQ(1.0f, testMatrix.R0C0); EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C0); EXPECT_FLOAT_EQ(1.0f, testMatrix.R1C1);

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[2]); 
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[3]); 

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][0]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[1][1]);
}

TEST(MAT2, ConstructionValue)
{
	Math::Mat2 testMatrix(7.4f);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C0);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C1);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[2]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[3]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][0]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][1]);
}

TEST(MAT2, ConstructionFloats)
{
	Math::Mat2 testMatrix(
		 7.4f,  4.4f,
		-8.3f, -6.8f
	);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[2]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[3]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]);
}

TEST(MAT2, ConstructionArray)
{
	float data[4] = {
		  7.4f,  4.4f,
		- 8.3f, -6.8f
	};

	Math::Mat2 testMatrix(data);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[2]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[3]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]);

}

TEST(MAT2, Construction2DArray)
{
	float data[2][2] = {
		{ 7.4f,  4.4f},
		{-8.3f, -6.8f}
	};

	Math::Mat2 testMatrix(*data);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[2]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[3]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]);
}

TEST(MAT2, Addition)
{
	Math::Mat2 a(
		 7.4f,  4.4f,
		-8.3f, -6.8f
	);

	Math::Mat2 b{
		 0.1f,  2.1f,
		-0.1f,  3.4f
	};

	Math::Mat2 testMatrix = a + b;

	EXPECT_FLOAT_EQ( 7.5f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.4f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ( 6.5f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-3.4f, testMatrix.R1C1);
}

TEST(MAT2, Subtraction)
{
	Math::Mat2 a(
		 7.4f,  4.4f,
		-8.3f, -6.8f
	);

	Math::Mat2 b{
		 0.1f,  2.1f,
		-0.1f,  3.4f
	};

	Math::Mat2 testMatrix = a - b;

	EXPECT_FLOAT_EQ( 7.3f, testMatrix.R0C0); EXPECT_FLOAT_EQ( -8.2f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ( 2.3f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-10.2f, testMatrix.R1C1);
}

TEST(MAT2, Multiplication)
{
	Math::Mat2 a(
		 7.4f,  4.4f,
		-8.3f, -6.8f
	);

	Math::Mat2 b{
		 0.1f,  2.1f,
		-0.1f,  3.4f
	};

	Math::Mat2 testMatrix = a * b;

	EXPECT_FLOAT_EQ(  0.30f, testMatrix.R0C0); EXPECT_FLOAT_EQ( -0.15f, testMatrix.R0C1);
	EXPECT_FLOAT_EQ( 30.50f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-40.55f, testMatrix.R1C1);
}