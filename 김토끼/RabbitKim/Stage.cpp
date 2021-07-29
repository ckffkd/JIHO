#include "Stage.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"

#include "Player.h"
#include "BackGround.h"



Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	Object* pPlayer = new Player;
	pPlayer->Initialize();

	ObjectManager::GetInstance()->Initialize();
	ObjectManager::GetInstance()->SetPlayer(pPlayer);

	m_pBackGround = new BackGround;
	m_pBackGround->Initialize();

	//ObjectManager::GetInstance()->CreateEnemy();
}

void Stage::Update()
{
	m_pBackGround->Update();

	ObjectManager::GetInstance()->Update();


	if (GetAsyncKeyState(VK_TAB))
		ObjectManager::GetInstance()->AddScore(50);

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
	}
}

void Stage::Render()
{
	m_pBackGround->Render();

	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	SAFE_RELEASE(m_pBackGround);
}

