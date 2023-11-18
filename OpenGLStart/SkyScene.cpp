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
const char* v1 =
"#version 330\n"
"uniform mat4 model;"
"uniform mat4 projection;"
"uniform mat4 view;"
"uniform mat4 camMatrix;"
"out vec3 vertexColor;"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 vn;"
"void main () {"
"     vertexColor=vn;"
"     gl_Position = view * camMatrix * vec4(vp, 1.0);"
"}";


const char* f1 =
"#version 330\n"
"out vec4 frag_colour;"
"in vec3 vertexColor;"
"void main () {"
"     frag_colour = vec4(vertexColor, 0.0);"
"}";

Scene* SkyScene::ComposeScene()
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
		Transformation* t = (new Transformation(
			vec3(initPos, 0.0f, -1.0f),
			1
		))->scaleModel()->rotateModel();
		Shader* shader = new Shader();
		shader->loadShader("basic.vert", "basic.frag");
		this->addObject(
			(new DrawableObject())
			->setModel((x[randomNumber])->setTheShape())
			->setTransformation(t)
			->setShader(shader)
		);
	}

	return this;
}

Scene* SkyScene::SceneControls()
{
	return nullptr;
}
