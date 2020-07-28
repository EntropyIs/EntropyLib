#version 330 core
out vec4 FragColor;

in vec3 normal;  
in vec3 fragPos;  
in vec2 texCoord;

void main()
{
	FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}