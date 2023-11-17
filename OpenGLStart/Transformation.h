#pragma once
#include <glm/glm.hpp>
using namespace glm;
static class Transformation
{
public:
	Transformation* rotateModel();
	Transformation* translateModel();
	Transformation* perspectiveModel();
	void bindTransformation(unsigned int shaderProgram, float test);
private:
	mat4 rotateVar;
	mat4 translateVar;
	mat4 perspectiveVar;
};

