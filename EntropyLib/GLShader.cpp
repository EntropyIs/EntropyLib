#include "GLShader.h"

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * Loads and Compiles a Shader Program using the defined code files.
 * @param vertexPath, path to vertex shader source code.
 * @param fragmentPath, path to fragment shader source code.
 */
Entropy::GLShader::GLShader(const char* vertexPath, const char* fragmentPath)
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
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infolog[1024];
		glGetProgramInfoLog(ID, 1024, NULL, infolog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infolog << std::endl;
	}
	// Cleanup Memory
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Entropy::GLShader::~GLShader()
{
	glDeleteProgram(ID);
}

void Entropy::GLShader::use()
{
	glUseProgram(ID);
}

/**
 * Compiles a given shader unit.
 * @param path, path to shader source code.
 * @param type, type of shader been compiled.
 */
unsigned int Entropy::GLShader::compile(const char* path, unsigned int type)
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
		glGetShaderiv(compileID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char infolog[1024];
			glGetShaderInfoLog(compileID, 1024, NULL, infolog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infolog << std::endl;
		}
		return compileID;
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
}

/*

void MyShader::setBool(const GLchar* name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name), (int)value);
}

void MyShader::setInt(const GLchar* name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name), value);
}

void MyShader::setFloat(const GLchar* name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name), value);
}

void MyShader::setFloat2(const GLchar* name, float v0, float v1)
{
	glUniform2f(glGetUniformLocation(ID, name), v0, v1);
}

void MyShader::setFloat3(const GLchar* name, float v0, float v1, float v2)
{
	glUniform3f(glGetUniformLocation(ID, name), v0, v1, v2);
}

void MyShader::setFloat4(const GLchar* name, float v0, float v1, float v2, float v3)
{
	glUniform4f(glGetUniformLocation(ID, name), v0, v1, v2, v3);
} */