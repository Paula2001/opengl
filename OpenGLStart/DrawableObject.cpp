#include "DrawableObject.h"
using namespace ShaderHeaders;
DrawableObject* DrawableObject::setModel(Model* model) {
	this->model = model;
	return this;
}
DrawableObject* DrawableObject::setTransformation(Transformation* t) {
	this->transformation = t;
	return this;
}
DrawableObject* DrawableObject::setShader(Shader* shader) {
	this->shader = shader;
	return this;
}

DrawableObject* DrawableObject::setColor(vec4 color) {
	this->color = color;
	return this;
}

void DrawableObject::move(float test) {
	
	this->transformation
		->rotateModel()
		->translateModel()
		->scaleModel()
		->bindTransformation(
			this->shader->getShaderProgram(),
			test
		);
	unsigned int c = glGetUniformLocation(this->shader->getShaderProgram(), "objColor");
	glUniform4f(c, this->color.r,this->color.g, this->color.b, this->color.a);
}
void DrawableObject::draw() {
	this->model->drawTheShape(); // TODO : I don't like it...
}

