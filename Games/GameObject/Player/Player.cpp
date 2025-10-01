#include "Player.h"
#include"../Games/GameDive/Pad/Pad.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../Games/GameDive/game.h"

namespace
{
	constexpr float kSpeed = 10.0f; // プレイヤーの移動速度
	constexpr float kBoost = 5.0f; // 瞬間移動の距離を増やす係数
	constexpr float kPlayerImageWidth = 16.1f; // プレイヤー画像の幅
	constexpr float kPlayerImageHeight = 25.6f;// プレイヤー画像の高さ
	constexpr float kPlayerScale = 2.0f; // プレイヤー画像の拡大率
	constexpr int half = 2; // 2で割るための定数
	constexpr int kAnimeFrameSpeed = 5; // アニメーションのフレーム速度
	constexpr int kMoveAnimeNum = 3; // 移動アニメーションの枚数

	// プレイヤーの向き
	enum PlayerDir
	{
		kFront = 0, // 正面(下)	
		kRight = 1, // 右
		kLeft = 2, // 左
		kBack = 3, // 後ろ(上)
		kRightFront = 4, // 右斜め前
		kLeftFront = 5, // 左斜め前
		kRightBack = 6, // 右斜め後ろ
		kLeftBack = 7 // 左斜め後ろ
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
	m_pos.x = Game::kScreenWidth / half; // 画面の中心に初期化
	m_pos.y = Game::kScreenHeight / half; // 画面の中心に初期化
	m_playerHandle = LoadGraph("Image/Player/Player.Png"); // プレイヤー画像の読み込み
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
	int animeIndex = m_frame / kMoveAnimeNum; // アニメーションのインデックス
	// プレイヤーの描画
	if (m_isMove)
	{
		// 移動中の描画
		switch (m_dir)
		{
		case kFront:
			// 下移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				4*kPlayerImageWidth, animeIndex*kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
		case kRight:
			// 右移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				2*kPlayerImageWidth, animeIndex*kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
		case kLeft:
			// 左移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				6 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
		case kBack:
			// 上移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				0 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
		case kRightFront:
			// 右下移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				3 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
		case kLeftFront:
			// 左下移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				5 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
		case kRightBack:
			// 右上移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				1 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
		case kLeftBack:
			// 左上移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				7 * kPlayerImageWidth, animeIndex * kPlayerImageHeight, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
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
			// 下移動の画像描画
			DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
				4*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
				kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
			break;
			case kRight:
				// 右移動の画像描画
				DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
					2*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
				break;
			case kLeft:
				// 左移動の画像描画
				DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
					6*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
				break;
			case kBack:
				// 上移動の画像描画
				DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
					0*kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
				break;
			case kRightFront:
				// 右下移動の画像描画
				DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
					3 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
				break;
			case kLeftFront:
				// 左下移動の画像描画
				DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
					5 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
				break;
			case kRightBack:
				// 右上移動の画像描画
				DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
					1 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
				break;
			case kLeftBack:
				// 左上移動の画像描画
				DrawRectRotaGraph(m_pos.x, m_pos.y, // 描画位置
					7 * kPlayerImageWidth, 0, kPlayerImageWidth, kPlayerImageHeight, // 切り出す位置
					kPlayerScale, 0.0f, m_playerHandle, TRUE, FALSE); // 拡大率、回転角度、ハンドル、透明色を使うか、反転するか
				break;
		default:
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

	// どの方向に移動しているか判定
	if(Pad::IsPress(PAD_INPUT_LEFT)&&Pad::IsPress(PAD_INPUT_DOWN))
	{
		// 左下に移動
		move.x -= speed;
		move.y += speed;
		m_isMove = true;
		m_dir = kLeftFront;
	}
	if (Pad::IsPress(PAD_INPUT_LEFT) && Pad::IsPress(PAD_INPUT_UP))
	{
		// 左上に移動
		move.x -= speed;
		move.y -= speed;
		m_isMove = true;
		m_dir = kLeftBack;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT) && Pad::IsPress(PAD_INPUT_DOWN))
	{
		// 右下に移動
		move.x += speed;
		move.y += speed;
		m_isMove = true;
		m_dir = kRightFront;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT) && Pad::IsPress(PAD_INPUT_UP))
	{
		// 右上に移動
		move.x += speed;
		move.y -= speed;
		m_isMove = true;
		m_dir = kRightBack;
	}

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

	//move.x *= kBoost; // X軸のスピードのギアを上げる
	//move.y *= kBoost; // Y軸のスピードのギアを上げる

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
	return m_pos.y - (kPlayerImageHeight * kPlayerScale) / half;
}

float Player::HitSquareBottom()
{
	// プレイヤーの下辺の当たり判定を取得
	return m_pos.y + (kPlayerImageHeight * kPlayerScale) / half;
}

float Player::HitSquareLeft()
{
	// プレイヤーの左辺の当たり判定を取得
	return m_pos.x - (kPlayerImageWidth * kPlayerScale) / half;
}

float Player::HitSquareRight()
{
	// プレイヤーの右辺の当たり判定を取得
	return m_pos.x + (kPlayerImageWidth * kPlayerScale) / half;
}
