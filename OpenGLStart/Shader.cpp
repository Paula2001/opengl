#include <GL/glew.h>
#include "Shader.h"
#include <stdexcept>
#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

Shader::Shader() {
    this->shaderProgram = glCreateProgram();
}

Shader::~Shader() {
    cout << "Shader is being eleminated, cleaning...";
    glDeleteShader(this->vertexShader);
    glDeleteShader(this->fragShader);
    glDeleteProgram(this->shaderProgram); // TODO : can produce bugs
}

Shader* Shader::setVertexShader(const char* vertexShaderSource) {
    int success;
    char infoLog[512];
    this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(this->vertexShader);
    glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(this->vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        throw runtime_error("GLFW error, vertex shader");
    }
    return this;
}

Shader* Shader::setFragmentShader(const char* fragmentShaderSource) {
    int success;
    char infoLog[512];

    this->fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(this->fragShader);

    glGetShaderiv(this->fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(this->fragShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
        throw runtime_error("GLFW error, frag shader");
    }
    return this;
}

Shader* Shader::linkShaders() {
    int success;
    char infoLog[512];
    glAttachShader(this->shaderProgram, this->vertexShader);
    glAttachShader(this->shaderProgram, this->fragShader);
    glLinkProgram(this->shaderProgram);
    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
        throw runtime_error("GLFW error, linking shader failed");
    }
    return this;
}

unsigned int Shader::getShaderProgram() {
    return this->shaderProgram;
}