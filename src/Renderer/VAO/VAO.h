//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_VAO_H
#define VOXELGAME_VAO_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "Vbo/VBO.h"
#include "Ebo/EBO.h"

class VAO
{
private:
    unsigned int m_id = 0;
    VBO* m_VBO;
    EBO* m_EBO;

public:
    VAO();

    void bind() const;

    void unbind() const;

    void deallocate() const;

    unsigned int getId() const { return m_id; }

    VBO* getVbo() const { return m_VBO; }

    EBO* getEbo() const { return m_EBO; }
};


#endif //VOXELGAME_VAO_H
