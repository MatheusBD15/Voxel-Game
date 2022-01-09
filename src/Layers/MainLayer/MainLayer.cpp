
#include <map>
#include "MainLayer.h"

#define EVENT_FUNCTION(function) [this](auto&&... args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }

void MainLayer::onAttach()
{
    m_Noise = NoiseGenerator::generate2d(m_mapX, m_mapZ, 4, m_mapX, m_mapZ, 4.7f);

    m_Meshes.reserve(m_chunkNumber * m_chunkNumber);

    for (int cX = 0; cX < m_chunkNumber; ++cX)
    {
        for (int cZ = 0; cZ < m_chunkNumber; ++cZ)
        {
            glm::vec3 offset = { cX * m_chunkWidth, 0.0f, cZ * m_chunkWidth };

            m_Futures.push_back(std::async(std::launch::async,  [&](const glm::vec3& chunkOffset) -> void {

                std::vector<Vertex> chunk = generateOptimizedChunk(chunkOffset);
//                std::vector<Vertex> chunk = generateChunk(chunkOffset.x, chunkOffset.z, m_Noise);

                std::lock_guard<std::mutex> lock(m_ChunksMutex);

                m_Chunks.push_back(chunk);

            }, offset));
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
    chunk.reserve(m_chunkWidth * m_chunkWidth);

    for (int x = 0; x < m_chunkWidth; ++x)
    {
        for (int z = 0; z < m_chunkWidth; ++z)
        {
            int height = floor(noise.at((z + zOffset) * m_mapX + x + xOffset)) - 120;

            std::vector<Vertex> cube = Renderer::createCube((float)(x + xOffset), (float)height, (float)(z + zOffset));

            chunk.insert(chunk.end(), cube.begin(), cube.end());
        }
    }

    return chunk;
}


std::vector<Vertex> MainLayer::generateOptimizedChunk(const glm::vec3& chunkPos) const
{
    const int chunkSize = 10;

    glm::vec4 generalColor = { 0.2f, 0.65f, 0.32f, 1.0f };

    std::vector<int> volume;
    std::vector<Vertex> quads;

    // sweep over 3 axes
    for (int d = 0; d < 3; ++d)
    {
        int i, j, k, l, w, h;
        int u = (d+1) % 3;
        int v = (d+2) % 3;

        glm::vec3 x { 0.0f, 0.0f, 0.0f };
        glm::vec3 q { 0.0f, 0.0f, 0.0f };

        std::array<bool, chunkSize * chunkSize> mask {};

        q[d] = 1.0f;

        // check each slice of the chunk
        for (x[d] = -1; x[d] < chunkSize;)
        {
            // compute the mask
            int n = 0;

            for (x[v] = 0; x[v] < chunkSize; x[v] += 1.0f)
            {
                for (x[u] = 0; x[u] < chunkSize; x[u] += 1.0f)
                {
                    // q determines the direction (X, Y or Z) that we are searching
                    // m.IsBlockAt(x,y,z) takes global map positions and returns true if a block exists there

                    // bool blockCurrent = 0 <= x[d]             ? IsBlockAt(x[0] + chunkPos.x,        x[1] + chunkPos.y,        x[2] + chunkPos.z)        : true;
                    // bool blockCompare = x[d] < chunkSize - 1 ? IsBlockAt(x[0] + q[0] + chunkPos.x, x[1] + q[1] + chunkPos.y, x[2] + q[2] + chunkPos.z) : true;

                    bool blockCurrent = 0 <= x[d];
                    bool blockCompare = x[d] < chunkSize - 1;

                    // The mask is set to true if there is a visible face between two blocks,
                    //   i.e. both aren't empty and both aren't blocks
                    mask.at(n++) = blockCurrent != blockCompare;
                }
            }

            ++x[d];

            n = 0;

            // Generate a mesh from the mask using lexicographic ordering,
            //   by looping over each block in this slice of the chunk
            for (j = 0; j < chunkSize; ++j)
            {
                for (i = 0; i < chunkSize;)
                {
                    if(mask.at(n))
                    {
                        // Compute the width of this quad and store it in w
                        //   This is done by searching along the current axis until mask[n + w] is false
                        for (w = 1; i + w < chunkSize && mask.at(n + w); w++);

                        // Compute the height of this quad and store it in h
                        //   This is done by checking if every block next to this row (range 0 to w) is also part of the mask.
                        //   For example, if w is 5 we currently have a quad of dimensions 1 x 5. To reduce triangle count,
                        //   greedy meshing will attempt to expand this quad out to CHUNK_SIZE x 5, but will stop if it reaches a hole in the mask

                        bool done = false;
                        for (h = 1; j + h < chunkSize; ++h)
                        {
                            // Check each block next to this quad
                            for (k = 0; k < w; ++k)
                            {
                                // If there's a hole in the mask, exit
                                if (!mask.at(n + k + h * chunkSize))
                                {
                                    done = true;
                                    break;
                                }
                            }

                            if (done)
                            {
                                break;
                            }
                        }

                        x[u] = (float)i;
                        x[v] = (float)j;

                        // du and dv determine the size and orientation of this face
                        std::array<int, 3> du {};
                        du.at(u) = w;

                        std::array<int, 3> dv {};
                        dv.at(v) = h;

                        glm::vec3 topLeftPos {x[0] + chunkPos.x, x[1], x[2] + chunkPos.z};
                        glm::vec3 topRightPos {x[0] + du[0] + chunkPos.x,  x[1] + du[1],  x[2] + du[2] + chunkPos.z};
                        glm::vec3 bottomLeftPos {x[0] + dv[0] + chunkPos.x, x[1] + dv[1], x[2] + dv[2] + chunkPos.z};
                        glm::vec3 bottomRightPos {x[0] + du[0] + dv[0] + chunkPos.x, x[1] + du[1] + dv[1], x[2] + du[2] + dv[2] + chunkPos.z};

                        std::array<glm::vec3, 3> triangle {topLeftPos, topRightPos, bottomLeftPos};

                        glm::vec3 faceNormal = Mesh::normalizeTriangle(triangle);

                        Vertex topLeft {topLeftPos, generalColor, faceNormal};

                        Vertex topRight {topRightPos, generalColor, faceNormal};

                        Vertex bottomLeft {bottomLeftPos, generalColor, faceNormal};

                        Vertex bottomRight {bottomRightPos, generalColor, faceNormal};

                        std::array<Vertex, 4> quad { topLeft, topRight, bottomLeft, bottomRight};

                        quads.insert(quads.end(), quad.begin(), quad.end());

                        // Clear this part of the mask, so we don't add duplicate faces
                        for (l = 0; l < h; ++l)
                            for (k = 0; k < w; ++k)
                                mask.at(n + k + l * chunkSize) = false;

                        // Increment counters and continue
                        i += w;
                        n += w;
                    }

                    else
                    {
                        ++i;
                        ++n;
                    }
                }
            }

        }
    }

    return quads;
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
    const float cameraSpeed = 200.0f * m_DeltaTime; // adjust accordingly

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
