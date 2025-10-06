#pragma once
#include <memory>
class Timer;
class resultTimer
{
public:
	resultTimer();
	~resultTimer();
	void Init();
	void End();
	void Update();
	void Draw();
private:
	std::shared_ptr<Timer> m_timer;
};

