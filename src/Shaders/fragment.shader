#version 460 core
out vec4 FragColor;

in vec4 vColor;
in vec3 vNormal;
in vec3 vFragPos;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    // ambient light
    float ambientStrength = 0.2;
    vec4 ambient = ambientStrength * lightColor;

    // diffuse light
    vec3 norm = vNormal;
    vec3 lightDir = normalize(lightPos - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * lightColor;

    // specular light
    float specularStrength = 0.1;
    vec3 viewDir = normalize(viewPos - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * vec3(lightColor.r, lightColor.g, lightColor.b);

    // result light
    vec4 result = (ambient + (diffuse * 0.1) + vec4(0.1) + vec4(specular, 1.0)) * vColor;

//    if(result.r > 0.8 ||  result.g > 0.8 || result.b > 0.8)
//        result = vColor;

    FragColor = result;
}
