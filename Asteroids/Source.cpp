#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Shader.h>
#include <Entropy/Graphics/Camera.h>

#include <Entropy/Graphics/UniformBuffer.h>
#include <Entropy/Graphics/Model.h>

#include <Entropy/Math/Transform3D.h>
#include <Entropy/Math/Converters.h>

#include <Entropy/Timing/Clock.h>

#include <iostream>
#include <exception>

using namespace Entropy;

int main(int argc, char* argv[])
{
	try
	{
		// Load OpenGL Window
		Graphics::Window window("Asteroids Example Project.", 1280, 720);
		window.captureMouse();

		// Load Shaders
		Graphics::Shader shader("vBaseShader.glsl", "fLighting.glsl");
		Graphics::Shader skyboxShader("vCubeMap.glsl", "fCubeMap.glsl");

		// Load Scene Assets
		std::vector<std::string> skyboxTextures;
		skyboxTextures.push_back("Assets/GalaxyRight.png");
		skyboxTextures.push_back("Assets/GalaxyLeft.png");
		skyboxTextures.push_back("Assets/GalaxyTop.png");
		skyboxTextures.push_back("Assets/GalaxyBottom.png");
		skyboxTextures.push_back("Assets/GalaxyFront.png");
		skyboxTextures.push_back("Assets/GalaxyBack.png");
		Graphics::Texture skyboxTexture = Entropy::Graphics::LoadTexture::LoadCubeMap(skyboxTextures);

		Graphics::Model planet("Assets/planet.obj");
		Graphics::Model asteroid("Assets/rock.obj");

		// Setup Camera (Position, Up, Yaw, Pitch);
		Entropy::Camera camera(Math::Vec3(0.0f, 0.0f, -5.0f), Math::Vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

		// Setup Uniform Blocks
		Graphics::UniformBuffer matrices(2 * sizeof(Math::Mat4), NULL);
		shader.setUniformBlockBinding("Matrices", matrices.UBO);

		/**
		 * Setup Scene Data
		 */
		// Shader Matrices
		Math::Mat4 projection = Math::Perspective(Math::Radians(camera.zoom), (float)window.Width / (float)window.Height, 0.1f, 1000.0f); //(FOV, ScreenRatio, Near, Far)
		Math::Mat4 view = camera.getViewMatrix();
		Math::Mat4 model;

		matrices.setSubData(0, sizeof(Math::Mat4), projection.Data);
		matrices.setSubData(sizeof(Math::Mat4), sizeof(Math::Mat4), view.Data);

		// Window & Framebuffer Data
		window.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		// Asteroids

		// Skybox
		Graphics::SkyboxMesh skybox(skyboxTexture);

		// Timing
		Entropy::Timing::Clock clock;
		clock.initialize();
		clock.poll();

		// Render Loop
		while (window.getShouldClose() == false)
		{
			// Input
			{
				if (window.getKeyPressed(Graphics::GLKeys::KEY_ESCAPE) == true) // If Escape Key Pressed, Close Scene
					window.setShouldClose(true);

				if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_W))
					camera.updatePosition(Entropy::CameraMovement::CAMERA_FORWARD, clock.timeElapsed(), 10.0f);
				if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_S))
					camera.updatePosition(Entropy::CameraMovement::CAMERA_BACKWARD, clock.timeElapsed(), 10.0f);
				if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_A))
					camera.updatePosition(Entropy::CameraMovement::CAMERA_LEFT, clock.timeElapsed(), 10.0f);
				if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_D))
					camera.updatePosition(Entropy::CameraMovement::CAMERA_RIGHT, clock.timeElapsed(), 10.0f);

				
				if (window.MouseDelta.MoveTrigger) // Handle Mouse Movement Event
				{
					camera.updateRotation(window.MouseDelta.XOffset, window.MouseDelta.YOffset);
					window.MouseDelta.MoveTrigger = false;
				}
			}

			// Render
			{
				// Clear Screen First
				window.bind();
				window.clear();

				// Render Planet
				model = Math::Translate(0.0f, -3.0f, 0.0f) * Math::Scale(4.0f);
				shader.use();
				shader.setMat4("model", model);
				planet.Draw(shader);

				// Render Skybox Last
				skybox.Draw(skyboxShader, view, projection);
			}

			// Update
			{
				window.processEvents();
				clock.poll();

				// Process View Changes
				view = camera.getViewMatrix();
				matrices.setSubData(sizeof(Math::Mat4), sizeof(Math::Mat4), view.Data);
			}
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
}