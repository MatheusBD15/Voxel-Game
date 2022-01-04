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
    glDrawArrays(GL_TRIANGLES, 0, 48);

    mesh->unbind();
}

void Renderer::prepare()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

std::vector<Vertex> Renderer::createCube()
{
    glm::vec4 generalColor = { 0.18f, 0.6f, 0.96f, 1.0f };

    Vertex v0 = Vertex{{-0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v1 = Vertex{{ 0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v2 = Vertex{{ 0.5f,  0.5f, -0.5f }, generalColor};
    Vertex v3 = Vertex{{ 0.5f,  0.5f, -0.5f }, generalColor};
    Vertex v4 = Vertex{{ -0.5f,  0.5f, -0.5f }, generalColor};
    Vertex v5 = Vertex{{ -0.5f, -0.5f, -0.5f }, generalColor};

    Vertex v6 = Vertex{{ -0.5f, -0.5f,  0.5f }, generalColor};
    Vertex v7 = Vertex{{ 0.5f, -0.5f,  0.5f }, generalColor};
    Vertex v8 = Vertex{{ 0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v9 = Vertex{{ 0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v10 = Vertex{{ -0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v11 = Vertex{{ -0.5f, -0.5f,  0.5f }, generalColor};

    Vertex v12 = Vertex{{ -0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v13 = Vertex{{ -0.5f,  0.5f, -0.5f }, generalColor};
    Vertex v14 = Vertex{{ -0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v15 = Vertex{{ -0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v16 = Vertex{{ -0.5f, -0.5f,  0.5f }, generalColor};
    Vertex v17 = Vertex{{ -0.5f,  0.5f,  0.5f }, generalColor};

    Vertex v18 = Vertex{{  0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v19 = Vertex{{ 0.5f,  0.5f, -0.5f }, generalColor};
    Vertex v20 = Vertex{{ 0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v21 = Vertex{{ 0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v22 = Vertex{{ 0.5f, -0.5f,  0.5f }, generalColor};
    Vertex v23 = Vertex{{ 0.5f,  0.5f,  0.5f}, generalColor};

    Vertex v24 = Vertex{{ -0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v25 = Vertex{{  0.5f, -0.5f, -0.5f }, generalColor};
    Vertex v26 = Vertex{{  0.5f, -0.5f,  0.5f }, generalColor};
    Vertex v27 = Vertex{{ 0.5f, -0.5f,  0.5f }, generalColor};
    Vertex v28 = Vertex{{  -0.5f, -0.5f,  0.5f }, generalColor};
    Vertex v29 = Vertex{{ -0.5f, -0.5f, -0.5f }, generalColor};

    Vertex v30 = Vertex{{ -0.5f,  0.5f, -0.5f }, generalColor};
    Vertex v31 = Vertex{{ 0.5f,  0.5f, -0.5f }, generalColor};
    Vertex v32 = Vertex{{ 0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v33 = Vertex{{ 0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v34 = Vertex{{ -0.5f,  0.5f,  0.5f }, generalColor};
    Vertex v35 = Vertex{{ -0.5f,  0.5f, -0.5f }, generalColor};

    return {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18,
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35};
}

