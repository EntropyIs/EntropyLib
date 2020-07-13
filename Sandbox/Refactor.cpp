#include<Entropy/Graphics/Window.h>

#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		// Initalize Window
		Entropy::Graphics::Window window("My OpenGL Window");
		window.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		// Render Loop
		while (!window.getShouldClose())
		{
			// Input
			// Set window to close when KEY_ESCAPE is pressed
			if (window.getKeyPressed(Entropy::Graphics::GLKeys::KEY_ESCAPE))
				window.setShouldClose(true);

			// Render
			window.clear();

			// Update
			window.processEvents();
		}
		return 0;
	}
	catch (std::exception e)
	{
		// Handle Exeptions
		std::cout << e.what() << std::endl;
		return -1;
	}
}