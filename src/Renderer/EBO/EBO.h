//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_EBO_H
#define VOXELGAME_EBO_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <vector>

class EBO
{
private:
    unsigned int m_Id;
    std::vector<unsigned int> m_Indices;

public:
    EBO() = default;
    ~EBO();

    explicit EBO(const std::vector<unsigned int>& indices);

    unsigned int getId() const { return m_Id; }
};


#endif //VOXELGAME_EBO_H
