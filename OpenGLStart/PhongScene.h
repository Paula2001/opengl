#pragma once

#include "Scene.h"

namespace ScenesHeaders {
	class PhongScene : public Scene
	{
	public:
		Scene* ComposeScene();
		Scene* SceneControls();
	};
}

