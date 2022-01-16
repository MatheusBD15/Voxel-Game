//
// Created by MBDambo on 15/01/2022.
//

#include "RenderableMesh.h"

void RenderableMesh::InitBuffers()
{

    glGenVertexArrays(1, &m_Vao);
    glGenBuffers(1, &m_Vbo);

    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glBufferData(GL_ARRAY_BUFFER, BYTES_V(Vertex, m_Vertices), m_Vertices.data(), GL_STATIC_DRAW);

    if (m_Layout & VAO_LAYOUT::POSITION)
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFFSET_S(Vertex, Position));
        glEnableVertexAttribArray(0);
    }
    if (m_Layout & VAO_LAYOUT::NORMAL)
    {
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFFSET_S(Vertex, Normal));
        glEnableVertexAttribArray(1);
    }
    if (m_Layout & VAO_LAYOUT::COLOR)
    {
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFFSET_S(Vertex, Color));
        glEnableVertexAttribArray(2);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
