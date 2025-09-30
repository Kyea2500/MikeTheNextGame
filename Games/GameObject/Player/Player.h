#pragma once
#include"../../GameDive/Vec2.h"
class Player
{
public:
	Player();
	~Player();
	void Init();
	void End();
	void Update();
	void Draw();
private:
	void UpdateMove();
private:
	// �v���C���[�̈ʒu
	Vec2 m_pos;
	// �v���C���[�̃n���h��
	int m_playerHandle;
	// �v���C���[�̈ړ����x
	float speed;
	// �v���C���[�̈ړ����
	bool m_isMove;	// true�Ȃ�ړ���		false�Ȃ�ړ����Ă��Ȃ�

};

