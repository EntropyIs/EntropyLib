#include <GL/glew.h>

#include <GLApplication.h>
#include <GLWindow.h>
#include <GLShader.h>

#include <Vector4.h>
#include <Matrix4.h>
#include <Clock.h>

#include <cmath>
#include <thread>
#include <iostream>

using namespace Entropy::Math;
using namespace Entropy::Timing;

void sleep(unsigned int millis);

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
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
	 *	posistions		colors
	 *	x, y, z, 1		r, g, b, a
	 */
		Vector4( 0.0f,  0.1f, 0.0f, 1.0f), Vector4(1.0f,  1.0f,  0.0f,  1.0f),
		Vector4(-0.1f, -0.1f, 0.0f, 1.0f), Vector4(0.0f,  1.0f,  1.0f,  1.0f),
		Vector4( 0.1f, -0.1f, 0.0f, 1.0f), Vector4(1.0f,  0.0f,  1.0f,  1.0f)
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
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Vertex Color
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Enter Wireframe Mode

	// Translate & Rotate Object
	Vector4 translation, velocity, rotation;

	float PI = 2 * acos(0);

	float accel = 1.0f;
	float maxVelocity = 1.0f;

	// Init Clock
	myClock.initialize();
	// Gameloop
	while (!myWindow.getShouldClose())
	{
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;
		bool clockwise = false;
		bool anticlockwise = false;
		bool reset = false;

		// Input
		if (myWindow.getKeyPressed(Entropy::KEY_ESCAPE))
			myWindow.setShouldClose(true);

		if (myWindow.getKeyPressed(Entropy::KEY_W))
			up = true;
		if(myWindow.getKeyPressed(Entropy::KEY_S))
			down = true;

		if (myWindow.getKeyPressed(Entropy::KEY_A))
			left = true;
		if (myWindow.getKeyPressed(Entropy::KEY_D))
			right = true;

		if (myWindow.getKeyPressed(Entropy::KEY_Q))
			anticlockwise = true;
		if (myWindow.getKeyPressed(Entropy::KEY_E))
			clockwise = true;

		if (myWindow.getKeyPressed(Entropy::KEY_SPACE))
			reset = true;

		// Render
		myWindow.render();

		const unsigned int numVerts = sizeof(verts) / sizeof(*verts);

		Vector4 translatedVerts[numVerts];
		for (unsigned int i = 1; i < numVerts; i = i + 2)
		{
			translatedVerts[i - 1] = RotationAboutXYZMatrix(rotation) * (verts[i - 1] + translation);
			translatedVerts[i] = verts[i];
		}

		// Use our shader program
		shader.use();
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

		// Update
		myWindow.processEvents();

		if (up)
		{
			if (velocity.j < maxVelocity)
				velocity.j += accel * myClock.timeElapsed();
		}
		else
		{
			if (velocity.j > 0)
				velocity.j -= accel * myClock.timeElapsed();
		}
		if (down)
		{
			if (velocity.j > -maxVelocity)
				velocity.j -= accel * myClock.timeElapsed();
		}
		else
		{
			if (velocity.j < 0)
				velocity.j += accel * myClock.timeElapsed();
		}
		if (right)
		{
			if (velocity.i < maxVelocity)
				velocity.i += accel * myClock.timeElapsed();
		}
		else
		{
			if (velocity.i > 0)
				velocity.i -= accel * myClock.timeElapsed();
		}
		if (left)
		{
			if (velocity.i > -maxVelocity)
				velocity.i -= accel * myClock.timeElapsed();
		}
		else
		{
			if (velocity.i < 0)
				velocity.i += accel * myClock.timeElapsed();
		}
		if(clockwise)
			rotation.k += 0.1f;
		if (anticlockwise)
			rotation.k -= 0.1f;
		if (reset)
		{
			translation = Vector4();
			velocity = Vector4();
			rotation = Vector4();
		}

		translation += velocity * myClock.timeElapsed();

		if (translation.i > 1.2f)
			translation.i = -1.2f;
		else if (translation.i < -1.2f)
			translation.i = 1.2f;
		if (translation.j > 1.2f)
			translation.j = -1.2f;
		else if (translation.j < -1.2f)
			translation.j = 1.2f;

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