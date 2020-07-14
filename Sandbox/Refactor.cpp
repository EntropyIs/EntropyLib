#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Mesh.h>

#include <GLShader.h>

#include <vector>
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		// Initalize Window
		Entropy::Graphics::Window window("My OpenGL Window");
		window.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		// Load Triangle Position Data
		std::vector<Entropy::Graphics::Vertex> vertices;
		vertices.push_back(Entropy::Graphics::Vertex(0.0f, 0.5f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, -0.5f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, -0.5f, 0.0f));

		// Load Triangle Index Data
		std::vector<unsigned int> indices;
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		// Load Triangle Texture Data
		std::vector<Entropy::Graphics::Texture> textures;


		// Construct Data
		Entropy::Graphics::Mesh triangle(vertices, indices, textures);

		// Load Shader
		Entropy::GLShader shader("vShader.glsl", "fShader.glsl");

		// Render Loop
		while (!window.getShouldClose())
		{
			// Input
			// Set window to close when KEY_ESCAPE is pressed
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_ESCAPE))
				window.setShouldClose(true);

			// Render
			window.clear();
			triangle.Draw(shader);

			// Update
			window.processEvents();
		}
		return 0;
	}
	catch (std::exception e)
	{
		// Handle Exeptions
		std::cout << e.what() << std::endl;
		return -1;
	}
}