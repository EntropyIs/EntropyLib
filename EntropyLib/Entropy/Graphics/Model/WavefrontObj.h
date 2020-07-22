#pragma once

#include "../../Math/Vec2.h"
#include "../../Math/Vec3.h"
#include "../Mesh.h"

#include <vector>
#include <string>

#ifndef LIB_API
#define LIB_API __declspec(dllimport)
#endif // !LIB_API

namespace Entropy
{
	namespace Graphics
	{
		class LIB_API WavefrontObj
		{
		private:
			struct FaceIndex {
				unsigned int vertexPosition;
				unsigned int vertexNormal;
				unsigned int vertexTextureCoord;
				FaceIndex() :vertexPosition(0), vertexNormal(0), vertexTextureCoord(0) {};
			};

			struct ObjectData {
				std::string objectName;
				std::vector<Math::Vec3> vertexPositions;
				std::vector<Math::Vec3> vertexNormals;
				std::vector<Math::Vec2> vertexTextureCoords;
				std::vector<FaceIndex> faceIndices;
				std::string materialName;
				ObjectData(std::string objectName);
			};

			std::vector<ObjectData> objects;
			std::vector<Material> materials;

			std::vector<std::string> mtlFiles;

			void pharseVertexPosition(std::vector<std::string> lineData, unsigned int index);
			void pharseTextureCoord(std::vector<std::string> lineData, unsigned int index);
			void pharseNormal(std::vector<std::string> lineData, unsigned int index);
			void pharseFace(std::vector<std::string> lineData, unsigned int index, unsigned int positionOffset, unsigned int textureCoordOffset, unsigned int normalOffset);

			unsigned int addObject(std::string objectName);
			unsigned int getObjectIndex(std::string objectName);
			bool hasObject(std::string objectName);

			void pharseColorAmbient(std::vector<std::string> lineData, unsigned int index);
			void pharseColorDiffuse(std::vector<std::string> lineData, unsigned int index);
			void pharseColorSpecular(std::vector<std::string> lineData, unsigned int index);
			void pharseShininess(std::vector<std::string> lineData, unsigned int index);
			void pharseTexture(std::vector<std::string> lineData, unsigned int index);

			unsigned int addMaterial(std::string materialName);
			unsigned int getMaterialIndex(std::string materialName);
			bool hasMaterial(std::string materialName);

			bool readObjFile(const char* path);
			bool readMtlFile(const char* path);

		public:
			WavefrontObj(const char* path);

			std::vector<Mesh> getAll();

			Mesh getMesh(const char* objectName);
			Mesh getMesh(unsigned int index);

			std::vector<Vertex> getVertices(const char* objectName);
			std::vector<Vertex> getVertices(unsigned int index);

			std::vector<unsigned int> getIndices(const char* objectName);
			std::vector<unsigned int> getIndices(unsigned int index);

			Material getMaterial(const char* objectName);
			Material getMaterial(unsigned int index);

		};
	}
}