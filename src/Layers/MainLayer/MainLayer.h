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

class MainLayer : public Layer {
private:
    Camera* m_Camera;
    Shader* m_Shader;
    Mesh* m_Mesh;
    float m_DeltaTime = 0.0f;

public:
    MainLayer() = default;
    ~MainLayer() override = default;

    void onUpdate(float deltaTime) override;
    void onAttach() override;
    void onDetach() override;
    void onEvent(Event& event) override;

    bool onKeyPressed(KeyPressedEvent& event);
    bool onMouseMoved(MouseMovedEvent& event);
};


#endif //VOXELGAME_MAINLAYER_H
