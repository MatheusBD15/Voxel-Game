//
// Created by MatheusBD on 30/11/2021.
//

#ifndef VOXELGAME_RENDERER_H
#define VOXELGAME_RENDERER_H


class Renderer
{
public:
    Renderer() = default;

    static void prepare();

    static void render(Mesh* mesh, Camera* camera);
};


#endif //VOXELGAME_RENDERER_H
