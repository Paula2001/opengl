#pragma once
#include "Scene.h"
namespace ScenesHeaders {
	class SkyScene : public Scene
	{
		public:
			Scene* ComposeScene();
			Scene* SceneControls();
	};
}

