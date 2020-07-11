#pragma once

namespace Entropy
{
	namespace Math
	{
		class __declspec(dllexport) Matrix4
		{
		public:
			union
			{
				struct
				{
					float r0c0; float r1c0; float r2c0; float r3c0;
					float r0c1; float r1c1; float r2c1; float r3c1;
					float r0c2; float r1c2; float r2c2; float r3c2;
					float r0c3; float r1c3; float r2c3; float r3c3;
				};
				float data[16];
			};

			Matrix4(
				float r0c0 = 1, float r0c1 = 0, float r0c2 = 0, float r0c3 = 0,
				float r1c0 = 0, float r1c1 = 1, float r1c2 = 0, float r1c3 = 0,
				float r2c0 = 0, float r2c1 = 0, float r2c2 = 1, float r2c3 = 0,
				float r3c0 = 0, float r3c1 = 0, float r3c2 = 0, float r3c3 = 1) :
				r0c0(r0c0), r0c1(r0c1), r0c2(r0c2), r0c3(r0c3),
				r1c0(r1c0), r1c1(r1c1), r1c2(r1c2), r1c3(r1c3),
				r2c0(r2c0), r2c1(r2c1), r2c2(r2c2), r2c3(r2c3), 
				r3c0(r3c0), r3c1(r3c1), r3c2(r3c2), r3c3(r3c3) {}
		};
		
		Matrix4 __declspec(dllexport) operator* (const Matrix4& left, const Matrix4& right);
		Matrix4 __declspec(dllexport) operator+ (const Matrix4& left, const Matrix4& right);
		Matrix4 __declspec(dllexport) operator- (const Matrix4& left, const Matrix4& right);
	}
}


