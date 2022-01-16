//
// Created by MBDambo on 15/01/2022.
//

#ifndef VOXELGAME_RENDERABLEMESH_H
#define VOXELGAME_RENDERABLEMESH_H


#include <Shader/Shader.h>
#include <Utils/Vertex.h>
#include <vector>
#include "Mesh.h"

#define BIT(x) 1 << x
#define OFFSET_S(struct, attribute) (const void*)offsetof(struct, attribute)
#define BYTES_V(type, vector) sizeof(type) * vector.size()

enum VAO_LAYOUT
{
    POSITION = BIT(1),
    NORMAL = BIT(2),
    COLOR = BIT(3),
};

class RenderableMesh : public Mesh
{
private:
    Shader m_Shader;

    int m_Primitive;
    int m_Layout;
    GLuint m_Vao, m_Vbo;

public:
    RenderableMesh() = default;

    RenderableMesh(std::vector<Vertex>&& vertices, const char* vert, const char* frag, int layout, int primitive)
            : Mesh{std::move(vertices)}
            , m_Shader{Shader{vert, frag}}
            , m_Layout(layout)
            , m_Primitive(primitive)
    {
        InitBuffers();
    }

    RenderableMesh(Mesh mesh, const char* vert, const char* frag, int layout, int primitive)
            : Mesh(mesh)
            , m_Shader{Shader{vert, frag}}
            , m_Layout(layout)
            , m_Primitive(primitive)
    {
        InitBuffers();
    }

    ~RenderableMesh()
    {
        glDeleteBuffers(1, &m_Vbo);
        glDeleteVertexArrays(1, &m_Vao);
    }

public:
    inline void Connect()
    {
        glBindVertexArray(m_Vao);
        m_Shader.use();
    }

    inline void Disconnect()
    {
        m_Shader.unUse();
        glBindVertexArray(0);
    }

    inline Shader& GetShader()
    {
        return m_Shader;
    }

    inline int PrimitiveType() const
    {
        return m_Primitive;
    }

    inline std::pair<int, int> Offsets()
    {
        return { 0, m_Vertices.size() };
    }

private:
    void InitBuffers();
};



#endif //VOXELGAME_RENDERABLEMESH_H
