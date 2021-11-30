//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_VBO_H
#define VOXELGAME_VBO_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <vector>
#include <Utils/Vertice.h>

class VBO
{
private:
    unsigned int m_id;
    std::vector<float> m_vertices;

public:
    VBO() = default;

    explicit VBO(std::vector<float> vertices);

    unsigned int getId() const { return m_id; };

    void deallocate() const;
};


#endif //VOXELGAME_VBO_H
