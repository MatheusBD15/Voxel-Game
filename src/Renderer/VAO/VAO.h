//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_VAO_H
#define VOXELGAME_VAO_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "VBO/VBO.h"
#include "EBO/EBO.h"

class VAO
{
private:
    unsigned int m_Id = 0;
    VBO* m_VBO;
    EBO* m_EBO;

public:
    VAO() = default;
    ~VAO();

    VAO(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

    void bind() const;

    void unbind() const;

    unsigned int getId() const { return m_Id; }

    VBO* getVbo() const { return m_VBO; }

    EBO* getEbo() const { return m_EBO; }
};


#endif //VOXELGAME_VAO_H
