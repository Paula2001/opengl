#include "SkyScene.h"
#include "DrawableObject.h"
#include "TriangleModel.h"

const char* v1 = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"   gl_Position = model * vec4(aPos, 1.0);\n"
"}\0";

const char* f1 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";

Scene* SkyScene::ComposeScene()
{
	this->addObject(
		(new DrawableObject())
		->setModel((new TriangleModel())->setTheShape())
		->setTransformation(new Transformation())
		->setShader(
			(new Shader())
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
