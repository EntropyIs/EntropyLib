#pragma once

namespace Entropy
{
	struct Image
	{
		unsigned long width;
		unsigned long height;
		char* data;
	};

	Image* __declspec(dllexport) loadImage(const char* filename);
	bool __declspec(dllexport) loadBitmap(const char* filename, Image* image);

	unsigned int __declspec(dllexport) generateTexture(const char* filename);
}
