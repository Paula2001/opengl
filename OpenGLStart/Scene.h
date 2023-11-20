#pragma once
#include"DrawableObject.h"
#include<vector>
#include "Camera.h"
#include "Light.h"


namespace ScenesHeaders {
	class Scene
	{
		public:
			Scene* addObject(DrawableObject* obj);
			Scene* setCamera(Camera* camera);
			Scene* setLight(Light* light);
			virtual Scene* ComposeScene() = 0;
			virtual Scene* SceneControls() = 0;
			void init(GLFWwindow* window);
		protected:
			vector<DrawableObject*> objects;
			Camera* camera;
			Light* light;
	};
}
