#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace glm;

class Light {
public:
    vec3 position;
    vec3 color;

    Light(const vec3 pos, const vec3 col);

    void setUniforms(GLuint shaderProgram);
};