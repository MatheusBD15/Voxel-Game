//
// Created by MatheusBD on 30/11/2021.
//

#ifndef VOXELGAME_RENDERER_H
#define VOXELGAME_RENDERER_H

#include <Mesh/Mesh.h>
#include <Camera/Camera.h>
#include <memory>
#include <Mesh/RenderableMesh.h>


class Renderer
{
public:
    Renderer() = delete;
    ~Renderer() = delete;

public:
    static void Init();

    static void Prepare();

    static void Render(RenderableMesh& renderable, const Camera& camera);
};



#endif //VOXELGAME_RENDERER_H
