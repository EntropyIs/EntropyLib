#version 330 core
out vec4 FragColor;

in vec3 normal;  
in vec3 fragPos;  
in vec2 texCoord;

struct Material {
    vec3 color_ambient;
    vec3 color_diffuse;
    vec3 color_specular;
    float shininess;

    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

stuct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
}

uniform Material material;
uniform Light light;

uniform vec3 viewPos;

vec3 calulateDirectionalLighting(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // Diffuse Shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular Shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Combine Results
    vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse1, texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture (material.texture_diffuse1, texCoord));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, texCoord));
    return(ambient + diffuse + specular);
}

void main()
{
    // Ambient Lighting
    vec3 ambient = light.ambient * material.color_ambient * vec3(texture(material.texture_diffuse1, texCoord));

    // Diffuse Lighting
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - fragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * material.color_diffuse * vec3(texture (material.texture_diffuse1, texCoord));

    // Specular Lighting
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = light.specular * spec * material.color_specular * vec3(texture(material.texture_specular1, texCoord));

    // Combine lighting
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}

