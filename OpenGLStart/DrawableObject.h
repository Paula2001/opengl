#pragma once
#include "Model.h"
#include "Transformation.h"
#include "Shader.h"

using namespace ModelsHeaders;
using namespace ShaderHeaders;
class DrawableObject
{
	public:
		DrawableObject* setModel(Model* model);
		DrawableObject* setTransformation(Transformation* t);
		DrawableObject* setShader(Shader* shader);
		Shader* shader;
		void draw();
		void move(float test);
	private:
		Model* model;
		Transformation* transformation;
};

