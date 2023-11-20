#include <GL/glew.h>
#include "Scene.h"

using namespace ScenesHeaders;

Scene* Scene::addObject(DrawableObject* obj) {
	this->objects.push_back(obj);
	return this;
}
Scene* Scene::setCamera(Camera* camera) {
	this->camera = camera;
	return this;
}

Scene* Scene::setLight(Light* light) {
	this->light = light;
	return this;
}
void Scene::init(GLFWwindow* window) {
	for (auto& obj : this->objects) {
		glUseProgram(obj->shader->getShaderProgram());
		this->camera->Inputs(window);
		this->light->setUniforms(obj->shader->getShaderProgram());
		this->camera->Matrix(45.0f, 0.1f, 100.0f, obj->shader->getShaderProgram(), "camMatrix");
		obj->draw();
		obj->move(4.0f);
	}
}