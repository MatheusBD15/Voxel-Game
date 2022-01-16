//
// Created by MBDambo on 05/01/2022.
//

#include <iostream>
#include "NoiseGenerator.h"

std::vector<float> NoiseGenerator::generate1d(int nCount, int octaves, int outputSize, float scalingBias)
{
    std::vector<float> fNoiseSeed1d;
    fNoiseSeed1d.reserve(outputSize);

    std::vector<float> fPerlinNoise1d;
    fPerlinNoise1d.reserve(outputSize);

    // fill seed array
    for (int i = 0; i < outputSize; ++i)
    {
        fNoiseSeed1d[i] = (float)rand() / (float)RAND_MAX;
    }

    for (int x = 0; x < nCount; ++x)
    {
        float fNoise = 0.0f;
        float fScale = 1.0f;
        float fScaleAcc = 0.0f;

        for (int o = 0; o < octaves; ++o)
        {
            int nPitch = nCount >> o; // divide by 2^o
            int nSample1 = (x / nPitch) * nPitch;

            int nSample2 = (nSample1 + nPitch) % nCount;

            float fBlend = (float)(x - nSample1) / (float)nPitch;
            float fSample = (1.0f - fBlend) * fNoiseSeed1d[nSample1] + fBlend * fNoiseSeed1d[nSample2];

            fNoise += fSample * fScale;

            fScaleAcc += fScale;

            fScale = fScale / scalingBias;
        }

        fPerlinNoise1d[x] = fNoise / fScale;
//        std::cout << fPerlinNoise1d[x] << " : : : ";
    }

    return fPerlinNoise1d;
}

std::vector<float> NoiseGenerator::generate2d(
        int nHeight,
        int nWidth,
        int octaves,
        int outputHeight,
        int outputWidth,
        float scalingBias)
{
    std::vector<float> fNoiseSeed2d (outputHeight * outputWidth);

    std::vector<int> teste (outputHeight * outputWidth);

    std::vector<float> fPerlinNoise2d (outputHeight * outputHeight);
    // fill seed array

    for (int i = 0; i < fNoiseSeed2d.size(); ++i)
    {
        fNoiseSeed2d.at(i) = (float)rand() / (float)RAND_MAX;
    }

    for (int i = 0; i < teste.size(); ++i)
    {
        teste.at(i) = 1;
    }

    for (int x = 0; x < nWidth; ++x)
        for (int y = 0; y < nHeight; ++y)
        {
            float fNoise = 0.0f;
            float fScale = 1.0f;
            float fScaleAcc = 0.0f;

            for (int o = 0; o < octaves; ++o)
            {
                int nPitch = nWidth >> o; // divide by 2^o
                int nSample1X = (x / nPitch) * nPitch;
                int nSample1Y = (y / nPitch) * nPitch;

                int nSample2X = (nSample1X + nPitch) % nWidth;
                int nSample2Y = (nSample1Y + nPitch) % nWidth;

                float fBlendX = (float)(x - nSample1X) / (float)nPitch;
                float fBlendY = (float)(y - nSample1Y) / (float)nPitch;

                float fSampleT = (1.0f - fBlendX) * fNoiseSeed2d.at(nSample1Y * nWidth + nSample1X) + fBlendX * fNoiseSeed2d.at(nSample1Y * nWidth + nSample2X);
                float fSampleB = (1.0f - fBlendX) * fNoiseSeed2d.at(nSample2Y * nWidth + nSample1X) + fBlendX * fNoiseSeed2d.at(nSample2Y * nWidth + nSample2X);

                fNoise += (fBlendY * (fSampleB - fSampleT) + fSampleT) * fScale;
                fScaleAcc += fScale;
                fScale = fScale / scalingBias;
            }

            fPerlinNoise2d.at(y * nWidth + x) = fNoise / fScale;
        }

    return fPerlinNoise2d;

}
