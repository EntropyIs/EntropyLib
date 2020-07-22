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

		public:
			Model(const char* path);
			void Draw(Shader& shader);
		};
	}
}
