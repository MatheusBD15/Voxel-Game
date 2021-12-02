//
// Created by MatheusBD on 27/11/2021.
//

#include "VAO.h"

VAO::VAO(std::vector<float> vertices, std::vector<unsigned int> indices)
{
    glCreateVertexArrays(1, &m_id);
    glBindVertexArray(m_id);

    m_VBO = new VBO(vertices);
    m_EBO = new EBO(indices);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void VAO::bind() const
{
    glBindVertexArray(m_id);
}

void VAO::unbind() const
{
    glBindVertexArray(0);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_id);
    delete(m_EBO);
    delete(m_VBO);
}