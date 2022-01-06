//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_VBO_H
#define VOXELGAME_VBO_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <vector>
#include <Utils/Vertex.h>

class VBO
{
private:
    unsigned int m_Id;
    std::vector<Vertex> m_vertices;

public:
    VBO() = default;
    ~VBO();

    explicit VBO(const std::vector<Vertex>& vertices);

    inline unsigned int getId() const { return m_Id; };
};


#endif //VOXELGAME_VBO_H
