#include <GL/glew.h>
#include "Transformation.h"
#include <glm/ext/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

Transformation::Transformation(vec3 cords, float angle, float scale) {
	this->cords = cords;
	this->scaleVarient = scale;
}

Transformation* Transformation::rotateModel() {
	// Info : middle angel
	this->rotateVar = rotate(glm::mat4(1.0f), 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	return this;
}
Transformation* Transformation::translateModel() {
	this->translateVar = translate(mat4(1.0f), cords);
	return this;
}
Transformation* Transformation::perspectiveModel() {
	this->translateVar = perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	return this;
}

Transformation* Transformation::scaleModel() {
	this->translateVar = scale(translateVar, vec3(scaleVarient));
	return this;
}

void Transformation::bindTransformation(unsigned int shaderProgram, float test) {
	unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, value_ptr(this->translateVar));

	unsigned int scale = glGetUniformLocation(shaderProgram, "scale");
	glUniformMatrix4fv(scale, 1, GL_FALSE, value_ptr(this->scaleVar));

}