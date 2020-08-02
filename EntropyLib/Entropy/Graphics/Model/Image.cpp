#include "Image.h"

#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "..\..\..\stb_image.h"

#include <iostream>

Entropy::Graphics::Image Entropy::Graphics::LoadTexture::LoadBitmap(std::string path)
{
#ifdef _DEBUG
	std::cout << "Loading Bitmap: " << path << std::endl;
#endif // DEBUG

	// load file into buffer
	std::ifstream file;
	file.open(path, std::ios::binary);
	if (!file.is_open())
	{
		std::string error = "Unable to open file: ";
		error.append(path);
		throw std::exception(error.c_str());
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
	std::cout << "Loading successful: width:" << result.width << "px, height:" << result.height << "px" << std::endl;
#endif // DEBUG	
	return result;
}

Entropy::Graphics::Image Entropy::Graphics::LoadTexture::LoadJPEG(std::string path)
{
	// load file into buffer
	std::ifstream file;
	file.open(path, std::ios::binary);
	if (!file.is_open())
	{
		std::string error = "Unable to open file: ";
		error.append(path);
		throw std::exception(error.c_str());
	}
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

	// generate image from loaded data
	Image result;

#ifdef _DEBUG
	std::cout << "Loading successful: width:" << result.width << "px, height:" << result.height << "px" << std::endl;
#endif // DEBUG	
	return result;
}

Entropy::Graphics::Image Entropy::Graphics::LoadTexture::LoadGif(std::string path)
{
#ifdef _DEBUG
	std::cout << "Loading Bitmap: " << path << std::endl;
#endif // DEBUG
	// load file into buffer
	std::ifstream file;
	file.open(path, std::ios::binary);
	if (!file.is_open())
	{
		std::string error = "Unable to open file: ";
		error.append(path);
		throw std::exception(error.c_str());
	}
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

	// generate image from loaded data
	Image result;

#ifdef _DEBUG
	std::cout << "Loading successful: width:" << result.width << "px, height:" << result.height << "px" << std::endl;
#endif // DEBUG	
	return result;
}

Entropy::Graphics::Image Entropy::Graphics::LoadTexture::LoadTiff(std::string path)
{
#ifdef _DEBUG
	std::cout << "Loading Bitmap: " << path << std::endl;
#endif // DEBUG
	// load file into buffer
	std::ifstream file;
	file.open(path, std::ios::binary);
	if (!file.is_open())
	{
		std::string error = "Unable to open file: ";
		error.append(path);
		throw std::exception(error.c_str());
	}
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

	// generate image from loaded data
	Image result;

#ifdef _DEBUG
	std::cout << "Loading successful: width:" << result.width << "px, height:" << result.height << "px" << std::endl;
#endif // DEBUG	
	return result;
}

Entropy::Graphics::Image Entropy::Graphics::LoadTexture::LoadPNG(std::string path)
{
#ifdef _DEBUG
	std::cout << "Loading Bitmap: " << path << std::endl;
#endif // DEBUG
	// load file into buffer
	std::ifstream file;
	file.open(path, std::ios::binary);
	if (!file.is_open())
	{
		std::string error = "Unable to open file: ";
		error.append(path);
		throw std::exception(error.c_str());
	}
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	file.close();

	// generate image from loaded data
	Image result;
	
#ifdef _DEBUG
	std::cout << "Loading successful: width:" << result.width << "px, height:" << result.height << "px" << std::endl;
#endif // DEBUG	
	return result;
}



Entropy::Graphics::Texture Entropy::Graphics::LoadTexture::LoadFromFile(std::string path, std::string type)
{
	// Determine image format
	std::string imgType = path.substr(path.find_last_of("."), path.size() - 1);

	Image image;
	// Convert based on type
	if (imgType == ".bmp" || imgType == ".dib")
		image = LoadBitmap(path);
	else if (imgType == ".jpg" || imgType == ".jpeg" || imgType == ".jpe" || imgType == ".jfif")
		image = LoadJPEG(path);
	else if (imgType == ".gif")
		image = LoadGif(path);
	else if (imgType == ".tif" || imgType == ".tiff")
		image = LoadTiff(path);
	else if (imgType == ".png")
		image = LoadPNG(path);
	else
	{
		std::string errStr = "Image format not supported: " + imgType + ", " + path;
		throw std::exception(errStr.c_str());
	}

	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Load Image into Texture.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, (char*)&image.data[0]);

	return Texture(id, type);
}

Entropy::Graphics::Texture Entropy::Graphics::LoadTexture::LoadFromImageFile(std::string path, std::string type)
{
#ifdef _DEBUG
	std::cout << "Loading Image: " << path << std::endl;
#endif // DEBUG
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Load Image into Texture.
	if (type == "texture_diffuse")
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else if (type == "sprite_sheet")
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	stbi_image_free(data);

#ifdef _DEBUG
	std::cout << "Loading successful: width:" << width << "px, height:" << height << "px" << std::endl << std::endl;
#endif // DEBUG	

	return Texture(id, type);
}

Entropy::Graphics::Texture Entropy::Graphics::LoadTexture::LoadCubeMap(std::vector<std::string> paths)
{
#ifdef _DEBUG
	std::cout << "Loading Cube Map:" << std::endl;
#endif // DEBUG
	unsigned int id;
	glGenTextures(1, &id);

	int width, height, nrChannels;
	for (unsigned int i = 0; i < paths.size(); i++)
	{
		unsigned char* data = stbi_load(paths[i].c_str(), &width, &height, &nrChannels, 0);

		// Load Image into Texture.
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_SRGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);

#ifdef _DEBUG
		std::cout << "Loading " << paths[i] << " successful: width:" << width << "px, height:" << height << "px" << std::endl;
#endif // DEBUG	
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

#ifdef _DEBUG
	std::cout << std::endl;
#endif // DEBUG	

	return Texture(id, "texture_cubemap");
}
