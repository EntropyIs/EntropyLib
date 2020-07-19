#include <gtest/gtest.h>
#include <Entropy/Math/Mat4.h>

using namespace Entropy;

TEST(MAT4, ConstructionEmpty)
{
	Math::Mat4 testMatrix;

	EXPECT_FLOAT_EQ(1.0f, testMatrix.R0C0); EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C1); EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C2); EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C3);			
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C0); EXPECT_FLOAT_EQ(1.0f, testMatrix.R1C1); EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C2); EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C3);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C0); EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C1); EXPECT_FLOAT_EQ(1.0f, testMatrix.R2C2); EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C3);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R3C0); EXPECT_FLOAT_EQ(0.0f, testMatrix.R3C1); EXPECT_FLOAT_EQ(0.0f, testMatrix.R3C2); EXPECT_FLOAT_EQ(1.0f, testMatrix.R3C3);

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[4]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 8]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[12]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 9]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[13]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[6]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[10]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[14]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[7]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[11]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[15]);

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[3][0]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][1]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[3][1]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[2][2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[3][2]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][3]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][3]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][3]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[3][3]);
}

TEST(MAT4, ConstructionValue)
{
	Math::Mat4 testMatrix(7.4f);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C1);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C2);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R0C3);	
	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C0);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C1);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C2);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R1C3);	
	EXPECT_FLOAT_EQ(7.4f, testMatrix.R2C0);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R2C1);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R2C2);	EXPECT_FLOAT_EQ(7.4f, testMatrix.R2C3);	
	EXPECT_FLOAT_EQ(7.4f, testMatrix.R3C0); EXPECT_FLOAT_EQ(7.4f, testMatrix.R3C1); EXPECT_FLOAT_EQ(7.4f, testMatrix.R3C2); EXPECT_FLOAT_EQ(7.4f, testMatrix.R3C3);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[4]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[ 8]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[12]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[5]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[ 9]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[13]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[6]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[10]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[14]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[3]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[7]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[11]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data[15]);

	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[2][0]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[3][0]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[2][1]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[3][1]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[2][2]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[3][2]);
	EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[0][3]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[1][3]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[2][3]); EXPECT_FLOAT_EQ(7.4f, testMatrix.Data2[3][3]);
}

TEST(MAT4, ConstructionFloats)
{
	Math::Mat4 testMatrix(
		 7.4f,  4.4f,  3.6f,  0.2f,
		-8.3f, -6.8f, -2.3f,  2.9f,
		-1.7f,  2.9f, -9.8f,  3.0f,
		 5.8f,  0.8f, -6.9f, -3.4f 
	);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-1.7f, testMatrix.R0C2); EXPECT_FLOAT_EQ( 5.8f, testMatrix.R0C3); 
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R1C2); EXPECT_FLOAT_EQ( 0.8f, testMatrix.R1C3);
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-2.3f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-9.8f, testMatrix.R2C2); EXPECT_FLOAT_EQ(-6.9f, testMatrix.R2C3);
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.R3C0); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R3C1); EXPECT_FLOAT_EQ( 3.0f, testMatrix.R3C2); EXPECT_FLOAT_EQ(-3.4f, testMatrix.R3C3);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[4]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data[ 8]); EXPECT_FLOAT_EQ( 5.8f, testMatrix.Data[12]);
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[5]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[ 9]); EXPECT_FLOAT_EQ( 0.8f, testMatrix.Data[13]);
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data[6]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data[10]); EXPECT_FLOAT_EQ(-6.9f, testMatrix.Data[14]);
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.Data[3]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[7]); EXPECT_FLOAT_EQ( 3.0f, testMatrix.Data[11]); EXPECT_FLOAT_EQ(-3.4f, testMatrix.Data[15]);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data2[2][0]); EXPECT_FLOAT_EQ( 5.8f, testMatrix.Data2[3][0]);
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[2][1]); EXPECT_FLOAT_EQ( 0.8f, testMatrix.Data2[3][1]);
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data2[2][2]); EXPECT_FLOAT_EQ(-6.9f, testMatrix.Data2[3][2]);
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.Data2[0][3]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[1][3]); EXPECT_FLOAT_EQ( 3.0f, testMatrix.Data2[2][3]); EXPECT_FLOAT_EQ(-3.4f, testMatrix.Data2[3][3]);
}

TEST(MAT4, ConstructionArray)
{
	float data[16] = {
		 7.4f,  4.4f,  3.6f,  0.2f,
		-8.3f, -6.8f, -2.3f,  2.9f,
		-1.7f,  2.9f, -9.8f,  3.0f,
		 5.8f,  0.8f, -6.9f, -3.4f };

	Math::Mat4 testMatrix(data);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-1.7f, testMatrix.R0C2); EXPECT_FLOAT_EQ( 5.8f, testMatrix.R0C3); 
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R1C2); EXPECT_FLOAT_EQ( 0.8f, testMatrix.R1C3); 
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-2.3f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-9.8f, testMatrix.R2C2); EXPECT_FLOAT_EQ(-6.9f, testMatrix.R2C3); 
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.R3C0); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R3C1); EXPECT_FLOAT_EQ( 3.0f, testMatrix.R3C2); EXPECT_FLOAT_EQ(-3.4f, testMatrix.R3C3);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[4]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data[ 8]); EXPECT_FLOAT_EQ( 5.8f, testMatrix.Data[12]);
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[5]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[ 9]); EXPECT_FLOAT_EQ( 0.8f, testMatrix.Data[13]);
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data[6]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data[10]); EXPECT_FLOAT_EQ(-6.9f, testMatrix.Data[14]);
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.Data[3]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[7]); EXPECT_FLOAT_EQ( 3.0f, testMatrix.Data[11]); EXPECT_FLOAT_EQ(-3.4f, testMatrix.Data[15]);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data2[2][0]); EXPECT_FLOAT_EQ( 5.8f, testMatrix.Data2[3][0]);
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[2][1]); EXPECT_FLOAT_EQ( 0.8f, testMatrix.Data2[3][1]);
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data2[2][2]); EXPECT_FLOAT_EQ(-6.9f, testMatrix.Data2[3][2]);
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.Data2[0][3]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[1][3]); EXPECT_FLOAT_EQ( 3.0f, testMatrix.Data2[2][3]); EXPECT_FLOAT_EQ(-3.4f, testMatrix.Data2[3][3]);
}

TEST(MAT4, Construction2DArray)
{
	float data[4][4] = {
		{ 7.4f,  4.4f,  3.6f,  0.2f},
		{-8.3f, -6.8f, -2.3f,  2.9f},
		{-1.7f,  2.9f, -9.8f,  3.0f},
		{ 5.8f,  0.8f, -6.9f, -3.4f}};

	Math::Mat4 testMatrix(*data);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.R0C0); EXPECT_FLOAT_EQ(-8.3f, testMatrix.R0C1); EXPECT_FLOAT_EQ(-1.7f, testMatrix.R0C2); EXPECT_FLOAT_EQ( 5.8f, testMatrix.R0C3); 
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.R1C0); EXPECT_FLOAT_EQ(-6.8f, testMatrix.R1C1); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R1C2); EXPECT_FLOAT_EQ( 0.8f, testMatrix.R1C3); 
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.R2C0); EXPECT_FLOAT_EQ(-2.3f, testMatrix.R2C1); EXPECT_FLOAT_EQ(-9.8f, testMatrix.R2C2); EXPECT_FLOAT_EQ(-6.9f, testMatrix.R2C3); 
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.R3C0); EXPECT_FLOAT_EQ( 2.9f, testMatrix.R3C1); EXPECT_FLOAT_EQ( 3.0f, testMatrix.R3C2); EXPECT_FLOAT_EQ(-3.4f, testMatrix.R3C3); 

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.Data[0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data[4]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data[ 8]); EXPECT_FLOAT_EQ( 5.8f, testMatrix.Data[12]);
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.Data[1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data[5]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[ 9]); EXPECT_FLOAT_EQ( 0.8f, testMatrix.Data[13]);
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.Data[2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data[6]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data[10]); EXPECT_FLOAT_EQ(-6.9f, testMatrix.Data[14]);
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.Data[3]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data[7]); EXPECT_FLOAT_EQ( 3.0f, testMatrix.Data[11]); EXPECT_FLOAT_EQ(-3.4f, testMatrix.Data[15]);

	EXPECT_FLOAT_EQ( 7.4f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(-8.3f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(-1.7f, testMatrix.Data2[2][0]); EXPECT_FLOAT_EQ( 5.8f, testMatrix.Data2[3][0]);
	EXPECT_FLOAT_EQ( 4.4f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(-6.8f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[2][1]); EXPECT_FLOAT_EQ( 0.8f, testMatrix.Data2[3][1]);
	EXPECT_FLOAT_EQ( 3.6f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(-2.3f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(-9.8f, testMatrix.Data2[2][2]); EXPECT_FLOAT_EQ(-6.9f, testMatrix.Data2[3][2]);
	EXPECT_FLOAT_EQ( 0.2f, testMatrix.Data2[0][3]); EXPECT_FLOAT_EQ( 2.9f, testMatrix.Data2[1][3]); EXPECT_FLOAT_EQ( 3.0f, testMatrix.Data2[2][3]); EXPECT_FLOAT_EQ(-3.4f, testMatrix.Data2[3][3]);
}
	