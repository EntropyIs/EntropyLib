#include "MyGlWindow.h"

int main(int argc, char** argv)
{
	// Open Qt Window
	MyGlWindow myWindow(800, 600, "LearnOpenGL");

	myWindow.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	while (!myWindow.getShouldClose())
	{
		// Input
		if (myWindow.getKeyPressed(GLKeys::KEY_ESCAPE))
			myWindow.setWindowShouldClose(true);

		// Render
		myWindow.render();

		// Update
		myWindow.processEvents();
	}

	return 0;
}