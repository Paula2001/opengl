#pragma once

#include "Model.h"

namespace ModelsHeaders {
	class HouseModel : public Model
	{
	private:
		int count = 0;
	public:
		Model* setTheShape();
		Model* setMotion();
		void drawTheShape();
	};
}
