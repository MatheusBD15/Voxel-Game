//
// Created by MBDambo on 02/12/2021.
//

#ifndef VOXELGAME_SHADER_H
#define VOXELGAME_SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader
{
public:
    GLuint m_Id;
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader() = default;
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    // activate the shader
    // ------------------------------------------------------------------------
    inline void use() const { glUseProgram(m_Id); }

    inline void unUse() const { glUseProgram(0); }

    inline GLuint getId() const { return m_Id; }

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setUniform(const std::string &name, glm::mat4 mat) const;

    void setUniform(const std::string &name, glm::vec4 vec) const;

    void setUniform(const std::string &name, glm::vec3 vec) const;

    void setUniform(const std::string &name, bool value) const;

    // ------------------------------------------------------------------------
    void setUniform(const std::string &name, int value) const;
    // ------------------------------------------------------------------------
    void setUniform(const std::string &name, float value) const;

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type);
};


#endif //VOXELGAME_SHADER_H
