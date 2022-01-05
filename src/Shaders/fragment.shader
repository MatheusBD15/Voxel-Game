#version 330 core
out vec4 FragColor;

in vec4 vColor;

uniform vec4 lightColor;

void main()
{
    float ambientStrength = 0.1;
    vec4 ambient = ambientStrength * lightColor;

    vec4 result = ambient * vColor;

    FragColor = result;
}
