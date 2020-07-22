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

			Texture(Image image, std::string type);
		};

		static class __declspec(dllexport) LoadImage
		{
		public:
			static Texture LoadBitmap(const char* path, const char* type);
		};
	}
}