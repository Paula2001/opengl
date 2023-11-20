#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class LightBase
{
public:
	virtual void setUniforms(GLuint shaderProgram) = 0;
};

