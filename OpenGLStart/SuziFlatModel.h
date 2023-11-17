#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class SuziFlatModel : public Model
	{
	public:
		Model* setTheShape();
		Model* setMotion();
		void drawTheShape();
	};
}

