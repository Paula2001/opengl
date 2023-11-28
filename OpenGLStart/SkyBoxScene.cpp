#include "SkyBoxScene.h"
#include "HouseModel.h"
#include "CubeModel.h"
using namespace ScenesHeaders;
using namespace std;

#include <vector>
Scene* SkyBoxScene::ComposeScene()
{
	

	Shader* shader = new Shader();
	auto x = (new CubeModel)->setTheShape();
	shader->loadShader("skyBox.vert", "skyBox.frag");
	
	Transformation* t1 = (new Transformation(
		vec3(2.0f, 0.0f, 0.0f),
		1
	))->scaleModel()->rotateModel();
	/*this->addObject(
		(new DrawableObject())
		->setModel(x)
		->setTransformation(t1)
		->setShader(shader)
	);*/

	this->addObject(
		(new DrawableObject())
		->setModel(x)
		->setTransformation(t1)
		->setShader(shader)
	);
	

	return this;
}

Scene* SkyBoxScene::SceneControls()
{
	return nullptr;
}