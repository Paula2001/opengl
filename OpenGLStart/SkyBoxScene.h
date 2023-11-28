#pragma once
#include "Scene.h"

namespace ScenesHeaders {
	class SkyBoxScene : public Scene
	{
		public:
			Scene* ComposeScene();
			Scene* SceneControls();
	};
}


