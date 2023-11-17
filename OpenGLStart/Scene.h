#pragma once
#include"DrawableObject.h"
#include<vector>
using namespace std;
class Scene
{
public:
	Scene* addObject(DrawableObject* obj);
	virtual Scene* ComposeScene() = 0;
	virtual Scene* SceneControls() = 0;
	void init();
protected:
	vector<DrawableObject*> objects;
};

