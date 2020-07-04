#include "MyShader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>

#include <iostream>

MyShader::MyShader(const char* vertexPath, const char* fragmentPath)
{
	// Read shaders from file.
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);

	try
	{
		std::stringstream vShaderStream;
		std::stringstream fShaderStream;
		// Open file
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		// Read from files
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// Close files
		vShaderFile.close();
		fShaderFile.close();
		// Convert to string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// Compile Shaders
	// Compile Vertex Shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Compile Fragment Shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Compile and link Shader Program
	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER_PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}

	// Free shader compilations from memory
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

MyShader::~MyShader()
{
	glDeleteProgram(ID);
}

void MyShader::use()
{
	glUseProgram(ID);
}

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
}

