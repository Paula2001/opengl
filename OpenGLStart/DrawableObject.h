#pragma once
#include "Model.h"
#include "Transformation.h"
#include "Shader.h"
class DrawableObject
{
	public:
		DrawableObject* setModel(Model* model);
		DrawableObject* setTransformation(Transformation* t);
		DrawableObject* setShader(Shader* shader);
		Shader* shader;
		void draw();
		void move();
	private:
		Model* model;
		Transformation* transformation;
};

