#include "Shader.h"

#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <cassert>
#include <cstring>

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

			std::string errString = "Error Compiling " + shaderType + ".\n" + std::string(path) + "\n" + errorLog;
			throw std::exception(errString.c_str());
		}
		return compileID;
	}
	catch (std::ifstream::failure e)
	{
		std::string errString = "Shader file, " + std::string(path) + ", not succefully read.";
#ifdef DEBUG
		std::cout << errString << std::endl;
#endif // DEBUG
		throw std::exception(errString.c_str());
	}
}

Entropy::Graphics::Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometaryShaderPath)
{
	try
	{
		// Compile Shaders
		std::vector<unsigned int> compilations;
		compilations.push_back(compile(vertexShaderPath, GL_VERTEX_SHADER));
		compilations.push_back(compile(fragmentShaderPath, GL_FRAGMENT_SHADER));
		if(geometaryShaderPath != nullptr)
			compilations.push_back(compile(geometaryShaderPath, GL_GEOMETRY_SHADER));

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
			int maxLength;
			glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &maxLength);
			char* errorLog = new char[maxLength];
			glGetProgramInfoLog(ID, maxLength, &maxLength, errorLog);
			glDeleteShader(ID);

			std::string errString = "Error linking shader program.\n";
			errString.append(vertexShaderPath);
			errString.append(", ");
			errString.append(fragmentShaderPath);
			if (geometaryShaderPath != nullptr)
			{
				errString.append(", ");
				errString.append(geometaryShaderPath);
			}
			errString.append(".\n");
			errString.append(errorLog);
			throw std::exception(errString.c_str());
		}

		for (unsigned int i = 0; i < compilations.size(); i++)
			glDeleteShader(compilations[i]);
	}
	catch (std::exception e)
	{
		throw e;
	}
}

void Entropy::Graphics::Shader::use() const
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

void Entropy::Graphics::Shader::setVec2(const char* name, const Math::Vec2& v0) const
{
	glUniform2fv(glGetUniformLocation(ID, name), 1, v0.Data);
}

void Entropy::Graphics::Shader::setVec3(const char* name, const Math::Vec3& v0) const
{
	glUniform3fv(glGetUniformLocation(ID, name), 1, v0.Data);
}

void Entropy::Graphics::Shader::setVec4(const char* name, const Math::Vec4& v0) const
{
	glUniform4fv(glGetUniformLocation(ID, name), 1, v0.Data);
}

void Entropy::Graphics::Shader::setMat2(const char* name, const Math::Mat2& v0) const
{
	glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, v0.Data);
}

void Entropy::Graphics::Shader::setMat3(const char* name, const Math::Mat3& v0) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, v0.Data);
}

void Entropy::Graphics::Shader::setMat4(const char* name, const Math::Mat4& v0) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, v0.Data);
}

void Entropy::Graphics::Shader::setMaterial(const Material& v0) const
{
	setVec3("material.color_ambient", v0.Ambient);
	setVec3("material.color_diffuse", v0.Diffuse);
	setVec3("material.color_specular", v0.Specular);
	setFloat("material.shininess", v0.Shininess);
}

void Entropy::Graphics::Shader::setDirectionalLight(const DirectionalLight& v0) const
{
	setVec3("directionalLight.direction", v0.Direction);
	setVec3("directionalLight.ambient", v0.Ambient);
	setVec3("directionalLight.diffuse", v0.Diffuse);
	setVec3("directionalLight.specular", v0.Specular);

	setBool("directionalLight.use", true);
}

void Entropy::Graphics::Shader::setPointLight(unsigned int index, const PointLight& v0) const
{
	setVec3(std::string("pointLights[").append(std::to_string(index)).append("].position").c_str(), v0.Position);

	setFloat(std::string("pointLights[").append(std::to_string(index)).append("].constant").c_str(), v0.Constant);
	setFloat(std::string("pointLights[").append(std::to_string(index)).append("].Linear").c_str(), v0.Constant);
	setFloat(std::string("pointLights[").append(std::to_string(index)).append("].quadratic").c_str(), v0.Constant);

	setVec3(std::string("pointLights[").append(std::to_string(index)).append("].ambient").c_str(), v0.Ambient);
	setVec3(std::string("pointLights[").append(std::to_string(index)).append("].diffuse").c_str(), v0.Diffuse);
	setVec3(std::string("pointLights[").append(std::to_string(index)).append("].specular").c_str(), v0.Specular);

	setBool(std::string("pointLights[").append(std::to_string(index)).append("].use").c_str(), true);
}

void Entropy::Graphics::Shader::setSpotLight(unsigned int index, const SpotLight& v0) const
{
	setVec3(std::string("spotLights[").append(std::to_string(index)).append("].position").c_str(), v0.Position);
	setVec3(std::string("spotLights[").append(std::to_string(index)).append("].direction").c_str(), v0.Direction);

	setFloat(std::string("spotLights[").append(std::to_string(index)).append("].InnerCutOff").c_str(), v0.InnerCutOff);
	setFloat(std::string("spotLights[").append(std::to_string(index)).append("].outerCutOff").c_str(), v0.OuterCutOff);

	setVec3(std::string("spotLights[").append(std::to_string(index)).append("].ambient").c_str(), v0.Ambient);
	setVec3(std::string("spotLights[").append(std::to_string(index)).append("].diffuse").c_str(), v0.Diffuse);
	setVec3(std::string("spotLights[").append(std::to_string(index)).append("].specular").c_str(), v0.Specular);

	setBool(std::string("spotLights[").append(std::to_string(index)).append("].use").c_str(), true);
}

void Entropy::Graphics::Shader::setUniformBlockBinding(const char* name, unsigned int v0) const
{
	glUniformBlockBinding(ID, getUniformBlockIndex(name), v0);
}

unsigned int Entropy::Graphics::Shader::getUniformBlockIndex(const char* name) const
{
	return glGetUniformBlockIndex(ID, name);
}
