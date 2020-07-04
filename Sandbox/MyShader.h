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
	void setFloat2(const GLchar* name, float v0, float v1);
	void setFloat3(const GLchar* name, float v0, float v1, float v2);
	void setFloat4(const GLchar* name, float v0, float v1, float v2, float v3);
};

