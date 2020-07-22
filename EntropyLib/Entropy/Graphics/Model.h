#pragma once

#include "Shader.h"
#include "Mesh.h"

#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Entropy
{
	namespace Graphics
	{
		class __declspec(dllexport) Model
		{
		private:
			std::vector<Mesh> meshes;
			std::string directory;

			void loadModel(std::string path);
			void processNode(aiNode* node, const aiScene* scene);
			Mesh processMesh(aiMesh* mesh, const aiScene* scene);
			unsigned int textureFromFile(const char* path, bool gamma = false);
			std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);

		public:
			Model(const char* path);

			void Draw(Shader& shader);
		};
	}
}
