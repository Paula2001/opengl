#include "SkyScene.h"
#include "DrawableObject.h"
#include "TriangleModel.h"
#include "SuziSmoothModel.h"
#include "SphereModel.h"
#include "TreeModel.h"
#include "GiftModel.h"
#include "BushesModel.h"
#include "PlainModel.h"
#include "SuziFlatModel.h"
#include <random>

using namespace ScenesHeaders;
using namespace ModelsHeaders;
using namespace ShaderHeaders;
using namespace std;


Scene* SkyScene::ComposeScene()
{
	
	vector<Model*> x = {
		new TreeModel, 
		new SphereModel,
	};
	float initPos = 0.0f;
	for (int i = 0; i < 3; i++) {
		std::random_device rd;
		std::mt19937 gen(rd());

		// Define the range
		std::uniform_int_distribution<> distr(0, 1); // Range is 0 to 4 inclusive

		// Generate and print a random number
		int randomNumber = distr(gen);
		initPos += 5.0f;
		
	}

	
	Shader* shader = new Shader();
	shader->loadShader("phong.vert", "phong.frag");

	Transformation* t1 = (new Transformation(
		vec3(2.0f, 0.0f, 0.0f),
		1
	))->scaleModel()->rotateModel();
	this->addObject(
		(new DrawableObject())
		->setModel((new SphereModel)->setTheShape())
		->setTransformation(t1)
		->setShader(shader)
	);
	Transformation* t2 = (new Transformation(
		vec3(-2.0f, 0.0f, 0.0f),
		1
	))->scaleModel()->rotateModel();
	this->addObject(
		(new DrawableObject())
		->setModel((new SphereModel)->setTheShape())
		->setTransformation(t2)
		->setShader(shader)
	);
	Transformation* t3 = (new Transformation(
		vec3(0.0f, 2.0f, 0.0f),
		1
	))->scaleModel()->rotateModel();
	this->addObject(
		(new DrawableObject())
		->setModel((new SphereModel)->setTheShape())
		->setTransformation(t3)
		->setShader(shader)
	);
	Transformation* t4 = (new Transformation(
		vec3(0.0f, -2.0f, 0.0f),
		1
	))->scaleModel()->rotateModel();
	this->addObject(
		(new DrawableObject())
		->setModel((new SphereModel)->setTheShape())
		->setTransformation(t4)
		->setShader(shader)
	);

	return this;
}

Scene* SkyScene::SceneControls()
{
	return nullptr;
}
