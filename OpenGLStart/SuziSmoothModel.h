#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class SuziSmoothModel : public Model
	{
	public:
		Model* setTheShape();
		Model* setMotion();
		void drawTheShape();
	};
}