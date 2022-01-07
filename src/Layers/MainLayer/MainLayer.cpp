
#include <map>
#include "MainLayer.h"

#define EVENT_FUNCTION(function) [this](auto&&... args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }

void MainLayer::onAttach()
{
    m_Noise = NoiseGenerator::generate2d(m_mapX, m_mapZ, 4, m_mapX, m_mapZ, 3.2f);

    m_Meshes.reserve(m_chunkNumber * m_chunkNumber);

    for (int cX = 0; cX < m_chunkNumber; ++cX)
    {
        for (int cZ = 0; cZ < m_chunkNumber; ++cZ)
        {
            m_Futures.push_back(std::async(std::launch::async,  [&](int xOffset, int zOffset) -> void {

                std::vector<Vertex> chunk = generateChunk(xOffset, zOffset, m_Noise);

                std::lock_guard<std::mutex> lock(m_ChunksMutex);

                m_Chunks.push_back(chunk);

            }, cX * m_chunkWidth, cZ * m_chunkWidth));
        }
    }

    for ( std::future<void>& future : m_Futures)
    {
        future.wait();
    }

    for( const auto& chunk : m_Chunks )
    {
        Mesh* mesh = new Mesh(chunk, m_indices);

        m_Meshes.push_back(mesh);
    }

    m_Shader = new Shader("src/Shaders/vertex.shader",
                           "src/Shaders/fragment.shader");

    m_Camera = new Camera();

    m_Camera->setVertexShader(*m_Shader);
}

std::vector<Vertex> MainLayer::generateChunk(int xOffset, int zOffset, std::vector<float>& noise) const
{
    std::vector<Vertex> chunk;

    for (int x = 0; x < m_chunkWidth; ++x)
    {
        for (int z = 0; z < m_chunkWidth; ++z)
        {
            int height = floor(noise.at((z + zOffset) * m_mapX + x + xOffset)) - 120;

            std::vector<Vertex> cube = Renderer::createCube((float)(x + xOffset), (float)height, (float)(z + zOffset));

//            std::vector<Vertex> processedCube;

//            for (auto const & vertex : cube)
//            {
//                std::vector<Vertex>::iterator it;
//
//                it = std::find (chunk.begin(), chunk.end(), vertex);
//
//                if (it == chunk.end())
//                {
//                    processedCube.push_back(vertex);
//                }
//            }

//            std::cout << "Normal cube size: " << cube.size();
//            std::cout << "     Processed cube size: " << processedCube.size() << std::endl;

            chunk.insert(chunk.end(), cube.begin(), cube.end());
        }
    }

//    std::cout << "Normal chunk size: " << chunk.size() << std::endl;

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
