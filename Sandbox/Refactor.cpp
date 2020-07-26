#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Shader.h>
#include <Entropy/Graphics/Model.h>
#include <Entropy/Graphics/FrameBuffer.h>

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

		// Load Shader
		std::vector<const char*> lightingShaderPaths;
		lightingShaderPaths.push_back("vLighting.glsl");
		lightingShaderPaths.push_back("fLighting.glsl");
		std::vector<unsigned int> lightingShaderTypes;
		lightingShaderTypes.push_back(GL_VERTEX_SHADER);
		lightingShaderTypes.push_back(GL_FRAGMENT_SHADER);
		Entropy::Graphics::Shader shader(lightingShaderPaths, lightingShaderTypes);

		std::vector<const char*> screenShaderPaths;
		screenShaderPaths.push_back("vFramebuffer.glsl");
		screenShaderPaths.push_back("fFramebuffer.glsl");
		std::vector<unsigned int> screenShaderTypes;
		screenShaderTypes.push_back(GL_VERTEX_SHADER);
		screenShaderTypes.push_back(GL_FRAGMENT_SHADER);
		Entropy::Graphics::Shader screenShader(screenShaderPaths, screenShaderTypes);

		screenShader.use();
		screenShader.setInt("screenTexture", 0);

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

		float quadVertices[] = {
			-1.0f,  1.0f,  0.0f, 1.0f,
			-1.0f, -1.0f,  0.0f, 0.0f,
			 1.0f, -1.0f,  1.0f, 0.0f,

			-1.0f,  1.0f,  0.0f, 1.0f,
			 1.0f, -1.0f,  1.0f, 0.0f,
			 1.0f,  1.0f,  1.0f, 1.0f
		};
		unsigned int quadVAO, quadVBO;
		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &quadVBO);
		glBindVertexArray(quadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

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

		//setup framebuffers
		Entropy::Graphics::FrameBuffer frameBuffer(window.Width, window.Height, true, false, false);
		frameBuffer.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);

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

			Entropy::Math::Mat4 projection = Entropy::Math::Perspective(Entropy::Math::radians(camera.zoom), (float)window.Width / (float)window.Height, 0.1f, 1000.0f);
			Entropy::Math::Mat4 view = camera.getViewMatrix();
			Entropy::Math::Mat4 model;

			// Render Pass 1;
			frameBuffer.bind();
			frameBuffer.clear();

			shader.use();
			shader.setVec3("viewPos", camera.position);
			shader.setMat4("projection", projection);
			shader.setMat4("view", view);
			shader.setMat4("model", model);
			plane.Draw(shader);

			glBindVertexArray(0);

			// Render Pass 2;
			window.bind();
			window.setClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			window.clear();

			screenShader.use();
			glBindVertexArray(quadVAO);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, frameBuffer.ColorBuffer);	// use the color attachment texture as the texture of the quad plane
			glDrawArrays(GL_TRIANGLES, 0, 6);

			// Update
			clock.poll();
			window.processEvents();

			orbitAngle += 0.1f * clock.timeElapsed();

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