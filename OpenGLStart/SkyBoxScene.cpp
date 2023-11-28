#include "SkyBoxScene.h"
#include "HouseModel.h"
#include "CubeModel.h"
#include "PlainModel.h"
#include "SphereModel.h"
#include "TreeModel.h"
using namespace ScenesHeaders;
using namespace std;

#include <vector>
Scene* SkyBoxScene::ComposeScene()
{
	

	Shader* sky = new Shader();
	Shader* phong = new Shader();
	Shader* house = new Shader();
	auto x = (new CubeModel)->setTheShape();
	sky->loadShader("skyBox.vert", "skyBox.frag");
	phong->loadShader("phong.vert", "phong.frag");
	house->loadShader("3dHouse.vert", "3dHouse.frag");


	Transformation* t1 = (new Transformation(
		vec3(0.0f, 0.0f, 0.0f),
		1,
		30.0f
	))->scaleModel()->rotateModel();

	Transformation* t2 = (new Transformation(
		vec3(0.0f, 0.0f, 0.0f),
		1,
		1.0f
	))->scaleModel()->rotateModel();


	Transformation* t3 = (new Transformation(
		vec3(0.0f, -30.0f, -10.0f),
		1,
		1.0f
	))->scaleModel();
	Transformation* t4 = (new Transformation(
		vec3(10.0f, -30.0f, -10.0f),
		1,
		1.0f
	))->scaleModel();

	Transformation* t5 = (new Transformation(
		vec3(10.0f, -30.0f, -5.0f),
		1,
		1.0f
	))->scaleModel();

	Transformation* t6 = (new Transformation(
		vec3(-10.0f, -30.0f, -5.0f),
		1,
		1.0f
	))->scaleModel();
	/*this->addObject(
		(new DrawableObject())
		->setModel((new SphereModel)->setTheShape())
		->setTransformation(t2)
		->setShader(phong)
	);*/

	this->addObject(
		(new DrawableObject())
		->setModel((new HouseModel)->setTheShape())
		->setTransformation(t3)
		->setShader(house)
	);

	this->addObject(
		(new DrawableObject())
		->setModel((new TreeModel)->setTheShape())
		->setTransformation(t4)
		->setColor(vec4(0.13, 0.55, 0.13, 1.0))

		->setShader(phong)
	);

	this->addObject(
		(new DrawableObject())
		->setModel((new TreeModel)->setTheShape())
		->setTransformation(t5)
		->setColor(vec4(0.13, 0.55, 0.13, 1.0))
		->setShader(phong)
	);


	this->addObject(
		(new DrawableObject())
		->setModel((new TreeModel)->setTheShape())
		->setTransformation(t6)
		->setColor(vec4(0.13, 0.55, 0.13, 1.0))

		->setShader(phong)
	);

	this->addObject(
		(new DrawableObject())
		->setModel((new CubeModel)->setTheShape())
		->setTransformation(t1)
		->setShader(sky)
	);



	return this;
}

Scene* SkyBoxScene::SceneControls()
{
	return nullptr;
}