//
// Created by MatheusBD on 28/11/2021.
//

#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
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

glm::vec3 Mesh::normalizeTriangle(std::array<glm::vec3, 3>& triangle)
{
    glm::vec3 u = triangle[1] - triangle [0];
    glm::vec3 v = triangle[2] - triangle [0];

    glm::vec3 normal;

    normal.x = (u.y * v.z) - (u.z * v.y);
    normal.y = (u.z * v.x) - (u.x * v.z);
    normal.z = (u.x * v.y) - (u.y * v.x);

    return normal;
}
