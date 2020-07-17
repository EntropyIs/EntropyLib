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