#include <gtest/gtest.h>
#include <Entropy/Math/Vec3.h>

using namespace Entropy;

TEST(VEC3, ConstructionEmpty)
{
	Math::Vec3 empty;

	EXPECT_FLOAT_EQ(0.0f, empty.X);
	EXPECT_FLOAT_EQ(0.0f, empty.Y);
	EXPECT_FLOAT_EQ(0.0f, empty.Z);

	EXPECT_FLOAT_EQ(0.0f, empty.I);
	EXPECT_FLOAT_EQ(0.0f, empty.J);
	EXPECT_FLOAT_EQ(0.0f, empty.K);

	EXPECT_FLOAT_EQ(0.0f, empty.R);
	EXPECT_FLOAT_EQ(0.0f, empty.G);
	EXPECT_FLOAT_EQ(0.0f, empty.B);

	EXPECT_FLOAT_EQ(0.0f, empty.Data[0]);
	EXPECT_FLOAT_EQ(0.0f, empty.Data[1]);
	EXPECT_FLOAT_EQ(0.0f, empty.Data[2]);
}

TEST(VEC3, ConstructionValue)
{
	Math::Vec3 value(4.7f);

	EXPECT_FLOAT_EQ(4.7f, value.X);
	EXPECT_FLOAT_EQ(4.7f, value.Y);
	EXPECT_FLOAT_EQ(4.7f, value.Z);

	EXPECT_FLOAT_EQ(4.7f, value.I);
	EXPECT_FLOAT_EQ(4.7f, value.J);
	EXPECT_FLOAT_EQ(4.7f, value.K);

	EXPECT_FLOAT_EQ(4.7f, value.R);
	EXPECT_FLOAT_EQ(4.7f, value.G);
	EXPECT_FLOAT_EQ(4.7f, value.B);

	EXPECT_FLOAT_EQ(4.7f, value.Data[0]);
	EXPECT_FLOAT_EQ(4.7f, value.Data[1]);
	EXPECT_FLOAT_EQ(4.7f, value.Data[2]);
}

TEST(VEC3, ConstructionIJ)
{
	Math::Vec3 textVector(3.9f, -6.7f);

	EXPECT_FLOAT_EQ(3.9f, textVector.X);
	EXPECT_FLOAT_EQ(-6.7f, textVector.Y);
	EXPECT_FLOAT_EQ(1.0f, textVector.Z);

	EXPECT_FLOAT_EQ(3.9f, textVector.I);
	EXPECT_FLOAT_EQ(-6.7f, textVector.J);
	EXPECT_FLOAT_EQ(1.0f, textVector.K);

	EXPECT_FLOAT_EQ(3.9f, textVector.R);
	EXPECT_FLOAT_EQ(-6.7f, textVector.G);
	EXPECT_FLOAT_EQ(1.0f, textVector.B);

	EXPECT_FLOAT_EQ(3.9f, textVector.Data[0]);
	EXPECT_FLOAT_EQ(-6.7f, textVector.Data[1]);
	EXPECT_FLOAT_EQ(1.0f, textVector.Data[2]);
}

TEST(VEC3, ConstructionIJK)
{
	Math::Vec3 testVector(5.7f, -1.3f, 3.4f);

	EXPECT_FLOAT_EQ(5.7f, testVector.X);
	EXPECT_FLOAT_EQ(-1.3f, testVector.Y);
	EXPECT_FLOAT_EQ(3.4f, testVector.Z);

	EXPECT_FLOAT_EQ(5.7f, testVector.I);
	EXPECT_FLOAT_EQ(-1.3f, testVector.J);
	EXPECT_FLOAT_EQ(3.4f, testVector.K);

	EXPECT_FLOAT_EQ(5.7f, testVector.R);
	EXPECT_FLOAT_EQ(-1.3f, testVector.G);
	EXPECT_FLOAT_EQ(3.4f, testVector.B);

	EXPECT_FLOAT_EQ(5.7f, testVector.Data[0]);
	EXPECT_FLOAT_EQ(-1.3f, testVector.Data[1]);
	EXPECT_FLOAT_EQ(3.4f, testVector.Data[2]);
}