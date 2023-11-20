#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "LightBase.h"
using namespace glm;

class SpotLight : public LightBase
{
public:
    vec3 position;
    vec3 color;
    float alpha = 0.0f;

    SpotLight(const vec3 pos, const vec3 col);

    void setUniforms(GLuint shaderProgram);
};

