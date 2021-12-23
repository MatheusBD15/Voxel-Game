//
// Created by MatheusBD on 28/11/2021.
//

#ifndef VOXELGAME_MESH_H
#define VOXELGAME_MESH_H

#include <VAO/VAO.h>

class Mesh
{
private:
    VAO* m_VAO;

public:
    Mesh(std::vector<float> vertices, std::vector<unsigned int> indices);
    Mesh() = default;
    ~Mesh();

    VAO* getVAO() { return m_VAO; }

    void bind();

    void unbind();
};


#endif //VOXELGAME_MESH_H
