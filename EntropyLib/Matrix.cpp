#include "Matrix.h"

#include <stdlib.h>

Entropy::Math::Matrix::Matrix(size_t numRows, size_t numCols) : numCols(numCols), numRows(numRows)
{
	data = (float*)malloc((numRows * numCols) * sizeof(float));
	for (size_t i = 0; i < numRows * numCols; i++) {
		data[i] = 0.0f;
	}
}

Entropy::Math::Matrix::Matrix(size_t numRows, size_t numCols, const float* data) : numCols(numCols), numRows(numRows)
{
	this->data = (float*)malloc((numRows * numCols) * sizeof(float));
	for (size_t i = 0; i < numRows * numCols; i++) {
		this->data[i] = data[i];
	}
}

float Entropy::Math::Matrix::get(size_t col, size_t row)
{
	return data[(numRows*col)+row];
}
