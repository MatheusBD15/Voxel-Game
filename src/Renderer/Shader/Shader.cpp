//
// Created by MBDambo on 02/12/2021.
//

#include "Shader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    CompileLinkShader(vertexPath, fragmentPath);
}

Shader::~Shader()
{
    glDeleteProgram(m_ShaderId);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: "
                << type
                << "\n"
                << infoLog
                << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: "
                << type
                << "\n"
                << infoLog
                << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
}

void Shader::setUniform(const std::string &name, glm::mat4 mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setUniform(const std::string &name, glm::vec4 vec) const
{
    glUniform4fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, glm::value_ptr(vec));
}

void Shader::setUniform(const std::string &name, glm::vec3 vec) const
{
    glUniform3fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, glm::value_ptr(vec));
}

void Shader::setUniform(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_ShaderId, name.c_str()), (int)value);
}
// ------------------------------------------------------------------------
void Shader::setUniform(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(m_ShaderId, name.c_str()), value);
}
// ------------------------------------------------------------------------
void Shader::setUniform(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(m_ShaderId, name.c_str()), value);
}

void Shader::CompileLinkShader(const char *vFileName, const char *fFileName)
{
    std::string vTempCode = LoadShader(GL_VERTEX_SHADER, vFileName);
    std::string fTempCode = LoadShader(GL_FRAGMENT_SHADER, fFileName);

    const GLchar* vShaderCode = vTempCode.c_str();
    const GLchar* fShaderCode = fTempCode.c_str();

    GLuint vertexShader, fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);
    CheckErrors(vertexShader, "VERTEX");

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);
    CheckErrors(fragmentShader, "FRAGMENT");

    m_ShaderId = glCreateProgram();
    glAttachShader(m_ShaderId, vertexShader);
    glAttachShader(m_ShaderId, fragmentShader);
    glLinkProgram(m_ShaderId);
    CheckErrors(m_ShaderId, "PROGRAM");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

std::string Shader::LoadShader(GLenum shaderType, const char *fileName)
{
    std::string currentLine = "";
    std::string sourceCode = "";
    std::ifstream shaderFile;

    shaderFile.open(fileName);

    if (shaderFile.is_open())
    {
        while (std::getline(shaderFile, currentLine))
            sourceCode += currentLine + "\n";
    }
    else
    {
        std::cout << "Falha ao abrir o arquivo: "
                  << fileName
                  << "\n ************************************************** \n";
    }

    shaderFile.close();

    return sourceCode;
}


void Shader::CheckErrors(GLuint shader, const char* type)
{
    int compiled;
    char log[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            glGetShaderInfoLog(shader, 1024, NULL, log);
            std::cout << "Erro ao compilar o shader de: "
                      << type
                      << "\n"
                      << log
                      << "\n ************************************************** \n";
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &compiled);
        if (!compiled)
        {
            glGetProgramInfoLog(shader, 1024, NULL, log);
            std::cout << "Erro ao vincular o shader de: "
                      << type
                      << "\n"
                      << log
                      << "\n ************************************************** \n";
        }
    }
}

