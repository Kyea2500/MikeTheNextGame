#include "SceneOver.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../../GameDive/Pad/Pad.h"
#include"../../GameObject/Timer/resultTimer.h"

namespace
{
	// テキスト位置
	constexpr int kTextPosX = 200;
	constexpr int kTextPosY = 200;

	// タイトルへ戻るテキスト位置
	constexpr int kTitleTextPosX = 150;
	constexpr int kTitleTextPosY = 250;

	// ゲーム終了テキスト位置
	constexpr int kGameEndTextPosX = 150;
	constexpr int kGameEndTextPosY = 300;

}
SceneOver::SceneOver() :m_resultTimer(nullptr)
{
}

SceneOver::~SceneOver()
{
}
void SceneOver::Init()
{
	m_resultTimer = std::make_shared<resultTimer>();
	m_resultTimer->Init();
}
void SceneOver::End()
{
}

SceneManager::SceneKind SceneOver::Update()
{
	// Aボタンが押されたらタイトルシーンへ
	if (Pad::IsPress(PAD_INPUT_1))
	{
		return SceneManager::SceneKind::kSceneTitle;
	}
	// Bボタンが押されたらゲームを終了
	if (Pad::IsPress(PAD_INPUT_2))
	{
		PostQuitMessage(0);
	}


	return SceneManager::SceneKind::kSceneGameOver;
}
void SceneOver::Draw()
{
	DrawFormatString(kTextPosX, kTextPosY, 0xff0000, "result");
	DrawFormatString(kTitleTextPosX, kTitleTextPosY, 0xffffff, "push A button :Title");
	DrawFormatString(kGameEndTextPosX, kGameEndTextPosY, 0xffffff, "push B button :GameEnd");

	m_resultTimer->Draw();
}
