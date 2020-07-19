#include <gtest/gtest.h>
#include <Entropy/Math/Transform2D.h>

using namespace Entropy;

TEST(TRANSFORM2D, MatrixVectorMultiplication)
{
	Math::Vec3 a(1.2f, -2.3f, 1.0f);
	Math::Mat3 m(
		 7.4f,  4.4f,  3.6f,
		-8.3f, -6.8f, -2.3f,
		-1.7f,  2.9f, -9.8f
	);

	Math::Vec3 testVector = m * a;

	EXPECT_FLOAT_EQ(26.27f, testVector.X);
	EXPECT_FLOAT_EQ(23.82f, testVector.Y);
	EXPECT_FLOAT_EQ(-0.19f, testVector.Z);
}