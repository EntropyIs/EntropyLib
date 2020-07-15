#version 330 core
out vec4 FragColor;

in vec3 normal;  
in vec3 fragPos;  

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;

uniform vec3 viewPos;

void main()
{
    // Ambient Lighting
    vec3 ambient = light.ambient * (vec3(1.0) * material.ambient);

    // Diffuse Lighting
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - fragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (vec3(1.0) * (diff * material.diffuse));

    // Specular Lighting
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = light.specular * (vec3(1.0) *  (spec * material.specular));

    // Combine lighting
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 