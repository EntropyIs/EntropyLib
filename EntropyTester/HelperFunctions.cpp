#include "HelperFunctions.h"
#include <gtest/gtest.h>
#include <cmath>

void FLOAT_EQ(float left, float right, float threshold)
{
    EXPECT_NEAR(left, right, threshold);
}
