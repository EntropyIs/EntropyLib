#include <GLWindow.h>
#include <GLShader.h>
#include <GLTexture.h>
#include <Clock.h>
#include <Matrix4Ext.h>
#include <Converters.h>

using namespace Entropy;
using namespace Entropy::Math;
using namespace Entropy::Timing;

int main(int argc, char* argv[])
{
	//Initalize OpenGL Window
	GLWindow window(800, 600, "OpenGL Sandbox");
	window.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	//Define Object Verticies
	Vector4 vertices[] = {
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4( 0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4( 0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4(-0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4(-0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4( 0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4(-0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4(-0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4(-0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4(-0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4(-0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4(-0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4( 0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4( 0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4( 0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4( 0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4( 0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4(-0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4(-0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
		Vector4( 0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 1.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f),
		Vector4(-0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4(-0.5f,  0.5f, -0.5f, 1.0f), Vector4(1.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 1.0f),
	};

	//Define Object Tris
	unsigned int indices[] = {
		0,1,2,
		3,4,5,
		6,7,8,
		9,10,11,
		12,13,14,
		15,16,17,
		18,19,20,
		21,22,23,
		24,25,26,
		27,28,29,
		30,31,32,
		33,34,35
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
	Matrix4 projection = Perspective(45.0f, 800.0f / 600.0f, 0.1f, 10.0f);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	Clock clock;
	clock.initialize();
	clock.poll();
	float angle = 0;

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
		angle += 0.5 * clock.timeElapsed();
		model = RotationAboutAxisMatrix(Vector4(1.0f, 1.0f), angle);
		window.processEvents();
		clock.poll();
	}
	clock.shutdown();
}