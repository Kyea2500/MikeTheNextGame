#pragma once
#include"../SceneManager/SceneManager.h"

class SceneMain
{
	public:
	SceneMain();
	~SceneMain();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
};

