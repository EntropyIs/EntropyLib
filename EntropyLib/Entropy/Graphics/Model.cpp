#include "Model.h"

#include <iostream>
#include <exception>

#include "Model/WavefrontObj.h"

Entropy::Graphics::Model::Model(const char* path)
{
	WavefrontObj object(path);
	meshes = object.getAll();
}

Entropy::Graphics::Model::Model(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material material)
{
	meshes.push_back(Mesh(vertices, indices, material));
}

void Entropy::Graphics::Model::Draw(Shader& shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].Draw(shader);
}
