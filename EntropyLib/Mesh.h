#pragma once

#include "Vector3.h"
#include "Vector2.h"

#include "GLShader.h"

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
		};

		struct __declspec(dllexport) Texture
		{
			unsigned int ID;
			char* type;
		};

		class __declspec(dllexport) Mesh
		{
		public:
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<Texture> textures;

			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
			void Draw(GLShader& shader);
		private:
			unsigned int VAO, VBO, EBO;
			
			void setupMesh();
		};
	}
}