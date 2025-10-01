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
	int m_timeSec; // Œo‰ßŠÔ(•b)
	int m_timeMns; // Œo‰ßŠÔ(•ª)
	float m_time;   // Œo‰ßŠÔ(•b.ƒ~ƒŠ•b)
};

