#include <gtest/gtest.h>
#include <Entropy/Math/Vec2.h>

using namespace Entropy;

TEST(VEC2, ConstructionEmpty)
{
	Math::Vec2 empty;

	EXPECT_FLOAT_EQ(0.0f, empty.X);
	EXPECT_FLOAT_EQ(0.0f, empty.Y);

	EXPECT_FLOAT_EQ(0.0f, empty.I);
	EXPECT_FLOAT_EQ(0.0f, empty.J);

	EXPECT_FLOAT_EQ(0.0f, empty.Data[0]);
	EXPECT_FLOAT_EQ(0.0f, empty.Data[1]);
}

TEST(VEC2, ConstructionValue)
{
	Math::Vec2 value(1.3f);

	EXPECT_FLOAT_EQ(1.3f, value.X);
	EXPECT_FLOAT_EQ(1.3f, value.Y);

	EXPECT_FLOAT_EQ(1.3f, value.I);
	EXPECT_FLOAT_EQ(1.3f, value.J);

	EXPECT_FLOAT_EQ(1.3f, value.Data[0]);
	EXPECT_FLOAT_EQ(1.3f, value.Data[1]);
}

TEST(VEC2, ConstructionIJ)
{
	Math::Vec2 testVector(2.5f, -7.9f);

	EXPECT_FLOAT_EQ(2.5f, testVector.X);
	EXPECT_FLOAT_EQ(-7.9f, testVector.Y);

	EXPECT_FLOAT_EQ(2.5f, testVector.I);
	EXPECT_FLOAT_EQ(-7.9f, testVector.J);

	EXPECT_FLOAT_EQ(2.5f, testVector.Data[0]);
	EXPECT_FLOAT_EQ(-7.9f, testVector.Data[1]);
}