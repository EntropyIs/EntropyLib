#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Mesh.h>
#include <Entropy/Graphics/Shader.h>

#include <GLCamera.h>
#include <Clock.h>
#include <Matrix4Ext.h>
#include <Converters.h>
#include <GLTexture.h>

#include <vector>
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		// Initalize Window
		Entropy::Graphics::Window window("My OpenGL Window", 1280, 720);
		window.setWindowClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		// Load Cube Position Data
		std::vector<Entropy::Graphics::Vertex> vertices;
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex( 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex( 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f));

		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f));

		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f));

		vertices.push_back(Entropy::Graphics::Vertex(0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f));

		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f));

		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f));
		vertices.push_back(Entropy::Graphics::Vertex(0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f));
		vertices.push_back(Entropy::Graphics::Vertex(-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f));

		// Load Triangle Index Data
		std::vector<unsigned int> indices;
		indices.push_back(0); indices.push_back(1); indices.push_back(2);
		indices.push_back(2); indices.push_back(3); indices.push_back(0);

		indices.push_back(4); indices.push_back(5); indices.push_back(6);
		indices.push_back(6); indices.push_back(7); indices.push_back(4);

		indices.push_back(8); indices.push_back(9); indices.push_back(10);
		indices.push_back(10); indices.push_back(11); indices.push_back(8);

		indices.push_back(12); indices.push_back(13); indices.push_back(14);
		indices.push_back(14); indices.push_back(15); indices.push_back(12);

		indices.push_back(16); indices.push_back(17); indices.push_back(18);
		indices.push_back(18); indices.push_back(19); indices.push_back(16);

		indices.push_back(20); indices.push_back(21); indices.push_back(22);
		indices.push_back(22); indices.push_back(23); indices.push_back(20);

		// Load Triangle Texture Data
		
		

		std::vector<Entropy::Graphics::Texture> textures;
		Entropy::Texture boxTexture("assets/container2.bmp");
		textures.push_back(Entropy::Graphics::Texture(boxTexture.ID, "texture_diffuse"));
		Entropy::Texture boxSpecular("assets/container2_specular.bmp");
		textures.push_back(Entropy::Graphics::Texture(boxSpecular.ID, "texture_specular"));

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
		Entropy::Math::Vector4 cubePos[] = {
		Entropy::Math::Vector4(0.0f,  0.0f,  0.0f),
		Entropy::Math::Vector4(2.0f,  5.0f, -15.0f),
		Entropy::Math::Vector4(-1.5f, -2.2f, -2.5f),
		Entropy::Math::Vector4(-3.8f, -2.0f, -12.3f),
		Entropy::Math::Vector4(2.4f, -0.4f, -3.5f),
		Entropy::Math::Vector4(-1.7f,  3.0f, -7.5f),
		Entropy::Math::Vector4(1.3f, -2.0f, -2.5f),
		Entropy::Math::Vector4(1.5f,  2.0f, -2.5f),
		Entropy::Math::Vector4(1.5f,  0.2f, -1.5f),
		Entropy::Math::Vector4(-1.3f,  1.0f, -1.5f)
		};

		Entropy::Graphics::Material cubeMaterial[] = {
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
			Entropy::Graphics::Materials::White,
		};

		float cubeAngle = 0.0f;

		Entropy::Math::Vector3 lightPos(1.2f, 1.0f, 2.0f);

		Entropy::Math::Vector3 lightColor(1.0f, 1.0f, 1.0f);
		Entropy::Math::Vector3 lightDiffuse = lightColor * 0.5f;
		Entropy::Math::Vector3 lightAmbient = lightColor * 0.2f;

		// Load Textures
		

		// Setup Clock
		Entropy::Timing::Clock clock;
		clock.initialize();
		clock.poll();

		// Render Loop
		while (!window.getShouldClose())
		{
			// Input

			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_W))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_FORWARD, clock.timeElapsed());
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_S))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_BACKWARD, clock.timeElapsed());
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_A))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_LEFT, clock.timeElapsed());
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_D))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_RIGHT, clock.timeElapsed());

			// Set window to close when KEY_ESCAPE is pressed
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_ESCAPE))
				window.setShouldClose(true);

			// Render
			window.clear();

			Entropy::Math::Matrix4 projection = Entropy::Math::Perspective(Entropy::Math::radians(camera.zoom), (float)window.Width / (float)window.Height, 0.1f, 100.0f);
			Entropy::Math::Matrix4 view = camera.getViewMatrix();
			Entropy::Math::Matrix4 model;

			// Render Cubes
			for (unsigned int i = 0; i < 10; i++)
			{
				float offset = 1.0f * i;

				model = Entropy::Math::TranslationMatrix4(cubePos[i]) * Entropy::Math::RotationAboutAxisMatrix4(Entropy::Math::Vector4(-3.0f + i, 4.3f - i, 0.5f + i), cubeAngle + offset);

				lightingShader.setMaterial(cubeMaterial[i]);

				lightingShader.setVec3("light.position", lightPos);
				lightingShader.setVec3("light.ambient", lightAmbient);
				lightingShader.setVec3("light.diffuse", lightDiffuse);
				lightingShader.setVec3("light.specular", lightColor);

				lightingShader.setVec3("viewPos", camera.position);

				lightingShader.setMat4("projection", projection);
				lightingShader.setMat4("view", view);
				lightingShader.setMat4("model", model);
				block.Draw(lightingShader);
			}

			// Render Light Source
			model = Entropy::Math::TranslationMatrix4(Entropy::Math::Vector4(lightPos.i, lightPos.j, lightPos.k, 1.0f)) * Entropy::Math::ScaleMatrix4(0.2f, 0.2f, 0.2f);
			lightCubeShader.use();
			lightCubeShader.setVec3("lightColor", lightColor);
			lightCubeShader.setMat4("projection", projection);
			lightCubeShader.setMat4("view", view);
			lightCubeShader.setMat4("model", model);
			lightSource.Draw(lightCubeShader);

			// Update
			clock.poll();
			window.processEvents();

			if (window.MouseDelta.MoveTrigger)
			{
				camera.updateRotation(window.MouseDelta.XOffset, window.MouseDelta.YOffset);
				window.MouseDelta.MoveTrigger = false;
			}

			cubeAngle += 1.0f * clock.timeElapsed();
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