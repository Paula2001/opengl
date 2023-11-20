#include "SpotLight.h"
#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>

SpotLight::SpotLight(const vec3 pos, const vec3 col) {
    this->position = pos;
    this->color = col;
}

void SpotLight::setUniforms(GLuint shaderProgram) {
    // Set the light position uniform
    this->alpha += 0.0001;


    auto M = glm::lookAt(glm::vec3(5.0f, 5.0f, 0.0f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
    auto x = glGetUniformLocation(shaderProgram, "spotLightSize");
    glUniformMatrix4fv(x, 1, GL_FALSE, glm::value_ptr(M));

    glm::vec3 dir = glm::vec3(glm::cos(this->alpha) * 0.4, -1, glm::sin(alpha) * 0.4);
    GLuint varLocation = glGetUniformLocation(shaderProgram, "spotDir");
    glUniform3f(varLocation, dir.x, dir.y, dir.z);

    glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
    GLuint camPositionLocation = glGetUniformLocation(shaderProgram, "lightPos");
    glUniform3fv(camPositionLocation, 1, glm::value_ptr(pos));

    // Set the light color uniform
    GLint lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
    glUniform3f(lightColorLoc, 1.0f, 0.1f, 1.0f);
}