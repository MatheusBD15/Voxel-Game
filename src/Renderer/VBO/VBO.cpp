//
// Created by MatheusBD on 27/11/2021.
//

#include "VBO.h"
#include <vector>
#include <iostream>

VBO::VBO(std::vector<Vertex> vertices)
{
    std::cout << "VERTICES" << std::endl;

    for (auto i : vertices)
    {
        std::cout << i.position.x << " ";
        std::cout << i.position.y << " ";
        std::cout << i.position.z << " " << std::endl;
    }

    glCreateBuffers(1, &m_Id);
    m_vertices = std::move(vertices);

    std::cout << "M_VERTICES" << std::endl;

    for (auto i : m_vertices)
    {
        std::cout << i.position.x << " ";
        std::cout << i.position.y << " ";
        std::cout << i.position.z << " " << std::endl;
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
    glBufferStorage(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_DYNAMIC_STORAGE_BIT);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &m_Id);
}

