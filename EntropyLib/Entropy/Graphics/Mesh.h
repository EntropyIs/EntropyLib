#pragma once

#include "../../Vector3.h"
#include "../../Vector2.h"

#include "Shader.h"

#include <string>
#include <vector>

namespace Entropy
{
	namespace Graphics
	{
		struct __declspec(dllexport) Vertex
		{
			Math::Vector3 Position;
			Math::Vector3 Normal;
			Math::Vector2 TexCoord;

			Vertex(Math::Vector3 position, Math::Vector3 normal = Math::Vector3(), Math::Vector2 texCoord = Math::Vector2()) : Position(position), Normal(normal), TexCoord(texCoord) {};
			Vertex(float x, float y, float z, float i = 0.0f, float j = 0.0f, float k = 0.0f, float tX = 0.0f, float tY = 0.0f) : Position(x, y, z), Normal(i, j, k), TexCoord(tX, tY) {};
		};

		struct __declspec(dllexport) Texture
		{
			unsigned int ID;
			const char* Type;

			Texture(unsigned int ID, const char* type) : ID(ID), Type(type) {};
		};

		class __declspec(dllexport) Mesh
		{
		public:
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<Texture> textures;

			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
			void Draw(Shader& shader);
		private:
			unsigned int VAO, VBO, EBO;
			
			void setupMesh();
		};
	}
}