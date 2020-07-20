#include <gtest/gtest.h>
#include <Entropy/Math/Transform3D.h>

using namespace Entropy;

TEST(TRANSFORM3D, MatrixVectorMultiplication)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Mat4 m(
		 7.4f,  4.4f,  3.6f,  0.2f,
		-8.3f, -6.8f, -2.3f,  2.9f,
		-1.7f,  2.9f, -9.8f,  3.0f,
		 5.8f,  0.8f, -6.9f, -3.4f 
	);

	Math::Vec4 testVector = m * a;

	EXPECT_FLOAT_EQ( 23.74f, testVector.X);
	EXPECT_FLOAT_EQ( 38.83f, testVector.Y);
	EXPECT_FLOAT_EQ(-55.11f, testVector.Z);
	EXPECT_FLOAT_EQ(  7.87f, testVector.W);
}

TEST(TRANSFORM3D, ScaleByFloat)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec4 testVector = Math::Scale(2.0f) * a;

	EXPECT_FLOAT_EQ( 2.4f, testVector.X);
	EXPECT_FLOAT_EQ(-4.6f, testVector.Y);
	EXPECT_FLOAT_EQ(11.8f, testVector.Z);
	EXPECT_FLOAT_EQ( 1.0f, testVector.W);
}

TEST(TRANSFORM3D, ScaleByVector)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec3 scale(2.0f, 1.5f, 3.0f);
	Math::Vec4 testVector = Math::Scale(scale) * a;

	EXPECT_FLOAT_EQ( 2.4f, testVector.X);
	EXPECT_FLOAT_EQ(-3.45f, testVector.Y);
	EXPECT_FLOAT_EQ(17.7f, testVector.Z);
	EXPECT_FLOAT_EQ( 1.0f, testVector.W);
}

TEST(TRANSFORM3D, ScaleByDeltas)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec4 testVector = Math::Scale(2.0f, 1.5f, 3.0f) * a;

	EXPECT_FLOAT_EQ( 2.4f, testVector.X);
	EXPECT_FLOAT_EQ(-3.45f, testVector.Y);
	EXPECT_FLOAT_EQ(17.7f, testVector.Z);
	EXPECT_FLOAT_EQ( 1.0f, testVector.W);
}

TEST(TRANSFORM3D, TranslateByVector)
{
	Math::Vec4 a( 1.2f, -2.3f,  5.9f, 1.0f);
	Math::Vec4 b(-3.5f,  1.8f, -5.9f, 1.0f);
	Math::Vec3 translation(2.0f, 3.0f, 4.0f);

	Math::Vec4 testVectorA = Math::Translate(translation) * a;
	EXPECT_FLOAT_EQ( 3.2f, testVectorA.X);
	EXPECT_FLOAT_EQ( 0.7f, testVectorA.Y);
	EXPECT_FLOAT_EQ( 9.9f, testVectorA.Z);
	EXPECT_FLOAT_EQ( 1.0f, testVectorA.W);

	Math::Vec4 testVectorB = Math::Translate(translation) * b;
	EXPECT_FLOAT_EQ(-1.5f, testVectorB.X);
	EXPECT_FLOAT_EQ( 4.8f, testVectorB.Y);
	EXPECT_FLOAT_EQ(-1.9f, testVectorB.Z);
	EXPECT_FLOAT_EQ( 1.0f, testVectorB.W);
}

TEST(TRANSFORM3D, TranslateByValues)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec4 b(-3.5f, 1.8f, -5.9f, 1.0f);
	Math::Vec4 testVectorA = Math::Translate(2.0f, 3.0f, 4.0f) * a;
	EXPECT_FLOAT_EQ(3.2f, testVectorA.X);
	EXPECT_FLOAT_EQ(0.7f, testVectorA.Y);
	EXPECT_FLOAT_EQ(9.9f, testVectorA.Z);
	EXPECT_FLOAT_EQ(1.0f, testVectorA.W);

	Math::Vec4 testVectorB = Math::Translate(2.0f, 3.0f, 4.0f) * b;
	EXPECT_FLOAT_EQ(-1.5f, testVectorB.X);
	EXPECT_FLOAT_EQ( 4.8f, testVectorB.Y);
	EXPECT_FLOAT_EQ(-1.9f, testVectorB.Z);
	EXPECT_FLOAT_EQ( 1.0f, testVectorB.W);
}

TEST(TRANSFORM3D, RotateXByAngle)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec4 testVector = Math::RotateX(1.0f) * a;
	EXPECT_FLOAT_EQ( 1.20000f, testVector.X);
	EXPECT_FLOAT_EQ(-6.2073741f, testVector.Y);
	EXPECT_FLOAT_EQ( 1.2524f, testVector.Z);
	EXPECT_FLOAT_EQ( 1.00000f, testVector.W);
}


TEST(TRANSFORM3D, RotateYByAngle)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec4 testVector = Math::RotateY(1.0f) * a;
	EXPECT_FLOAT_EQ( 5.61304f, testVector.X);
	EXPECT_FLOAT_EQ(-2.30000f, testVector.Y);
	EXPECT_FLOAT_EQ( 2.1780183f, testVector.Z);
	EXPECT_FLOAT_EQ( 1.00000f, testVector.W);
}

TEST(TRANSFORM3D, RotateZByAngle)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec4 testVector = Math::RotateZ(1.0f) * a;
	EXPECT_FLOAT_EQ( 2.583746f, testVector.X);
	EXPECT_FLOAT_EQ(-0.23293f, testVector.Y);
	EXPECT_FLOAT_EQ( 5.90000f, testVector.Z);
	EXPECT_FLOAT_EQ( 1.00000f, testVector.W);
}

TEST(TRANSFORM3D, RotateAxisByAngle)
{
	Math::Vec4 a(1.2f, -2.3f, 5.9f, 1.0f);
	Math::Vec3 axis(2.0f, 3.0f, 4.0f);
	Math::Vec4 testVector = Math::Rotate(axis, 1.0f) * a;
	EXPECT_FLOAT_EQ( 5.457215f, testVector.X);
	EXPECT_FLOAT_EQ(-1.4281965f, testVector.Y);
	EXPECT_FLOAT_EQ( 3.11754f, testVector.Z);
	EXPECT_FLOAT_EQ( 1.00000f, testVector.W);
}