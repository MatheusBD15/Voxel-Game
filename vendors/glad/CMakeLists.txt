# Version settings
cmake_minimum_required(VERSION 3.7...3.20)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# GLAD project settings
project(glad VERSION 1.0 LANGUAGES C)

# Source Dir variable
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Include Dir variable
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(${PROJECT_NAME} STATIC "${SRC_DIR}/glad.c")
target_include_directories(${PROJECT_NAME} PRIVATE "${INCLUDE_DIR}")