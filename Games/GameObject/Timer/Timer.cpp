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
m_time(0.0),
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
	m_time += (double)(m_Start-m_End) / CLOCKS_PER_SEC;
	m_End = m_Start;
}
void Timer::Draw()
{
	DrawFormatString(kTextPosX, kTextPosY, 0xffffff, "%f秒",m_time);
}

void Timer::Stop()
{
	m_End = clock();
}
