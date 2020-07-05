#include <GLApplication.h>
#include <GLWindow.h>
#include <GLShader.h>

#include <iostream>

int main(int argc, char** argv)
{
	Entropy::GLApplication myApplication;
	myApplication.initializeGLFW();
	Entropy::GLWindow myWindow(600, 520, "LearnOpenGL");
	myApplication.initializeGLAD();

	myWindow.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	/*/
	// Initialize Triangle
	float verts[] =
	{
		// posistions			//colors
		  0.0f,  0.5f, 0.0f,		1.0f, 1.0f, 0.0f, 1.0f,
		 -0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 1.0f, 1.0f,
		  0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 1.0f, 1.0f,
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Define how OpenGL shoudl interperate the vertex data
	// Vertex Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Vertex Color
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Enter Wireframe Mode

	//Entropy::Shader shader("vShader.glsl", "fShader.glsl");
	*/

	// Gameloop
	while (!myWindow.getShouldClose())
	{
		// Input
		if (myWindow.getKeyPressed(Entropy::GLKeys::KEY_ESCAPE))
			myWindow.setShouldClose(true);

		// Render
		myWindow.render();

		// Use our shader program
		//shader.use();
		//glBindVertexArray(VAO);

		//glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

		// Update
		myWindow.processEvents();
	}

	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);

	return 0;
}