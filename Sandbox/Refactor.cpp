#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Mesh.h>
#include <Entropy/Graphics/Shader.h>

#include <GLCamera.h>

#include <Matrix4Ext.h>
#include <Converters.h>

#include <vector>
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		// Initalize Window
		Entropy::Graphics::Window window("My OpenGL Window");
		window.setWindowClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		// Load Cube Position Data
		std::vector<Entropy::Graphics::Vertex> vertices;
		vertices.push_back(Entropy::Graphics::Vertex( -0.5f,  0.5f, -0.5f));
		vertices.push_back(Entropy::Graphics::Vertex( -0.5f, -0.5f, -0.5f));
		vertices.push_back(Entropy::Graphics::Vertex(  0.5f, -0.5f, -0.5f));
		vertices.push_back(Entropy::Graphics::Vertex(  0.5f,  0.5f, -0.5f));
		vertices.push_back(Entropy::Graphics::Vertex( -0.5f,  0.5f,  0.5f));
		vertices.push_back(Entropy::Graphics::Vertex( -0.5f, -0.5f,  0.5f));
		vertices.push_back(Entropy::Graphics::Vertex(  0.5f, -0.5f,  0.5f));
		vertices.push_back(Entropy::Graphics::Vertex(  0.5f,  0.5f,  0.5f));

		// Load Triangle Index Data
		std::vector<unsigned int> indices;
		indices.push_back(0); indices.push_back(1); indices.push_back(2);
		indices.push_back(0); indices.push_back(2); indices.push_back(3);
		indices.push_back(3); indices.push_back(2); indices.push_back(6);
		indices.push_back(3); indices.push_back(6); indices.push_back(7);
		indices.push_back(7); indices.push_back(6); indices.push_back(5);
		indices.push_back(7); indices.push_back(5); indices.push_back(4);
		indices.push_back(4); indices.push_back(5); indices.push_back(1);
		indices.push_back(4); indices.push_back(1); indices.push_back(0);
		indices.push_back(1); indices.push_back(5); indices.push_back(6);
		indices.push_back(1); indices.push_back(6); indices.push_back(2);
		indices.push_back(4); indices.push_back(0); indices.push_back(3);
		indices.push_back(4); indices.push_back(3); indices.push_back(7);

		// Load Triangle Texture Data
		std::vector<Entropy::Graphics::Texture> textures;

		// Construct Data
		Entropy::Graphics::Mesh lightSource(vertices, indices, textures);
		Entropy::Graphics::Mesh block(vertices, indices, textures);

		// Load Shader
		std::vector<const char*> lightingShaderPaths;
		lightingShaderPaths.push_back("vLightingShader.glsl");
		lightingShaderPaths.push_back("fLightingShader.glsl");
		std::vector<unsigned int> lightingShaderTypes;
		lightingShaderTypes.push_back(GL_VERTEX_SHADER);
		lightingShaderTypes.push_back(GL_FRAGMENT_SHADER);
		Entropy::Graphics::Shader lightingShader(lightingShaderPaths, lightingShaderTypes);

		std::vector<const char*> lightCubeShaderPaths;
		lightCubeShaderPaths.push_back("vLightCubeShader.glsl");
		lightCubeShaderPaths.push_back("fLightCubeShader.glsl");
		std::vector<unsigned int> lightCubeShaderTypes;
		lightCubeShaderTypes.push_back(GL_VERTEX_SHADER);
		lightCubeShaderTypes.push_back(GL_FRAGMENT_SHADER);
		Entropy::Graphics::Shader lightCubeShader(lightCubeShaderPaths, lightCubeShaderTypes);

		// Setup Camera
		Entropy::GLCamera camera(Entropy::Math::Vector3(0.0f, 0.0f, 3.0f), Entropy::Math::Vector3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

		// Offset Vectors
		Entropy::Math::Vector4 cubePos(0.0f, 0.0f, 0.0f);
		float cubeAngle = 0.0f;

		Entropy::Math::Vector4 lightPos(1.2f, 1.0f, 2.0f);

		Entropy::Math::Matrix4 projection = Entropy::Math::Perspective(Entropy::Math::radians(45.0f), window.Width / window.Height, 0.1f, 100.0f);
		Entropy::Math::Matrix4 view = camera.getViewMatrix();
		Entropy::Math::Matrix4 model = Entropy::Math::TranslationMatrix4(cubePos) * Entropy::Math::RotationAboutAxisMatrix4(Entropy::Math::Vector4(1.0f, 1.0f, 1.0f), cubeAngle);

		// Render Loop
		while (!window.getShouldClose())
		{
			// Input
			// Set window to close when KEY_ESCAPE is pressed
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_ESCAPE))
				window.setShouldClose(true);

			// Render
			window.clear();

			model = Entropy::Math::TranslationMatrix4(cubePos) * Entropy::Math::RotationAboutAxisMatrix4(Entropy::Math::Vector4(1.0f, 1.0f, 1.0f), cubeAngle);
			lightingShader.use();
			lightingShader.setVec3("objectColor", Entropy::Math::Vector3(1.0f, 0.5f, 0.31f));
			lightingShader.setVec3("lightColor", Entropy::Math::Vector3(1.0f, 1.0f, 1.0f));
			lightingShader.setMat4("projection", projection);
			lightingShader.setMat4("view", view);
			lightingShader.setMat4("model", model);
			block.Draw(lightingShader);

			model = Entropy::Math::TranslationMatrix4(lightPos) * Entropy::Math::ScaleMatrix4(0.2f, 0.2f, 0.2f);
			lightCubeShader.use();
			lightCubeShader.setMat4("projection", projection);
			lightCubeShader.setMat4("view", view);
			lightCubeShader.setMat4("model", model);
			lightSource.Draw(lightCubeShader);

			// Update
			window.processEvents();

			cubeAngle += 0.01f;
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