#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class SphereModel : public Model
	{
		public:
			Model* setTheShape();
			Model* setMotion();
			void drawTheShape();
	};
}
