//
// Created by MatheusBD on 27/11/2021.
//

#include <iostream>
#include "VAO.h"

VAO::VAO(const std::vector<Vertex>& vertices )
{
    glCreateVertexArrays(1, &m_Id);
    glBindVertexArray(m_Id);

    m_VBO = new VBO(vertices);

    // position attribute
    glEnableVertexArrayAttrib(m_Id, 0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    // color attribute
    glEnableVertexArrayAttrib(m_Id, 1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Color));

    glEnableVertexArrayAttrib(m_Id, 2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Normal));
}

void VAO::bind() const
{
    glBindVertexArray(m_Id);
}

void VAO::unbind() const
{
    glBindVertexArray(0);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_Id);
    delete(m_EBO);
    delete(m_VBO);
}