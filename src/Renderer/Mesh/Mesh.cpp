//
// Created by MatheusBD on 28/11/2021.
//

#include "Mesh.h"

Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices)
{
    m_VAO = new VAO(vertices, indices);
}

Mesh::~Mesh()
{
    delete(m_VAO);
}

void Mesh::bind()
{
    m_VAO->bind();
}

void Mesh::unbind()
{
    m_VAO->unbind();
}