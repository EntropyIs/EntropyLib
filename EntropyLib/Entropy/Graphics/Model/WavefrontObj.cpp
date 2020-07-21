#include "WavefrontObj.h"

#include <fstream>
#include <sstream>
#include <exception>

Entropy::Graphics::WavefrontObj::Data::Data(std::string objectName) : objectName(objectName)
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
	objects.push_back(Data(objectName));
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

Entropy::Graphics::WavefrontObj::WavefrontObj(const char* path)
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
		if(!line.empty())
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

		std::string objectName;

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
			// TODO: Implement Matreial Useage
			break;
		case 'm':
			if (lineToken == "mtllib")
				// TODO: Pharse .mtl file
				break;
			else if (lineToken == "mg")
				// TODO: Handle merging group
				break;
		case 'g':
			// Todo: Handle Group
			break;
		case 's':
			// Todo: Handle Group Number
		case 'o':
			for (unsigned int i = 1; i < lineComp.size(); i++)
				objectName.append(lineComp[i]); // treate everything after first comp as object name
			objectIndex = addObject(objectName);
			positionOffset = 0;
			normalOffset = 0;
			textureCoordOffset = 0;
			for (unsigned int i = 0; i < objectIndex; i++) // get object offset
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
}

Entropy::Graphics::Mesh Entropy::Graphics::WavefrontObj::getMesh(const char* objectName)
{
	return getMesh(getObjectIndex(objectName));
}

Entropy::Graphics::Mesh Entropy::Graphics::WavefrontObj::getMesh(unsigned int index)
{
	// Build Mesh
	std::vector<Vertex> vertices;
	for (unsigned int i = 0; i < objects[index].faceIndices.size(); i++)
		vertices.push_back(Vertex(
			objects[index].vertexPositions[objects[index].faceIndices[i].vertexPosition],
			objects[index].vertexNormals[objects[index].faceIndices[i].vertexNormal],
			objects[index].vertexTextureCoords[objects[index].faceIndices[i].vertexTextureCoord]
		));
	std::vector<unsigned int> indices;
	for (unsigned int i = 0; i < objects[index].faceIndices.size(); i++)
		indices.push_back(i);
	std::vector<Texture> textures;

	return Mesh(vertices, indices, textures);
}


