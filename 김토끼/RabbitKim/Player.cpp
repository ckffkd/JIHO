#include "Player.h"
#include "InputManager.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"
#include "SceneManager.h"

//#include "Bullet.h"

Player::Player()
{

}

Player::~Player()
{
	Release();
}


void Player::Initialize()
{
	//기본
	Texture[0][0] = (char*)"  /)/)";
	Texture[0][1] = (char*)" (> 3<)";
	Texture[0][2] = (char*)"o(⊃⊂)";
	Texture[0][3] = (char*)"  U  U";
	Texture[0][4] = (char*)" ,*   ";

	//공격
	Texture[1][0] = (char*)"  /)/)";
	Texture[1][1] = (char*)"|(> 3<)/";
	Texture[1][2] = (char*)"o(    )";
	Texture[1][3] = (char*)"  U  U";
	Texture[1][4] = (char*)" ,*   ";


	//화살토끼
	Texture[2][0] = (char*)"    '~☆,";
	Texture[2][1] = (char*)"  /)/)∴∵*-+";
	Texture[2][2] = (char*)"|(> 3<)/ ∵∴※>";
	Texture[2][3] = (char*)"o(    )∴∵+~";
	Texture[2][4] = (char*)"  U  U,~★";
	Texture[2][5] = (char*)" ,*   ";
	
	//∪
	/*
	 '~☆";
	  ∴∵*-+";
	     ∵∴※>";
	   ∴∵+~";
	 ,~★";
	
	*/

	TransInfo.Position = Vector3(10.0f, 5.0f);
	TransInfo.Scale = Vector3((float)strlen(Texture[0][1]), 5.0f);
	
	HP = 100;

	AttackColl = false;
	Color = 9;

	Time = (ULONG)GetTickCount64();
}


int Player::Update()
{
	if (AttackColl)
	{
		Color++;

		if (TransInfo.Position.x >= 4)
			TransInfo.Position.x -= 1.0f;
		 
		if (Color >= 15)
			Color = 9;

		if (Time + 800 < GetTickCount64())
		{
			AttackColl = false;
		}
	}
	
	CheckKey();

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 5; i++)
	{
		if (AttackColl)
		{
			DoubleBuffer::GetInstance()->WriteBuffer(
				int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
				int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
				Texture[0][i], Color);
		}
		else
		{
			DoubleBuffer::GetInstance()->WriteBuffer(
				int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
				int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
				Texture[0][i],1);
		}
	}

	
	for (int i = 0; i < 5; i++)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			DoubleBuffer::GetInstance()->WriteBuffer(
				int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
				int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
				Texture[1][i],1);
			
			if (AttackColl)
			{
				DoubleBuffer::GetInstance()->WriteBuffer(
					int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
					int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
					Texture[1][i], Color);
			} 
		} 
	}

	DoubleBuffer::GetInstance()->WriteBuffer(
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		HP, Color);
	
	  
	if (HP <= 0)
	{
		SceneManager::GetInstance()->SetScene(SCENEID_OVER);
	}
	 
	
	

}

void Player::Release()
{

}

void Player::CheckKey()
{
	ULONG ulKey = InputManager::GetInstance()->GetKey();

	if (ulKey & KEYID_UP)
	{
		if(TransInfo.Position.y >= 4)
		TransInfo.Position.y--;
	}

	if (ulKey & KEYID_DOWN)
	{
		if(TransInfo.Position.y <= 27)
		TransInfo.Position.y++;
	}

	if (ulKey & KEYID_RIGHT)
	{
		if(TransInfo.Position.x <=115)
		TransInfo.Position.x++;
	}

	if (ulKey & KEYID_LEFT)
	{
		if(TransInfo.Position.x >= 4)
		TransInfo.Position.x--;
	}

	if (ulKey & KEYID_SPACE)
	{
		ObjectManager::GetInstance()->FireBullet();
	}
}

/*
		for (int i = 0; i < 128; ++i)
		{
			if (m_Bullet[i] == NULL)
			{
				m_Bullet[i] = new Bullet;
				m_Bullet[i]->Initialize();

				m_Bullet[i]->SetPosition(
					TransInfo.Position.x + strlen(" |(> 3<)/"),
					TransInfo.Position.y + 1);

			}
			break;
		}
	 */