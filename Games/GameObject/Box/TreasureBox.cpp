#include "TreasureBox.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"

namespace
{
	// 宝箱の画像の幅
	constexpr int kTreasureBoxImageWidth = 18;
	// 宝箱の画像の高さ
	constexpr int kTreasureBoxImageHeight = 17;
	// 宝箱の拡大率
	constexpr float kTreasureBoxScale = 2.0f;

	// 宝箱の初期位置
	constexpr float kTreasureBoxInitPosX = 300.0f;
	constexpr float kTreasureBoxInitPosY = 300.0f;
	constexpr int half = 2; // 2で割るための定数
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
	DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
		0, 0, kTreasureBoxImageWidth, kTreasureBoxImageHeight, // 切り出す位置
		kTreasureBoxScale, 0.0f, m_treasureBoxHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
	//当たり判定を描画
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
