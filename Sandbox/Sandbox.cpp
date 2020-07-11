#include <GLWindow.h>
#include <GLShader.h>

#include <Matrix4Ext.h>

using namespace Entropy;
using namespace Entropy::Math;

int main(int argc, char* argv[])
{
	//Initalize OpenGL Window
	GLWindow window(800, 600, "OpenGL Sandbox");
	window.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	//Define Object Verticies
	Vector4 vertices[] = {
		Vector4(0.5f, 0.5f, 0.0f, 1.0f),
		Vector4(0.5f, -0.5f, 0.0f, 1.0f),
		Vector4(-0.5f, -0.5f, 0.0f, 1.0f),
		Vector4(-0.5f, 0.5f, 0.0f, 1.0f)
	};
	//Define Object Tris
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	//Load Object Data into Window
	window.setVertexBufferData(sizeof(vertices), (float*)vertices);
	window.setElementBufferData(sizeof(indices), indices);
	window.setVertexAttributes(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

	//Generate Shader Program
	GLShader shader("v2shader.glsl", "f2Shader.glsl");

	//Graphics Loop
	while (!window.getShouldClose())
	{
		//Input

		//Render
		shader.use();
		window.render();

		//Update

		window.processEvents();
	}
}