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

	EXPECT_FLOAT_EQ(6, result1.i);
	EXPECT_FLOAT_EQ(8, result1.j);
	EXPECT_FLOAT_EQ(10, result1.k);

	EXPECT_FLOAT_EQ(result1.i, result2.i);
	EXPECT_FLOAT_EQ(result1.j, result2.j);
	EXPECT_FLOAT_EQ(result1.k, result2.k);
}

TEST(Vector3, VectorSubtraction)
{
	Vector3 a(2, 3, 4);
	Vector3 b(4, 5, 6);

	Vector3 result1 = a - b;
	Vector3 result2 = b - a;

	EXPECT_FLOAT_EQ(-2, result1.i);
	EXPECT_FLOAT_EQ(-2, result1.j);
	EXPECT_FLOAT_EQ(-2, result1.k);

	EXPECT_FLOAT_EQ(2, result2.i);
	EXPECT_FLOAT_EQ(2, result2.j);
	EXPECT_FLOAT_EQ(2, result2.k);
}

TEST(Vector3, ScalarMultiplycation)
{
	Vector3 a(2, 3, 4);
	float scalar = 3;

	Vector3 result1 = a * scalar;
	Vector3 result2 = scalar * a;

	EXPECT_FLOAT_EQ(6, result1.i);
	EXPECT_FLOAT_EQ(9, result1.j);
	EXPECT_FLOAT_EQ(12, result1.k);

	EXPECT_FLOAT_EQ(result1.i, result2.i);
	EXPECT_FLOAT_EQ(result1.j, result2.j);
	EXPECT_FLOAT_EQ(result1.k, result2.k);
}

TEST(Vector3, DotProduct)
{
	Vector3 a(-1, 7, 4);
	Vector3 b(-5, 8, 4);

	float dotProduct = dot(a,b);
	
	EXPECT_FLOAT_EQ(77, dotProduct);
}

TEST(Vector3, CrossProduct)
{
	Vector3 a(-1, 7, 4);
	Vector3 b(-5, 8, 4);

	Vector3 crossProduct = cross(a,b);

	EXPECT_FLOAT_EQ(-4, crossProduct.i);
	EXPECT_FLOAT_EQ(-16, crossProduct.j);
	EXPECT_FLOAT_EQ(27, crossProduct.k);
}

TEST(Vector3, Magnitude)
{
	Vector3 a(-1, 7, 4);

	float magnitude = a.magnitude();

	EXPECT_FLOAT_EQ(8.12404f, magnitude);
}

TEST(Vector3, UnitVector)
{
	Vector3 a(-1, 7, 4);

	Vector3 unit = normalize(a);

	EXPECT_FLOAT_EQ(1, unit.magnitude());
}

TEST(Vector3, AssignmentOperator)
{
	Vector3 source(-1, 7, 4);
	Vector3 copy(source);
	EXPECT_FLOAT_EQ(source.i, copy.i);
	EXPECT_FLOAT_EQ(source.j, copy.j);
	EXPECT_FLOAT_EQ(source.k, copy.k);
}

TEST(Vector3, PlusAssignmentOperator)
{
	Vector3 a(-1, 7, 4);
	Vector3 b(-5, 8, 4);

	EXPECT_FLOAT_EQ(-1, a.i);
	EXPECT_FLOAT_EQ(7, a.j);
	EXPECT_FLOAT_EQ(4, a.k);

	a += b;

	EXPECT_FLOAT_EQ(-6, a.i);
	EXPECT_FLOAT_EQ(15, a.j);
	EXPECT_FLOAT_EQ(8, a.k);
}

TEST(Vector3, MinusAssignmentOperator)
{
	Vector3 a(-1, 7, 4);
	Vector3 b(-5, 8, 4);

	EXPECT_FLOAT_EQ(-1, a.i);
	EXPECT_FLOAT_EQ(7, a.j);
	EXPECT_FLOAT_EQ(4, a.k);

	a -= b;

	EXPECT_FLOAT_EQ(4, a.i);
	EXPECT_FLOAT_EQ(-1, a.j);
	EXPECT_FLOAT_EQ(0, a.k);
}