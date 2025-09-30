#include "Player.h"
#include"../Games/GameDive/Pad/Pad.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../Games/GameDive/game.h"

namespace
{
	constexpr float kSpeed = 10.0f; // プレイヤーの移動速度
	constexpr float kBoost = 5.0f; // 瞬間移動の距離を増やす係数
	constexpr int kPlayerImageWidth = 64; // プレイヤー画像の幅
	constexpr int kPlayerImageHeight = 64; // プレイヤー画像の高さ
	constexpr int half = 2; // 2で割るための定数
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
	// プレイヤーの移動処理
	// 移動ベクトルを初期化
	Vec2 move(0.0f, 0.0f);
	m_isMove = false;
	move.x = 0.0f;
	move.y = 0.0f;

	// プレイヤーの移動方向の向きを初期化
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		// 左に移動
		move.x -= speed;
		m_isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		// 下に移動
		move.y += speed;
		m_isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		// 右に移動
		move.x += speed;
		m_isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_UP))
	{
		// 上に移動
		move.y -= speed;
		m_isMove = true;
	}
	// 移動ベクトルを正規化
	if (move.Length() > 0.0f)
	{
		move.Normalize();
	}

	move.x *= kBoost; // 瞬間移動の距離を増やす
	move.y *= kBoost; // 瞬間移動の距離を増やす

	// プレイヤーの位置を更新
	m_pos += move;

	// 画面外に出ないように制限
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
