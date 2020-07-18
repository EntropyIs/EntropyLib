#include <gtest/gtest.h>
#include <Entropy/Math/Vec3.h>

using namespace Entropy;

Math::Vec3 vectors[]{
	Math::Vec3( 59.5f, 100.0f,  65.7f),
	Math::Vec3(-38.5f, -55.9f, -93.5f),
	Math::Vec3( 55.1f,  46.4f,  77.1f),
	Math::Vec3(-43.2f, -68.2f, -83.0f),
	Math::Vec3(-85.9f, - 4.4f, -68.0f),
	Math::Vec3(-39.5f, -30.0f,  75.2f),
	Math::Vec3( 46.1f, -12.8f,  62.9f),
	Math::Vec3( 91.2f,   3.4f, -47.1f),
	Math::Vec3(-55.7f,  45.3f,  61.0f),
	Math::Vec3(  1.5f, -31.3f, -84.7f),
	Math::Vec3(- 9.3f, -94.5f,  90.0f),
	Math::Vec3(-85.4f, -63.4f,  91.4f),
	Math::Vec3( 23.4f,  53.5f, -49.3f),
	Math::Vec3(-55.5f, - 7.0f,  90.0f),
	Math::Vec3( 98.1f,  57.0f,  78.0f),
	Math::Vec3( 75.9f, -58.4f, -87.2f),
	Math::Vec3( 22.0f,  23.0f,  54.6f),
	Math::Vec3(-14.7f, -50.4f, -67.8f),
	Math::Vec3(-23.6f, - 4.6f,  12.5f),
	Math::Vec3( 34.6f, -58.3f, -13.9f),
	Math::Vec3( 92.5f,  89.5f,  93.5f),
	Math::Vec3( 41.6f,  48.1f,  34.1f),
	Math::Vec3(-90.5f,  38.8f, -85.8f),
	Math::Vec3(-44.0f,  42.8f, -92.6f)
};

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
	EXPECT_FLOAT_EQ(0.0f, textVector.Z);

	EXPECT_FLOAT_EQ(3.9f, textVector.I);
	EXPECT_FLOAT_EQ(-6.7f, textVector.J);
	EXPECT_FLOAT_EQ(0.0f, textVector.K);

	EXPECT_FLOAT_EQ(3.9f, textVector.R);
	EXPECT_FLOAT_EQ(-6.7f, textVector.G);
	EXPECT_FLOAT_EQ(0.0f, textVector.B);

	EXPECT_FLOAT_EQ(3.9f, textVector.Data[0]);
	EXPECT_FLOAT_EQ(-6.7f, textVector.Data[1]);
	EXPECT_FLOAT_EQ(0.0f, textVector.Data[2]);
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

TEST(VEC3, AssignmentAdition)
{
	Math::Vec3 testVector;

	testVector = vectors[0];
	EXPECT_FLOAT_EQ( 59.5f, testVector.X);
	EXPECT_FLOAT_EQ(100.0f, testVector.Y);
	EXPECT_FLOAT_EQ( 65.7f, testVector.Z);

	testVector += vectors[1];
	EXPECT_FLOAT_EQ( 21.0f, testVector.X);
	EXPECT_FLOAT_EQ( 44.1f, testVector.Y);
	EXPECT_FLOAT_EQ(-27.8f, testVector.Z);
}

TEST(VEC3, AssignmentSubtraction)
{
	Math::Vec3 testVector;

	testVector = vectors[0];
	EXPECT_FLOAT_EQ( 59.5f, testVector.X);
	EXPECT_FLOAT_EQ(100.0f, testVector.Y);
	EXPECT_FLOAT_EQ( 65.7f, testVector.Z);

	testVector -= vectors[1];
	EXPECT_FLOAT_EQ( 98.0f, testVector.X);
	EXPECT_FLOAT_EQ(155.9f, testVector.Y);
	EXPECT_FLOAT_EQ(159.2f, testVector.Z);
}

TEST(VEC3, Addition)
{
	Math::Vec3 a = vectors[0];
	Math::Vec3 b = vectors[1];
	Math::Vec3 testVector = a + b;

	EXPECT_FLOAT_EQ( 59.5f, a.X);
	EXPECT_FLOAT_EQ(100.0f, a.Y);
	EXPECT_FLOAT_EQ( 65.7f, a.Z);

	EXPECT_FLOAT_EQ(-38.5f, b.X);
	EXPECT_FLOAT_EQ(-55.9f, b.Y);
	EXPECT_FLOAT_EQ(-93.5f, b.Z);

	EXPECT_FLOAT_EQ(21.0f, testVector.X);
	EXPECT_FLOAT_EQ(44.1f, testVector.Y);
	EXPECT_FLOAT_EQ(-27.8f, testVector.Z);
}

TEST(VEC3, Subtraction)
{
	Math::Vec3 a = vectors[0];
	Math::Vec3 b = vectors[1];
	Math::Vec3 testVector = a - b;

	EXPECT_FLOAT_EQ( 59.5f, a.X);
	EXPECT_FLOAT_EQ(100.0f, a.Y);
	EXPECT_FLOAT_EQ( 65.7f, a.Z);

	EXPECT_FLOAT_EQ(-38.5f, b.X);
	EXPECT_FLOAT_EQ(-55.9f, b.Y);
	EXPECT_FLOAT_EQ(-93.5f, b.Z);

	EXPECT_FLOAT_EQ(98.0f, testVector.X);
	EXPECT_FLOAT_EQ(155.9f, testVector.Y);
	EXPECT_FLOAT_EQ(159.2f, testVector.Z);
}

TEST(VEC3, MultiplicationScalar)
{
	Math::Vec3 vector = vectors[0];
	float scalar = 2.1f;
	Math::Vec3 testVectorA = vector * scalar;
	Math::Vec3 testVectorB = scalar * vector;

	EXPECT_FLOAT_EQ(124.95f, testVectorA.X);
	EXPECT_FLOAT_EQ(210.0f, testVectorA.Y);
	EXPECT_FLOAT_EQ(137.97f, testVectorA.Z);

	EXPECT_FLOAT_EQ(testVectorA.X, testVectorB.X);
	EXPECT_FLOAT_EQ(testVectorA.Y, testVectorB.Y);
	EXPECT_FLOAT_EQ(testVectorA.Z, testVectorB.Z);
}

TEST(VEC3, DotProduct)
{
	Math::Vec3 a = vectors[0];
	Math::Vec3 b = vectors[1];

	float resultA = Math::dot(a, b);
	float resultB = Math::dot(b, a);

	EXPECT_FLOAT_EQ(-14023.7f, resultA);
	EXPECT_FLOAT_EQ(resultA, resultB);
}

TEST(VEC3, Magnitude)
{
	Math::Vec3 testVector = vectors[0];
	float result = Math::magnitude(testVector);

	EXPECT_FLOAT_EQ(133.6291135943f, result);
}

TEST(VEC3, Normalize)
{
	Math::Vec3 a = vectors[0];
	float magnitude = Math::magnitude(a);
	EXPECT_FLOAT_EQ(133.6291135943f, magnitude);

	Math::Vec3 resultVector = Math::normalize(a);

	EXPECT_FLOAT_EQ(0.4452622516f, resultVector.X);
	EXPECT_FLOAT_EQ(0.7483399186f, resultVector.Y);
	EXPECT_FLOAT_EQ(0.4916593265f, resultVector.Z);

	float resultMagnitude = Math::magnitude(resultVector);
	EXPECT_FLOAT_EQ(1.0, resultMagnitude);
}