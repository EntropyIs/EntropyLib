#include <Entropy/Graphics/Model/WavefrontObj.h>
#include <Entropy/Graphics/Mesh.h>

#include <Entropy/Math/Vec3.h>

#include <iostream>
#include <vector>

using namespace Entropy;

int main(int argc, char* argv[])
{
	// Load objects from file
	Graphics::WavefrontObj object("platonic.obj");
	std::vector<Graphics::Vertex> vertices = object.getVertices("icosahedron");
	std::vector<unsigned int> indices = object.getIndices("icosahedron");

	for (int i = 0; i < indices.size(); i += 3) // add 3 each time to get next tri
	{
		Math::Vec3 U = vertices[i + 1].Position - vertices[i].Position; 
		Math::Vec3 V = vertices[i + 2].Position - vertices[i].Position;

		Math::Vec3 Normal = Math::cross(U, V);

		std::cout << "vn " << Normal.I << " " << Normal.J << " " << Normal.K << std::endl;
	}

	return 0;
}
