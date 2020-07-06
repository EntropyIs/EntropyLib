#include <gtest/gtest.h>
#include <Vector2.h>

using namespace Entropy::Math;

TEST(Vector2, Constructor)
{
	Vector2 empty;
	Vector2 unit(1, 1);
	Vector2 value(2, 3);

	EXPECT_EQ(0, empty.i);
	EXPECT_EQ(0, empty.j);

	EXPECT_EQ(1, unit.i);
	EXPECT_EQ(1, unit.j);

	EXPECT_EQ(2, value.i);
	EXPECT_EQ(3, value.j);
}

TEST(Vector2, VectorAddition)
{
	Vector2 a(2, 3);
	Vector2 b(4, 5);

	Vector2 result1 = a + b;
	Vector2 result2 = b + a;

	EXPECT_FLOAT_EQ(6, result1.i);
	EXPECT_FLOAT_EQ(8, result1.j);

	EXPECT_FLOAT_EQ(result1.i, result2.i);
	EXPECT_FLOAT_EQ(result1.j, result2.j);
}

TEST(Vector2, VectorSubtraction)
{
	Vector2 a(2, 3);
	Vector2 b(4, 5);

	Vector2 result1 = a - b;
	Vector2 result2 = b - a;

	EXPECT_FLOAT_EQ(-2, result1.i);
	EXPECT_FLOAT_EQ(-2, result1.j);

	EXPECT_FLOAT_EQ(2, result2.i);
	EXPECT_FLOAT_EQ(2, result2.j);
}

TEST(Vector2, ScalarMultiplycation)
{
	Vector2 a(2, 3);
	float scalar = 3;

	Vector2 result1 = a * scalar;
	Vector2 result2 = scalar * a;

	EXPECT_FLOAT_EQ(6, result1.i);
	EXPECT_FLOAT_EQ(9, result1.j);

	EXPECT_FLOAT_EQ(result1.i, result2.i);
	EXPECT_FLOAT_EQ(result1.j, result2.j);
}