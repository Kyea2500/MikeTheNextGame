#pragma once
#include<time.h>
#include<memory>
class SceneMain;
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
	void Stop();
	double GetTime(); // Œo‰ßŽžŠÔ‚ðŽæ“¾
private:
	std::shared_ptr<SceneMain> m_sceneMain;
private:
    double m_timer;
	long m_Start;
	long m_End;

};

