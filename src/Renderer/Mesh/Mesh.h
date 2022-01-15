//
// Created by MatheusBD on 28/11/2021.
//

#ifndef VOXELGAME_MESH_H
#define VOXELGAME_MESH_H

#include <VAO/VAO.h>

class Mesh
{
private:
    VAO* m_VAO;
    unsigned int m_size;

public:
    Mesh(const std::vector<Vertex>& vertices);
    Mesh() = default;
    ~Mesh();

    inline VAO* getVAO() { return m_VAO; }

    inline unsigned int getSize() const { return m_size; }

    void bind();

    void unbind();

    static glm::vec3 normalizeTriangle(std::array<glm::vec3, 3>& triangle);
};


#endif //VOXELGAME_MESH_H
