#version 440 core

out vec4 FragColor;

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 aPosition;
in vec3 aNormal;
in vec3 aColor;

uniform vec3 viewPositiom;
uniform Material material;
uniform Light light;

void main()
{
    vec3 normal = normalize(aNormal);
    vec3 lightDir = normalize(light.position - aPosition);
    vec3 viewDir = normalize(viewPositiom - aPosition);
    vec3 reflectDir = reflect(-lightDir, normal);
    float dist = length(light.position - aPosition) / 10.0f;

    // Ambient component
    vec3 ambient = light.ambient * material.ambient;

    // Difuse component
    float dCoefficient = max(dot(normal, lightDir), 0.0f);
    vec3 diffuse = light.diffuse * (dCoefficient * material.diffuse);

    // Difuse component
    float sCoefficient = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess * 64.0f);
    vec3 specular = light.specular * (sCoefficient * material.specular);

    float attenuation = 1.0f / (1.013f * dist + 0.00045f * pow(dist, 2.5f));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= pow(attenuation, 2.2f);

    vec3 color = ambient + diffuse + specular;

    FragColor = vec4(color, 1.0f);
}
