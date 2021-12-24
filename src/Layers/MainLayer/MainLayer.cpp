
#include "MainLayer.h"

void MainLayer::onAttach()
{
    std::vector<unsigned int> indices = {
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

    std::vector<float> vertices = {
            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,

            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,

            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,

            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f
    };

    m_Mesh = new Mesh(vertices, indices);

    m_Shader = new Shader("src/Shaders/vertex.shader",
                           "src/Shaders/fragment.shader");

    m_Camera = new Camera();

    m_Camera->setVertexShader(*m_Shader);
}

void MainLayer::onDetach()
{
    std::cout << "Detach";
}

void MainLayer::onEvent(Event &event)
{
    std::string eventType = std::string(event.getName());

    if(eventType == "KeyPressed")
    {
        auto* keyPressedEvent = dynamic_cast<KeyEvent*>(&event);

        const float cameraSpeed = 2.5f * m_DeltaTime; // adjust accordingly

        // w key was pressed
        if(keyPressedEvent->getKeyCode() == 87)
        {
            m_Camera->m_CameraPos += cameraSpeed * m_Camera->m_CameraFront;
        }
        // s key
        if(keyPressedEvent->getKeyCode() == 83)
        {
            m_Camera->m_CameraPos -= cameraSpeed * m_Camera->m_CameraFront;
        }
        // a key
        if(keyPressedEvent->getKeyCode() == 65)
        {
            m_Camera->m_CameraPos -= glm::normalize(glm::cross(m_Camera->m_CameraFront, m_Camera->m_CameraUp)) * cameraSpeed;
        }
        // d key
        if(keyPressedEvent->getKeyCode() == 68)
        {
            m_Camera->m_CameraPos += glm::normalize(glm::cross(m_Camera->m_CameraFront, m_Camera->m_CameraUp)) * cameraSpeed;
        }
    }
    if(eventType == "MouseMoved")
    {
        auto* mouseMovedEvent = dynamic_cast<MouseMovedEvent*>(&event);

        float xoffset = mouseMovedEvent->getX() - m_Camera->m_LastX;
        float yoffset = m_Camera->m_lastY - mouseMovedEvent->getY(); // reversed since y-coordinates range from bottom to top
        m_Camera->m_LastX = mouseMovedEvent->getX();
        m_Camera->m_lastY = mouseMovedEvent->getY();

        xoffset *= m_Camera->m_Sensitivity;
        yoffset *= m_Camera->m_Sensitivity;

        m_Camera->m_Yaw   += xoffset;
        m_Camera->m_Pitch += yoffset;

        if(m_Camera->m_Pitch > 89.0f)
            m_Camera->m_Pitch =  89.0f;
        if(m_Camera->m_Pitch < -89.0f)
            m_Camera->m_Pitch = -89.0f;
    }
}

void MainLayer::onUpdate(float deltaTime)
{
    m_DeltaTime = deltaTime;

    Renderer::prepare();

    m_Shader->use();

    Renderer::render(m_Mesh, m_Camera);
}