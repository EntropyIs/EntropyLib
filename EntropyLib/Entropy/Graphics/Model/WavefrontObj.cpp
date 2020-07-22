#include "WavefrontObj.h"

#include <fstream>
#include <sstream>
#include <exception>

Entropy::Graphics::WavefrontObj::ObjectData::ObjectData(std::string objectName) : objectName(objectName)
{
	// Add empties to data (because wavefront obj files index from 1).
	vertexPositions.push_back(Math::Vec3());
	vertexNormals.push_back(Math::Vec3());
	vertexTextureCoords.push_back(Math::Vec2());
}

void Entropy::Graphics::WavefrontObj::pharseVertexPosition(std::vector<std::string> lineData, unsigned int index)
{
	if (lineData.size() == 5) // Vec4 Position Data. TODO: Handle W Components
		objects[index].vertexPositions.push_back(Math::Vec3(std::stof(lineData[1]), std::stof(lineData[2]), std::stof(lineData[3])));
	else if (lineData.size() == 4) // Vec3 Position Data.
		objects[index].vertexPositions.push_back(Math::Vec3(std::stof(lineData[1]), std::stof(lineData[2]), std::stof(lineData[3])));
#ifdef DEBUG
	else
		std::cout << "Error Reading Vertex Data." << std::endl;
#endif // DEBUG
}

void Entropy::Graphics::WavefrontObj::pharseTextureCoord(std::vector<std::string> lineData, unsigned int index)
{
	if (lineData.size() == 4) // Vec3 Texture Coord Data TODO: Decide how to handle
		objects[index].vertexTextureCoords.push_back(Math::Vec2(std::stof(lineData[1]), std::stof(lineData[2])));
	else if (lineData.size() == 3) // Vec2 Texture Coord Data
		objects[index].vertexTextureCoords.push_back(Math::Vec2(std::stof(lineData[1]), std::stof(lineData[2])));
#ifdef DEBUG
	else
		std::cout << "Error Reading Texture Coords Data." << std::endl;
#endif // DEBUG
}

void Entropy::Graphics::WavefrontObj::pharseNormal(std::vector<std::string> lineData, unsigned int index)
{
	if (lineData.size() == 4) // Vec3 Normal Data
		objects[index].vertexNormals.push_back(Math::normalize(Math::Vec3(std::stof(lineData[1]), std::stof(lineData[2]), std::stof(lineData[3]))));
#ifdef DEBUG
	else
		std::cout << "Error Reading Normal Data." << std::endl;
#endif // DEBUG
}

void Entropy::Graphics::WavefrontObj::pharseFace(std::vector<std::string> lineData, unsigned int index, unsigned int positionOffset, unsigned int textureCoordOffset, unsigned int normalOffset)
{
	for (int i = 1; i < lineData.size(); i++) // TODO: Handle shapes other than triangles, currently will just load data as indices (which get interperated as tris).
	{
		std::stringstream faceStream(lineData[i]);
		std::vector<std::string> faceComp;
		std::string faceToken;
		while (std::getline(faceStream, faceToken, '/'))
			faceComp.push_back(faceToken);

		FaceIndex faceIndex;

		if (faceComp.size() == 3) // v/t/n or v//n
		{
			if (faceComp[1].empty())
			{
				faceIndex.vertexPosition = std::stoi(faceComp[0]) - positionOffset;
				faceIndex.vertexNormal = std::stoi(faceComp[2]) - normalOffset;
			}
			else
			{
				faceIndex.vertexPosition = std::stoi(faceComp[0]) - positionOffset;
				faceIndex.vertexTextureCoord = std::stoi(faceComp[1]) - textureCoordOffset;
				faceIndex.vertexNormal = std::stoi(faceComp[2]) - normalOffset;
			}
		}
		else if (faceComp.size() == 2) // v/t
		{
			faceIndex.vertexPosition = std::stoi(faceComp[0]) - positionOffset;
			faceIndex.vertexTextureCoord = std::stoi(faceComp[1]) - textureCoordOffset;
		}
		else if (faceComp.size() == 1) // v
		{
			faceIndex.vertexPosition = std::stoi(faceComp[0]) - positionOffset;
		}

		objects[index].faceIndices.push_back(faceIndex);
	}
}

unsigned int Entropy::Graphics::WavefrontObj::addObject(std::string objectName)
{
	if (hasObject(objectName))
		return getObjectIndex(objectName);
	objects.push_back(ObjectData(objectName));
	return objects.size() - 1;
}

unsigned int Entropy::Graphics::WavefrontObj::getObjectIndex(std::string objectName)
{
	for (unsigned int i = 0; i < objects.size(); i++)
		if (objects[i].objectName.compare(objectName) == 0)
			return i;
	std::string error = "Mesh not found: ";
	error.append(objectName);
	throw std::exception(error.c_str());
}

bool Entropy::Graphics::WavefrontObj::hasObject(std::string objectName)
{
	for (unsigned int i = 0; i < objects.size(); i++)
		if (objects[i].objectName.compare(objectName) == 0)
			return true;
	return false;
}

void Entropy::Graphics::WavefrontObj::pharseColorAmbient(std::vector<std::string> lineData, unsigned int index)
{
	if (lineData.size() == 4) // Vec3 Color Data
		materials[index].Ambient = Math::Vec3(std::stof(lineData[1]), std::stof(lineData[2]), std::stof(lineData[3]));
#ifdef DEBUG
	else
		std::cout << "Error Reading Ambient Color Data." << std::endl;
#endif // DEBUG
}

void Entropy::Graphics::WavefrontObj::pharseColorDiffuse(std::vector<std::string> lineData, unsigned int index)
{
	if (lineData.size() == 4) // Vec3 Color Data
		materials[index].Diffuse = Math::Vec3(std::stof(lineData[1]), std::stof(lineData[2]), std::stof(lineData[3]));
#ifdef DEBUG
	else
		std::cout << "Error Reading Diffuse Color Data." << std::endl;
#endif // DEBUG
}

void Entropy::Graphics::WavefrontObj::pharseColorSpecular(std::vector<std::string> lineData, unsigned int index)
{
	if (lineData.size() == 4) // Vec3 Color Data
		materials[index].Specular = Math::Vec3(std::stof(lineData[1]), std::stof(lineData[2]), std::stof(lineData[3]));
#ifdef DEBUG
	else
		std::cout << "Error Reading Specular Color Data." << std::endl;
#endif // DEBUG
}

void Entropy::Graphics::WavefrontObj::pharseShininess(std::vector<std::string> lineData, unsigned int index)
{
	if (lineData.size() == 2) // Shinyness Data
		materials[index].Shininess = std::stof(lineData[1]);
#ifdef DEBUG
	else
		std::cout << "Error Reading Shininess Data." << std::endl;
#endif // DEBUG
}

void Entropy::Graphics::WavefrontObj::pharseTexture(std::vector<std::string> lineData, unsigned int index)
{
	std::string type;
	if (lineData[0] == "map_Ka") // Ambient Texture Map
		type = "texture_ambient";
	else if (lineData[0] == "map_Kd") // Diffuse Texture Map
		type = "texture_diffuse";
	else if (lineData[0] == "map_Ks") // Specular Texture Map
		type = "texture_specular";
	else if (lineData[0] == "map_Ns") // Specular Highlight Component Map
		type = "texture_shininess";
	else if (lineData[0] == "map_bump" || lineData[0] == "bump") // bump map
		type = "texture_bump";

	std::string nameBuffer;
	for (unsigned int i = 1; i < lineData.size(); i++)
		nameBuffer.append(lineData[i]); // Treat everything after first comp as texture file name

	std::string filename = directory + '/' + nameBuffer;

	materials[index].Textures.push_back(LoadImage::LoadBitmap(filename.c_str(), type.c_str()));
}

unsigned int Entropy::Graphics::WavefrontObj::addMaterial(std::string materialName)
{
	if (hasMaterial(materialName))
		return getMaterialIndex(materialName);
	materials.push_back(Material(materialName));
	return materials.size() - 1;
}

unsigned int Entropy::Graphics::WavefrontObj::getMaterialIndex(std::string materialName)
{
	for (unsigned int i = 0; i < materials.size(); i++)
		if (materials[i].Name.compare(materialName) == 0)
			return i;
	std::string error = "Material not found: ";
	error.append(materialName);
	throw std::exception(error.c_str());
}

bool Entropy::Graphics::WavefrontObj::hasMaterial(std::string materialName)
{
	for (unsigned int i = 0; i < materials.size(); i++)
		if (materials[i].Name.compare(materialName) == 0)
			return true;
	return false;
}

bool Entropy::Graphics::WavefrontObj::readObjFile(const char* path)
{
	// Read Contents of file into lines vector
	std::ifstream inFile;
	inFile.open(path, std::ios_base::in);
	if (!inFile.is_open())
	{
		std::string error = "Could not open file: ";
		error.append(path);
		throw std::exception(error.c_str());
	}

	std::vector<std::string> lines;

	while (inFile.good() && inFile.peek() != EOF)
	{
		std::string line;
		std::getline(inFile, line);
		if (!line.empty())
			lines.push_back(line);
	}
	inFile.close();

	unsigned int objectIndex = addObject(""); // Add unammed object;
	unsigned int positionOffset = 0;
	unsigned int textureCoordOffset = 0;
	unsigned int normalOffset = 0;

	// Pharse
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::stringstream lineStream(lines[i]);
		std::vector<std::string> lineComp;
		std::string lineToken;
		while (std::getline(lineStream, lineToken, ' '))
			if (!lineToken.empty())
				lineComp.push_back(lineToken);
		lineToken = lineComp[0];

		std::string nameBuffer;

		switch (lineToken.c_str()[0])
		{
		case 'v': //Vertex Data (Position, TextureCoordinate or Normal)
			if (lineToken == "v")
				pharseVertexPosition(lineComp, objectIndex);
			else if (lineToken == "vt")
				pharseTextureCoord(lineComp, objectIndex);
			else if (lineToken == "vn")
				pharseNormal(lineComp, objectIndex);
			break;
		case 'p':
		case 'l':
		case 'f':
			pharseFace(lineComp, objectIndex, positionOffset, textureCoordOffset, normalOffset);
			break;
		case 'u':
			// TODO: Implement Split Matreial Useage?
			for (unsigned int i = 1; i < lineComp.size(); i++)
				nameBuffer.append(lineComp[i]); // Treat everything after first comp as material name
			objects[objectIndex].materialName = nameBuffer;
			break;
		case 'm':
			if (lineToken == "mtllib")
			{
				for (unsigned int i = 1; i < lineComp.size(); i++)
					nameBuffer.append(lineComp[i]); // Treat everything after first comp as mtl filename
				mtlFiles.push_back(nameBuffer);
				break;
			}
			else if (lineToken == "mg")
				// TODO: Handle merging group
				break;
		case 'g':
			// Todo: Handle Group
			break;
		case 's':
			// Todo: Handle Smoothing Group
			break;
		case 'o':
			for (unsigned int i = 1; i < lineComp.size(); i++)
				nameBuffer.append(lineComp[i]); // Treat everything after first comp as object name
			objectIndex = addObject(nameBuffer);
			positionOffset = 0;
			normalOffset = 0;
			textureCoordOffset = 0;
			for (unsigned int i = 0; i < objectIndex; i++) // Get object offset
			{
				positionOffset += objects[i].vertexPositions.size() - 1;
				normalOffset += objects[i].vertexNormals.size() - 1;
				textureCoordOffset += objects[i].vertexTextureCoords.size() - 1;
			}
			break;
		default:
			break;
		}
	}
	return true;
}

bool Entropy::Graphics::WavefrontObj::readMtlFile(const char* path)
{
	// Read Contents of file into lines vector
	std::string filename = directory + '/' + std::string(path);
	std::ifstream inFile;
	inFile.open(filename, std::ios_base::in);
	if (!inFile.is_open())
	{
		std::string error = "Could not open file: ";
		error.append(path);
		throw std::exception(error.c_str());
	}

	std::vector<std::string> lines;

	while (inFile.good() && inFile.peek() != EOF)
	{
		std::string line;
		std::getline(inFile, line);
		if (!line.empty())
			lines.push_back(line);
	}
	inFile.close();

	unsigned int materialIndex = addMaterial(""); // Add unammed material;
	
	// Pharse
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::stringstream lineStream(lines[i]);
		std::vector<std::string> lineComp;
		std::string lineToken;
		while (std::getline(lineStream, lineToken, ' '))
			if (!lineToken.empty())
				lineComp.push_back(lineToken);
		lineToken = lineComp[0];

		std::string nameBuffer;

		switch (lineToken.c_str()[0])
		{
		case 'n': // New Material
			for (unsigned int i = 1; i < lineComp.size(); i++)
				nameBuffer.append(lineComp[i]); // Treat everything after first comp as object name
			materialIndex = addMaterial(nameBuffer);
			break;
		case 'K':
			if (lineToken == "Ka") // Ambient Color
				pharseColorAmbient(lineComp, materialIndex);
			else if (lineToken == "Kd") // Diffuse Color
				pharseColorDiffuse(lineComp, materialIndex);
			else if (lineToken == "Ks") // Specular Color
				pharseColorSpecular(lineComp, materialIndex);
			break;
		case 'N':
			if (lineToken == "Ns")// Specular Exponent
			{
				pharseShininess(lineComp, materialIndex);
			}
			else if (lineToken == "Ni") // Optical Density (Index of Refraction)
			{
				// TODO: Handle Transparancy
			}
			break;
		case 'd':
		case 'T':
			if (lineToken == "d" || lineToken == "Tr")// Transparency or Disolve
			{
				// TODO: Handle Transparancy
			}
			break;
		case 'i': // Illum
			break;
		case 'm':
		case 'b':
			if (lineToken == "map_Ka" || lineToken == "map_Kd" || lineToken == "map_Ks" || lineToken == "map_Ns" || lineToken == "map_bump" || lineToken == "bump")
				pharseTexture(lineComp, materialIndex);
			break;
		default:
			break;
		}
	}
	return false;
}

Entropy::Graphics::WavefrontObj::WavefrontObj(std::string path)
{
	directory = path.substr(0, path.find_last_of("/"));
	// Phase OBJ File
	readObjFile(path.c_str());

	// Phase any associated MTL Files
	for (unsigned int i = 0; i < mtlFiles.size(); i++)
		readMtlFile(mtlFiles[i].c_str());
}

std::vector<Entropy::Graphics::Mesh> Entropy::Graphics::WavefrontObj::getAll()
{
	std::vector<Mesh> result;
	for (unsigned int i = 1; i < objects.size(); i++)
		result.push_back(getMesh(i));
	return result;
}

Entropy::Graphics::Mesh Entropy::Graphics::WavefrontObj::getMesh(const char* objectName)
{
	return getMesh(getObjectIndex(objectName));
}

Entropy::Graphics::Mesh Entropy::Graphics::WavefrontObj::getMesh(unsigned int index)
{
	return Mesh(getVertices(index), getIndices(index), getMaterial(index));
}

std::vector<Entropy::Graphics::Vertex> Entropy::Graphics::WavefrontObj::getVertices(const char* objectName)
{
	return getVertices(getObjectIndex(objectName));
}

std::vector<Entropy::Graphics::Vertex> Entropy::Graphics::WavefrontObj::getVertices(unsigned int index)
{
	std::vector<Vertex> vertices;
	for (unsigned int i = 0; i < objects[index].faceIndices.size(); i++)
		vertices.push_back(Vertex(
			objects[index].vertexPositions[objects[index].faceIndices[i].vertexPosition],
			objects[index].vertexNormals[objects[index].faceIndices[i].vertexNormal],
			objects[index].vertexTextureCoords[objects[index].faceIndices[i].vertexTextureCoord]
		));
	return vertices;
}

std::vector<unsigned int> Entropy::Graphics::WavefrontObj::getIndices(const char* objectName)
{
	return getIndices(getObjectIndex(objectName));
}

std::vector<unsigned int> Entropy::Graphics::WavefrontObj::getIndices(unsigned int index)
{
	std::vector<unsigned int> indices;
	for (unsigned int i = 0; i < objects[index].faceIndices.size(); i++)
		indices.push_back(i);
	return indices;
}

Entropy::Graphics::Material Entropy::Graphics::WavefrontObj::getMaterial(const char* objectName)
{
	return getMaterial(getObjectIndex(objectName));
}

Entropy::Graphics::Material Entropy::Graphics::WavefrontObj::getMaterial(unsigned int index)
{
	if(hasMaterial(objects[index].materialName))
		return materials[getMaterialIndex(objects[index].materialName)];
	std::string error = "Material not found: ";
	error.append(objects[index].materialName);
	throw std::exception(error.c_str());
}
