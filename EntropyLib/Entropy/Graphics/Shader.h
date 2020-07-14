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
			Shader(std::vector<const char*> shaderPath, std::vector<unsigned int> shaderType);
			void use();

			void setBool(const char* name, bool v0) const;
			void setInt(const char* name, int v0) const;
			void setFloat(const char* name, float v0) const;

			void setVec2(const char* name, const Math::Vector2& v0) const;
			void setVec3(const char* name, const Math::Vector3& v0) const;
			void setVec4(const char* name, const Math::Vector4& v0) const;

			void setMat2(const char* name, const Math::Matrix2& v0) const;
			void setMat3(const char* name, const Math::Matrix3& v0) const;
			void setMat4(const char* name, const Math::Matrix4& v0) const;
		};
	}
}