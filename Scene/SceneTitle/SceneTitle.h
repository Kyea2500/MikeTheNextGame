#pragma once
#include "../SceneManager/SceneManager.h"
class SceneTitle
{
public:
	SceneTitle();
	~SceneTitle();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
};

