//
// Created by MBDambo on 05/01/2022.
//

#ifndef VOXELGAME_NOISEGENERATOR_H
#define VOXELGAME_NOISEGENERATOR_H

#include <array>
#include <stdlib.h>
#include <vector>

class NoiseGenerator
{
public:
    NoiseGenerator() = default;

    static std::vector<float> generate1d(int nCount, int octaves, int outputSize, float scalingBias);
    static std::vector<float> generate2d(int nHeight, int nWidth, int octaves, int outputHeight, int outputWidth, float scalingBias);

};



#endif //VOXELGAME_NOISEGENERATOR_H
