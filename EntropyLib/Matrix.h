#pragma once

namespace Entropy
{
	namespace Math
	{
		class __declspec(dllexport)Matrix
		{
		public:
			size_t numRows;
			size_t numCols;
			float* data;

			Matrix(size_t numRows, size_t numCols);
			Matrix(size_t numRows, size_t numCols, const float* data);

			float get(size_t col, size_t row);
		};
		
	}
}