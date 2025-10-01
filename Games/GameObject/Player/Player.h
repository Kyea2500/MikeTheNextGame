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
	// プレイヤーの位置
	Vec2 m_pos;
	
	// プレイヤーのハンドル
	int m_playerHandle;
	
	// プレイヤーの移動速度
	float speed;

	// プレイヤーの移動状態
	bool m_isMove;	// trueなら移動中		falseなら移動していない

	// プレイヤーの向き
	int m_dir;	// 0:正面 1:右 2:左 3:後ろ 4:右斜め前 5:左斜め前 6:右斜め後ろ 7:左斜め後ろ

	// プレイヤーのアニメフレーム
	int m_frame;

};

