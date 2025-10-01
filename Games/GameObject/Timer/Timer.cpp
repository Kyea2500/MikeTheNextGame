#include "Timer.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"

namespace
{
	constexpr float kMaxTime = 60.0f; // 1�b�Ԃ̃t���[����
	constexpr int kMaxSec = 60; // 1���Ԃ̕b��
	constexpr int kMaxMns = 100; // �ő啪��
}

Timer::Timer():m_timeSec(0),
m_timeMns(0),
m_time(0.0f)
{
}

Timer::~Timer()
{
}

void Timer::Init()
{
	m_time = 0.0f;
	m_timeSec = 0;
	m_timeMns = 0;
}
void Timer::End()
{
}
void Timer::Update()
{
	m_time++;
	if (m_time >= kMaxTime)
	{
		m_timeSec++;
		m_time = 0.0f;
		if (m_timeSec >= kMaxSec)
		{
			m_timeMns++;
			m_timeSec = 0;
			if (m_timeMns >= kMaxMns)
			{
				m_timeMns = 99;
				m_timeSec = 59;
			}
		}
	}
}
void Timer::Draw()
{
	// �o�ߎ��Ԃ̕`��
	if(m_timeMns<10&&m_timeSec<10)
	{
		DrawFormatString(10, 10, GetColor(255, 255, 255), "0%d:0%d",m_timeMns,m_timeSec);
		return;
	}
	else if(m_timeMns<10)
	{
		DrawFormatString(10, 10, GetColor(255, 255, 255), "0%d:%d", m_timeMns, m_timeSec);
		return;
	}
	else if(m_timeSec<10)
	{
		DrawFormatString(10, 10, GetColor(255, 255, 255), "%d:0%d", m_timeMns, m_timeSec);
		return;
	}
	DrawFormatString(10, 10, GetColor(255, 255, 255), "%d:%d", m_timeMns, m_timeSec);

}
