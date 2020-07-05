#include <gtest/gtest.h>
#include <Vector3.h>

using namespace Entropy::Math;

TEST(Vector3, Constructor)
{
	Vector3 empty;
	Vector3 unit(1, 1, 1);
	Vector3 value(2, 3, 4);

	EXPECT_EQ(0, empty.i);
	EXPECT_EQ(0, empty.j);
	EXPECT_EQ(0, empty.k);

	EXPECT_EQ(1, unit.i);
	EXPECT_EQ(1, unit.j);
	EXPECT_EQ(1, unit.k);

	EXPECT_EQ(2, value.i);
	EXPECT_EQ(3, value.j);
	EXPECT_EQ(4, value.k);
}

TEST(Vector3, VectorAddition)
{
	Vector3 a(2, 3, 4);
	Vector3 b(4, 5, 6);

	Vector3 result1 = a + b;
	Vector3 result2 = b + a;

	EXPECT_EQ(6, result1.i);
	EXPECT_EQ(8, result1.j);
	EXPECT_EQ(10, result1.k);

	EXPECT_EQ(result1.i, result2.i);
	EXPECT_EQ(result1.j, result2.j);
	EXPECT_EQ(result1.k, result2.k);
}

TEST(Vector3, ScalarMultiplycation)
{
	Vector3 a(2, 3, 4);
	float scalar = 3;

	Vector3 result1 = a * scalar;
	Vector3 result2 = scalar * a;

	EXPECT_EQ(6, result1.i);
	EXPECT_EQ(9, result1.j);
	EXPECT_EQ(12, result1.k);

	EXPECT_EQ(result1.i, result2.i);
	EXPECT_EQ(result1.j, result2.j);
	EXPECT_EQ(result1.k, result2.k);
}