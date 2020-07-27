#version 330 core
out vec4 FragColor;
  
in vec2 texCoord;

uniform sampler2D screenTexture;

void normal();
void inverted();
void grayscale();
void kernel(float[9] kernel);

const float offset = 1.0 / 300.0;

void main()
{ 
    normal();

    //kernel(float[](
    //    1,  1, 1,
    //    1, -8, 1,
    //    1,  1, 1
    //)); // Sharpen
}

void normal()
{
    FragColor = texture(screenTexture, texCoord);
}

void inverted()
{
    FragColor = vec4(vec3(1.0 - texture(screenTexture, texCoord)), 1.0);
}

void grayscale()
{
    FragColor = texture(screenTexture, texCoord);
    float average = 0.2126 * FragColor.r + 0.7152 * FragColor.g + 0.0722 * FragColor.b;
    FragColor = vec4(average, average, average, 1.0);
}

void kernel(float[9] kernel)
{
    vec2 offsets[9] = vec2[] (
        vec2(-offset,  offset), // top-left
        vec2( 0.0f,    offset), // top-center
        vec2( offset,  offset), // top-right
        vec2(-offset,  0.0f),   // center-left
        vec2( 0.0f,    0.0f),   // center-center
        vec2( offset,  0.0f),   // center-right
        vec2(-offset, -offset), // bottom-left
        vec2( 0.0f,   -offset), // bottom-center
        vec2( offset, -offset)  // bottom-right  
    );

    vec3 sampleTex[9];
    for(int i = 0; i < 9; i++)
        sampleTex[i] = vec3(texture(screenTexture, texCoord.st + offsets[i]));
    vec3 col = vec3(0.0);
    for(int i = 0; i < 9; i++)
        col += sampleTex[i] * kernel[i];
    FragColor = vec4(col, 1.0);
}