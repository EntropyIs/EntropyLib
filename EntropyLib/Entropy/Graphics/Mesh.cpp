#include "Mesh.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Entropy::Graphics::Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
	: vertices(vertices), indices(indices), textures(textures)
{
	setupMesh();
}

void Entropy::Graphics::Mesh::Draw(Shader& shader)
{
	shader.use();
	// assign textures
	unsigned int diffuseNr = 0;
	unsigned int specularNr = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, textures[i].ID);

		std::string number;
		std::string name = textures[i].Type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++);
		shader.setInt(("material." + name + "[" + number  + "]").c_str(), i);
	}

	shader.setInt("material.diffuseNr", diffuseNr);
	shader.setInt("material.specularNr", specularNr);

	// draw mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Entropy::Graphics::Mesh::setupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	// vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));

	glBindVertexArray(0);
}

Entropy::Graphics::Mesh Entropy::Graphics::LoadWavefrontObj(const char* path)
{
    try
    {
        // Read File.
        std::ifstream inFile(path);
        inFile.exceptions(std::ifstream::badbit);

        std::string line;
        std::vector<Math::Vec3> Positions;
        std::vector<Math::Vec3> Normals;
        std::vector<Math::Vec2> TexCoords;
        std::vector<FaceIndex> VTNIndices;

        std::vector<Entropy::Graphics::Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Entropy::Graphics::Texture> textures;

        while (inFile.peek() != EOF && std::getline(inFile, line)) //Not EOF, Read Line
        {
            // Skip Empty Line
            if (line.empty())
                continue;

            // Split Line Contents
            std::stringstream stringStream(line);
            std::vector<std::string> components;
            std::string tokenStr;
            while (std::getline(stringStream, tokenStr, ' '))
                if(!tokenStr.empty())
                    components.push_back(tokenStr);
            tokenStr = components[0];

            if (tokenStr == "v") // Phase Vertex Data
            {
#ifdef _DEBUG
                std::cout << "Vertex Data: " << line << ", ";
#endif // _DEBUG
                if (components.size() == 4) // Vec3 Position Data
                    Positions.push_back(Math::Vec3(std::stof(components[1]), std::stof(components[2]), std::stof(components[3])));
                else if (components.size() == 5) // Vec4 Position Data, TODO: decide how to handle W component.
                    Positions.push_back(Math::Vec3(std::stof(components[1]), std::stof(components[2]), std::stof(components[3])));
#ifdef _DEBUG
                else
                    std::cout << "Error Reading Vertex Data.";
#endif // _DEBUG
            }
            else if (tokenStr == "vt")
            {
#ifdef _DEBUG
                std::cout << "Texture Coords Data: " << line << ", ";
#endif // _DEBUG
                if (components.size() == 3) // Vec2 Texture Coord Data
                    TexCoords.push_back(Math::Vec2(std::stof(components[1]), std::stof(components[2])));
                else if (components.size() == 4) // Vec3 Texture Coord Data TODO: Decide how to handle
                    TexCoords.push_back(Math::Vec2(std::stof(components[1]), std::stof(components[2])));
#ifdef _DEBUG
                else
                    std::cout << "Error Reading Texture Coords Data.";
#endif // _DEBUG
            }
            else if (tokenStr == "vn")
            {
#ifdef _DEBUG
                std::cout << "Normal Data: " << line << ", ";
#endif // _DEBUG
                if (components.size() == 4) // Vec3 Normal Data
                    Normals.push_back(Math::normalize(Math::Vec3(std::stof(components[1]), std::stof(components[2]), std::stof(components[3]))));
#ifdef _DEBUG
                else
                    std::cout << "Error Reading Normal Data.";
#endif // _DEBUG
            }
            else if (tokenStr == "p" || tokenStr == "l" || tokenStr == "f")
            {
#ifdef _DEBUG
                std::cout << "Face, Line or Point Data: " << line << ", ";
#endif // _DEBUG
                for (unsigned int i = 1; i < components.size(); i++)
                {
                    std::stringstream vtnStream(components[i]);
                    std::vector<std::string> vtnComponents;
                    std::string vtnTokenStr;
                    while (std::getline(vtnStream, vtnTokenStr, '/'))
                        vtnComponents.push_back(vtnTokenStr);
                    
                    FaceIndex vtnIndex;

                    if (vtnComponents.size() == 3) // VTN
                    {
                        if (vtnComponents[1].empty())
                        {
                            vtnIndex.Position = std::stoi(vtnComponents[0]);
                            vtnIndex.Normal = std::stoi(vtnComponents[2]);
                        }
                        else
                        {
                            vtnIndex.Position = std::stoi(vtnComponents[0]);
                            vtnIndex.TexCoord = std::stoi(vtnComponents[1]);
                            vtnIndex.Normal = std::stoi(vtnComponents[2]);
                        }
                    }
                    else if (vtnComponents.size() == 2) // VT
                    {
                        vtnIndex.Position = std::stoi(vtnComponents[0]);
                        vtnIndex.TexCoord = std::stoi(vtnComponents[1]);
                    }
                    else if (vtnComponents.size() == 1)
                    {
                        vtnIndex.Position = std::stoi(vtnComponents[0]);
                    }
                    VTNIndices.push_back(vtnIndex);
                }
            }
            else if (tokenStr == "u")
            {
#ifdef _DEBUG
                std::cout << "Material desc. settler: " << line << ", ";
#endif // _DEBUG
            }
            else if (tokenStr == "mtllib")
            {
#ifdef _DEBUG
                std::cout << "Material Library: " << line << ", ";
#endif // _DEBUG
            }
            else if (tokenStr == "mg")
            { 
#ifdef _DEBUG
                std::cout << "Merging Group: " << line << ", ";
#endif // _DEBUG
            }
            else if (tokenStr == "g")
            {
#ifdef _DEBUG
                std::cout << "Group Name: " << line << ", ";
#endif // _DEBUG
            }
            else if (tokenStr == "s")
            {
#ifdef _DEBUG
                std::cout << "Group Number: " << line << ", ";
#endif // _DEBUG
            }
            else if (tokenStr == "o")
            {
#ifdef _DEBUG
                std::cout << "Object Name: " << line << ", ";
#endif // _DEBUG
            }
            else if (tokenStr == "#")
            {
#ifdef _DEBUG
                std::cout << "Comment: " << line << ", ";
#endif // _DEBUG
            }
            else
            {
#ifdef _DEBUG
                std::cout << "Unkown Line: " << line << ", ";
#endif // _DEBUG
            }
#ifdef _DEBUG
            std::cout << std::endl;
#endif // _DEBUG
        }

        // Generate Mesh
        for (unsigned int i = 0; i < VTNIndices.size(); i++)
            vertices.push_back(Vertex(Positions[VTNIndices[i].Position - 1], Normals[VTNIndices[i].Normal - 1], TexCoords[VTNIndices[i].TexCoord - 1]));
        // TODO: Optemize loading

        for (unsigned int i = 0; i < VTNIndices.size(); i++)
            indices.push_back(i);
        // TODO: Optimize, currenty each vertex is loaded, this can be reduced by using search function to find index matching VTNIndex.
        
        return Mesh(vertices, indices, textures);
    }
    catch (std::ifstream::failure e)
    {
        std::string errString = "Object file, " + std::string(path) + ", not succefully read. " + e.what();
#ifdef _DEBUG
        std::cout << errString << std::endl;
#endif // _DEBUG
        throw std::exception(errString.c_str());
    }
}

std::vector<Entropy::Graphics::Texture> Entropy::Graphics::LoadTextures(const char* filename)
{
    return std::vector<Texture>();
}
