#version 330 core
out vec4 FragColor;

in vec3 normal;  
in vec3 fragPos;  
in vec2 texCoord;

#define NR_POINT_LIGHTS 4
#define NR_SPOT_LIGHTS 4

struct Material {
    vec3 color_ambient;
    vec3 color_diffuse;
    vec3 color_specular;
    float shininess;

    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
};

struct DirectionalLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    int use;
};

struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadtratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    int use;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float innerCutOff;
    float outerCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    int use;
};


uniform Material material;
uniform DirectionalLight directionalLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLights[NR_SPOT_LIGHTS];

uniform vec3 viewPos;

vec3 calulateDirectionalLighting(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 calulatePointLighting(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 calulateSpotLighting(SpotLight light, vec3 normal, vec3 viewDir);

void main()
{
    // Properties
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 result;

    // Phase 1: Directional Lighting
    if(directionalLight.use == 1)
        result += calulateDirectionalLighting(directionalLight, norm, viewDir);

    // Phase 2: Point Lights
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        if(pointLights[i].use == 1)
            result += calulatePointLighting(pointLights[i], norm, fragPos, viewDir);

    // Phase 3: Spot Lights
    for(int i = 0; i < NR_SPOT_LIGHTS; i++)
        if(spotLights[i].use == 1)
            result += calulateSpotLighting(spotLights[i], norm, viewDir);

    FragColor = vec4(result, 1.0);
}

vec3 calulateDirectionalLighting(DirectionalLight light, vec3 normal, vec3 viewDir)
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

vec3 calulatePointLighting(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse Shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular Shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Attenuation
    float attDistance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * attDistance + light.quadtratic * (attDistance * attDistance));
    // Combine Results
    vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse1, texCoord)) * attenuation;
    vec3 diffuse = light.diffuse * diff * vec3(texture (material.texture_diffuse1, texCoord)) * attenuation;
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, texCoord)) * attenuation;
    return(ambient + diffuse + specular);
}

vec3 calulateSpotLighting(SpotLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(light.direction);
    // Calulate Base Values
    float theta = dot(lightDir, normalize(-lightDir));
    float epsilon = (light.innerCutOff - light.outerCutOff);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    // Diffuse Shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular Shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    // Combine Results
    vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse1, texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture (material.texture_diffuse1, texCoord)) * intensity;
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, texCoord)) * intensity;
    return(ambient + diffuse + specular);
}
