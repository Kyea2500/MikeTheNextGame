#pragma once
#include"../../GameDive/Vec2.h"
class TreasureBox
{
	public:
	TreasureBox();
	~TreasureBox();
	void Init();
	void End();
	void Update();
	void Draw();
public:
	// •ó” ‚Ì“–‚½‚è”»’è
	float HitSquareTop();
	float HitSquareBottom();
	float HitSquareLeft();
	float HitSquareRight();
private:
	// •ó” ‚ÌˆÊ’u
	Vec2 m_pos;
	// •ó” ‚Ìƒnƒ“ƒhƒ‹
	int m_treasureBoxHandle;
	int m_frame;
};

