#pragma once
#include"../SceneManager/SceneManager.h"
class SceneOver
{
public:
	SceneOver();
	~SceneOver();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
};

