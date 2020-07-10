#include "GLTexture.h"

#include <exception>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <iterator>

#include <GLFW/glfw3.h>

Entropy::Texture::Image Entropy::Texture::loadBitmap(const char* path)
{
#ifdef _DEBUG
	std::cout << "Loading Image: " << path << std::endl;
#endif // _DEBUG

	// load file into buffer
	std::ifstream file;
	file.open(path, std::ios::binary);
	if (!file.is_open())
	{
#ifdef _DEBUG
		std::cout << "Error: Unable to open file" << std::endl;
#endif //_DEBUG
		throw std::exception("Unable to open file");
	}
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

	// generate image from loaded data
	Image result;
	std::vector<char> headerinfo;
	{
		auto it = std::next(buffer.begin(), 54);
		std::move(buffer.begin(), it, std::back_inserter(headerinfo));
		buffer.erase(buffer.begin(), it);
	}

	result.width = *reinterpret_cast<int*>((char*)headerinfo.data() + 18);
	result.height = *reinterpret_cast<int*>((char*)headerinfo.data() + 22);

	int size = 3 * result.width * result.height;

	std::vector<char> imagesdata;
	{
		auto it = std::next(buffer.begin(), size);
		std::move(buffer.begin(), it, std::back_inserter(result.data));
		buffer.erase(buffer.begin(), it);
	}

#ifdef _DEBUG
	std::cout << "Loading successful: width:" << result.width << "px, height:" << result.height << "px"<< std::endl;
#endif // _DEBUG	

	return result;
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