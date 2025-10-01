#include "SceneTitle.h"
#include"../../../FilesAddProject_for_VC/DxLib.h"
#include"../../GameDive/Pad/Pad.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}


void SceneTitle::Init()
{
}

void SceneTitle::End()
{
}

SceneManager::SceneKind SceneTitle::Update()
{
	Pad::Update();
	// Aボタンが押されたらメインシーンへ
	if (Pad::IsPress(PAD_INPUT_1))
	{
		return SceneManager::SceneKind::kSceneMain;
	}
	// Bボタンが押されたらゲームを終了
	if (Pad::IsPress(PAD_INPUT_2))
	{
		PostQuitMessage(0);
	}

	return SceneManager::SceneKind::kSceneTitle;
}

void SceneTitle::Draw()
{
	DrawFormatString(200, 200, 0x00ff00, "title");
	DrawFormatString(150, 250, 0xffffff, "push A button :GameStart");
	DrawFormatString(150, 300, 0xffffff, "push B button :GameEnd");
}
