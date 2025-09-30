#include "Player.h"
#include"../Games/GameDive/Pad/Pad.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../Games/GameDive/game.h"

namespace
{
	constexpr float kSpeed = 10.0f; // �v���C���[�̈ړ����x
	constexpr float kBoost = 5.0f; // �u�Ԉړ��̋����𑝂₷�W��
	constexpr int kPlayerImageWidth = 64; // �v���C���[�摜�̕�
	constexpr int kPlayerImageHeight = 64; // �v���C���[�摜�̍���
	constexpr int half = 2; // 2�Ŋ��邽�߂̒萔
}


Player::Player() :m_pos(0.0f, 0.0f),
m_playerHandle(-1),
speed(kSpeed),
m_isMove(false)
{
}
Player::~Player()
{
}
void Player::Init()
{

}
void Player::End()
{
}
void Player::Update()
{
	UpdateMove();
}
void Player::Draw()
{
}

void Player::UpdateMove()
{
	// �v���C���[�̈ړ�����
	// �ړ��x�N�g����������
	Vec2 move(0.0f, 0.0f);
	m_isMove = false;
	move.x = 0.0f;
	move.y = 0.0f;

	// �v���C���[�̈ړ������̌�����������
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		// ���Ɉړ�
		move.x -= speed;
		m_isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		// ���Ɉړ�
		move.y += speed;
		m_isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		// �E�Ɉړ�
		move.x += speed;
		m_isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_UP))
	{
		// ��Ɉړ�
		move.y -= speed;
		m_isMove = true;
	}
	// �ړ��x�N�g���𐳋K��
	if (move.Length() > 0.0f)
	{
		move.Normalize();
	}

	move.x *= kBoost; // �u�Ԉړ��̋����𑝂₷
	move.y *= kBoost; // �u�Ԉړ��̋����𑝂₷

	// �v���C���[�̈ʒu���X�V
	m_pos += move;

	// ��ʊO�ɏo�Ȃ��悤�ɐ���
	if (m_pos.x < kPlayerImageWidth / half)
	{
		m_pos.x = kPlayerImageWidth / half;
	}
	if (m_pos.x > Game::kScreenWidth - kPlayerImageWidth / half)
	{
		m_pos.x = kPlayerImageWidth / half;
	}
	if (m_pos.y < kPlayerImageHeight / half)
	{
		m_pos.y = kPlayerImageHeight / half;
	}
	if (m_pos.y > Game::kScreenHeight - kPlayerImageHeight / half)
	{
		m_pos.y = Game::kScreenHeight - kPlayerImageHeight / half;
	}

}
