#pragma once
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
	double m_time;	// ‚±‚¢‚Â‚ğdoubleŒ^‚É‚µ‚½‚¢‚ªc
				// TimerƒNƒ‰ƒX‚ÌGetTime()‚ªintŒ^‚ğ•Ô‚·‚Ì‚ÅintŒ^‚É‚µ‚Ä‚¨‚­
	int m_min;
	int m_sec; 
	float m_remitt;
};

