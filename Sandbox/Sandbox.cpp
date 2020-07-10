#include <GL/glew.h>

#include <GLApplication.h>
#include <GLWindow.h>
#include <GLShader.h>
#include <GLTexture.h>

#include <Vector4.h>
#include <Matrix4.h>
#include <Clock.h>

#include <cmath>
#include <thread>
#include <iostream>

using namespace Entropy::Math;
using namespace Entropy::Timing;

void sleep(unsigned int millis);

int main(int argc, char* argv[])
{
	Clock myClock;

	// Initalize Applicaiton & Window
	Entropy::GLApplication myApplication;
	myApplication.initializeGLFW();
	Entropy::GLWindow myWindow(800, 800, "LearnOpenGL");
	myApplication.initializeGLEW();

	myWindow.setWindowClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate Shader Program
	Entropy::GLShader shader("E:/Onedrive/Scratch/CPPScratch/EntropyLib/x64/Debug/vShader.glsl", "E:/Onedrive/Scratch/CPPScratch/EntropyLib/x64/Debug/fShader.glsl");
	
	// Initialize Triangle
	Vector4 verts[] =
	{
	/**
	 *	posistions		colors			texture coordinates
	 *	x, y, z, w		r, g, b, a		x, y, z, w
	 */
		Vector4( 0.0f,  0.1f, 0.0f, 1.0f), Vector4(1.0f,  1.0f,  0.0f,  1.0f), Vector4(0.5f, 1.0f),
		Vector4(-0.1f, -0.1f, 0.0f, 1.0f), Vector4(0.0f,  1.0f,  1.0f,  1.0f), Vector4(0.0f, 0.0f),
		Vector4( 0.1f, -0.1f, 0.0f, 1.0f), Vector4(1.0f,  0.0f,  1.0f,  1.0f), Vector4(1.0f, 0.0f)
	};
	
	unsigned int indices[] =
	{
		0, 1, 2,
	};

	// Initalize Vertex Buffer and Array
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	
	// Bind buffer and copy in our vertex data
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Define how OpenGL shoudl interperate the vertex data
	// Vertex Position
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Vertex Color
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(4 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// Tex Coords
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Enter Wireframe Mode

	// Load Textures
	Entropy::Texture tex0("E:/Onedrive/Scratch/CPPScratch/EntropyLib/x64/Debug/assets/wall.bmp");
	Entropy::Texture tex1("E:/Onedrive/Scratch/CPPScratch/EntropyLib/x64/Debug/assets/spiral.bmp");

	// Translate & Rotate Object
	Vector4 translation, velocity, rotation;
	float scaleValue = 1;

	float accel = 1.0f;
	float maxVelocity = 1.0f;

	// Init Clock
	myClock.initialize();
	float time = 0;

	// Setup Shader Definitions
	shader.use();
	shader.set1Int("tex0", 0);
	shader.set1Int("tex1", 1);
	shader.setMat4("transform", Matrix4());

	// Gameloop
	while (!myWindow.getShouldClose())
	{
		bool clockwise = false;
		bool anticlockwise = false;
		bool reset = false;

		// Input
		if (myWindow.getKeyPressed(Entropy::KEY_ESCAPE))
			myWindow.setShouldClose(true);

		if (myWindow.getKeyPressed(Entropy::KEY_W) || myWindow.getKeyPressed(Entropy::KEY_UP))
		{
			if (velocity.j < maxVelocity)
				velocity.j += accel * myClock.timeElapsed();
		}
		else
		{
			if (velocity.j > 0)
				velocity.j -= accel * myClock.timeElapsed();
		}

		if (myWindow.getKeyPressed(Entropy::KEY_A) || myWindow.getKeyPressed(Entropy::KEY_LEFT))
		{
			rotation.k += 0.1f;
		}
		if (myWindow.getKeyPressed(Entropy::KEY_D) || myWindow.getKeyPressed(Entropy::KEY_RIGHT))
		{
			rotation.k -= 0.1f;
		}

		if (myWindow.getKeyPressed(Entropy::KEY_SPACE))
		{
			translation = Vector4();
			velocity = Vector4();
			rotation = Vector4();
		}

		// Render
		myWindow.render();

		// Use our shader program
		shader.use();

		// Set transformations
		shader.setMat4("transform", TranslationMatrix(translation) * ScaleMatrix(scaleValue, scaleValue, scaleValue) * RotationAboutXYZMatrix(rotation));

		// Bind Textures
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex0.ID);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex1.ID);

		// Render Objects
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

		// Update
		myWindow.processEvents();

		// Update Ship Position
		{
			translation += RotationAboutXYZMatrix(rotation) * (velocity * myClock.timeElapsed());
			// Screen Looping
			if (translation.x < -1.2)
				translation.x += 2.4;
			if (translation.x > 1.2)
				translation.x -= 2.4;
			if (translation.y < -1.2)
				translation.y += 2.4;
			if (translation.y > 1.2)
				translation.y -= 2.4;
		}

		// Scaling Fun
		time += myClock.timeElapsed();
		scaleValue = sin(time) / 4.0f + 1.0f;

		myClock.poll();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	myClock.shutdown();

	return 0;
}

void sleep(unsigned int millis)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}