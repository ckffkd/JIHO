#pragma once
#include "Headers.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* m_pInstance;
public:
	static SceneManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new SceneManager;
		return m_pInstance;
	}
private:
	Scene* m_pSceneState;
public:
	void SetScene(const SCENEID& _SceneID);
	void Update();
	void Render();
	void Release();
private:
	SceneManager();
public:
	~SceneManager();
};

