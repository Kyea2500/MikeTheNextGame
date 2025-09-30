#include "../SceneManager/SceneManager.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneMain/SceneMain.h"
#include "../SceneOver/SceneOver.h"
#include "../Games/GameDive/Pad/Pad.h"

SceneManager::SceneManager() :
	m_Kind(kSceneTitle), // �����V�[�����^�C�g���ɐݒ�
	m_pSceneTitle(nullptr), // �^�C�g���V�[���̃|�C���^��������
	m_pSceneMain(nullptr),  // ���C���V�[���̃|�C���^��������
	m_pSceneGameOver(nullptr) // �Q�[���I�[�o�[�V�[���̃|�C���^��������
{
}

SceneManager::~SceneManager()
{
	// �e�V�[���̃|�C���^�����
	if (m_pSceneTitle != nullptr)
	{
		m_pSceneTitle = nullptr;
		delete m_pSceneTitle;
	}
	else if (m_pSceneMain != nullptr)
	{
		m_pSceneMain = nullptr;
		delete m_pSceneMain;
	}
	else if (m_pSceneGameOver != nullptr)
	{
		m_pSceneGameOver = nullptr;
		delete m_pSceneGameOver;
	}
}

void SceneManager::Init()
{
	// �V�[���̏�����
	switch (m_Kind)
	{
	case SceneKind::kSceneTitle:
		m_pSceneTitle = new SceneTitle();
		m_pSceneTitle->Init();
		break;
	case SceneKind::kSceneMain:
		m_pSceneMain = new SceneMain();
		m_pSceneMain->Init();
		break;
	case SceneKind::kSceneGameOver:
		m_pSceneGameOver = new SceneOver();
		m_pSceneGameOver->Init();
		break;
	default:
		break;
	}
}

void SceneManager::End()
{// �V�[���̏I������
	switch (m_Kind)
	{
	case SceneKind::kSceneTitle:
		m_pSceneTitle->End();
		delete m_pSceneTitle;
		m_pSceneTitle = nullptr;
		break;
	case SceneKind::kSceneMain:
		m_pSceneMain->End();
		delete m_pSceneMain;
		m_pSceneMain = nullptr;
		break;
	case SceneKind::kSceneGameOver:
		m_pSceneGameOver->End();
		delete m_pSceneGameOver;
		m_pSceneGameOver = nullptr;
		break;
	default:
		break;
	}
}

void SceneManager::Update()
{
	Pad::Update();
	SceneKind nextKind = m_Kind;
	// �V�[���̍X�V
	switch (m_Kind)
	{
	case SceneKind::kSceneTitle:
		nextKind = m_pSceneTitle->Update();
		break;
	case SceneKind::kSceneMain:
		nextKind = m_pSceneMain->Update();
		break;
	case SceneKind::kSceneGameOver:
		nextKind = m_pSceneGameOver->Update();
		break;
	default:
		break;
	}

	if (nextKind != m_Kind)
	{
		// ���ݎ��s���̃V�[��(m_kind)�̏I������
		End();
		// ���̃V�[���ɐ؂�ւ�
		m_Kind = nextKind;
		// �؂�ւ���̃V�[���̏�����
		Init();
	}
}


void SceneManager::Draw()
{
	// �V�[���̕`��
	switch (m_Kind)
	{
	case SceneKind::kSceneTitle:
		m_pSceneTitle->Draw();
		break;
	case SceneKind::kSceneMain:
		m_pSceneMain->Draw();
		break;
	case SceneKind::kSceneGameOver:
		m_pSceneGameOver->Draw();
		break;
	default:
		break;
	}
}
