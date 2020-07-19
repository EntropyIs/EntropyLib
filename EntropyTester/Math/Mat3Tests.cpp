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
		-1.7f,  2.9f, -9.8f };

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
		{-1.7f,  2.9f, -9.8f} };

	Math::Mat3 testMatrix(*data);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-1.7f, testMatrix.R0C2);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R1C2); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-2.3f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-9.8f, testMatrix.R2C2);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data[6]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[4]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[7]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data[8]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data2[2][0]);
	EXPECT_FLOAT_EQ(4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[2][1]); 
	EXPECT_FLOAT_EQ(3.6f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data2[2][2]);}
