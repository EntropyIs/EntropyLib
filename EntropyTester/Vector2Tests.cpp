#include <gtest/gtest.h>
#include <Vector2.h>

using namespace Entropy::Math;

TEST(Vector2, Constructor)
{
	Vector2 empty;
	Vector2 a(2.5f, -7.0f);

	EXPECT_FLOAT_EQ(0.0f, empty.i);
	EXPECT_FLOAT_EQ(0.0f, empty.j);

	EXPECT_FLOAT_EQ(2.5f, a.i);
	EXPECT_FLOAT_EQ(-7.0f, a.j);
}

TEST(Vector2, ElementSubtypes)
{
	Vector2 a(2.5f, -7.0f);

	EXPECT_FLOAT_EQ(a.i, a.x);
	EXPECT_FLOAT_EQ(a.j, a.y);
	EXPECT_FLOAT_EQ(a.i, a.data[0]);
	EXPECT_FLOAT_EQ(a.j, a.data[1]);

	a.i = 3.0f;
	EXPECT_FLOAT_EQ(a.i, a.x);
	EXPECT_FLOAT_EQ(a.j, a.y);

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

TEST(Vector2, AssignmentOperator)
{
	Vector2 source(-1, 7);
	Vector2 copy(source);
	EXPECT_FLOAT_EQ(source.i, copy.i);
	EXPECT_FLOAT_EQ(source.j, copy.j);
}

TEST(Vector2, PlusAssignmentOperator)
{
	Vector2 a(-1, 7);
	Vector2 b(-5, 8);

	EXPECT_FLOAT_EQ(-1, a.i);
	EXPECT_FLOAT_EQ(7, a.j);

	a += b;

	EXPECT_FLOAT_EQ(-6, a.i);
	EXPECT_FLOAT_EQ(15, a.j);
}

TEST(Vector2, MinusAssignmentOperator)
{
	Vector2 a(-1, 7);
	Vector2 b(-5, 8);

	EXPECT_FLOAT_EQ(-1, a.i);
	EXPECT_FLOAT_EQ(7, a.j);

	a -= b;

	EXPECT_FLOAT_EQ(4, a.i);
	EXPECT_FLOAT_EQ(-1, a.j);
}