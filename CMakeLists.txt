cmake_minimum_required(VERSION 3.7...3.20)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project(voxelGame VERSION 0.0
        DESCRIPTION "Implementation of minecraft using C and OpenGL."
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Source dir variable
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Vendors dir variables
set(VENDORS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendors")

set(TRANSLATION_FILES "${SRC_DIR}/Main.cpp"
        "${SRC_DIR}/Window/Window.cpp"
        src/Renderer/EBO/EBO.cpp
        src/Renderer/EBO/EBO.h
        src/Renderer/VBO/VBO.cpp
        src/Renderer/VBO/VBO.h
        src/Renderer/VAO/VAO.cpp
        src/Renderer/VAO/VAO.h
        src/Application/Application.cpp
        src/Application/Application.h
        src/Renderer/Mesh/Mesh.cpp
        src/Renderer/Mesh/Mesh.h
        src/Renderer/Renderer/Renderer.cpp
        src/Renderer/Renderer/Renderer.h
        src/Renderer/Shader/Shader.cpp
        src/Renderer/Shader/Shader.h
        src/Camera/Camera.cpp
        src/Camera/Camera.h
        src/Events/Event.h
        src/Events/KeyEvent.h
        src/Events/MouseEvent.h
        src/Events/ApplicationEvent.h
        src/Layers/LayerStack.cpp
        src/Layers/LayerStack.h
        src/Layers/MainLayer/MainLayer.cpp
        src/Layers/MainLayer/MainLayer.h
        src/Layers/Layer.h
        src/Renderer/Utils/Vertex.h
        src/Layers/MainLayer/NoiseGenerator.cpp
        src/Layers/MainLayer/NoiseGenerator.h
        )

set(SOURCES_FILES "${TRANSLATION_FILES}")

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

include_directories("${SRC_DIR}/Renderer"
        "${SRC_DIR}/")

# GLFW
set(GLFW_DIR "${VENDORS_DIR}/glfw")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} PRIVATE "glfw")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# GLAD
set(GLAD_DIR "${VENDORS_DIR}/glad")
add_subdirectory("${GLAD_DIR}")
target_link_libraries(${PROJECT_NAME} PRIVATE "glad")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")

# GLM
set(GLM_DIR "${VENDORS_DIR}/glm")
add_subdirectory("${GLM_DIR}")
target_link_libraries(${PROJECT_NAME} PRIVATE "glm")
target_include_directories(${PROJECT_NAME} PRIVATE "${glm_dir}/include")