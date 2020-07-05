#pragma once

namespace Entropy
{
	class __declspec(dllexport) GLShader
	{
	public:
		unsigned int ID;

		GLShader(const char* vertexPath, const char* fragmentPath);
		~GLShader();

		void use();

	private:
		unsigned int compile(const char* path, unsigned int type);
	};
}