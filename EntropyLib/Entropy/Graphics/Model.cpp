#include "Model.h"

#include <iostream>
#include <exception>

#include "Model/WavefrontObj.h"

Entropy::Graphics::Model::Model(const char* path)
{
	WavefrontObj object(path);
	meshes = object.getAll();
}

void Entropy::Graphics::Model::Draw(Shader& shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].Draw(shader);
}
