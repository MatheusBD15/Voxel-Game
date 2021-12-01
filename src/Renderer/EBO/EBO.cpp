//
// Created by MatheusBD on 27/11/2021.
//

#include "EBO.h"

EBO::EBO(std::vector<unsigned int> indices)
{
    glCreateBuffers(1, &m_id);
    m_indices = std::move(indices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_DYNAMIC_STORAGE_BIT);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &m_id);
}
