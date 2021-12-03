//
// Created by MatheusBD on 27/11/2021.
//

#include "VBO.h"
#include <vector>

VBO::VBO(std::vector<float> vertices)
{
    glCreateBuffers(1, &m_id);
    m_vertices = std::move(vertices);

    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferStorage(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), m_vertices.data(), GL_DYNAMIC_STORAGE_BIT);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &m_id);
}
