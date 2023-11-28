#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class CubeModel : public Model
	{
	public:
		Model* setTheShape();
		Model* setMotion();
		void drawTheShape();
	};
}
