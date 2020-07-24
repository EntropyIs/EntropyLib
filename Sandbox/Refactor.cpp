#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Shader.h>
#include <Entropy/Graphics/Model.h>

#include <Entropy/Math/Transform3D.h>

#include <GLCamera.h>
#include <Clock.h>
#include <Converters.h>

#include <vector>
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		// Initalize Window
		Entropy::Graphics::Window window("My OpenGL Window", 1280, 720);
		window.captureMouse();
		window.setWindowClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		// Load Shader
		std::vector<const char*> lightingShaderPaths;
		lightingShaderPaths.push_back("vLighting.glsl");
		lightingShaderPaths.push_back("fLighting.glsl");
		std::vector<unsigned int> lightingShaderTypes;
		lightingShaderTypes.push_back(GL_VERTEX_SHADER);
		lightingShaderTypes.push_back(GL_FRAGMENT_SHADER);
		Entropy::Graphics::Shader shader(lightingShaderPaths, lightingShaderTypes);

		// Setup Camera
		Entropy::GLCamera camera(Entropy::Math::Vec3(0.0f, 0.0f, -5.0f), Entropy::Math::Vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

		// Offset Vectors
		Entropy::Math::Vec4 backpackPos[] = {
			Entropy::Math::Vec4( 0.0f,  0.0f, -2.0f, 1.0f),
		};

		// Setup Objects
		std::vector<Entropy::Graphics::Vertex> planeVertices;
		planeVertices.push_back(Entropy::Graphics::Vertex( 10.0f, -0.5f,  10.0f, 0.0f, 1.0f, 0.0f, 10.0f,  0.0f));
		planeVertices.push_back(Entropy::Graphics::Vertex(-10.0f, -0.5f,  10.0f, 0.0f, 1.0f, 0.0f,  0.0f,  0.0f));
		planeVertices.push_back(Entropy::Graphics::Vertex(-10.0f, -0.5f, -10.0f, 0.0f, 1.0f, 0.0f,  0.0f, 10.0f));
		planeVertices.push_back(Entropy::Graphics::Vertex( 10.0f, -0.5f, -10.0f, 0.0f, 1.0f, 0.0f, 10.0f, 10.0f));
		std::vector<unsigned int> planeIndices;
		planeIndices.push_back(0); planeIndices.push_back(1); planeIndices.push_back(2);
		planeIndices.push_back(0); planeIndices.push_back(2); planeIndices.push_back(3);
		Entropy::Graphics::Material planeMaterial("planeMaterial", 33.0f, 1.0f, 1.0f, 1.0f);
		planeMaterial.Textures.push_back(Entropy::Graphics::LoadTexture::LoadFromImageFile("assets/wood.jpg", "texture_diffuse"));
		Entropy::Graphics::Model plane(planeVertices, planeIndices, planeMaterial);

		// Setup Lights
		Entropy::Graphics::DirectionalLight directionalLight(Entropy::Math::Vec3(-0.2f, -1.0f, -0.3f), Entropy::Math::Vec3(0.2f), Entropy::Math::Vec3(0.8f), Entropy::Math::Vec3(1.0f));

		Entropy::Math::Vec3 lightColor = Entropy::Math::Vec3(1.0f, 1.0f, 1.0f);
		Entropy::Graphics::PointLight pointLight(Entropy::Math::Vec3(0.0f, 2.0f, 0.0f), 1.0f, 0.09f, 0.032f, lightColor * 0.1f, lightColor * 0.5f, lightColor * 0.8f);

		shader.use();
		//shader.setDirectionalLight(directionalLight);
		shader.setPointLight(0, pointLight);

		// Setup Clock
		Entropy::Timing::Clock clock;
		clock.initialize();
		clock.poll();

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		float orbitAngle = 0.0f;

		// Render Loop
		while (!window.getShouldClose())
		{
			// Input
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_W))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_FORWARD, clock.timeElapsed(), 10.0f);
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_S))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_BACKWARD, clock.timeElapsed(), 10.0f);
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_A))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_LEFT, clock.timeElapsed(), 10.0f);
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_D))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_RIGHT, clock.timeElapsed(), 10.0f);

			// Set window to close when KEY_ESCAPE is pressed
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_ESCAPE))
				window.setShouldClose(true);

			// Render
			window.clear();

			Entropy::Math::Mat4 projection = Entropy::Math::Perspective(Entropy::Math::radians(camera.zoom), (float)window.Width / (float)window.Height, 0.1f, 1000.0f);
			Entropy::Math::Mat4 view = camera.getViewMatrix();
			Entropy::Math::Mat4 model;

			shader.use();
			shader.setVec3("viewPos", camera.position);
			shader.setMat4("projection", projection);
			shader.setMat4("view", view);
			shader.setMat4("model", model);
			plane.Draw(shader);

			// Update
			clock.poll();
			window.processEvents();

			orbitAngle += 0.1 * clock.timeElapsed();

			if (window.MouseDelta.MoveTrigger)
			{
				camera.updateRotation(window.MouseDelta.XOffset, window.MouseDelta.YOffset);
				window.MouseDelta.MoveTrigger = false;
			}
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