//
// Created by MatheusBD on 28/11/2021.
//

#include "Mesh.h"

Mesh::Mesh()
{
    std::vector<unsigned int> indices = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
    };

    std::vector<float> vertices = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
    };

    m_VAO = new VAO(vertices, indices);
}

Mesh::~Mesh()
{
    m_VAO->deallocate();
}

void Mesh::bind()
{
    m_VAO->bind();
}

void Mesh::unbind()
{
    m_VAO->unbind();
}