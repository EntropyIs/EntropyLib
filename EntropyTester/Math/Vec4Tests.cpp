#include <gtest/gtest.h>
#include <Entropy/Math/Vec4.h>

using namespace Entropy;

Math::Vec4 vectors[]{
	Math::Vec4( 59.5f, 100.0f,  65.7f, -77.7f),
	Math::Vec4(-38.5f, -55.9f, -93.5f,  13.3f),
	Math::Vec4( 55.1f,  46.4f,  77.1f, -96.2f),
	Math::Vec4(-43.2f, -68.2f, -83.0f,  90.0f),
	Math::Vec4(-85.9f, - 4.4f, -68.0f,  86.7f),
	Math::Vec4(-39.5f, -30.0f,  75.2f, -50.1f),
	Math::Vec4( 46.1f, -12.8f,  62.9f,  60.0f),
	Math::Vec4( 91.2f,   3.4f, -47.1f, -84.5f),
	Math::Vec4(-55.7f,  45.3f,  61.0f,   9.7f),
	Math::Vec4(  1.5f, -31.3f, -84.7f, -91.8f),
	Math::Vec4(- 9.3f, -94.5f,  90.0f, -49.9f),
	Math::Vec4(-85.4f, -63.4f,  91.4f,   8.0f),
	Math::Vec4( 23.4f,  53.5f, -49.3f, -70.0f),
	Math::Vec4(-55.5f, - 7.0f,  90.0f,   4.4f),
	Math::Vec4( 98.1f,  57.0f,  78.0f,  64.5f),
	Math::Vec4( 75.9f, -58.4f, -87.2f, -96.9f),
	Math::Vec4( 22.0f,  23.0f,  54.6f, -73.5f),
	Math::Vec4(-14.7f, -50.4f, -67.8f, -49.7f),
	Math::Vec4(-23.6f, - 4.6f,  12.5f,  49.1f),
	Math::Vec4( 34.6f, -58.3f, -13.9f,  35.0f),
	Math::Vec4( 92.5f,  89.5f,  93.5f, -50.1f),
	Math::Vec4( 41.6f,  48.1f,  34.1f, -21.0f),
	Math::Vec4(-90.5f,  38.8f, -85.8f,  80.2f),
	Math::Vec4(-44.0f,  42.8f, -92.6f, -13.0f)
};

TEST(VEC4, ConstructionEmpty)
{
	Math::Vec4 empty;

	EXPECT_FLOAT_EQ(0.0f, empty.X);
	EXPECT_FLOAT_EQ(0.0f, empty.Y);
	EXPECT_FLOAT_EQ(0.0f, empty.Z);
	EXPECT_FLOAT_EQ(0.0f, empty.W);

	EXPECT_FLOAT_EQ(0.0f, empty.I);
	EXPECT_FLOAT_EQ(0.0f, empty.J);
	EXPECT_FLOAT_EQ(0.0f, empty.K);
	EXPECT_FLOAT_EQ(0.0f, empty.L);

	EXPECT_FLOAT_EQ(0.0f, empty.R);
	EXPECT_FLOAT_EQ(0.0f, empty.G);
	EXPECT_FLOAT_EQ(0.0f, empty.B);
	EXPECT_FLOAT_EQ(0.0f, empty.A);

	EXPECT_FLOAT_EQ(0.0f, empty.Data[0]);
	EXPECT_FLOAT_EQ(0.0f, empty.Data[1]);
	EXPECT_FLOAT_EQ(0.0f, empty.Data[2]);
	EXPECT_FLOAT_EQ(0.0f, empty.Data[3]);
}

TEST(VEC4, ConstructionValue)
{
	Math::Vec4 value(-5.2f);

	EXPECT_FLOAT_EQ(-5.2f, value.X);
	EXPECT_FLOAT_EQ(-5.2f, value.Y);
	EXPECT_FLOAT_EQ(-5.2f, value.Z);
	EXPECT_FLOAT_EQ(-5.2f, value.W);

	EXPECT_FLOAT_EQ(-5.2f, value.I);
	EXPECT_FLOAT_EQ(-5.2f, value.J);
	EXPECT_FLOAT_EQ(-5.2f, value.K);
	EXPECT_FLOAT_EQ(-5.2f, value.L);

	EXPECT_FLOAT_EQ(-5.2f, value.R);
	EXPECT_FLOAT_EQ(-5.2f, value.G);
	EXPECT_FLOAT_EQ(-5.2f, value.B);
	EXPECT_FLOAT_EQ(-5.2f, value.A);

	EXPECT_FLOAT_EQ(-5.2f, value.Data[0]);
	EXPECT_FLOAT_EQ(-5.2f, value.Data[1]);
	EXPECT_FLOAT_EQ(-5.2f, value.Data[2]);
	EXPECT_FLOAT_EQ(-5.2f, value.Data[3]);
}

TEST(VEC4, ConstructionIJ)
{
	Math::Vec4 testVector(1.8f, -2.8f);

	EXPECT_FLOAT_EQ(1.8f, testVector.X);
	EXPECT_FLOAT_EQ(-2.8f, testVector.Y);
	EXPECT_FLOAT_EQ(0.0f, testVector.Z);
	EXPECT_FLOAT_EQ(0.0f, testVector.W);

	EXPECT_FLOAT_EQ(1.8f, testVector.I);
	EXPECT_FLOAT_EQ(-2.8f, testVector.J);
	EXPECT_FLOAT_EQ(0.0f, testVector.K);
	EXPECT_FLOAT_EQ(0.0f, testVector.L);

	EXPECT_FLOAT_EQ(1.8f, testVector.R);
	EXPECT_FLOAT_EQ(-2.8f, testVector.G);
	EXPECT_FLOAT_EQ(0.0f, testVector.B);
	EXPECT_FLOAT_EQ(0.0f, testVector.A);

	EXPECT_FLOAT_EQ(1.8f, testVector.Data[0]);
	EXPECT_FLOAT_EQ(-2.8f, testVector.Data[1]);
	EXPECT_FLOAT_EQ(0.0f, testVector.Data[2]);
	EXPECT_FLOAT_EQ(0.0f, testVector.Data[3]);
}

TEST(VEC4, ConstructionIJK)
{
	Math::Vec4 testVector(-4.3f, 6.0f, 1.7f);

	EXPECT_FLOAT_EQ(-4.3f, testVector.X);
	EXPECT_FLOAT_EQ(6.0f, testVector.Y);
	EXPECT_FLOAT_EQ(1.7f, testVector.Z);
	EXPECT_FLOAT_EQ(0.0f, testVector.W);

	EXPECT_FLOAT_EQ(-4.3f, testVector.I);
	EXPECT_FLOAT_EQ(6.0f, testVector.J);
	EXPECT_FLOAT_EQ(1.7f, testVector.K);
	EXPECT_FLOAT_EQ(0.0f, testVector.L);

	EXPECT_FLOAT_EQ(-4.3f, testVector.R);
	EXPECT_FLOAT_EQ(6.0f, testVector.G);
	EXPECT_FLOAT_EQ(1.7f, testVector.B);
	EXPECT_FLOAT_EQ(0.0f, testVector.A);

	EXPECT_FLOAT_EQ(-4.3f, testVector.Data[0]);
	EXPECT_FLOAT_EQ(6.0f, testVector.Data[1]);
	EXPECT_FLOAT_EQ(1.7f, testVector.Data[2]);
	EXPECT_FLOAT_EQ(0.0f, testVector.Data[3]);
}

TEST(VEC4, ConstructionIJKL)
{
	Math::Vec4 testVector(6.7f, -2.9f, -4.9f, 8.3f);

	EXPECT_FLOAT_EQ(6.7f, testVector.X);
	EXPECT_FLOAT_EQ(-2.9f, testVector.Y);
	EXPECT_FLOAT_EQ(-4.9f, testVector.Z);
	EXPECT_FLOAT_EQ(8.3f, testVector.W);

	EXPECT_FLOAT_EQ(6.7f, testVector.I);
	EXPECT_FLOAT_EQ(-2.9f, testVector.J);
	EXPECT_FLOAT_EQ(-4.9f, testVector.K);
	EXPECT_FLOAT_EQ(8.3f, testVector.L);

	EXPECT_FLOAT_EQ(6.7f, testVector.R);
	EXPECT_FLOAT_EQ(-2.9f, testVector.G);
	EXPECT_FLOAT_EQ(-4.9f, testVector.B);
	EXPECT_FLOAT_EQ(8.3f, testVector.A);

	EXPECT_FLOAT_EQ(6.7f, testVector.Data[0]);
	EXPECT_FLOAT_EQ(-2.9f, testVector.Data[1]);
	EXPECT_FLOAT_EQ(-4.9f, testVector.Data[2]);
	EXPECT_FLOAT_EQ(8.3f, testVector.Data[3]);
}

TEST(VEC4, AssignmentAdition)
{
	Math::Vec4 testVector;

	testVector = vectors[0];
	EXPECT_FLOAT_EQ( 59.5f, testVector.X);
	EXPECT_FLOAT_EQ( 100.0f, testVector.Y);
	EXPECT_FLOAT_EQ( 65.7f, testVector.Z);
	EXPECT_FLOAT_EQ(-77.7f, testVector.W);

	testVector += vectors[1];
	EXPECT_FLOAT_EQ( 21.0f, testVector.X);
	EXPECT_FLOAT_EQ( 44.1f, testVector.Y);
	EXPECT_FLOAT_EQ(-27.8f, testVector.Z);
	EXPECT_FLOAT_EQ(-64.4f, testVector.W);
}

TEST(VEC4, AssignmentSubtraction)
{
	Math::Vec4 testVector;

	testVector = vectors[0];
	EXPECT_FLOAT_EQ(59.5f, testVector.X);
	EXPECT_FLOAT_EQ(100.0f, testVector.Y);
	EXPECT_FLOAT_EQ(65.7f, testVector.Z);
	EXPECT_FLOAT_EQ(-77.7f, testVector.W);

	testVector -= vectors[1];
	EXPECT_FLOAT_EQ( 98.0f, testVector.X);
	EXPECT_FLOAT_EQ(155.9f, testVector.Y);
	EXPECT_FLOAT_EQ(159.2f, testVector.Z);
	EXPECT_FLOAT_EQ(-91.0f, testVector.W);
}

TEST(VEC4, Addition)
{
	Math::Vec4 a = vectors[0];
	Math::Vec4 b = vectors[1];
	Math::Vec4 testVector = a + b;

	EXPECT_FLOAT_EQ( 59.5f, a.X);
	EXPECT_FLOAT_EQ(100.0f, a.Y);
	EXPECT_FLOAT_EQ( 65.7f, a.Z);
	EXPECT_FLOAT_EQ(-77.7f, a.W);

	EXPECT_FLOAT_EQ(-38.5f, b.X);
	EXPECT_FLOAT_EQ(-55.9f, b.Y);
	EXPECT_FLOAT_EQ(-93.5f, b.Z);
	EXPECT_FLOAT_EQ( 13.3f, b.W);

	EXPECT_FLOAT_EQ(21.0f, testVector.X);
	EXPECT_FLOAT_EQ(44.1f, testVector.Y);
	EXPECT_FLOAT_EQ(-27.8f, testVector.Z);
	EXPECT_FLOAT_EQ(-64.4f, testVector.W);
}

TEST(VEC4, Subtraction)
{
	Math::Vec4 a = vectors[0];
	Math::Vec4 b = vectors[1];
	Math::Vec4 testVector = a - b;

	EXPECT_FLOAT_EQ( 59.5f, a.X);
	EXPECT_FLOAT_EQ(100.0f, a.Y);
	EXPECT_FLOAT_EQ( 65.7f, a.Z);
	EXPECT_FLOAT_EQ(-77.7f, a.W);

	EXPECT_FLOAT_EQ(-38.5f, b.X);
	EXPECT_FLOAT_EQ(-55.9f, b.Y);
	EXPECT_FLOAT_EQ(-93.5f, b.Z);
	EXPECT_FLOAT_EQ( 13.3f, b.W);

	EXPECT_FLOAT_EQ(98.0f, testVector.X);
	EXPECT_FLOAT_EQ(155.9f, testVector.Y);
	EXPECT_FLOAT_EQ(159.2f, testVector.Z);
	EXPECT_FLOAT_EQ(-91.0f, testVector.W);
}