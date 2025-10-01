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
public:
	void UpdateMove();
	float HitSquareTop();
	float HitSquareBottom();
	float HitSquareLeft();
	float HitSquareRight();
private:
	// �v���C���[�̈ʒu
	Vec2 m_pos;
	
	// �v���C���[�̃n���h��
	int m_playerHandle;
	
	// �v���C���[�̈ړ����x
	float speed;

	// �v���C���[�̈ړ����
	bool m_isMove;	// true�Ȃ�ړ���		false�Ȃ�ړ����Ă��Ȃ�

	// �v���C���[�̌���
	int m_dir;	// 0:���� 1:�E 2:�� 3:��� 4:�E�΂ߑO 5:���΂ߑO 6:�E�΂ߌ�� 7:���΂ߌ��

	// �v���C���[�̃A�j���t���[��
	int m_frame;

};

