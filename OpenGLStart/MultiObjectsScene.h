#pragma once
#include "Scene.h"
namespace ScenesHeaders {
	class MultiObjectsScene : public Scene
	{
		public:
			Scene* ComposeScene();
			Scene* SceneControls();
	};
}

