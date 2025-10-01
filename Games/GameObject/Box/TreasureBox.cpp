#include "TreasureBox.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"

namespace
{
	// �󔠂̉摜�̕�
	constexpr int kTreasureBoxImageWidth = 18;
	// �󔠂̉摜�̍���
	constexpr int kTreasureBoxImageHeight = 17;
	// �󔠂̊g�嗦
	constexpr float kTreasureBoxScale = 2.0f;

	// �󔠂̏����ʒu
	constexpr float kTreasureBoxInitPosX = 300.0f;
	constexpr float kTreasureBoxInitPosY = 300.0f;
	constexpr int half = 2; // 2�Ŋ��邽�߂̒萔
}

TreasureBox::TreasureBox() :m_pos(0.0f, 0.0f),
m_treasureBoxHandle(-1),
m_frame(0)
{
}

TreasureBox::~TreasureBox()
{
}
void TreasureBox::Init()
{
	m_pos.x = kTreasureBoxInitPosX;
	m_pos.y = kTreasureBoxInitPosY;
	m_treasureBoxHandle = LoadGraph("Image/Chast/chests.png");
}
void TreasureBox::End()
{
}
void TreasureBox::Update()
{
	
}
void TreasureBox::Draw()
{
	DrawRectRotaGraph(m_pos.x, m_pos.y, // �`��ʒu
		0, 0, kTreasureBoxImageWidth, kTreasureBoxImageHeight, // �؂�o���ʒu
		kTreasureBoxScale, 0.0f, m_treasureBoxHandle, TRUE, FALSE); // �g�嗦�A��]�p�x�A�n���h���A�����F���g�����A���]���邩
	//�����蔻���`��
	DrawBox(HitSquareLeft(), HitSquareTop(), HitSquareRight(), HitSquareBottom(),0x00ffff, FALSE);
}

float TreasureBox::HitSquareTop()
{
	return m_pos.y - (kTreasureBoxImageHeight * kTreasureBoxScale) / half;
}
float TreasureBox::HitSquareBottom()
{
	return m_pos.y + (kTreasureBoxImageHeight * kTreasureBoxScale) / half;
}
float TreasureBox::HitSquareLeft()
{
	return m_pos.x - (kTreasureBoxImageWidth * kTreasureBoxScale) / half;
}
float TreasureBox::HitSquareRight()
{
	return m_pos.x + (kTreasureBoxImageWidth * kTreasureBoxScale) / half;
}
