#include "Light.h"
#include "Shader.h"

using namespace ShaderHeaders;
Light::Light(Shader* sha)
{
	shader = sha;
	postion = glm::vec3(0.0f);
	shader->setLightPos(postion);
}


void Light::setPosition(float x, float y, float z)
{
	postion = glm::vec3(x, y, z);
	shader->setLightPos(postion);
}