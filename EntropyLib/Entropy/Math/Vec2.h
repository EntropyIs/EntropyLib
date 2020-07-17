#pragma once

namespace Entropy
{
	namespace Math
	{
		class _declspec(dllexport) Vec2
		{
		public:
			union
			{
				struct { float I, J; };
				struct { float X, Y; };
				float Data[2];
			};

			Vec2() : I(0.0f), J(0.0f) {};
			Vec2(float value) : I(value), J(value) {};
			Vec2(float i, float j) : I(i), J(j) {};
		};
	}
}