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
using namespace ScenesHeaders;
using namespace ModelsHeaders;
const char* v1 =
"#version 330\n"
"uniform mat4 model;"
"uniform mat4 projectMatrix;"
"uniform mat4 viewMatrix;"
"out vec3 vertexColor;"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 vn;"
"void main () {"
"     vertexColor=vn;"
"     gl_Position = projectMatrix * viewMatrix * model * vec4(vp, 1.0);"
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
	/*this->addObject(
		(new DrawableObject())
		->setModel((new TriangleModel())->setTheShape())
		->setTransformation(new Transformation())
		->setShader(
			(new Shader())
			->setFragmentShader(f1)
			->setVertexShader(v1)
			->linkShaders()
		)
	);*/

	//this->addObject(
	//	(new DrawableObject())
	//	->setModel((new SphereModel)->setTheShape())
	//	->setTransformation(new Transformation())
	//	->setShader((new Shader())
	//		->setFragmentShader(f1)
	//		->setVertexShader(v1)
	//		->linkShaders()
	//	)
	//);

	//this->addObject(
	//	(new DrawableObject())
	//	->setModel((new SuziModel)->setTheShape())
	//	->setTransformation(new Transformation())
	//	->setShader((new Shader())
	//		->setFragmentShader(f1)
	//		->setVertexShader(v1)
	//		->linkShaders()
	//	)
	//);

	//this->addObject(
	//	(new DrawableObject())
	//	->setModel((new TreeModel)->setTheShape())
	//	->setTransformation(new Transformation())
	//	->setShader((new Shader())
	//		->setFragmentShader(f1)
	//		->setVertexShader(v1)
	//		->linkShaders()
	//	)
	//);

	//this->addObject(
	//	(new DrawableObject())
	//	->setModel((new GiftModel)->setTheShape())
	//	->setTransformation(new Transformation())
	//	->setShader((new Shader())
	//		->setFragmentShader(f1)
	//		->setVertexShader(v1)
	//		->linkShaders()
	//	)
	//);

	//this->addObject(
	//	(new DrawableObject())
	//	->setModel((new BushesModel)->setTheShape())
	//	->setTransformation(new Transformation())
	//	->setShader((new Shader())
	//		->setFragmentShader(f1)
	//		->setVertexShader(v1)
	//		->linkShaders()
	//	)
	//);



	this->addObject(
		(new DrawableObject())
		->setModel((new SuziFlatModel)->setTheShape())
		->setTransformation(new Transformation())
		->setShader((new Shader())
			->setFragmentShader(f1)
			->setVertexShader(v1)
			->linkShaders()
		)
	);


	return this;
}

Scene* SkyScene::SceneControls()
{
	return nullptr;
}
