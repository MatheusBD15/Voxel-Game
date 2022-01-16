//
// Created by MBDambo on 15/01/2022.
//

#include "Chunk.h"

Chunk::Chunk(glm::vec2 position, Material material)
        : m_Position(position)
        , m_Material(material)
        , m_Heights {
                Terrain::newHeightMap(
                        position, 120, 0.1f
                )
        }
        , m_Renderable {
                RenderableMesh {
                        Mesh{ Terrain::newTerrain(m_Heights, 120) },
                        DEFAULT_VERT, DEFAULT_FRAG,
                        POSITION | NORMAL | COLOR,
                        GL_TRIANGLES
                }
        }
{
    Shader& shader = m_Renderable.GetShader();

    shader.use();
    shader.setUniform("material.ambient", material.ambient);
    shader.setUniform("material.diffuse", material.diffuse);
    shader.setUniform("material.specular", material.specular);
    shader.setUniform("material.shininess", material.shininess);

    shader.unUse();
}


void Chunk::Prepare(glm::vec3 &ligthPos, Lighting &aspects, glm::vec3 cameraPos)
{
    Shader& shader = m_Renderable.GetShader();

    shader.use();
    // Sets camera pos in shader
    shader.setUniform("viewPositiom", cameraPos);
    // Sets light's properties
    shader.setUniform("light.position", ligthPos);

    shader.setUniform("light.ambient", aspects.ambient);
    shader.setUniform("light.diffuse", aspects.diffuse);
    shader.setUniform("light.specular", aspects.specular);

    shader.unUse();
}


