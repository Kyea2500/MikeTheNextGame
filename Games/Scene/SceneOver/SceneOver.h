#pragma once
#include"../SceneManager/SceneManager.h"
class Timer;
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
	std::shared_ptr<Timer> m_Timer;
};

