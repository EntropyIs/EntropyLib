#include "Shader.h"

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
Entropy::Shader::Shader(const char* vertexPath, const char* fragmentPath)
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

Entropy::Shader::~Shader()
{
	glDeleteProgram(ID);
}

/**
 * Compiles a given shader unit.
 * @param path, path to shader source code.
 * @param type, type of shader been compiled.
 */
unsigned int Entropy::Shader::compile(const char* path, unsigned int type)
{
	unsigned int compileID;
	std::ifstream file;
	file.exceptions(std::ifstream::failbit || std::ifstream::badbit);
	try
	{
		file.open(path);
		std::stringstream stream;
		stream << file.rdbuf();
		const char* sourceCode = stream.str().c_str();
		compileID = glCreateShader(type);
		glShaderSource(compileID, 1, &sourceCode, NULL);
		int success;
		glGetShaderiv(compileID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char infolog[1024];
			glGetShaderInfoLog(compileID, 1024, NULL, infolog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infolog << std::endl;
		}
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	return compileID;
}
