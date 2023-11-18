#include "PhongScene.h"
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
#include "Light.h"

using namespace ScenesHeaders;
using namespace ModelsHeaders;
using namespace ShaderHeaders;
using namespace std;

Scene* PhongScene::ComposeScene()
{

	vector<Model*> x = {
		new TreeModel,
		new SuziSmoothModel,
		new SuziFlatModel,
		new GiftModel,
		new BushesModel
	};
	float initPos = 0.0f;
	for (int i = 0; i < 2; i++) {
		std::random_device rd;
		std::mt19937 gen(rd());

		// Define the range
		std::uniform_int_distribution<> distr(0, 4); // Range is 0 to 4 inclusive

		// Generate and print a random number
		int randomNumber = distr(gen);
		initPos += 0.3f;
		Shader* shader = new Shader();

		Light* ff = new Light(shader);
		Transformation* t = (new Transformation(
			vec3(initPos, 0.0f, -1.0f),
			1
		))->scaleModel()->rotateModel();
		shader->loadShader("phong.vert", "phong.frag");
		this->addObject(
			(new DrawableObject())
			->setModel((x[randomNumber])->setTheShape())
			->setTransformation(t)
			->setShader(shader)
		);
	}

	return this;
}

Scene* PhongScene::SceneControls()
{
	return nullptr;
}
