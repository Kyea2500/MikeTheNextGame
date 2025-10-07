#include "resultTimer.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"Timer.h"
#include<cassert>

namespace
	{
		// テキスト位置
		constexpr int kTextPosX = 400;
		constexpr int kTextPosY = 200;

		// タイマーの位最大値
		constexpr int kMax = 10;

		// 
		constexpr double kMaxMinSec = 60.0;

		// 時間切れ
		constexpr float kTimeUp = 120.0f;
	}

resultTimer::resultTimer() :m_time(0.0),
m_min(0),
m_sec(0),
m_remitt(0.0f)
{
}

resultTimer::~resultTimer()
{
}
void resultTimer::Init()
{

}
void resultTimer::End()
{
}
void resultTimer::Update()
{
	// 経過時間を取得
	m_remitt++;
	// Timerクラスから時間を取得
	Timer timer;
	m_time = timer.GetTime();
	// 分と秒に変換
	if (m_time >= kMaxMinSec)
	{
		m_sec++;
		m_time - kMaxMinSec;
		if (m_sec >= 60)
		{
			m_min++;
			m_sec - kMaxMinSec;
		}
	}

	// 時間が取得できていない場合
	if (m_time == 0)
	{
		// 120フレームだけ待って、変化が無いか待つ
		if (m_remitt > kTimeUp && m_time == 0)
		{
			// 待っても変化が無い場合はエラーを出力して強制終了
			assert("時間を取得できませんでした　_(._.)_　" && false);
			return;
		}
	}
}

void resultTimer::Draw()
{
	// 分と秒を表示
	DrawFormatString(kTextPosX, kTextPosY, 0xffffff, "タイム: %f", m_time);
}
