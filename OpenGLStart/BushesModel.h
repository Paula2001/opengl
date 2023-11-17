#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class BushesModel : public Model
	{
		public:
			Model* setTheShape();
			Model* setMotion();
			void drawTheShape();
	};
}

