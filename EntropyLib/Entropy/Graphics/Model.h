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
		class Model
		{
		private:
			std::vector<Mesh> meshes;

		public:
			__declspec(dllexport) Model(const char* path);
			void __declspec(dllexport) Draw(Shader& shader);
		};
	}
}
