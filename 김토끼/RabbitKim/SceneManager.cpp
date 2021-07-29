#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Story.h"
#include "Ending.h"
#include "Over.h"

SceneManager* SceneManager::m_pInstance = NULL;


SceneManager::SceneManager() : m_pSceneState(NULL)
{

}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(const SCENEID & _SceneID)
{
	SAFE_RELEASE(m_pSceneState);

	switch (_SceneID)
	{
	case SCENEID_LOGO:
		m_pSceneState = new Logo;
		break;

	case SCENEID_MENU:
		m_pSceneState = new Menu;
		break;

	case SCENEID_STORY:
		m_pSceneState = new Story;
		break;

	case SCENEID_STAGE:
		m_pSceneState = new Stage;
		break;

	case SCENEID_ENDING:
		m_pSceneState = new Ending;
		break;

	case SCENEID_OVER:
		m_pSceneState = new Over;
		break;

	case SCENEID_EXIT:
		exit(NULL);
		break;

	}

	m_pSceneState->Initialize();
	Sleep(1500);
}

void SceneManager::Update()
{
	m_pSceneState->Update();
}

void SceneManager::Render()
{
	m_pSceneState->Render();
}

void SceneManager::Release()
{
	SAFE_RELEASE(m_pSceneState);
}

