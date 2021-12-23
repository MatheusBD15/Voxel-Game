//
// Created by MBDambo on 23/12/2021.
//

#ifndef VOXELGAME_LAYERSTACK_H
#define VOXELGAME_LAYERSTACK_H

#include <Layers/Layer.h>
#include <vector>
#include <algorithm>

class LayerStack {
private:
    std::vector<Layer*> m_Layers;
    std::vector<Layer*>::iterator m_LayerInsert;

public:
    LayerStack();
    ~LayerStack();

    void pushLayer(Layer* layer);
    void pushOverlay(Layer* overlay);
    void popLayer(Layer* layer);
    void popOverlay(Layer* overlay);

    std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
    std::vector<Layer*>::iterator end() { return m_Layers.end(); }
};


#endif //VOXELGAME_LAYERSTACK_H
