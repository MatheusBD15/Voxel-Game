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
#include "Layers/MainLayer/Noise/NoiseGenerator.h"
#include "Layers/MainLayer/Components/Light.h"
#include "Layers/MainLayer/Components/Chunk.h"
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
    int m_chunkWidth = 10;
    int m_chunkNumber = 10;
    Light* m_Light;
    Chunk* m_Chunk1;

    std::vector<Mesh*> m_Meshes;
    std::vector<std::vector<Vertex>> m_Chunks;
    std::vector<std::future<void>> m_Futures;
    std::mutex m_ChunksMutex;

public:
    MainLayer() = default;
    ~MainLayer() override = default;

    void onUpdate(float deltaTime) override;
    void onAttach() override;
    void onDetach() override;
    void onEvent(Event& event) override;

    bool onKeyPressed(KeyPressedEvent& event);
    bool onMouseMoved(MouseMovedEvent& event);

    std::vector<Vertex> generateChunk(int xOffset, int zOffset, std::vector<float>& noise) const;
};


#endif //VOXELGAME_MAINLAYER_H
