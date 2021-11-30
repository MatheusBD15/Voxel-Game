//
// Created by MatheusBD on 30/11/2021.
//

#include <Mesh/Mesh.h>
#include "Renderer.h"

// in the future receives a mesh, shader and camera, and sets them all, unbinds at the end
void Renderer::render()
{
    Mesh* mesh = new Mesh();

    mesh->bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    mesh->unbind();
}

void Renderer::prepare()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

