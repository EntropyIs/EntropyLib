#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "MyGLKeys.h"

class MyGlWindow
{
private:
	GLFWwindow* glWindow;
public:
	MyGlWindow(int width, int height, const char* title);
	~MyGlWindow();

	void processEvents();

	bool getShouldClose();
	bool getKeyPressed(GLKeys key);

	void setWindowShouldClose(bool value);
	void setWindowClearColor(GLfloat red, GLfloat blue, GLfloat green, GLfloat alpha);

	void render();

protected:
	void createWindow(int width, int height, const char* title);
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

