
#include <map>
#include "MainLayer.h"
#include "Layers/MainLayer/Components/Light.h"
#include "Layers/MainLayer/Components/Chunk.h"

#define EVENT_FUNCTION(function) [this](auto&&... args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }

float iterTime = 0.0f;

glm::vec3 circularPath(glm::vec3 current, float dt)
{
    iterTime += dt;

    return glm::vec3 {
            75.0f,
            10.0f,
            75.0f,
    };
}

void MainLayer::onAttach()
{
    m_Camera = new Camera(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), 60.0f);

    Renderer::Init();

    m_Light = new Light(
            glm::vec3(0.0f, 0.0f, 0.0f),
            Lighting {
                    glm::vec3(1.0f),
                    glm::vec3(1.0f),
                    glm::vec3(1.0f),
            },
            circularPath
    );

    float x = 0.0f;
    float y = 0.0f;

    m_Chunk1 = new Chunk(
            glm::vec2(x, y),
            Material {
                    glm::vec3(0.05375f, 0.05f, 0.06625f),
                    glm::vec3(0.18275f, 0.17f, 0.22525f),
                    glm::vec3(0.332741f, 0.328634f, 0.346435),
                    0.3f
            }
    );

}


void MainLayer::onUpdate(float deltaTime)
{
    m_DeltaTime = deltaTime;

    m_Light->Update(deltaTime);

    Renderer::Prepare();

    // Preparação da luz

    m_Light->Prepare();

    // Preparação do chunk
    m_Chunk1->Prepare(
            m_Light->GetPosition(),
            m_Light->GetAspect(),
            m_Camera->GetPosition()
    );

    // Render
    Renderer::Render(m_Light->GetRenderable(), *m_Camera);
    Renderer::Render(m_Chunk1->GetRenderable(), *m_Camera);
}


void MainLayer::onDetach()
{
    std::cout << "Detach";
}

void MainLayer::onEvent(Event &event)
{
    std::string eventType = std::string(event.getName());

    EventDispatcher dispatcher(event);

    dispatcher.dispatch<KeyPressedEvent>(EVENT_FUNCTION(MainLayer::onKeyPressed));
    dispatcher.dispatch<MouseMovedEvent>(EVENT_FUNCTION(MainLayer::onMouseMoved));
}

bool MainLayer::onKeyPressed(KeyPressedEvent& event)
{
    m_Camera->UpdateKeyboard(event, m_DeltaTime);

    return true;
}

bool MainLayer::onMouseMoved(MouseMovedEvent &event)
{
    m_Camera->UpdateMouse(event);

    return true;
}
