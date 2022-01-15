//
// Created by MBDambo on 15/01/2022.
//

#ifndef VOXELGAME_PRIMITIVES_H
#define VOXELGAME_PRIMITIVES_H


#include <Mesh/Mesh.h>

class Primitives
        {
public:
    Primitives() = delete;
    ~Primitives() = delete;

public:
    static Mesh cube(glm::vec3 scale = glm::vec3(1.0f), glm::vec3 color = glm::vec3(1.0f));
};


#endif //VOXELGAME_PRIMITIVES_H
