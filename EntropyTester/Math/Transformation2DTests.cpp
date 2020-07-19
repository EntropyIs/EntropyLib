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
	EXPECT_FLOAT_EQ(1.0f, testVector.Z);
}

TEST(TRANSFORM2D, ScaleByVector)
{
	Math::Vec3 a(1.2f, -2.3f, 1.0f);
	Math::Vec2 scale(2.0f, 1.5f);
	Math::Vec3 testVector = Math::Scale(scale) * a;

	EXPECT_FLOAT_EQ( 2.4f, testVector.X);
	EXPECT_FLOAT_EQ(-3.45f, testVector.Y);
	EXPECT_FLOAT_EQ( 1.0f, testVector.Z);
}

TEST(TRANSFORM2D, ScaleByDeltas)
{
	Math::Vec3 a(1.2f, -2.3f, 1.0f);
	Math::Vec3 testVector = Math::Scale(2.0f, 1.5f) * a;

	EXPECT_FLOAT_EQ( 2.40f, testVector.X);
	EXPECT_FLOAT_EQ(-3.45f, testVector.Y);
	EXPECT_FLOAT_EQ( 1.00f, testVector.Z);
}

TEST(TRANSFORM2D, TranslateByVector)
{
	Math::Vec3 a( 5.5f,  9.0f, 1.0f);
	Math::Vec3 b(-3.5f, -5.9f, 1.0f);
	Math::Vec2 translation(2.0f, 3.0f);

	Math::Vec3 testVectorA = Math::Translate(translation) * a;
	EXPECT_FLOAT_EQ( 7.5f, testVectorA.X);
	EXPECT_FLOAT_EQ(12.0f, testVectorA.Y);
	EXPECT_FLOAT_EQ(1.00f, testVectorA.Z);

	Math::Vec3 testVectorB = Math::Translate(translation) * b;
	EXPECT_FLOAT_EQ(-1.5f, testVectorB.X);
	EXPECT_FLOAT_EQ(-2.9f, testVectorB.Y);
	EXPECT_FLOAT_EQ(1.00f, testVectorB.Z);
}

TEST(TRANSFORM2D, TranslateByValues)
{
	Math::Vec3 a( 5.5f,  9.0f, 1.0f);
	Math::Vec3 b(-3.5f, -5.9f, 1.0f);
	Math::Mat3 translator = Math::Translate(2.0f, 3.0f);
	Math::Vec3 testVectorA = Math::Translate(2.0f, 3.0f) * a;
	EXPECT_FLOAT_EQ(7.5f, testVectorA.X);
	EXPECT_FLOAT_EQ(12.0f, testVectorA.Y);
	EXPECT_FLOAT_EQ(1.00f, testVectorA.Z);

	Math::Vec3 testVectorB = Math::Translate(2.0f, 3.0f) * b;
	EXPECT_FLOAT_EQ(-1.5f, testVectorB.X);
	EXPECT_FLOAT_EQ(-2.9f, testVectorB.Y);
	EXPECT_FLOAT_EQ(1.00f, testVectorB.Z);
}

TEST(TRANSFORM2D, RotateByAngle)
{
	Math::Vec3 a(5.5f, 9.0f, 1.0f);
	Math::Vec3 testVector = Math::Roatate(1.0f) * a;
	EXPECT_FLOAT_EQ(-4.601575f, testVector.X);
	EXPECT_FLOAT_EQ( 9.49081f, testVector.Y);
	EXPECT_FLOAT_EQ( 1.00f, testVector.Z);
}