cmake_minimum_required(VERSION 3.7...3.20)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(voxelGame VERSION 0.0
        DESCRIPTION "Implementation of minecraft using C and OpenGL."
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

# Source dir variable
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Vendors dir variables
set(VENDORS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendors")

set(TRANSLATION_FILES "${SRC_DIR}/Main.cpp" "${SRC_DIR}/Window/Window.cpp")

set(SOURCES_FILES "${TRANSLATION_FILES}")

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

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