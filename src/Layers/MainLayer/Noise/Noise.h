//
// Created by MBDambo on 15/01/2022.
//

#ifndef VOXELGAME_NOISE_H
#define VOXELGAME_NOISE_H

#include <glm/glm.hpp>

namespace Noise
{
    //  Bi-dimensional float noise generator
    float noise2df(float x, float y)
    {
        return sin(x) * cos(y) * 5;
    }

    //  Post pass cleaner function
    float cleanf(float x)
    {
        return round(x);
    }
};

#endif //VOXELGAME_NOISE_H
