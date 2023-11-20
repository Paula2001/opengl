#pragma once
#include "Light.h"
#include "Shader.h"



Light::Light(const vec3 pos, const vec3 col) {
    this->position = pos;
    this->color = col;
}

void Light::setUniforms(GLuint shaderProgram) {
    // Set the light position uniform
    glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
    GLuint camPositionLocation = glGetUniformLocation(shaderProgram, "lightPos");
    glUniform3fv(camPositionLocation, 1, glm::value_ptr(pos));

    // Set the light color uniform
    GLint lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
    glUniform3f(lightColorLoc, 1.0f, 0.1f, 1.0f);
}