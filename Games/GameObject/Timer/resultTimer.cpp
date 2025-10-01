#include "resultTimer.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"Timer.h"

namespace
	{
		// �e�L�X�g�ʒu
		constexpr int kTextPosX = 400;
		constexpr int kTextPosY = 200;

		// �^�C�}�[�̈ʍő�l
		constexpr int kMax = 10;
	}

resultTimer::resultTimer() :m_timeSec(0),
m_timeMns(0),
m_timer(nullptr)
{
}

resultTimer::~resultTimer()
{
}
void resultTimer::Init()
{
	m_timer = std::make_shared<Timer>();
	m_timer->Init();
}
void resultTimer::End()
{
	m_timer->End();
	m_timer = nullptr;
}
void resultTimer::Draw()
{
	m_timeSec = m_timer->GetTimeSec();
	m_timeMns = m_timer->GetTimeMns();
	// �o�ߎ��Ԃ̕`��
	if (m_timeMns < kMax && m_timeSec < kMax)
	{
		DrawFormatString(kTextPosX, kTextPosY,0xffffff, "0%d:0%d", m_timeMns, m_timeSec);
		return;
	}
	else if (m_timeMns < kMax)
	{
		DrawFormatString(kTextPosX, kTextPosY,0xffffff, "0%d:%d", m_timeMns, m_timeSec);
		return;
	}
	else if (m_timeSec < kMax)
	{
		DrawFormatString(kTextPosX, kTextPosY,0xffffff, "%d:0%d", m_timeMns, m_timeSec);
		return;
	}
	DrawFormatString(kTextPosX, kTextPosY,0xffffff, "%d:%d", m_timeMns, m_timeSec);
}
