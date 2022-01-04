//
// Created by MatheusBD on 27/11/2021.
//

#include "VBO.h"
#include <vector>

VBO::VBO(std::vector<Vertex> vertices)
{
    glCreateBuffers(1, &m_Id);
    m_vertices = std::move(vertices);

    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
    glBufferStorage(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_DYNAMIC_STORAGE_BIT);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &m_Id);
}

