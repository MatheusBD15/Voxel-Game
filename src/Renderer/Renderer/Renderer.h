//
// Created by MatheusBD on 30/11/2021.
//

#ifndef VOXELGAME_RENDERER_H
#define VOXELGAME_RENDERER_H

#include <Mesh/Mesh.h>
#include <Camera/Camera.h>


class Renderer
{
public:
    Renderer() = default;

    static void prepare();

    static void render(Mesh* mesh, Camera* camera);

    static std::vector<Vertex> createCube(float x, float y);
};


#endif //VOXELGAME_RENDERER_H
