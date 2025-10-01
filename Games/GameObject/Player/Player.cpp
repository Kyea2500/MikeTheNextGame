#include "Player.h"
#include"../Games/GameDive/Pad/Pad.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../Games/GameDive/game.h"

namespace
{
	constexpr float kSpeed = 10.0f; // �v���C���[�̈ړ����x
	constexpr float kBoost = 5.0f; // �u�Ԉړ��̋����𑝂₷�W��
	constexpr float kPlayerImageWidth = 16.1f; // �v���C���[�摜�̕�
	constexpr float kPlayerImageHeight = 25.6f;// �v���C���[�摜�̍���
	constexpr float kPlayerScale = 2.0f; // �v���C���[�摜�̊g�嗦
	constexpr int half = 2; // 2�Ŋ��邽�߂̒萔
	constexpr int kAnimeFrameSpeed = 5; // �A�j���[�V�����̃t���[�����x
	constexpr int kMoveAnimeNum = 3; // �ړ��A�j���[�V�����̖���

	// �v���C���[�̌���
	enum PlayerDir
	{
		kFront = 0, // ����(��)	
		kRight = 1, // �E
		kLeft = 2, // ��
		kBack = 3, // ���(��)
		kRightFront = 4, // �E�΂ߑO
		kLeftFront = 5, // ���΂ߑO
		kRightBack = 6, // �E�΂ߌ��
		kLeftBack = 7 // ���΂ߌ��
	};
}


Player::Player() :m_pos(0.0f, 0.0f),
m_playerHandle(-1),
speed(kSpeed),
m_isMove(false),
m_frame(0),
m_dir(kFront)
{
}
Player::~Player()
{
}
void Player::Init()
{
	m_pos.x = Game::kScreenWidth / half; // ��ʂ̒��S�ɏ�����
	m_pos.y = Game::kScreenHeight / half; // ��ʂ̒��S�ɏ�����
	m_playerHandle = LoadGraph("Image/Player/Player.Png"); // �v���C���[�摜�̓ǂݍ���
	// �v���C���[�̌�����������
	m_dir = kFront;
}
void Player::End()
{
}
void Player::Update()
{
	// �A�j���t���[���̍X�V
	m_frame++;
	int totalAnimeFrame = kAnimeFrameSpeed * kMoveAnimeNum;
	// �A�j���t���[�����ő�l�𒴂�����0�ɖ߂�
	if (m_frame >= totalAnimeFrame)
	{
		m_frame = 0;
	}
	// �p�b�h�̍X�V
	Pad::Update();
	// �v���C���[�̍X�V
	UpdateMove();
}
void Player::Draw()
{
	int animeIndex = m_frame / kMoveAnimeNum; // �A�j���[�V�����̃C���f�b�N�X
	// �v���C���[�̕`��
	if (m_isMove)
	{
		// �ړ����̕`��
		switch (m_dir)
		{
		case kFront:
			// ���ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				4*kPlayerImageWidth, animeIndex*kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		case kRight:
			// �E�ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				2*kPlayerImageWidth, animeIndex*kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		case kLeft:
			// ���ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				6 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		case kBack:
			// ��ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				0 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		case kRightFront:
			// �E���ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				3 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		case kLeftFront:
			// �����ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				5 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		case kRightBack:
			// �E��ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				1 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		case kLeftBack:
			// ����ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				7 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
		default:
			break;
		}
	}
	else
	{
		switch (m_dir)
		{
			case kFront:
			// ���ړ��̉摜�`��
			DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
				4*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
			break;
			case kRight:
				// �E�ړ��̉摜�`��
				DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
					2*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
				break;
			case kLeft:
				// ���ړ��̉摜�`��
				DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
					6*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
				break;
			case kBack:
				// ��ړ��̉摜�`��
				DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
					0*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
				break;
			case kRightFront:
				// �E���ړ��̉摜�`��
				DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
					3 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
				break;
			case kLeftFront:
				// �����ړ��̉摜�`��
				DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
					5 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
				break;
			case kRightBack:
				// �E��ړ��̉摜�`��
				DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
					1 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
				break;
			case kLeftBack:
				// ����ړ��̉摜�`��
				DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
					7 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // �؂�o���ʒu
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
				break;
		default:
			break;
		}
	}
	
	//�����蔻���`��
	DrawBox(HitSquareLeft(), HitSquareTop(), HitSquareRight(), HitSquareBottom(), 0xff0000, FALSE);
}

void Player::UpdateMove()
{
	// �v���C���[�̈ړ�����
	// �ړ��x�N�g����������
	Vec2 move(0.0f, 0.0f);
	m_isMove = false;
	move.x = 0.0f;
	move.y = 0.0f;

	// �ǂ̕����Ɉړ����Ă��邩����
	if(Pad::IsPress(PAD_INPUT_LEFT)&&Pad::IsPress(PAD_INPUT_DOWN))
	{
		// �����Ɉړ�
		move.x -= speed;
		move.y += speed;
		m_isMove = true;
		m_dir = kLeftFront;
	}
	if (Pad::IsPress(PAD_INPUT_LEFT) && Pad::IsPress(PAD_INPUT_UP))
	{
		// ����Ɉړ�
		move.x -= speed;
		move.y -= speed;
		m_isMove = true;
		m_dir = kLeftBack;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT) && Pad::IsPress(PAD_INPUT_DOWN))
	{
		// �E���Ɉړ�
		move.x += speed;
		move.y += speed;
		m_isMove = true;
		m_dir = kRightFront;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT) && Pad::IsPress(PAD_INPUT_UP))
	{
		// �E��Ɉړ�
		move.x += speed;
		move.y -= speed;
		m_isMove = true;
		m_dir = kRightBack;
	}

	// �v���C���[�̈ړ������̌�����������
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		// ���Ɉړ�
		move.x -= speed;
		m_isMove = true;
		m_dir = kLeft;
	}
	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		// ���Ɉړ�
		move.y += speed;
		m_isMove = true;
		m_dir = kFront;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		// �E�Ɉړ�
		move.x += speed;
		m_isMove = true;
		m_dir = kRight;
	}
	if (Pad::IsPress(PAD_INPUT_UP))
	{
		// ��Ɉړ�
		move.y -= speed;
		m_isMove = true;
		m_dir = kBack;
	}

	// �ړ��x�N�g���𐳋K��
	if (move.Length() > 0.0f)
	{
		move.Normalize();
	}

	//move.x *= kBoost; // X���̃X�s�[�h�̃M�A���グ��
	//move.y *= kBoost; // Y���̃X�s�[�h�̃M�A���グ��

	// �v���C���[�̈ʒu���X�V
	m_pos += move;

	// ��ʊO�ɏo�Ȃ��悤�ɐ���
	if (m_pos.x < kPlayerImageWidth / half)
	{
		m_pos.x = kPlayerImageWidth / half;
	}
	if (m_pos.x > Game::kScreenWidth - kPlayerImageWidth / half)
	{
		m_pos.x = Game::kScreenWidth-kPlayerImageWidth / half;
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

float Player::HitSquareTop()
{
	// �v���C���[�̏�ӂ̓����蔻����擾
	return m_pos.y - (kPlayerImageHeight * kPlayerScale) / half;
}

float Player::HitSquareBottom()
{
	// �v���C���[�̉��ӂ̓����蔻����擾
	return m_pos.y + (kPlayerImageHeight * kPlayerScale) / half;
}

float Player::HitSquareLeft()
{
	// �v���C���[�̍��ӂ̓����蔻����擾
	return m_pos.x - (kPlayerImageWidth * kPlayerScale) / half;
}

float Player::HitSquareRight()
{
	// �v���C���[�̉E�ӂ̓����蔻����擾
	return m_pos.x + (kPlayerImageWidth * kPlayerScale) / half;
}
