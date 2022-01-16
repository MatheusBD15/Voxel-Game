//
// Created by MatheusBD on 30/11/2021.
//

#include <Mesh/Mesh.h>
#include <Camera/Camera.h>
#include "Renderer.h"

// in the future receives a mesh, shader and camera, and sets them all, unbinds at the end
void Renderer::Render(RenderableMesh& renderable, const Camera& camera)
{
    renderable.Connect();

    Shader& shader = renderable.GetShader();

    shader.setUniform("uView", camera.GetView());
    shader.setUniform("uProjection", camera.GetProjection());

    auto [ start, finish ] = renderable.Offsets();
    glDrawArrays(renderable.PrimitiveType(), start, finish);

    renderable.Disconnect();
}

void Renderer::Prepare()
{
    glClearColor(52.0f / 255.0f, 200.0f / 255.0f, 251.0f / 235.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Init()
{
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    glFrontFace(GL_CCW);
    glCullFace(GL_FRONT);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
