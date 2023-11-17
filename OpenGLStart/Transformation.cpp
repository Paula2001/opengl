#include <GL/glew.h>
#include "Transformation.h"
#include <glm/ext/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

Transformation* Transformation::rotateModel() {
	// Info : middle angel
	this->rotateVar = rotate(mat4(1.0f), (float)glfwGetTime(), vec3(0.0f, 0.0f, 1.0f));
	return this;
}
Transformation* Transformation::translateModel() {
	this->translateVar = translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
	return this;
}
Transformation* Transformation::perspectiveModel() {
	this->perspectiveVar = perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	return this;
}

void Transformation::bindTransformation(unsigned int shaderProgram) {
	unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
	unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
	unsigned int projLoc = glGetUniformLocation(shaderProgram, "projection");
	// Pass them to the shaders
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(this->rotateVar));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, value_ptr(this->translateVar));
	// Note: Currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(this->perspectiveVar));
}