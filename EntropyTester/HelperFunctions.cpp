#include "HelperFunctions.h"
#include <cmath>

bool FLOAT_EQ(float left, float right, float threshold)
{
    return abs(left - right) < threshold;
}
