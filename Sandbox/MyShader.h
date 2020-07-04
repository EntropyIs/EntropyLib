#pragma once

#include <glad/glad.h>

#include <string>

class MyShader
{
public:
	unsigned int ID;

	MyShader(const char* vertexPath, const char* fragmentPath);
	~MyShader();

	void use();

	void setBool(const GLchar* name, bool value) const;
	void setInt(const GLchar* name, int value) const;
	void setFloat(const GLchar* name, float value) const;
};

