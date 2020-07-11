#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec4 aTexCoord;

out vec4 vertexColor;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	//gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	vertexColor = aColor;
	texCoord = vec2(aTexCoord.x, aTexCoord.y);
}