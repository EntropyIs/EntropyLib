#include <gtest/gtest.h>
#include <Entropy/Math/Mat3.h>

using namespace Entropy;

TEST(MAT3, ConstructionEmpty)
{
	Math::Mat3 testMatrix;

	EXPECT_FLOAT_EQ(1.0f, testMatrix.R0C0); EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C1); EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C0); EXPECT_FLOAT_EQ(1.0f, testMatrix.R1C1); EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C2);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C0); EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C1); EXPECT_FLOAT_EQ(1.0f, testMatrix.R2C2);

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[6]); 
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[4]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[7]); 
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[8]);

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][0]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][1]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[2][2]);
}

TEST(MAT3, ConstructionValue)
{
	Math::Mat3 testMatrix(7.4f);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C1);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C0);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C1);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C2);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.R2C0);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R2C1);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R2C2);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[6]); 
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[4]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[7]); 
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[8]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[2][0]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[2][1]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[2][2]);
}

TEST(MAT3, ConstructionFloats)
{
	Math::Mat3 testMatrix(
		 7.4f,  4.4f,  3.6f,
		-8.3f, -6.8f, -2.3f, 
		-1.7f,  2.9f, -9.8f
	);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-1.7f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R1C2); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-2.3f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-9.8f, testMatrix.R2C2);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data[6]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[4]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[7]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data[8]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data2[2][0]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[2][1]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data2[2][2]);
}

TEST(MAT3, ConstructionArray)
{
	float data[9] = {
		 7.4f,  4.4f,  3.6f,
		-8.3f, -6.8f, -2.3f,
		-1.7f,  2.9f, -9.8f
	};

	Math::Mat3 testMatrix(data);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-1.7f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R1C2); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-2.3f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-9.8f, testMatrix.R2C2);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data[6]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[4]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[7]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data[8]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data2[2][0]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[2][1]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data2[2][2]);

}

TEST(MAT3, Construction2DArray)
{
	float data[3][3] = {
		{ 7.4f,  4.4f,  3.6f},
		{-8.3f, -6.8f, -2.3f},
		{-1.7f,  2.9f, -9.8f}
	};

	Math::Mat3 testMatrix(*data);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-1.7f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R1C2); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-2.3f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-9.8f, testMatrix.R2C2);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data[6]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[4]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[7]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data[8]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data2[2][0]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[2][1]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data2[2][2]);
}

TEST(MAT3, Addition)
{
	Math::Mat3 a(
		 7.4f,  4.4f,  3.6f,
		-8.3f, -6.8f, -2.3f,
		-1.7f,  2.9f, -9.8f
	);

	Math::Mat3 b{
		 0.1f,  2.1f, -1.3f,
		-0.1f,  3.4f, -2.5f,
		-6.6f,  2.6f,  3.9f
	};

	Math::Mat3 testMatrix = a + b;

	EXPECT_FLOAT_EQ( 7.5f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.4f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-8.1f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ( 6.5f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-3.4f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 5.5f, testMatrix.R1C2);
	EXPECT_FLOAT_EQ( 2.3f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-4.8f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-5.9f, testMatrix.R2C2);
}

TEST(MAT3, Subtraction)
{
	Math::Mat3 a(
		 7.4f,  4.4f,  3.6f,
		-8.3f, -6.8f, -2.3f,
		-1.7f,  2.9f, -9.8f
	);

	Math::Mat3 b{
		 0.1f,  2.1f, -1.3f,
		-0.1f,  3.4f, -2.5f,
		-6.6f,  2.6f,  3.9f
	};

	Math::Mat3 testMatrix = a - b;

	EXPECT_FLOAT_EQ( 7.3f, testMatrix.R0C0); EXPECT_FLOAT_EQ( -8.2f, testMatrix.R0C1); EXPECT_FLOAT_EQ(  5.1f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ( 2.3f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-10.2f, testMatrix.R1C1); EXPECT_FLOAT_EQ(  0.3f, testMatrix.R1C2);
	EXPECT_FLOAT_EQ( 4.9f, testMatrix.R2C0); EXPECT_FLOAT_EQ(  0.2f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-13.7f, testMatrix.R2C2);
}