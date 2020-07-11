#include <GLApplication.h>
#include <GLWindow.h>
#include <GLShader.h>
#include <GLTexture.h>
#include <Matrix4Ext.h>
#include <thread>

using namespace Entropy;
using namespace Entropy::Math;

int main(int argc, char* argv[])
{
	//Initalize OpenGL Window
	GLWindow window(800, 600, "OpenGL Sandbox");
	window.setWindowClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	//Graphics Loop
	while (!window.getShouldClose())
	{
		//Input

		//Render
		window.render();

		//Update

		window.processEvents();
	}
}