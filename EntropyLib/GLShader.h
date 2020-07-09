#pragma once

#include "Matrix4.h"

namespace Entropy
{
	class __declspec(dllexport) GLShader
	{
	public:
		unsigned int ID;

		GLShader(const char* vertexPath, const char* fragmentPath);
		~GLShader();

		void use();

		void set1Bool(const char* name, bool v0) const;
		void set2Bool(const char* name, bool v0, bool v1) const;
		void set3Bool(const char* name, bool v0, bool v1, bool v2) const;
		void set4Bool(const char* name, bool v0, bool v1, bool v2, bool v3) const;

		void set1Int(const char* name, int v0) const;
		void set2Int(const char* name, int v0, int v1) const;
		void set3Int(const char* name, int v0, int v1, int v2) const;
		void set4Int(const char* name, int v0, int v1, int v2, int v3) const;

		void set1Float(const char* name, float v0) const;
		void set2Float(const char* name, float v0, float v1) const;
		void set3Float(const char* name, float v0, float v1, float v2) const;
		void set4Float(const char* name, float v0, float v1, float v2, float v3) const;

		void setMat4(const char* name, const Math::Matrix4& v0);

	private:
		unsigned int compile(const char* path, unsigned int type);
	};
}