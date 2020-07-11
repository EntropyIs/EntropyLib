#include <gtest/gtest.h>

#include <Matrix.h>

using namespace Entropy::Math;

TEST(Matrix, EmptyConstruction)
{
	Matrix empty(2, 3); // Empty 2 * 3 Matrix, data should be initalized to zeros.

	EXPECT_TRUE(empty.numRows == 2);
	EXPECT_TRUE(empty.numCols == 3);
	for (size_t i = 0; i < 6; i++)
		EXPECT_FLOAT_EQ(empty.data[i], 0.0f);
}

TEST(Matrix, BasicConstuction)
{
	float data[6] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	Matrix matrix(2, 3, data);

	EXPECT_TRUE(matrix.numRows == 2);
	EXPECT_TRUE(matrix.numCols == 3);
	for (size_t i = 0; i < 6; i++)
		EXPECT_FLOAT_EQ(matrix.data[i], data[i]);
}

TEST(Matrix, GetValue)
{
	// | 0 2 4 |
	// | 1 3 4 |
	float data[6] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	Matrix matrix(2, 3, data);

	EXPECT_TRUE(matrix.numRows == 2);
	EXPECT_TRUE(matrix.numCols == 3);

	// Get float at index (column, row)
	EXPECT_FLOAT_EQ(matrix.get(0, 0), data[0]); EXPECT_FLOAT_EQ(matrix.get(1, 0), data[2]); EXPECT_FLOAT_EQ(matrix.get(2, 0), data[4]);
	EXPECT_FLOAT_EQ(matrix.get(0, 1), data[1]); EXPECT_FLOAT_EQ(matrix.get(1, 1), data[3]); EXPECT_FLOAT_EQ(matrix.get(2, 1), data[5]);
}