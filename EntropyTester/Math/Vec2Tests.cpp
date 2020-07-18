#include <gtest/gtest.h>
#include <Entropy/Math/Vec2.h>

using namespace Entropy;

Math::Vec2 vectors[]{
	Math::Vec2( 59.5f, 100.0f),
	Math::Vec2(-38.5f, -55.9f),
	Math::Vec2( 55.1f,  46.4f),
	Math::Vec2(-43.2f, -68.2f),
	Math::Vec2(-85.9f, - 4.4f),
	Math::Vec2(-39.5f, -30.0f),
	Math::Vec2( 46.1f, -12.8f),
	Math::Vec2( 91.2f,   3.4f),
	Math::Vec2(-55.7f,  45.3f),
	Math::Vec2(  1.5f, -31.3f),
	Math::Vec2(- 9.3f, -94.5f),
	Math::Vec2(-85.4f, -63.4f),
	Math::Vec2( 23.4f,  53.5f),
	Math::Vec2(-55.5f, - 7.0f),
	Math::Vec2( 98.1f,  57.0f),
	Math::Vec2( 75.9f, -58.4f),
	Math::Vec2( 22.0f,  23.0f),
	Math::Vec2(-14.7f, -50.4f),
	Math::Vec2(-23.6f, - 4.6f),
	Math::Vec2( 34.6f, -58.3f),
	Math::Vec2( 92.5f,  89.5f),
	Math::Vec2( 41.6f,  48.1f),
	Math::Vec2(-90.5f,  38.8f),
	Math::Vec2(-44.0f,  42.8f),
};

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

TEST(VEC2, AssignmentAdition)
{
	Math::Vec2 testVector;

	testVector = vectors[0];
	EXPECT_FLOAT_EQ(59.5f, testVector.X);
	EXPECT_FLOAT_EQ(100.0f, testVector.Y);

	testVector += vectors[1];
	EXPECT_FLOAT_EQ(21.0f, testVector.X);
	EXPECT_FLOAT_EQ(44.1f, testVector.Y);
}

TEST(VEC2, AssignmentSubtraction)
{
	Math::Vec2 testVector;

	testVector = vectors[0];
	EXPECT_FLOAT_EQ( 59.5f, testVector.X);
	EXPECT_FLOAT_EQ(100.0f, testVector.Y);

	testVector -= vectors[1];
	EXPECT_FLOAT_EQ( 98.0f, testVector.X);
	EXPECT_FLOAT_EQ(155.9f, testVector.Y);
}

TEST(VEC2, Addition)
{
	Math::Vec2 a = vectors[0];
	Math::Vec2 b = vectors[1];
	Math::Vec2 testVector = a + b;

	EXPECT_FLOAT_EQ( 59.5f, a.X);
	EXPECT_FLOAT_EQ(100.0f, a.Y);

	EXPECT_FLOAT_EQ(-38.5f, b.X);
	EXPECT_FLOAT_EQ(-55.9f, b.Y);

	EXPECT_FLOAT_EQ(21.0f, testVector.X);
	EXPECT_FLOAT_EQ(44.1f, testVector.Y);
}

TEST(VEC2, Subtraction)
{
	Math::Vec2 a = vectors[0];
	Math::Vec2 b = vectors[1];
	Math::Vec2 testVector = a - b;

	EXPECT_FLOAT_EQ(59.5f, a.X);
	EXPECT_FLOAT_EQ(100.0f, a.Y);

	EXPECT_FLOAT_EQ(-38.5f, b.X);
	EXPECT_FLOAT_EQ(-55.9f, b.Y);

	EXPECT_FLOAT_EQ(98.0f, testVector.X);
	EXPECT_FLOAT_EQ(155.9f, testVector.Y);
}