#include <gtest/gtest.h>
#include <Entropy/Math/Transform2D.h>

using namespace Entropy;

TEST(TRANSFORM2D, MatrixVectorMultiplication)
{
	Math::Vec3 a(1.2f, -2.3f, 1.0f);
	Math::Mat3 m(
		 7.4f,  4.4f,  3.6f,
		-8.3f, -6.8f, -2.3f,
		-1.7f,  2.9f, -9.8f
	);

	Math::Vec3 testVector = m * a;

	EXPECT_FLOAT_EQ(26.27f, testVector.X);
	EXPECT_FLOAT_EQ(23.82f, testVector.Y);
	EXPECT_FLOAT_EQ(-0.1899996f, testVector.Z); // Note slight error -0.19
}

TEST(TRANSFORM2D, ScaleByFloat)
{
	Math::Vec3 a(1.2f, -2.3f, 1.0f);
	Math::Vec3 testVector = Math::Scale(2.0f) * a;

	EXPECT_FLOAT_EQ(2.4f, testVector.X);
	EXPECT_FLOAT_EQ(-4.6f, testVector.Y);
	EXPECT_FLOAT_EQ(1.0f, testVector.Z); // Note slight error -0.19
}

TEST(TRANSFORM2D, ScaleByVector)
{
	Math::Vec3 a(1.2f, -2.3f, 1.0f);
	Math::Vec2 scale(2.0f, 1.5f);
	Math::Vec3 testVector = Math::Scale(scale) * a;

	EXPECT_FLOAT_EQ( 2.4f, testVector.X);
	EXPECT_FLOAT_EQ(-3.45f, testVector.Y);
	EXPECT_FLOAT_EQ( 1.0f, testVector.Z); // Note slight error -0.19
}

TEST(TRANSFORM2D, ScaleByDeltas)
{
	Math::Vec3 a(1.2f, -2.3f, 1.0f);
	Math::Vec3 testVector = Math::Scale(2.0f, 1.5f) * a;

	EXPECT_FLOAT_EQ( 2.40f, testVector.X);
	EXPECT_FLOAT_EQ(-3.45f, testVector.Y);
	EXPECT_FLOAT_EQ( 1.00f, testVector.Z); // Note slight error -0.19
}