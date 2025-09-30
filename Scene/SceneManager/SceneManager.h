#pragma once
class SceneTitle;
class SceneMain;
class SceneOver;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void Init();
	void End();
	void Update();
	void Draw();
public:
	enum SceneKind
	{
		kSceneTitle,
		kSceneMain,
		kSceneGameOver,
		kSceneNum
	}; private:
		SceneKind m_Kind;
		// 各シーンのポインタ
		SceneTitle* m_pSceneTitle;
		SceneMain* m_pSceneMain;
		SceneOver* m_pSceneGameOver;
};


