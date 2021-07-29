#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"



MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Initialize()
{
	DoubleBuffer::GetInstance()->CreateBuffer(
		CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);

	SceneManager::GetInstance()->SetScene(SCENEID_LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->CheckKey();
	SceneManager::GetInstance()->Update();

	DoubleBuffer::GetInstance()->FlippingBuffer();
	DoubleBuffer::GetInstance()->ClearBuffer();

}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
	SceneManager::GetInstance()->Release();
	DoubleBuffer::GetInstance()->DestroyBuffer();
}


/*

  {}==={}

( 

¢×£þ¢Ù_______¢×£þ¢Ù
>                <   
¢Ø__¢×£þ£þ£þ£þ¢Ø__¢×

(
*/