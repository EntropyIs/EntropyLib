#include "GLTexture.h"

#include <stdlib.h>
#include <iostream>
#include <exception>

#include <GLFW/glfw3.h>

Entropy::Image* Entropy::loadImage(const char* filename)
{
    Image* image;

    image = (Image*)malloc(sizeof(Image));
    if(image == NULL)
        throw std::exception("Error allocating space for image");
    if (!loadBitmap(filename, image));
        throw std::exception("Error loading image.");
    return image;
}

bool Entropy::loadBitmap(const char* filename, Image* image)
{
    FILE* file;

    unsigned long size;
    unsigned long i;
    unsigned short int planes;
    unsigned short int bpp;
    char temp;

    // Open file
    if ((file = fopen(filename, "rb")) == NULL)
    {
        std::cout << "File not found: " << filename << std::endl;
        return false;
    }

    // Seek through header to width/height
    fseek(file, 18, SEEK_CUR);

    // Get Width
    if ((i = fread(&image->width, 4, 1, file)) != 1)
    {
        std::cout << "Error reading width from " << filename << std::endl;
        return false;
    }
    std::cout << "Width of " << filename << ": " << image->width << std::endl;

    // Get Height
    if ((i = fread(&image->height, 4, 1, file)) != 1)
    {
        std::cout << "Error reading height from " << filename << std::endl;
        return false;
    }
    std::cout << "Hight of " << filename << ": " << image->width << std::endl;

    // Calulate size of image (assuming 24bit pixel)
    size = image->width * image->height * 3;

    // Read Planes
    if ((fread(&planes, 2, 1, file)) != 1)
    {
        std::cout << "Error reading planes from " << filename << std::endl;
        return false;
    }

    if (planes != 1)
    {
        std::cout << "Planes from " << filename << " is not 1: " << planes << std::endl;
        return false;
    }

    // Read bits-per-pixel
    if ((i = fread(&bpp, 2, 1, file)) != 1)
    {
        std::cout << "Error reading bpp form " << filename << std::endl;
        return false;
    }

    if (bpp != 24) {
        std::cout << "Bpp from " << filename << " is not 24: " << bpp << std::endl;
        return false;
    }

    // Seek past end of bitmap header.
    fseek(file, 24, SEEK_CUR);

    // Read image data
    image->data = (char*)malloc(size);

    if (image->data == NULL)
    {
        std::cout << "Error allocating memory fro color-corrected image data" << std::endl;
        return false;
    }

    if ((i = fread(image->data, size, 1, file)) != 1)
    {
        std::cout << "Error reading image data from " << filename << std::endl;
        return false;
    }

    // Correct colors (bgr -> rgb)
    for (i = 0; i < size; i += 3)
    {
        temp = image->data[i];
        image->data[i] = image->data[i + 2];
        image->data[i + 2] = temp;
    }

    return true;
}

unsigned int Entropy::generateTexture(const char* filename)
{
    Image* image = loadImage(filename);
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
    (GL_TEXTURE_2D);
    return 0;
}
