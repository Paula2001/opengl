#pragma once
#include <glm/glm.hpp>
using namespace glm;
static class Transformation
{
public:
	Transformation(vec3 cords, float angle, float scale);
	Transformation* rotateModel();
	Transformation* translateModel();
	Transformation* perspectiveModel();
	Transformation* scaleModel();
	void bindTransformation(unsigned int shaderProgram, float test);
private:
	mat4 main;
	mat4 rotateVar;
	mat4 translateVar;
	mat4 perspectiveVar;
	mat4 scaleVar;
	vec3 cords;
	float scaleVarient;
};

