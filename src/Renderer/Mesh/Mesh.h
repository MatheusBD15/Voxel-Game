//
// Created by MatheusBD on 28/11/2021.
//

#ifndef VOXELGAME_MESH_H
#define VOXELGAME_MESH_H

#include <Utils/Vertex.h>
#include <vector>

class Mesh
{
public:
    Mesh() = default;

    Mesh(std::vector<Vertex>&& vertices)
            : m_Vertices{std::move(vertices)}
    {
    }

    Mesh(const Mesh& other)
    {
        m_Vertices = std::move(other.m_Vertices);
    }

    Mesh(Mesh&&);

    ~Mesh() = default;

protected:
    std::vector<Vertex> m_Vertices;
};


#endif //VOXELGAME_MESH_H
