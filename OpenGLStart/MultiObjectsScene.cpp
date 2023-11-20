#include "MultiObjectsScene.h"
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


Scene* MultiObjectsScene::ComposeScene()
{
	
	vector<Model*> x = {
		new TreeModel, 
		new SphereModel,
		new GiftModel,
		new SuziFlatModel,
		new BushesModel,
	};
	float initPos = 0.0f;
	Shader* shader = new Shader();
	shader->loadShader("phong.vert", "phong.frag");
	for (int i = 0; i < 10; i++) {
		std::random_device rd;
		std::mt19937 gen(rd());

		// Define the range
		std::uniform_int_distribution<> distr(0, 4); // Range is 0 to 4 inclusive

		// Generate and print a random number
		int randomNumber = distr(gen);
		initPos += 2.5f;
		Transformation* t1 = (new Transformation(
			vec3(initPos, 0.0f, 0.0f),
			1
		))->scaleModel()->rotateModel();
		this->addObject(
			(new DrawableObject())
			->setModel((x[randomNumber])->setTheShape())
			->setTransformation(t1)
			->setShader(shader)
		);
	}
	return this;
}

Scene* MultiObjectsScene::SceneControls()
{
	return nullptr;
}
