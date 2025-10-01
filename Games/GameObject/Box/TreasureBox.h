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
	// �󔠂̓����蔻��
	float HitSquareTop();
	float HitSquareBottom();
	float HitSquareLeft();
	float HitSquareRight();
private:
	// �󔠂̈ʒu
	Vec2 m_pos;
	// �󔠂̃n���h��
	int m_treasureBoxHandle;
	int m_frame;
};

