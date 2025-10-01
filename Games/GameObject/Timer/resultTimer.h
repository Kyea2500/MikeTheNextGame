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
	void Draw();
private:
	std::shared_ptr<Timer> m_timer;
private:
	int m_timeSec; // �o�ߎ���(�b)
	int m_timeMns; // �o�ߎ���(��)
};

