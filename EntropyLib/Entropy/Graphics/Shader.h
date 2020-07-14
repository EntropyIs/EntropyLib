#pragma once

#include "../../Vector2.h"
#include "../../Vector3.h"
#include "../../Vector4.h"
#include "../../Matrix2.h"
#include "../../Matrix3.h"
#include "../../Matrix4.h"

#include <vector>

namespace Entropy
{
	namespace Graphics
	{
		class __declspec(dllexport) Shader
		{
		private:
			unsigned int ID;

			unsigned int compile(const char* path, unsigned int type);
		public:
			Shader(std::vector<char*> shaderPath, std::vector<unsigned int> shaderType);
			void use();
		};
	}
}