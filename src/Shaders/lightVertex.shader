#version 440 core

 layout (location = 0) in vec3 iPosition;
 layout (location = 1) in vec3 iNormal;
 layout (location = 2) in vec3 iColor;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

void main()
 {
     gl_Position = uProjection * uView * uModel * vec4(iPosition, 1.0f);
 }
