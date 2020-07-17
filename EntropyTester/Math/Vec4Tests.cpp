#include <gtest/gtest.h>
#include <Entropy/Math/Vec4.h>

using namespace Entropy;

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