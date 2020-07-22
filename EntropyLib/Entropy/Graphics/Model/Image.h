#pragma once

#include <vector>
#include <string>

namespace Entropy
{
	namespace Graphics
	{
		struct Image
		{
			unsigned int width;
			unsigned int height;
			std::vector<char> data;
		};

		struct __declspec(dllexport) Texture
		{
			unsigned int ID;
			std::string Type;

			Texture(unsigned int id, std::string type) : ID(id), Type(type) {};
		};

		static class __declspec(dllexport) LoadImage
		{
		public:
			static Texture LoadBitmap(const char* path, const char* type);
		};
	}
}