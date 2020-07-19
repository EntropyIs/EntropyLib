#include "HelperFunctions.h"
#include <gtest/gtest.h>

void FLOAT_EQ(float left, float right, float threshold)
{
	EXPECT_NEAR(left, right, threshold);
}
