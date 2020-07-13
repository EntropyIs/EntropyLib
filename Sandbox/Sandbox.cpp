#include <GLWindow.h>
#include <GLShader.h>
#include <GLTexture.h>
#include <GLMouse.h>
#include <GLCamera.h>
#include <Clock.h>
#include <Matrix4Ext.h>
#include <Converters.h>
#include <cmath>

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
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f),	Vector4(0.0f, 0.0f, 0.0f, 1.0f), Vector4(0.0f, 0.0f),
		Vector4( 0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f, 1.0f, 0.0f, 1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f,  0.5f, -0.5f, 1.0f), Vector4(0.0f, 1.0f, 0.0f, 1.0f), Vector4(1.0f, 1.0f),
		Vector4(-0.5f,  0.5f, -0.5f, 1.0f), Vector4(0.0f, 1.0f, 1.0f, 1.0f), Vector4(0.0f, 1.0f),
		Vector4(-0.5f, -0.5f,  0.5f, 1.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f), Vector4(0.0f, 0.0f),
		Vector4( 0.5f, -0.5f,  0.5f, 1.0f), Vector4(0.0f, 0.0f, 1.0f, 1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f, 0.0f, 0.0f, 1.0f), Vector4(1.0f, 1.0f),
		Vector4(-0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f), Vector4(0.0f, 1.0f),
		Vector4(-0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f), Vector4(1.0f, 0.0f),
		Vector4(-0.5f,  0.5f, -0.5f, 1.0f), Vector4(0.0f, 1.0f, 1.0f, 1.0f), Vector4(1.0f, 1.0f),
		Vector4(-0.5f, -0.5f, -0.5f, 1.0f),	Vector4(0.0f, 0.0f, 0.0f, 1.0f), Vector4(0.0f, 1.0f),
		Vector4( 0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f, 0.0f, 0.0f, 1.0f), Vector4(1.0f, 0.0f),
		Vector4( 0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f, 1.0f, 0.0f, 1.0f), Vector4(0.0f, 1.0f),
		Vector4( 0.5f, -0.5f,  0.5f, 1.0f), Vector4(0.0f, 0.0f, 1.0f, 1.0f), Vector4(0.0f, 0.0f),
		Vector4( 0.5f, -0.5f, -0.5f, 1.0f), Vector4(1.0f, 1.0f, 0.0f, 1.0f), Vector4(1.0f, 1.0f),
		Vector4(-0.5f,  0.5f,  0.5f, 1.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f), Vector4(0.0f, 0.0f),
	};

	//Define Object Tris
	unsigned int indices[] = {
		0,  1,  2,
		2,  3,  0,
		4,  5,  6,
		6,  7,  4,
		8,  9,  10,
		10, 4,  8,
		11, 2,  12,
		12, 13, 11,
		10, 14, 5,
		5,  4,  10,
		3,  2,  11,
		11, 15, 3
	};

	Vector4 cubePos[] = {
		Vector4( 0.0f,  0.0f,  0.0f),
		Vector4( 2.0f,  5.0f, -15.0f),
		Vector4(-1.5f, -2.2f, -2.5f),
		Vector4(-3.8f, -2.0f, -12.3f),
		Vector4( 2.4f, -0.4f, -3.5f),
		Vector4(-1.7f,  3.0f, -7.5f),
		Vector4( 1.3f, -2.0f, -2.5f),
		Vector4( 1.5f,  2.0f, -2.5f),
		Vector4( 1.5f,  0.2f, -1.5f),
		Vector4(-1.3f,  1.0f, -1.5f)
	};

	//Load Object Data into Window
	window.setVertexBufferData(sizeof(vertices), (float*)vertices);
	window.setElementBufferData(sizeof(indices), indices);
	window.setVertexAttributes(0, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
	window.setVertexAttributes(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(4 * sizeof(float)));
	window.setVertexAttributes(2, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(8 * sizeof(float)));

	//Initallize Mouse
	GLMouse mouse(window.window, window.width, window.height);

	//Generate Shader Program
	GLShader shader("vshader.glsl", "fShader.glsl");

	//Load Textures
	Entropy::Texture tex0("assets/wall.bmp");
	Entropy::Texture tex1("assets/spiral.bmp");

	shader.use();
	shader.set1Int("tex0", 0);
	shader.set1Int("tex1", 1);

	//Setup Clock
	Clock clock;
	clock.initialize();
	clock.poll();

	//Setup Transformations & Camera
	Matrix4 model = RotationAboutXMatrix4(radians(-55.0f));
	Matrix4 projection = Perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	GLCamera camera(Vector3(0.0f, 0.0f, 3.0f), Vector3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

	shader.use();
	shader.setMat4("projection", projection);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	float angle = 0;

	//Graphics Loop
	while (!window.getShouldClose())
	{
		//Input
		if (window.getKeyPressed(KEY_W))
			camera.updatePosition(CAMERA_FORWARD, clock.timeElapsed());
		if (window.getKeyPressed(KEY_S))
			camera.updatePosition(CAMERA_BACKWARD, clock.timeElapsed());
		if (window.getKeyPressed(KEY_A))
			camera.updatePosition(CAMERA_LEFT, clock.timeElapsed());
		if (window.getKeyPressed(KEY_D))
			camera.updatePosition(CAMERA_RIGHT, clock.timeElapsed());

		if (window.getKeyPressed(KEY_ESCAPE))
			window.setShouldClose(true);

		//Render
		window.clear();

		shader.use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex0.ID);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex1.ID);

		shader.setMat4("view", camera.getViewMatrix());
		
		for (unsigned int i = 0; i < 10; i++)
		{
			float offset = 20.0f * i;
			if (i % 3 == 0)
				model = TranslationMatrix4(cubePos[i]) * RotationAboutAxisMatrix4(Vector4(-3.0f + i, 4.3f - i, 0.5f + i), angle + offset);
			else
				model = TranslationMatrix4(cubePos[i]) * RotationAboutAxisMatrix4(Vector4(-3.0f + i, 4.3f - i, 0.5f + i), offset);
			
			shader.setMat4("model", model);
			window.drawElements();
		}

		//Update
		angle += 0.5f * clock.timeElapsed();

		if (mouse.moveTrigger)
		{
			camera.updateRotation(mouse.xOffset, mouse.yOffset);
			mouse.moveTrigger = false;
		}
		if (mouse.scrollTrigger)
		{
			camera.updateFOV(mouse.sYOffset);
			mouse.scrollTrigger = false;
		}

		window.processEvents();
		clock.poll();
	}
	clock.shutdown();
}