#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Shader.h>
#include <Entropy/Graphics/Model.h>
#include <Entropy/Graphics/FrameBuffer.h>
#include <Entropy/Graphics/Camera.h>

#include <Entropy/Math/Transform3D.h>
#include <Entropy/Math/Converters.h>

#include <Clock.h>

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

		glEnable(GL_PROGRAM_POINT_SIZE);

		// Load Shader
		Entropy::Graphics::Shader shader("vBaseShader.glsl", "fLighting.glsl");
		Entropy::Graphics::Shader screenShader("vFramebuffer.glsl", "fFramebuffer.glsl");
		Entropy::Graphics::Shader skyboxShader("vCubeMap.glsl", "fCubeMap.glsl");
		Entropy::Graphics::Shader normalShader("vNormalShader.glsl", "fNormalShader.glsl", "gNormalShader.glsl");

		shader.setUniformBlockBinding("Matrices", 0);
		normalShader.setUniformBlockBinding("Matrices", 0);
		screenShader.setUniformBlockBinding("Matrices", 0);

		screenShader.use();
		screenShader.setInt("screenTexture", 0);
		skyboxShader.use();
		skyboxShader.setInt("skybox", 0);

		// Setup Camera
		Entropy::Camera camera(Entropy::Math::Vec3(0.0f, 0.0f, -5.0f), Entropy::Math::Vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

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
		planeMaterial.Textures.push_back(Entropy::Graphics::LoadTexture::LoadFromImageFile("assets/wood_specular.jpg", "texture_specular"));
		Entropy::Graphics::Model plane(planeVertices, planeIndices, planeMaterial);

		Entropy::Graphics::Model box("assets/backpack.obj");
		Entropy::Math::Vec3 boxPos(0.0f, 1.0f, 0.0f);
		float boxAngle = 0;

		float quadVertices[] = {
			 1.0f,  1.0f,  1.0f, 1.0f,
			 1.0f, -1.0f,  1.0f, 0.0f,
			-1.0f,  1.0f,  0.0f, 1.0f,
			-1.0f, -1.0f,  0.0f, 0.0f
		};
		unsigned int quadIndices[] = {
			0, 1, 2,
			1, 2, 3
		};
		unsigned int quadVAO, quadVBO, quadEBO;
		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &quadVBO);
		glGenBuffers(1, &quadEBO);
		glBindVertexArray(quadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices), &quadIndices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

		// Setup Skybox
		std::vector<std::string> faces;
		faces.push_back("assets/GalaxyRight.png");
		faces.push_back("assets/GalaxyLeft.png");
		faces.push_back("assets/GalaxyTop.png");
		faces.push_back("assets/GalaxyBottom.png");
		faces.push_back("assets/GalaxyFront.png");
		faces.push_back("assets/GalaxyBack.png");
		Entropy::Graphics::Texture skybox = Entropy::Graphics::LoadTexture::LoadCubeMap(faces);

		float skyboxVertices[] = {
			// positions          
			-1.0f,  1.0f, -1.0f,
			-1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,
			 1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,

			-1.0f, -1.0f,  1.0f,
			-1.0f, -1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f,  1.0f,
			-1.0f, -1.0f,  1.0f,

			 1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,

			-1.0f, -1.0f,  1.0f,
			-1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f, -1.0f,  1.0f,
			-1.0f, -1.0f,  1.0f,

			-1.0f,  1.0f, -1.0f,
			 1.0f,  1.0f, -1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			-1.0f,  1.0f,  1.0f,
			-1.0f,  1.0f, -1.0f,

			-1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f,  1.0f,
			 1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f,  1.0f,
			 1.0f, -1.0f,  1.0f
		};
		unsigned int skyboxVAO, skyboxVBO;
		glGenVertexArrays(1, &skyboxVAO);
		glGenBuffers(1, &skyboxVBO);
		glBindVertexArray(skyboxVAO);
		glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		// Setup Lights
		Entropy::Graphics::DirectionalLight directionalLight(Entropy::Math::Vec3(-0.2f, -1.0f, -0.3f), Entropy::Math::Vec3(0.2f), Entropy::Math::Vec3(0.8f), Entropy::Math::Vec3(1.0f));

		Entropy::Math::Vec3 lightColor[] =
		{
			Entropy::Math::Vec3(1.0f, 0.0f, 0.0f),
			Entropy::Math::Vec3(0.0f, 1.0f, 0.0f),
			Entropy::Math::Vec3(0.0f, 0.0f, 1.0f),
			Entropy::Math::Vec3(1.0f, 1.0f, 0.0f)
		};

		Entropy::Math::Vec3 lightPos[] =
		{
			Entropy::Math::Vec3(-3.0f,  1.0f,  3.0f),
			Entropy::Math::Vec3( 3.0f,  1.0f, -3.0f),
			Entropy::Math::Vec3(-3.0f,  1.0f, -3.0f),
			Entropy::Math::Vec3( 3.0f,  1.0f,  3.0f)
		};

		Entropy::Graphics::PointLight pointLight[] =
		{
			Entropy::Graphics::PointLight(lightPos[0], 1.0f, 0.09f, 0.032f, lightColor[0] * 0.1f, lightColor[0] * 0.5f, lightColor[0] * 0.8f),
			Entropy::Graphics::PointLight(lightPos[1], 1.0f, 0.09f, 0.032f, lightColor[1] * 0.1f, lightColor[1] * 0.5f, lightColor[1] * 0.8f),
			Entropy::Graphics::PointLight(lightPos[2], 1.0f, 0.09f, 0.032f, lightColor[2] * 0.1f, lightColor[2] * 0.5f, lightColor[2] * 0.8f),
			Entropy::Graphics::PointLight(lightPos[3], 1.0f, 0.09f, 0.032f, lightColor[3] * 0.1f, lightColor[3] * 0.5f, lightColor[3] * 0.8f)
		};

		shader.use();
		//shader.setDirectionalLight(directionalLight);
		shader.setPointLight(0, pointLight[0]);
		shader.setPointLight(1, pointLight[1]);
		shader.setPointLight(2, pointLight[2]);
		shader.setPointLight(3, pointLight[3]);

		// Setup Clock
		Entropy::Timing::Clock clock;
		clock.initialize();
		clock.poll();

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		float orbitAngle = 0.0f;

		//setup framebuffers
		Entropy::Graphics::FrameBuffer frameBuffer(window.Width, window.Height, true, false, false);
		frameBuffer.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		// Setup uniform blocks

		unsigned int uboMatrices;
		glGenBuffers(1, &uboMatrices);

		glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
		glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(Entropy::Math::Mat4), NULL, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(Entropy::Math::Mat4));

		Entropy::Math::Mat4 projection = Entropy::Math::Perspective(Entropy::Math::Radians(camera.zoom), (float)window.Width / (float)window.Height, 0.1f, 1000.0f);
		glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(Entropy::Math::Mat4), projection.Data);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

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

			
			Entropy::Math::Mat4 view = camera.getViewMatrix();
			glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
			glBufferSubData(GL_UNIFORM_BUFFER, sizeof(Entropy::Math::Mat4), sizeof(Entropy::Math::Mat4), view.Data);
			glBindBuffer(GL_UNIFORM_BUFFER, 0);

			Entropy::Math::Mat4 model;

			// Render Pass 1;
			frameBuffer.bind();
			frameBuffer.clear();

			// Box
			shader.use();
			shader.setVec3("viewPos", camera.position);
			model = Entropy::Math::Translate(boxPos) * Entropy::Math::RotateY(boxAngle) * Entropy::Math::Scale(0.5f);
			shader.setMat4("model", model);
			box.Draw(shader);

			// Floor
			shader.use();
			model = Entropy::Math::Mat4();
			shader.setMat4("model", model);
			plane.Draw(shader);

			// Render Skybox
			glDepthFunc(GL_LEQUAL);
			skyboxShader.use();
			Entropy::Math::Mat4 skyboxView(
				view.R0C0, view.R1C0, view.R2C0, 0.0f,
				view.R0C1, view.R1C1, view.R2C1, 0.0f,
				view.R0C2, view.R1C2, view.R2C2, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			);
			skyboxShader.setMat4("viewPos", skyboxView);
			skyboxShader.setMat4("projection", projection);
			glBindVertexArray(skyboxVAO);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_CUBE_MAP, skybox.ID);
			skyboxShader.setInt("cubemap", skybox.ID);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
			glDepthFunc(GL_LESS);

			// Render Pass 2;
			window.bind();
			window.setClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			window.clear();

			// render cube matrix

			screenShader.use();
			glBindVertexArray(quadVAO);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, frameBuffer.ColorBuffer);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			// Update
			clock.poll();
			window.processEvents();

			orbitAngle += 0.01f * clock.timeElapsed();
			boxAngle += 0.1f * clock.timeElapsed();

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