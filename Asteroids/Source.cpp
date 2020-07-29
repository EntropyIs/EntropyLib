#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Shader.h>

using namespace Entropy;

int main(int argc, char* argv[])
{
	// Load OpenGL Window
	Graphics::Window window("Asteroids Example Project.", 800, 600);
	window.captureMouse();

	// Load Shaders
	Graphics::Shader shader("vBaseShader.glsl", "fLighting.glsl");
	Graphics::Shader skyboxShader("vCubeMap.glsl", "fCubeMap.glsl");

	shader.setUniformBlockBinding("Matrices", 0);

	// Load Scene Assets
}