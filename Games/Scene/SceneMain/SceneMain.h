#pragma once
#include"../SceneManager/SceneManager.h"
class Player;
class TreasureBox;
class Timer;
class SceneMain
{
	public:
	SceneMain();
	~SceneMain();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	std::shared_ptr<Player> m_player;
	std::shared_ptr<TreasureBox> m_treasureBox;
	std::shared_ptr<Timer> m_timer;
};

