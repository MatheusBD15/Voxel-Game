//
// Created by MBDambo on 23/12/2021.
//

#ifndef VOXELGAME_LAYER_H
#define VOXELGAME_LAYER_H


#include <Events/Event.h>

class Layer {
public:
    Layer() {}
    virtual ~Layer() {}

    virtual void onAttach() {}
    virtual void onDetach() {}
    virtual void onUpdate() {}
    virtual void onEvent(Event& event) {}
};

#endif //VOXELGAME_LAYER_H
