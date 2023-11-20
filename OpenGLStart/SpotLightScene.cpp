#include "SpotLightScene.h"
#include "Scene.h"
#include "PlainModel.h"
#include "SuziFlatModel.h"
using namespace ScenesHeaders;

Scene* SpotLightScene::ComposeScene()
{
	Shader* shader = new Shader();
	shader->loadShader("spotLight.vert", "spotLight.freg");
	Transformation* t1 = (new Transformation(
		vec3(2.0f, 0.0f, 0.0f),
		1
	))->scaleModel()->rotateModel();
	Transformation* t2 = (new Transformation(
		vec3(4.0f, 41.0f, 0.0f),
		1
	))->scaleModel()->rotateModel();
	this->addObject(
		(new DrawableObject())
		->setModel((new PlainModel)->setTheShape())
		->setTransformation(t1)
		->setShader(shader)
	);
	return this;
}

Scene* SpotLightScene::SceneControls()
{
	return nullptr;
}