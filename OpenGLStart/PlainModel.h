#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class PlainModel : public Model
	{
		public:
			Model* setTheShape();
			Model* setMotion();
			void drawTheShape();
	};
}
