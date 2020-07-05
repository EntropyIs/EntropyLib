#include <gtest/gtest.h>

TEST(MyAbitraryCatergoyName, MyArbitatyTestName)
{
	int i = 7;
	int j = 10;
	int result = i * j;

	EXPECT_EQ(60, result);
	EXPECT_TRUE(result == 90);
}

TEST(MyAbitraryCatergoyName, SomeOtherTestName)
{

}