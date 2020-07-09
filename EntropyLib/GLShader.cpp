#include "GLShader.h"

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Entropy
{
	/**
	 * Loads and Compiles a Shader Program using the defined code files.
	 * @param vertexPath, path to vertex shader source code.
	 * @param fragmentPath, path to fragment shader source code.
	 */
	GLShader::GLShader(const char* vertexPath, const char* fragmentPath)
	{
		// Compile Shaders
		unsigned int vertexShader = compile(vertexPath, GL_VERTEX_SHADER);
		unsigned int fragmentShader = compile(fragmentPath, GL_FRAGMENT_SHADER);

		// Create Program
		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);

		int success;
		char infoLog[1024];
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR:\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}

		// Cleanup Memory
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	GLShader::~GLShader()
	{
		glDeleteProgram(ID);
	}

	void GLShader::use()
	{
		glUseProgram(ID);
	}

	void GLShader::set1Bool(const char* name, bool v0) const
	{
		glUniform1i(glGetUniformLocation(ID, name), (int)v0);
	}

	void GLShader::set2Bool(const char* name, bool v0, bool v1) const
	{
		glUniform2i(glGetUniformLocation(ID, name), (int)v0, (int)v1);
	}

	void GLShader::set3Bool(const char* name, bool v0, bool v1, bool v2) const
	{
		glUniform3i(glGetUniformLocation(ID, name), (int)v0, (int)v1, (int)v2);
	}

	void GLShader::set4Bool(const char* name, bool v0, bool v1, bool v2, bool v3) const
	{
		glUniform4i(glGetUniformLocation(ID, name), v0, v1, v2, v3);
	}

	void GLShader::set1Int(const char* name, int v0) const
	{
		glUniform1i(glGetUniformLocation(ID, name), v0);
	}

	void GLShader::set2Int(const char* name, int v0, int v1) const
	{
		glUniform2i(glGetUniformLocation(ID, name), v0, v1);
	}

	void GLShader::set3Int(const char* name, int v0, int v1, int v2) const
	{
		glUniform3i(glGetUniformLocation(ID, name), v0, v1, v2);
	}

	void GLShader::set4Int(const char* name, int v0, int v1, int v2, int v3) const
	{
		glUniform4i(glGetUniformLocation(ID, name), v0, v1, v2, v3);
	}

	void GLShader::set1Float(const char* name, float v0) const
	{
		glUniform1f(glGetUniformLocation(ID, name), v0);
	}

	void GLShader::set2Float(const char* name, float v0, float v1) const
	{
		glUniform2f(glGetUniformLocation(ID, name), v0, v1);
	}

	void GLShader::set3Float(const char* name, float v0, float v1, float v2) const
	{
		glUniform3f(glGetUniformLocation(ID, name), v0, v1, v2);
	}

	void GLShader::set4Float(const char* name, float v0, float v1, float v2, float v3) const
	{
		glUniform4f(glGetUniformLocation(ID, name), v0, v1, v2, v3);
	}

	void GLShader::setMat4(const char* name, const Math::Matrix4& v0)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, v0.data);
	}

	/**
	 * Compiles a given shader unit.
	 * @param path, path to shader source code.
	 * @param type, type of shader been compiled.
	 */
	unsigned int GLShader::compile(const char* path, unsigned int type)
	{
		std::ifstream file;
		file.exceptions(std::ifstream::failbit || std::ifstream::badbit);
		try
		{
			file.open(path);
			std::stringstream stream;
			stream << file.rdbuf();
			file.close();
			std::string source = stream.str();
			const char* sourceCode = source.c_str();
			unsigned int compileID = glCreateShader(type);
			glShaderSource(compileID, 1, &sourceCode, NULL);

			int success;
			char infoLog[1024];
			glGetShaderiv(compileID, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(compileID, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR:\n" << infoLog << std::endl;
			}

			return compileID;
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER_FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
	}
}