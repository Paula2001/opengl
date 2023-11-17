#pragma once
#include "Model.h"
namespace ModelsHeaders {
	class GiftModel : public Model
	{
		public:
			Model* setTheShape();
			Model* setMotion();
			void drawTheShape();
	};
}
