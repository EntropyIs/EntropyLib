#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Shader.h>
#include <Entropy/Graphics/Camera.h>

#include <Entropy/Graphics/Model.h>
#include <Entropy/Graphics/UniformBuffer.h>
#include <Entropy/Graphics/InstanceBuffer.h>

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
		Graphics::Shader instanceShader("vInstancedShader.glsl", "fLighting.glsl");
		Graphics::Shader skyboxShader("vCubeMap.glsl", "fCubeMap.glsl");

		shader.setUniformBlockBinding("Matrices", 0);
		instanceShader.setUniformBlockBinding("Matrices", 0);

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
		Camera camera(Math::Vec3(0.0f, 5.0f, -80.0f), Math::Vec3(0.0f, 1.0f, 0.0f), 105.0f, -10.0f);

		/**
		 * Setup Scene Data
		 */
		// Shader Matrices
		Math::Mat4 projection = Math::Perspective(Math::Radians(camera.zoom), (float)window.Width / (float)window.Height, 0.1f, 1000.0f); //(FOV, ScreenRatio, Near, Far)
		Math::Mat4 view = camera.getViewMatrix();
		Math::Mat4 model;

		// Setup Uniform Blocks
		Graphics::UniformBuffer matrices(2 * sizeof(Math::Mat4), NULL);
		matrices.setSubData(0, sizeof(Math::Mat4), projection.Data);
		matrices.setSubData(sizeof(Math::Mat4), sizeof(Math::Mat4), view.Data);

		// Window & Input Settings
		window.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		float cameraSpeed = 5.0f;

		// Planet
		float planetRot = 0.0f;
		Math::Vec3 planetPos(0.0f, -3.0f, 0.0f);
		float planetScale = 4.0f;

		// Asteroids
		unsigned int asteroidCount = 5000; // 

		Math::Mat4* asteroidModelMatrices = new Math::Mat4[asteroidCount];

		srand((unsigned int)glfwGetTime());
		float radius = 50.0f;
		float offset = 10.0f;

		for (unsigned int i = 0; i < asteroidCount; i++)
		{
			// 1. translation
			float angle = (float)i / (float)asteroidCount * 360.0f;
			float displacement = (rand() % (int)(2.0f * offset * 100.0f)) / 100.0f - offset;
			float x = sin(angle) * radius + displacement;
			displacement = (rand() % (int)(2.0f * offset * 100.0f)) / 100.0f - offset;
			float y = displacement * 0.1f;
			displacement = (rand() % (int)(2.0f * offset * 100.0f)) / 100.0f - offset;
			float z = cos(angle) * radius + displacement;

			// 2. scale
			float scale = (rand() % 20) / 100.0f + 0.05f;

			// 3. rotation
			float rotAngle = (float)(rand() % 360);

			asteroidModelMatrices[i] = Math::Translate(x, y, z) * Math::Rotate(Math::Vec3(0.4f, 0.6f, 0.8f), rotAngle) * Math::Scale(scale);
		}

		float fieldRot = 0.0f;

		// Setup Astroid Instance Matricies
		Graphics::InstanceBuffer(asteroidCount, sizeof(Math::Mat4), &asteroidModelMatrices[0]);
		asteroid.setupInstancedMatrix();

		// Skybox
		Graphics::SkyboxMesh skybox(skyboxTexture);

		// Setup Lights
		Entropy::Graphics::DirectionalLight directionalLight(Entropy::Math::Vec3(-0.2f, -1.0f, -0.3f), Entropy::Math::Vec3(0.2f), Entropy::Math::Vec3(0.8f), Entropy::Math::Vec3(1.0f));

		shader.use();
		shader.setDirectionalLight(directionalLight);
		instanceShader.use();
		instanceShader.setDirectionalLight(directionalLight);

		// Timing
		Entropy::Timing::Clock clock;
		clock.initialize();
		clock.poll();

		// Render Loop
		while (window.getShouldClose() == false)
		{
			// Input
			if (window.getKeyPressed(Graphics::GLKeys::KEY_ESCAPE) == true) // If Escape Key Pressed, Close Scene
				window.setShouldClose(true);

			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_W))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_FORWARD, clock.timeElapsed(), cameraSpeed);
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_S))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_BACKWARD, clock.timeElapsed(), cameraSpeed);
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_A))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_LEFT, clock.timeElapsed(), cameraSpeed);
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_D))
				camera.updatePosition(Entropy::CameraMovement::CAMERA_RIGHT, clock.timeElapsed(), cameraSpeed);

				
			if (window.MouseDelta.MoveTrigger) // Handle Mouse Movement Event
			{
				camera.updateRotation(window.MouseDelta.XOffset, window.MouseDelta.YOffset);
				window.MouseDelta.MoveTrigger = false;
			}

			// Process View Changes
			view = camera.getViewMatrix();
			matrices.setSubData(sizeof(Math::Mat4), sizeof(Math::Mat4), view.Data);

			// Render
			// Clear Screen First
			window.bind();
			window.clear();

			// Render Planet
			model = Math::Translate(planetPos) * Math::RotateY(planetRot) * Math::Scale(planetScale);
			shader.use();
			shader.setVec3("viewPos", camera.position);
			shader.setMat4("model", model);
			shader.setMat4("alteration", Math::Mat4());
			planet.Draw(shader);

			// Render Asteroids
			instanceShader.use();
			Math::Mat4 alteration = Math::RotateY(fieldRot);
			instanceShader.setMat4("alteration", alteration);
			asteroid.DrawInstanced(instanceShader, asteroidCount);

			// Render Skybox Last
			skybox.Draw(skyboxShader, view, projection);

			// Update
			window.processEvents();
			clock.poll();

			planetRot += 0.1f * clock.timeElapsed();
			fieldRot += 0.01f * clock.timeElapsed();
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
}