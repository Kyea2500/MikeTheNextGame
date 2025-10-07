#include "Timer.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../../Scene/SceneMain/SceneMain.h"

namespace
{
	// テキスト位置
	constexpr int kTextPosX = 10;
	constexpr int kTextPosY = 10;

}

Timer::Timer():
m_timer(0.0),
m_Start(0),
m_End(0)
{
	m_sceneMain = std::make_shared<SceneMain>();
}

Timer::~Timer()
{
}

void Timer::Init()
{
	m_timer = 0.0;
	m_Start = clock();
	m_End = m_Start;
}
void Timer::End()
{

}
void Timer::Update()
{
	m_Start = clock();
	if (m_sceneMain->m_clear)
	{
		Stop();
	}
	// 経過時間を秒に変換して加算
	m_timer += (double)(m_Start-m_End) / CLOCKS_PER_SEC;
	m_End = m_Start;
}
void Timer::Draw()
{
	DrawFormatString(kTextPosX, kTextPosY, 0xffffff, "%101f秒",m_timer);

}

void Timer::Stop()
{
	m_End = clock();
}

double Timer::GetTime()
{
	m_timer =(m_End - m_Start) / CLOCKS_PER_SEC;
	return m_timer;
}
