//
// Created by MBDambo on 23/12/2021.
//

#ifndef VOXELGAME_MAINLAYER_H
#define VOXELGAME_MAINLAYER_H

#include <Layers/Layer.h>
#include <iostream>
#include <vector>
#include <Events/ApplicationEvent.h>
#include <Events/KeyEvent.h>
#include <Events/MouseEvent.h>
#include <Mesh/Mesh.h>
#include <Shader/Shader.h>
#include <Camera/Camera.h>
#include <Renderer/Renderer.h>
#include <Renderer/Utils/Vertex.h>
#include "NoiseGenerator.h"
#include <stdlib.h>
#include <mutex>
#include <future>

class MainLayer : public Layer {
private:
    Camera* m_Camera;
    Shader* m_Shader;
    float m_DeltaTime = 0.0f;
    int m_mapX = 1024;
    int m_mapZ = 1024;
    std::vector<float> m_Noise;
    int m_chunkWidth = 32;
    int m_chunkNumber = 32;

    std::vector<unsigned int> m_indices = {
            0,1,2,
            1,2,3,
            4,5,6,
            5,6,7,
            0,1,5,
            0,4,5,
            2,3,7,
            2,6,7,
            0,2,6,
            0,4,6,
            1,5,7,
            1,3,7
    };

    std::vector<Mesh*> m_Meshes;
    std::vector<std::future<void>> m_Futures;
    std::mutex m_MeshesMutex;


public:
    MainLayer() = default;
    ~MainLayer() override = default;

    void onUpdate(float deltaTime) override;
    void onAttach() override;
    void onDetach() override;
    void onEvent(Event& event) override;

    bool onKeyPressed(KeyPressedEvent& event);
    bool onMouseMoved(MouseMovedEvent& event);

    Mesh* generateChunk(int xOffset, int zOffset, std::vector<float>& noise);
};


#endif //VOXELGAME_MAINLAYER_H
