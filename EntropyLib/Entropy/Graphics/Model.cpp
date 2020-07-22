#include "Model.h"

#include <iostream>
#include <exception>

#include "..\..\GLTexture.h"

void Entropy::Graphics::Model::loadModel(std::string path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
#ifdef DEBUG
		std::cout << "Assimp Error: " << importer.GetErrorString() << std::endl;
#endif // DEBUG
		std::string errStr = "AssimpError: ";
		errStr.append(importer.GetErrorString());
		throw std::exception(errStr.c_str());
	}

	directory = path.substr(0, path.find_last_of("/"));
	processNode(scene->mRootNode, scene);
}

void Entropy::Graphics::Model::processNode(aiNode* node, const aiScene* scene)
{
	// process all the nodes meshes (if any)
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	// then do same for each of its children
	for (unsigned int i = 0; i < node->mNumChildren; i++)
		processNode(node->mChildren[i], scene);
}

Entropy::Graphics::Mesh Entropy::Graphics::Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;
	
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Math::Vec3 vertex(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
		Math::Vec2 texCoords;
		if (mesh->mTextureCoords[0])
			texCoords = Math::Vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
		Math::Vec3 normal(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
		vertices.push_back(Vertex(vertex, normal, texCoords));
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* aiMaterial = scene->mMaterials[mesh->mMaterialIndex];
		std::vector<Texture> diffuseMaps = loadMaterialTextures(aiMaterial, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		std::vector<Texture> specularMaps = loadMaterialTextures(aiMaterial, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}

	Material material("Material");
	material.Textures = textures;

	return Mesh(vertices, indices, material);
}

unsigned int Entropy::Graphics::Model::textureFromFile(const char* path, bool gamma)
{
	std::string filename = directory + '/' + std::string(path);
	LoadTexture texture(filename.c_str());
	return texture.ID;
}

std::vector<Entropy::Graphics::Texture> Entropy::Graphics::Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
	std::vector<Texture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		Texture texture(textureFromFile(str.C_Str()), typeName);
		textures.push_back(texture);
	}
	return textures;
}

Entropy::Graphics::Model::Model(const char* path)
{
	loadModel(path);
}

void Entropy::Graphics::Model::Draw(Shader& shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].Draw(shader);
}
