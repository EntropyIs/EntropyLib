#include "MyGlWindow.h"

int main(int argc, char** argv)
{
	// Open Qt Window
	MyGlWindow myWindow(800, 600, "LearnOpenGL");

	while (!myWindow.getShouldClose())
	{
		if (myWindow.getKeyPressed(GLKeys::KEY_ESCAPE))
			myWindow.setWindowShouldClose(true);
		myWindow.processEvents();
	}

	return 0;
}