#pragma once
#include"Model.h"
namespace ModelsHeaders {
	class TriangleModel : public Model
	{
	public:
		Model* setTheShape();
		Model* setMotion();
		void drawTheShape();
	};
}
