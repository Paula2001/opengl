#pragma once
#include "Shader.h"
#include<glm/glm.hpp>

using namespace glm;
using namespace ShaderHeaders;
class Light
{
public:
	Light(Shader* shade);
	void setPosition(float x, float y, float z);

private:
	Shader* shader;
	vec3 postion;
};