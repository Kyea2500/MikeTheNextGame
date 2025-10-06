#include "resultTimer.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"Timer.h"

namespace
	{
		// テキスト位置
		constexpr int kTextPosX = 400;
		constexpr int kTextPosY = 200;

		// タイマーの位最大値
		constexpr int kMax = 10;
	}

resultTimer::resultTimer() :
m_timer(nullptr)
{
}

resultTimer::~resultTimer()
{
}
void resultTimer::Init()
{
	m_timer = std::make_shared<Timer>();
}
void resultTimer::End()
{
}
void resultTimer::Update()
{
	m_timer->Update();
	if (m_timer->GetTimeSec() >= kMax)
	{
		m_timer->End();
	}
}

void resultTimer::Draw()
{
	m_timer->Draw();
}
