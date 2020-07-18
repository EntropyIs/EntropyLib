#include <gtest/gtest.h>
#include <Entropy/Math/Mat4.h>

using namespace Entropy;

TEST(MAT4, ConstructionEmpty)
{
	Math::Mat4 testMatrix;

	EXPECT_FLOAT_EQ(1.0f, testMatrix.R0C0); EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C0);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C0);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R3C0);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C1);	EXPECT_FLOAT_EQ(1.0f, testMatrix.R1C1);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C1);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R3C1);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C2);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C2);	EXPECT_FLOAT_EQ(1.0f, testMatrix.R2C2);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R3C2);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.R0C3);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R1C3);	EXPECT_FLOAT_EQ(0.0f, testMatrix.R2C3);	EXPECT_FLOAT_EQ(1.0f, testMatrix.R3C3);

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[ 0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 4]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 8]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[12]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[ 5]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 9]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[13]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 6]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[10]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[14]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 3]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[ 7]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data[11]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data[15]);

	EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[0][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][0]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[3][0]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][1]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[1][1]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][1]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[3][1]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][2]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[2][2]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[3][2]);
	EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[0][3]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[1][3]); EXPECT_FLOAT_EQ(0.0f, testMatrix.Data2[2][3]); EXPECT_FLOAT_EQ(1.0f, testMatrix.Data2[3][3]);
}