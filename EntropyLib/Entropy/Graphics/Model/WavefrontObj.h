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

			struct Data {
				std::string objectName;
				std::vector<Math::Vec3> vertexPositions;
				std::vector<Math::Vec3> vertexNormals;
				std::vector<Math::Vec2> vertexTextureCoords;
				std::vector<FaceIndex> faceIndices;
				Data(std::string objectName);
			};

			std::vector<Data> objects;

			void pharseVertexPosition(std::vector<std::string> lineData, unsigned int index);
			void pharseTextureCoord(std::vector<std::string> lineData, unsigned int index);
			void pharseNormal(std::vector<std::string> lineData, unsigned int index);
			void pharseFace(std::vector<std::string> lineData, unsigned int index, unsigned int positionOffset, unsigned int textureCoordOffset, unsigned int normalOffset);

			unsigned int addObject(std::string objectName);

			unsigned int getObjectIndex(std::string objectName);
			bool hasObject(std::string objectName);

		public:
			WavefrontObj(const char* path);

			Mesh getMesh(const char* objectName);
			Mesh getMesh(unsigned int index);

			std::vector<Vertex> getVertices(const char* objectName);
			std::vector<Vertex> getVertices(unsigned int index);

			std::vector<unsigned int> getIndices(const char* objectName);
			std::vector<unsigned int> getIndices(unsigned int index);
		};
	}
}