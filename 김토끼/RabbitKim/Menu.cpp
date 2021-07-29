#include "Menu.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"


Menu::Menu()
{

}

Menu::~Menu()
{

}
    
//
void Menu::Initialize()
{


	MyMenu[0].Texture = (char*)"게임 시작";
	MyMenu[1].Texture = (char*)"게임 방법 ";
	MyMenu[2].Texture = (char*)"게임 종료";

//MyMenu[0].Texture = (char*)"         
//MyMenu[0].Texture = (char*)"┌────────/)/)────┐
//MyMenu[0].Texture = (char*)"│                │
//MyMenu[0].Texture = (char*)"│    게임 시작    │
//MyMenu[0].Texture = (char*)"│                │
//MyMenu[0].Texture = (char*)"│    게임 방법    │
//MyMenu[0].Texture = (char*)"│                │
//MyMenu[0].Texture = (char*)"│    게임 종료    │
//MyMenu[0].Texture = (char*)"│                │
//MyMenu[0].Texture = (char*)"└────────U──U────┘

	 


	MyMenu[0].Color = 8;
	MyMenu[1].Color = 8;
	MyMenu[2].Color = 8;
	//MyMenu[3].Color = 8;

	float Center = float((120 / 2) - (strlen("게임 시작") / 2));

	MyMenu[0].TransPos.Position = Vector3(Center, 15.0f);
	MyMenu[1].TransPos.Position = Vector3(Center, 16.0f);
	MyMenu[2].TransPos.Position = Vector3(Center, 17.0f);
	//MyMenu[3].TransPos.Position = Vector3(Center, 18.0f);

	MyMenu[0].TransPos.Scale = Vector3(9.0f, 1.0f);
	MyMenu[1].TransPos.Scale = Vector3(9.0f, 1.0f);
	MyMenu[2].TransPos.Scale = Vector3(9.0f, 1.0f);
	//MyMenu[3].TransPos.Scale = Vector3(9.0f, 1.0f);

	Choice = 0;
 
	TransInfo.Position = Vector3(0, 0);
}

void Menu::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (Choice != 0)
			Choice--;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (Choice != 2)
			Choice++;
	}
     
	switch (Choice)
	{
	case 0: 
		MyMenu[0].Color = 11;
		MyMenu[1].Color = 8;
		MyMenu[2].Color = 8;
		
		break;
		//5,13
		//3,11
	case 1:
		MyMenu[0].Color = 8;
		MyMenu[1].Color = 11;
		MyMenu[2].Color = 8;
		 
		Sleep = 0.5f;
		break;

	case 2:
		MyMenu[0].Color = 8;
		MyMenu[1].Color = 8;
		MyMenu[2].Color = 11;
		
		break;

	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (Choice)
		{
		case 0:
			SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
			break;

		case 1:
			SceneManager::GetInstance()->SetScene(SCENEID_STORY);
			break;

		case 2:
			exit(NULL);
			break;
			 
		}
	}
}

void Menu::Render()
{

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+51, (int)TransInfo.Position.y + 13, (char*)"┌────/)/)─┐");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+51, (int)TransInfo.Position.y + 14, (char*)"│　　　　　　　│");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+51, (int)TransInfo.Position.y + 15, (char*)"│　　　　　　　│");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+51, (int)TransInfo.Position.y + 16, (char*)"│　　　　　　　│");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+51, (int)TransInfo.Position.y + 17, (char*)"│　　　　　　　│");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+51, (int)TransInfo.Position.y + 18, (char*)"│　　　　　　　│");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+51, (int)TransInfo.Position.y + 19, (char*)"└────U─U─┘");
	

	for (int i = 0; i < 3; ++i)
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(MyMenu[i].TransPos.Position.x),
			int(MyMenu[i].TransPos.Position.y),
			MyMenu[i].Texture, MyMenu[i].Color);



}

void Menu::Release()
{

}

