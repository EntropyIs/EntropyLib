#pragma once

#include <vector>

namespace Entropy
{
	class __declspec(dllexport) Texture
	{
	private:
		struct Image
		{
			int width;
			int height;
			std::vector<char> data;
		};

		Image loadBitmap(const char* path);

	public:
		unsigned int ID;
		Texture(const char* path);
	};
}
