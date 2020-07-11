#include <GLWindow.h>
#include <GLShader.h>
#include <GLTexture.h>
#include <Matrix4Ext.h>
#include <Converters.h>

using namespace Entropy;
using namespace Entropy::Math;

int main(int argc, char* argv[])
{
	//Initalize OpenGL Window
	GLWindow window(800, 600, "OpenGL Sandbox");
	window.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	//Define Object Verticies
	Vector4 vertices[] = {
		Vector4(0.5f, 0.5f, 0.0f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f), //top-right
		Vector4(0.5f, -0.5f, 0.0f, 1.0f), Vector4(0.0f,  1.0f,  0.0f,  1.0f), Vector4(1.0f, 0.0f), //bottom-right
		Vector4(-0.5f, -0.5f, 0.0f, 1.0f), Vector4(0.0f,  0.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f), //bottom-left
		Vector4(-0.5f, 0.5f, 0.0f, 1.0f), Vector4(1.0f,  1.0f,  0.0f,  1.0f), Vector4(0.0f, 1.0f)  //top-left
	};
	//Define Object Tris
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	//Load Object Data into Window
	window.setVertexBufferData(sizeof(vertices), (float*)vertices);
	window.setElementBufferData(sizeof(indices), indices);
	window.setVertexAttributes(0, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
	window.setVertexAttributes(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(4 * sizeof(float)));
	window.setVertexAttributes(2, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(8 * sizeof(float)));

	//Generate Shader Program
	GLShader shader("vshader.glsl", "fShader.glsl");

	//Load Textures
	Entropy::Texture tex0("assets/wall.bmp");
	Entropy::Texture tex1("assets/spiral.bmp");

	shader.use();
	shader.set1Int("tex0", 0);
	shader.set1Int("tex1", 1);

	//Setup Transformations
	Matrix4 model = RotationAboutXMatrix(radians(-55.0f));
	Matrix4 view = TranslationMatrix(0.0f, 0.0f, -3.0f);
	Matrix4 projection = Perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	//Graphics Loop
	while (!window.getShouldClose())
	{
		//Input

		//Render
		shader.use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex0.ID);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex1.ID);

		shader.setMat4("model", model);
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);

		window.render();

		//Update

		window.processEvents();
	}
}