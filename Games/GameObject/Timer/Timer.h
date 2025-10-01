#pragma once
class Timer
{
public:
	Timer();
	~Timer();
	void Init();
	void End();
	void Update();
	void Draw();
public:
	int GetTimeSec() { return m_timeSec; }
	int GetTimeMns() { return m_timeMns; }
private:
	int m_timeSec; // �o�ߎ���(�b)
	int m_timeMns; // �o�ߎ���(��)
	float m_time;   // �o�ߎ���(�b.�~���b)
};

