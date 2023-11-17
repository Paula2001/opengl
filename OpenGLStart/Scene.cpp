#include "Scene.h"
#include <GL/glew.h>

Scene* Scene::addObject(DrawableObject* obj) {
	this->objects.push_back(obj);
	return this;
}

void Scene::init() {
	for (auto& obj : this->objects) {
		glUseProgram(obj->shader->getShaderProgram());
		obj->draw();
		obj->move();
	}
}