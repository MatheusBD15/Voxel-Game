//
// Created by MatheusBD on 27/11/2021.
//

#include "VAO.h"

VAO::VAO()
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


    glCreateVertexArrays(1, &m_id);
    glBindVertexArray(m_id);

    m_VBO = new VBO(vertices);
    m_EBO = new EBO(indices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VAO::bind() const
{
    glBindVertexArray(m_id);
}

void VAO::unbind() const
{
    glBindVertexArray(0);
}

void VAO::deallocate() const
{
    glDeleteVertexArrays(1, &m_id);
    m_EBO->deallocate();
    m_VBO->deallocate();
}