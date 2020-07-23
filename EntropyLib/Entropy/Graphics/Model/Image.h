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

		struct Texture
		{
			unsigned int ID;
			std::string Type;

			Texture(unsigned int id, std::string type) : ID(id), Type(type) {};
		};

		class __declspec(dllexport) LoadTexture
		{
		private:
			static Image LoadBitmap(std::string path);
			static Image LoadJPEG(std::string path);
			static Image LoadGif(std::string path);
			static Image LoadTiff(std::string path);
			static Image LoadPNG(std::string path);
		public:
			static Texture LoadFromFile(std::string path, std::string type);
			static Texture LoadImage(std::string path, std::string type);
		};
	}
}