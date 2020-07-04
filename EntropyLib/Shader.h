#pragma once

namespace Entropy
{
	class __declspec(dllexport) Shader
	{
	public:
		unsigned int ID;

		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

	private:
		unsigned int compile(const char* path, unsigned int type);
	};
}