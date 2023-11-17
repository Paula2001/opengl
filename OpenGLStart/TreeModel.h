#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class TreeModel : public Model
	{
	public:
		Model* setTheShape();
		Model* setMotion();
		void drawTheShape();
	};
}
