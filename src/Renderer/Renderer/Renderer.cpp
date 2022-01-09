//
// Created by MatheusBD on 30/11/2021.
//

#include <Mesh/Mesh.h>
#include <Camera/Camera.h>
#include "Renderer.h"

// in the future receives a mesh, shader and camera, and sets them all, unbinds at the end
void Renderer::render(Mesh* mesh, Camera* camera)
{
    mesh->bind();

    camera->use();

//    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh->getSize());

    mesh->unbind();
}

void Renderer::prepare()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

std::vector<Vertex> Renderer::createCube(float x, float y, float z)
{
    glm::vec4 generalColor = { 0.2, 0.65f, 0.32f, 1.0f };

    glm::vec3 face1Normal = {0.0f,  0.0f, -1.0f};
    glm::vec3 face2Normal = {0.0f,  0.0f, 1.0f};
    glm::vec3 face3Normal = {-1.0f,  0.0f,  0.0f};
    glm::vec3 face4Normal = {1.0f,  0.0f,  0.0f};
    glm::vec3 face5Normal = {0.0f, -1.0f,  0.0f};
    glm::vec3 face6Normal = {0.0f,  1.0f,  0.0f};

    Vertex v0 =  Vertex{{-0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face1Normal};
    Vertex v1 =  Vertex{{ 0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face1Normal};
    Vertex v2 =  Vertex{{ 0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face1Normal};
    Vertex v3 =  Vertex{{ 0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face1Normal};
    Vertex v4 =  Vertex{{-0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face1Normal};
    Vertex v5 =  Vertex{{-0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face1Normal};

    Vertex v6 =  Vertex{{-0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face2Normal};
    Vertex v7 =  Vertex{{ 0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face2Normal};
    Vertex v8 =  Vertex{{ 0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face2Normal};
    Vertex v9 =  Vertex{{ 0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face2Normal};
    Vertex v10 = Vertex{{-0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face2Normal};
    Vertex v11 = Vertex{{-0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face2Normal};

    Vertex v12 = Vertex{{-0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face3Normal};
    Vertex v13 = Vertex{{-0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face3Normal};
    Vertex v14 = Vertex{{-0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face3Normal};
    Vertex v15 = Vertex{{-0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face3Normal};
    Vertex v16 = Vertex{{-0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face3Normal};
    Vertex v17 = Vertex{{-0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face3Normal};

    Vertex v18 = Vertex{{ 0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face4Normal};
    Vertex v19 = Vertex{{ 0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face4Normal};
    Vertex v20 = Vertex{{ 0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face4Normal};
    Vertex v21 = Vertex{{ 0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face4Normal};
    Vertex v22 = Vertex{{ 0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face4Normal};
    Vertex v23 = Vertex{{ 0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face4Normal};

    Vertex v24 = Vertex{{-0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face5Normal};
    Vertex v25 = Vertex{{ 0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face5Normal};
    Vertex v26 = Vertex{{ 0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face5Normal};
    Vertex v27 = Vertex{{ 0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face5Normal};
    Vertex v28 = Vertex{{-0.5f + x, -0.5f + y,  0.5f + z }, generalColor, face5Normal};
    Vertex v29 = Vertex{{-0.5f + x, -0.5f + y, -0.5f + z }, generalColor, face5Normal};

    Vertex v30 = Vertex{{-0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face6Normal};
    Vertex v31 = Vertex{{ 0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face6Normal};
    Vertex v32 = Vertex{{ 0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face6Normal};
    Vertex v33 = Vertex{{ 0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face6Normal};
    Vertex v34 = Vertex{{-0.5f + x,  0.5f + y,  0.5f + z }, generalColor, face6Normal};
    Vertex v35 = Vertex{{-0.5f + x,  0.5f + y, -0.5f + z }, generalColor, face6Normal};

    return {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18,
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35};
}

