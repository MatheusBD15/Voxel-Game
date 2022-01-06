//
// Created by MatheusBD on 27/11/2021.
//

#include "EBO.h"

EBO::EBO(const std::vector<unsigned int>& indices)
{
    glCreateBuffers(1, &m_Id);
    m_Indices = indices;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
    glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), m_Indices.data(), GL_DYNAMIC_STORAGE_BIT);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &m_Id);
}
