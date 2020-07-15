#include "Shader.h"

#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <cassert>

unsigned int Entropy::Graphics::Shader::compile(const char* path, unsigned int type)
{
	try
	{
		// Read from file
		std::ifstream inFile(path);
		inFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);
		std::stringstream inStream;
		inStream << inFile.rdbuf();
		inFile.close();
		std::string shaderSource = inStream.str();
		const char* shaderCode = shaderSource.c_str();

		// Compile Shader
		unsigned int compileID = glCreateShader(type);
		glShaderSource(compileID, 1, &shaderCode, NULL);
		glCompileShader(compileID);

		// Check for errors
		int isCompiled;
		glGetShaderiv(compileID, GL_COMPILE_STATUS, &isCompiled);
		if (!isCompiled)
		{
			int maxLength;
			glGetShaderiv(compileID, GL_INFO_LOG_LENGTH, &maxLength);
			char* errorLog = new char[maxLength];
			glGetShaderInfoLog(compileID, maxLength, &maxLength, errorLog);
			glDeleteShader(compileID);

			std::string shaderType = "Shader";
			if (type == GL_VERTEX_SHADER)
				shaderType = "Vertex Shader";
			else if (type == GL_GEOMETRY_SHADER)
				shaderType = "Geomerty Shader";
			else if (type == GL_FRAGMENT_SHADER)
				shaderType = "Fragment Shader";
#ifdef _DEBUG
			std::cout << "Error Compiling " << shaderType << std::endl;
			std::cout << errorLog << std::endl;
			std::cout << "-- --------------------------------------------------- --" << std::endl;
#endif
			std::string errString = "Error Compiling " + shaderType + ".";
			throw std::exception(errString.c_str());
		}
		return compileID;
	}
	catch (std::ifstream::failure e)
	{
		std::string errString = "Shader file, " + std::string(path) + ", not succefully read.";
#ifdef _DEBUG
		std::cout << errString << std::endl;
#endif // _DEBUG
		throw std::exception(errString.c_str());
	}
}

Entropy::Graphics::Shader::Shader(std::vector<const char*> shaderPath, std::vector<unsigned int> shaderType)
{
	try
	{
		// Compile Shaders
		assert(shaderPath.size() == shaderType.size());
		std::vector<unsigned int> compilations;
		for (unsigned int i = 0; i < shaderPath.size(); i++)
			compilations.push_back(compile(shaderPath[i], shaderType[i]));

		// Construct Program
		ID = glCreateProgram();
		for (unsigned int i = 0; i < compilations.size(); i++)
			glAttachShader(ID, compilations[i]);
		glLinkProgram(ID);

		// Check for errors
		int isLinked;
		glGetProgramiv(ID, GL_LINK_STATUS, &isLinked);
		if (!isLinked)
		{
#ifdef _DEBUG
			int maxLength;
			glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &maxLength);
			char* errorLog = new char[maxLength];
			glGetProgramInfoLog(ID, maxLength, &maxLength, errorLog);
			glDeleteShader(ID);

			std::cout << "Error linking shader program:" << std::endl;
			std::cout << errorLog << std::endl;
			std::cout << "-- --------------------------------------------------- --" << std::endl;
#endif
			throw "Error linking shader program.";
		}

		for (unsigned int i = 0; i < compilations.size(); i++)
			glDeleteShader(compilations[i]);
	}
	catch (std::exception e)
	{
		throw e;
	}
}

void Entropy::Graphics::Shader::use()
{
	glUseProgram(ID);
}

void Entropy::Graphics::Shader::setBool(const char* name, bool v0) const
{
	glUniform1i(glGetUniformLocation(ID, name), (int) v0);
}

void Entropy::Graphics::Shader::setInt(const char* name, int v0) const
{
	glUniform1i(glGetUniformLocation(ID, name), v0);
}

void Entropy::Graphics::Shader::setFloat(const char* name, float v0) const
{
	glUniform1f(glGetUniformLocation(ID, name), v0);
}

void Entropy::Graphics::Shader::setVec2(const char* name, const Math::Vector2& v0) const
{
	glUniform2fv(glGetUniformLocation(ID, name), 1, v0.data);
}

void Entropy::Graphics::Shader::setVec3(const char* name, const Math::Vector3& v0) const
{
	glUniform3fv(glGetUniformLocation(ID, name), 1, v0.data);
}

void Entropy::Graphics::Shader::setVec4(const char* name, const Math::Vector4& v0) const
{
	glUniform4fv(glGetUniformLocation(ID, name), 1, v0.data);
}

void Entropy::Graphics::Shader::setMat2(const char* name, const Math::Matrix2& v0) const
{
	glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, v0.data);
}

void Entropy::Graphics::Shader::setMat3(const char* name, const Math::Matrix3& v0) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, v0.data);
}

void Entropy::Graphics::Shader::setMat4(const char* name, const Math::Matrix4& v0) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, v0.data);
}
