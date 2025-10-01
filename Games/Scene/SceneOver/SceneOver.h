#pragma once
#include"../SceneManager/SceneManager.h"
class resultTimer;
class SceneOver
{
public:
	SceneOver();
	~SceneOver();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	std::shared_ptr<resultTimer> m_resultTimer;
};

