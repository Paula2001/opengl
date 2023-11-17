#pragma once
#include"Model.h"
class TriangleModel : public Model
{
public:
	Model* setTheShape();
	Model* setMotion();
	void drawTheShape();
};

