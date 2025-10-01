#include "SceneMain.h"
#include"../../GameObject/Player/Player.h"
#include"../../GameObject/Box/TreasureBox.h"
#include"../../GameObject/Timer/Timer.h"

SceneMain::SceneMain() :m_player(nullptr),
m_treasureBox(nullptr),
m_timer(nullptr)
{
}
SceneMain::~SceneMain()
{
}
void SceneMain::Init()
{
	m_player = std::make_shared<Player>();
	m_player->Init();

	m_treasureBox = std::make_shared<TreasureBox>();
	m_treasureBox->Init();

	m_timer = std::make_shared<Timer>();
	m_timer->Init();

}
void SceneMain::End()
{
	m_player->End();
	m_player = nullptr;
	m_treasureBox->End();
	m_treasureBox = nullptr;
}

SceneManager::SceneKind SceneMain::Update()
{
	m_player->Update();
	m_treasureBox->Update();
	m_timer->Update();

	if(m_player->HitSquareRight()>=m_treasureBox->HitSquareLeft()&&
	   m_player->HitSquareLeft()<=m_treasureBox->HitSquareRight()&&
	   m_player->HitSquareTop()<=m_treasureBox->HitSquareBottom()&&
	   m_player->HitSquareBottom()>=m_treasureBox->HitSquareTop())
	{
		return SceneManager::SceneKind::kSceneGameOver;
	}

	return SceneManager::SceneKind::kSceneMain;
}

void SceneMain::Draw()
{
	m_player->Draw();
	m_treasureBox->Draw();
	m_timer->Draw();
}