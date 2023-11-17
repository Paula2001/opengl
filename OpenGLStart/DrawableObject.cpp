#include "DrawableObject.h"

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
void DrawableObject::move(float test) {
	this->transformation
		->rotateModel()
		->perspectiveModel()
		->translateModel()
		->bindTransformation(
			this->shader->getShaderProgram(),
			test
		);
}
void DrawableObject::draw() {
	this->model->drawTheShape(); // TODO : I don't like it...
}