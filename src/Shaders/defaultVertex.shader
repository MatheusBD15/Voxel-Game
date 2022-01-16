 #version 440 core

 layout (location = 0) in vec3 iPosition;
 layout (location = 1) in vec3 iNormal;
 layout (location = 2) in vec3 iColor;

 uniform mat4 uView;
 uniform mat4 uProjection;

 out vec3 aPosition;
 out vec3 aNormal;
 out vec3 aColor;

 void main()
 {
     aPosition = iPosition;
     aNormal = iNormal;
     aColor = iColor;

     gl_Position = uProjection * uView * vec4(iPosition, 1.0f);
 }
