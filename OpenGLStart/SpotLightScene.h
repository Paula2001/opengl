#pragma once

#include "Scene.h"

namespace ScenesHeaders {
	class SpotLightScene : public Scene
	{
	public:
		Scene* ComposeScene();
		Scene* SceneControls();
	};
}

