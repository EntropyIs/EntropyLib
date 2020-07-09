#include "GLTexture.h"

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <iterator>

#include <GLFW/glfw3.h>

Entropy::Texture::Image Entropy::Texture::loadBitmap(const char* path)
{
	Image image;

	// load file into buffer
	std::ifstream file;
	file.open(path, std::ios::binary);
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

	std::vector<char> headerinfo;
	{
		auto it = std::next(buffer.begin(), 54);
		std::move(buffer.begin(), it, std::back_inserter(headerinfo));
		buffer.erase(buffer.begin(), it);
	}

	image.width = *reinterpret_cast<int*>((char*)headerinfo.data() + 18);
	image.height = *reinterpret_cast<int*>((char*)headerinfo.data() + 22);

	int size = 3 * image.width * image.height;

	std::vector<char> imagesdata;
	{
		auto it = std::next(buffer.begin(), size);
		std::move(buffer.begin(), it, std::back_inserter(image.data));
		buffer.erase(buffer.begin(), it);
	}

	// display image height and width from header
	std::cout << " width:" << image.width << std::endl;
	std::cout << " height:" << image.height << std::endl;

	return image;
}

Entropy::Texture::Texture(const char* path)
{
	// Load Image.
	Image image = loadBitmap(path);
	// Create Texture.
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load Image into Texture.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, (char*)&image.data[0]);
}