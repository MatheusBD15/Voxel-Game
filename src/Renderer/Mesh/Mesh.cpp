//
// Created by MatheusBD on 28/11/2021.
//

#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
    m_VAO = new VAO(vertices, indices);
    m_size = vertices.size();
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