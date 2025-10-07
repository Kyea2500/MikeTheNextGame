#include "Player.h"
#include"../Games/GameDive/Pad/Pad.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../Games/GameDive/game.h"

namespace
{
	constexpr float kSpeed = 10.0f; // プレイヤーの移動速度
	constexpr float kBoost = 5.0f; // 瞬間移動の距離を増やす係数
	constexpr double kPlayerImageWidth = 18.0; // プレイヤー画像の幅
	constexpr double kPlayerImageHeight = 18.5;// プレイヤー画像の高さ
	constexpr double kPlayerIdleImageWidth = 16.5; // プレイヤー画像の幅(int型)
	constexpr double kPlayerIdleImageHeight = 16.5; // プレイヤー画像の高さ(int型)
	constexpr float kPlayerScale = 2.0f; // プレイヤー画像の拡大率
	constexpr int half = 2; // 2で割るための定数
	constexpr int kAnimeFrameSpeed = 8; // アニメーションのフレーム速度
	constexpr int kMoveAnimeNum = 3; // 移動アニメーションの枚数

	// プレイヤーの向き
	enum PlayerDir
	{
		kFront = 0, // 正面(下)	
		kRight = 1, // 右
		kLeft = 2, // 左
		kBack = 3, // 後ろ(上)
	};
}


Player::Player() :m_pos(0.0f, 0.0f),
m_playerHandleIdle(-1),
m_playerHandleMove(-1),
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
	m_pos.x = Game::kScreenWidth / half; // 画面の中心に初期化
	m_pos.y = Game::kScreenHeight / half; // 画面の中心に初期化
	m_playerHandleIdle = LoadGraph("Image/Player/NewPlayer_Idle.png"); // プレイヤー画像の読み込み
	m_playerHandleMove = LoadGraph("Image/Player/NewPlayer_Move.png"); // プレイヤー移動画像の読み込み
	// プレイヤーの向きを初期化
	m_dir = kFront;
}
void Player::End()
{
}
void Player::Update()
{
	// アニメフレームの更新
	m_frame++;

	int totalAnimeFrame = kAnimeFrameSpeed * kMoveAnimeNum;
	// アニメフレームが最大値を超えたら0に戻す
	if (m_frame >= totalAnimeFrame)
	{
		m_frame = 0;
	}
	// パッドの更新
	Pad::Update();
	// プレイヤーの更新
	UpdateMove();
}
void Player::Draw()
{
	// プレイヤーの描画
	int handle = m_playerHandleIdle; // 移動中なら移動画像、そうでなければ待機画像 
	if (m_isMove)
	{
		handle = m_playerHandleMove;
	}
	// アニメーションのフレームを計算
	int animeFrame = m_frame / kAnimeFrameSpeed;
	// プレイヤーの向きに応じて描画
	if (m_isMove)
	{
		switch (m_dir)
		{
		case kFront: // 正面
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerImageWidth * animeFrame, 0, kPlayerImageWidth, kPlayerImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, FALSE);
			break;
		case kRight: // 右
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerImageWidth * animeFrame, kPlayerImageHeight * 2, kPlayerImageWidth, kPlayerImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, TRUE);
			break;
		case kLeft: // 左
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerImageWidth * animeFrame, kPlayerImageHeight * 2, kPlayerImageWidth, kPlayerImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, FALSE);
			break;
		case kBack: // 後ろ
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerImageWidth * animeFrame, kPlayerImageHeight * 4, kPlayerImageWidth, kPlayerImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, FALSE);
			break;
		}
	}
	else
	{
		switch (m_dir)
		{
		case kFront: // 正面
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerIdleImageWidth * animeFrame, 0, kPlayerIdleImageWidth, kPlayerIdleImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, FALSE);
			break;
		case kRight: // 右
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerIdleImageWidth * animeFrame, kPlayerIdleImageHeight * 2, kPlayerIdleImageWidth, kPlayerIdleImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, TRUE);
			break;
		case kLeft: // 左
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerIdleImageWidth * animeFrame, kPlayerIdleImageHeight * 2, kPlayerIdleImageWidth, kPlayerIdleImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, FALSE);
			break;
		case kBack: // 後ろ
			DrawRectRotaGraph(m_pos.x, m_pos.y,
				kPlayerIdleImageWidth * animeFrame, kPlayerIdleImageHeight * 4, kPlayerIdleImageWidth, kPlayerIdleImageHeight,
				kPlayerScale, 0.0f, handle, TRUE, FALSE);
			break;
		}
	}

	
	//当たり判定を描画
	DrawBox(HitSquareLeft(), HitSquareTop(), HitSquareRight(), HitSquareBottom(), 0xff0000, FALSE);
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
		m_dir = kLeft;
	}
	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		// 下に移動
		move.y += speed;
		m_isMove = true;
		m_dir = kFront;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		// 右に移動
		move.x += speed;
		m_isMove = true;
		m_dir = kRight;
	}
	if (Pad::IsPress(PAD_INPUT_UP))
	{
		// 上に移動
		move.y -= speed;
		m_isMove = true;
		m_dir = kBack;
	}

	// 移動ベクトルを正規化
	if (move.Length() > 0.0f)
	{
		move.Normalize();
	}

	move.x *= kBoost; // X軸のスピードのギアを上げる
	move.y *= kBoost; // Y軸のスピードのギアを上げる

	// プレイヤーの位置を更新
	m_pos += move;

	// 画面外に出ないように制限
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
	// プレイヤーの上辺の当たり判定を取得
	return m_pos.y - (kPlayerIdleImageHeight * kPlayerScale) / half;
}

float Player::HitSquareBottom()
{
	// プレイヤーの下辺の当たり判定を取得
	return m_pos.y + (kPlayerIdleImageHeight * kPlayerScale) / half;
}

float Player::HitSquareLeft()
{
	// プレイヤーの左辺の当たり判定を取得
	return m_pos.x - (kPlayerIdleImageWidth * kPlayerScale) / half;
}

float Player::HitSquareRight()
{
	// プレイヤーの右辺の当たり判定を取得
	return m_pos.x + (kPlayerIdleImageWidth * kPlayerScale) / half;
}
