
#include "MainLayer.h"

#define EVENT_FUNCTION(function) [this](auto&&... args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }

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

    int chunkWidth = 32;
    int chunkNumber = 32;

    std::vector<float> perlinNoise = NoiseGenerator::generate2d(m_mapX, m_mapZ, 4, m_mapX, m_mapZ, 3.6f);

    m_Meshes.reserve(chunkNumber * chunkNumber);

    for (int cX = 0; cX < chunkNumber; ++cX)
    {
        for (int cZ = 0; cZ < chunkNumber; ++cZ)
        {
            int xOffset = cX * chunkWidth;
            int zOffset = cZ * chunkWidth;

            std::vector<Vertex> chunk = generateChunk(chunkWidth, xOffset, zOffset, perlinNoise);

            Mesh* mesh = new Mesh(chunk, indices);

            m_Meshes.push_back(mesh);
        }
    }

    m_Shader = new Shader("src/Shaders/vertex.shader",
                           "src/Shaders/fragment.shader");

    m_Camera = new Camera();

    m_Camera->setVertexShader(*m_Shader);
}

std::vector<Vertex> MainLayer::generateChunk(int width, int xOffset, int zOffset, std::vector<float>& noise)
{
    std::vector<Vertex> chunk;
    chunk.reserve(width * width);

    for (int x = 0; x < width; ++x)
    {
        for (int z = 0; z < width; ++z)
        {
            int height = floor(noise.at((z + zOffset) * m_mapX + x + xOffset)) - 120;

            std::vector<Vertex> cube = Renderer::createCube((float)(x + xOffset), (float)height, (float)(z + zOffset));

            chunk.insert(chunk.end(),
                            cube.begin(),
                            cube.end()
            );
        }
    }

    return chunk;
}


void MainLayer::onUpdate(float deltaTime)
{
    m_DeltaTime = deltaTime;

    glm::vec4 lightColor = {1.0f, 1.0f, 1.0f, 1.0f};
    glm::vec3 lightPos = {0.0f, 5000.0f, 0.0f};

    m_Shader->setUniform("lightColor", lightColor);
    m_Shader->setUniform("lightPos", lightPos);

    Renderer::prepare();

    m_Shader->use();

    for (auto mesh : m_Meshes)
    {
        Renderer::render(mesh, m_Camera);
    }
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
    const float cameraSpeed = 50.0f * m_DeltaTime; // adjust accordingly

    // w key was pressed
    if(event.getKeyCode() == 87)
    {
        m_Camera->m_CameraPos += cameraSpeed * m_Camera->m_CameraFront;
    }
    // s key
    if(event.getKeyCode() == 83)
    {
        m_Camera->m_CameraPos -= cameraSpeed * m_Camera->m_CameraFront;
    }
    // a key
    if(event.getKeyCode() == 65)
    {
        m_Camera->m_CameraPos -= glm::normalize(glm::cross(m_Camera->m_CameraFront, m_Camera->m_CameraUp)) * cameraSpeed;
    }
    // d key
    if(event.getKeyCode() == 68)
    {
        m_Camera->m_CameraPos += glm::normalize(glm::cross(m_Camera->m_CameraFront, m_Camera->m_CameraUp)) * cameraSpeed;
    }

    return true;
}

bool MainLayer::onMouseMoved(MouseMovedEvent &event)
{
    if (m_Camera->m_FirstMouse)
    {
        m_Camera->m_LastX = event.getX();
        m_Camera->m_lastY = event.getY();
        m_Camera->m_FirstMouse = false;
    }
    float xoffset = event.getX() - m_Camera->m_LastX;
    float yoffset = m_Camera->m_lastY - event.getY(); // reversed since y-coordinates range from bottom to top
    m_Camera->m_LastX = event.getX();
    m_Camera->m_lastY = event.getY();

    xoffset *= m_Camera->m_Sensitivity;
    yoffset *= m_Camera->m_Sensitivity;

    m_Camera->m_Yaw   += xoffset;
    m_Camera->m_Pitch += yoffset;

    if(m_Camera->m_Pitch > 89.0f)
        m_Camera->m_Pitch =  89.0f;
    if(m_Camera->m_Pitch < -89.0f)
        m_Camera->m_Pitch = -89.0f;

    m_Camera->updateCameraVectors();

    return true;
}
