//
// Created by MBDambo on 23/12/2021.
//

#ifndef VOXELGAME_MAINLAYER_H
#define VOXELGAME_MAINLAYER_H


#include <Layers/Layer.h>
#include <iostream>

class MainLayer : public Layer {
public:
    MainLayer() {}
    ~MainLayer() {}

    void onUpdate() override
    {
    }

    void onAttach() override
    {
        std::cout << "Attach";
    }

    void onDetach() override
    {
        std::cout << "Detach";
    }

    void onEvent(Event& event) override
    {
        std::cout << "EVENTO";
    }
};


#endif //VOXELGAME_MAINLAYER_H
