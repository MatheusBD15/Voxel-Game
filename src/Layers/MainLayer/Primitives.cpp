//
// Created by MBDambo on 15/01/2022.
//

#include "Primitives.h"

Mesh Primitives::cube(glm::vec3 scale, glm::vec3 color)
{
    // Unit cube, has 1 of width
    scale *= 0.5f;

    std::vector<Vertex> mesh {
            { -scale.x,  scale.y, -scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y, -scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y, -scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y, -scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y, -scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            {  scale.x, -scale.y, -scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },

            {  scale.x, -scale.y,  scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y,  scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y,  scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y,  scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y,  scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },
            { -scale.x,  scale.y,  scale.z,   0.0f,  0.0f, -1.0f,  color.r, color.g, color.b },

            { -scale.x,  scale.y,  scale.z,  -1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y,  scale.z,  -1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y, -scale.z,  -1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y, -scale.z,  -1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x,  scale.y, -scale.z,  -1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x,  scale.y,  scale.z,  -1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },

            {  scale.x,  scale.y,  scale.z,   1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y, -scale.z,   1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x, -scale.y, -scale.z,   1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x, -scale.y, -scale.z,   1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x, -scale.y,  scale.z,   1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y,  scale.z,   1.0f,  0.0f,  0.0f,  color.r, color.g, color.b },

            { -scale.x,  scale.y, -scale.z,   0.0f, -1.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y, -scale.z,   0.0f, -1.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y,  scale.z,   0.0f, -1.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x,  scale.y,  scale.z,   0.0f, -1.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x,  scale.y,  scale.z,   0.0f, -1.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x,  scale.y, -scale.z,   0.0f, -1.0f,  0.0f,  color.r, color.g, color.b },

            { -scale.x, -scale.y, -scale.z,   0.0f,  1.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y,  scale.z,   0.0f,  1.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x, -scale.y,  scale.z,   0.0f,  1.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x, -scale.y,  scale.z,   0.0f,  1.0f,  0.0f,  color.r, color.g, color.b },
            {  scale.x, -scale.y, -scale.z,   0.0f,  1.0f,  0.0f,  color.r, color.g, color.b },
            { -scale.x, -scale.y, -scale.z,   0.0f,  1.0f,  0.0f,  color.r, color.g, color.b }
    };

    return Mesh{std::move(mesh)};
}
