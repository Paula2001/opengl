#pragma once
#include "Model.h"

class SphereModel : public Model
{
public:
	Model* setTheShape();
	Model* setMotion();
	void drawTheShape();
};