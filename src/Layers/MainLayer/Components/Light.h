//
// Created by MBDambo on 15/01/2022.
//

#ifndef VOXELGAME_LIGHT_H
#define VOXELGAME_LIGHT_H


#include <Utils/Lighting.h>
#include <Mesh/RenderableMesh.h>
#include <functional>
#include "Layers/MainLayer/Primitives.h"

#define LIGHT_VERT "C:\\Users\\MBDambo\\Desktop\\vxel\\Shaders\\lightVertex.shader"
#define LIGHT_FRAG "C:\\Users\\MBDambo\\Desktop\\vxel\\Shaders\\lightFrag.shader"

class Light
{
    using pathFn = std::function<glm::vec3(glm::vec3&, float)>;

public:
    Light() = default;

    Light(glm::vec3 position, Lighting aspect, pathFn path)
            : m_Position(position)
            , m_Aspects(aspect)
            , m_Renderable {
                    RenderableMesh {
                            Primitives::Cube(glm::vec3(0.3f)),
                            LIGHT_VERT, LIGHT_FRAG,
                            POSITION | NORMAL | COLOR,
                            GL_TRIANGLES
                    }
            }
            , m_Path(path)
    {
    }

public:
    void Update(float dt)
    {
        m_Position = m_Path(m_Position, dt);
    }

    void Prepare();

    inline RenderableMesh& GetRenderable() { return m_Renderable; }

    inline glm::vec3& GetPosition() { return m_Position; }

    inline Lighting& GetAspect() { return m_Aspects; }

private:
    Lighting m_Aspects;
    glm::vec3 m_Position;
    RenderableMesh m_Renderable;

    pathFn m_Path;
};



#endif //VOXELGAME_LIGHT_H
