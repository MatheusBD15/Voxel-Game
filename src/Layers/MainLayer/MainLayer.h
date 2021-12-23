//
// Created by MBDambo on 23/12/2021.
//

#ifndef VOXELGAME_MAINLAYER_H
#define VOXELGAME_MAINLAYER_H

#include <Layers/Layer.h>
#include <iostream>

class MainLayer : public Layer {
public:
    MainLayer() = default;
    ~MainLayer() override = default;

    void onUpdate() override;
    void onAttach() override;
    void onDetach() override;
    void onEvent(Event& event) override;
};


#endif //VOXELGAME_MAINLAYER_H
