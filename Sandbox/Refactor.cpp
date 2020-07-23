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

		// Construct Object Data
		Entropy::Graphics::Model backpack("assets/box.obj");

		// Load Shader
		std::vector<const char*> lightingShaderPaths;
		lightingShaderPaths.push_back("vDepthTest.glsl");
		lightingShaderPaths.push_back("fDepthTest.glsl");
		std::vector<unsigned int> lightingShaderTypes;
		lightingShaderTypes.push_back(GL_VERTEX_SHADER);
		lightingShaderTypes.push_back(GL_FRAGMENT_SHADER);
		Entropy::Graphics::Shader lightingShader(lightingShaderPaths, lightingShaderTypes);

		// Setup Camera
		Entropy::GLCamera camera(Entropy::Math::Vec3(0.0f, 0.0f, 3.0f), Entropy::Math::Vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

		// Offset Vectors
		Entropy::Math::Vec4 backpackPos[] = {
			Entropy::Math::Vec4( 0.0f,  0.0f, -2.0f, 1.0f),
		};

		// Setup Lights
		Entropy::Graphics::DirectionalLight directionalLight(Entropy::Math::Vec3(-0.2f, -1.0f, -0.3f), Entropy::Math::Vec3(0.05f, 0.05f, 0.1f), Entropy::Math::Vec3(0.2f, 0.2f, 0.7f), Entropy::Math::Vec3(0.7f, 0.7f, 0.7f));

		Entropy::Math::Vec3 colors[] = {
			Entropy::Math::Vec3(0.2f, 0.2f, 0.6f),
			Entropy::Math::Vec3(0.3f, 0.3f, 0.7f),
			Entropy::Math::Vec3(0.0f, 0.0f, 0.3f),
			Entropy::Math::Vec3(0.4f, 0.4f, 0.4f)
		};

		Entropy::Graphics::PointLight pointLights[] = {
			Entropy::Graphics::PointLight(Entropy::Math::Vec3(0.7f, 0.2f, 0.2f), 1.0f, 0.09f, 0.032f, colors[0] * 0.1f, colors[0] * 0.5f, colors[0] * 0.8f),
			Entropy::Graphics::PointLight(Entropy::Math::Vec3(2.3f, -3.3f, -4.0f), 1.0f, 0.09f, 0.032f, colors[1] * 0.1f, colors[1] * 0.5f, colors[1] * 0.8f),
			Entropy::Graphics::PointLight(Entropy::Math::Vec3(-4.0f, 2.0f, -12.0f), 1.0f, 0.09f, 0.032f, colors[2] * 0.1f, colors[2] * 0.5f, colors[2] * 0.8f),
			Entropy::Graphics::PointLight(Entropy::Math::Vec3(0.0f, 0.0f, -3.0f), 1.0f, 0.09f, 0.032f, colors[3] * 0.1f, colors[3] * 0.5f, colors[3] * 0.8f)
		};

		lightingShader.use();
		lightingShader.setDirectionalLight(directionalLight);
		for (unsigned int i = 0; i < 4; i++)
			lightingShader.setPointLight(i, pointLights[i]);

		// Setup Clock
		Entropy::Timing::Clock clock;
		clock.initialize();
		clock.poll();

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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

			Entropy::Math::Mat4 projection = Entropy::Math::Perspective(Entropy::Math::radians(camera.zoom), (float)window.Width / (float)window.Height, 0.1f, 100.0f);
			Entropy::Math::Mat4 view = camera.getViewMatrix();
			Entropy::Math::Mat4 model = Entropy::Math::Translate(Entropy::Math::Vec4(0.0f, 0.0f, -2.0f, 1.0f));

			lightingShader.use();
			lightingShader.setVec3("viewPos", camera.position);
			lightingShader.setMat4("projection", projection);
			lightingShader.setMat4("view", view);
			lightingShader.setMat4("model", model);

			// Render Backpack
			backpack.Draw(lightingShader);
			
			// Update
			clock.poll();
			window.processEvents();

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