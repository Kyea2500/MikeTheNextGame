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
	// プレイヤーの位置
	Vec2 m_pos;
	// プレイヤーのハンドル
	int m_playerHandle;
	// プレイヤーの移動速度
	float speed;
	// プレイヤーの移動状態
	bool m_isMove;	// trueなら移動中		falseなら移動していない

};

