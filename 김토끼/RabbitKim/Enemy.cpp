#include "Enemy.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"


Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

/*
  ^~^  ,
 ('Y') )
 /   \/
(\|||/)


모션1
 /\\_/\\
((@v@))
():::()
 VV-VV

 모션2
 

모션3
	/\\_/\\",
 (↘((@^@))/)
   (↘:::/) "
	 w-w
 
    /\\_/\\
    ((@v@))
   ↙(:::) ↘
 ↙_/ w-w ↘_↘

∬ㅁ

 
 /\\_/\\
(ご,.こ)
():::()
 VV-VV

*/

void Enemy::Initialize()
{
	Motion = 0;
	Motion_Max = 3;

	Texture[0][0][0] = (char*)"    /\\_/\\";
	Texture[0][0][1] = (char*)"(↘((@v@))/)";
	Texture[0][0][2] = (char*)"  (↘:::/) ";
	Texture[0][0][3] = (char*)"    w-w";

	Texture[0][1][0] = (char*)"　　/\\_/\\";
	Texture[0][1][1] = (char*)"　 ((@v@))";
	Texture[0][1][2] = (char*)"　↙(:::)↘";
	Texture[0][1][3] = (char*)"↙_/ w-w ↘_↘";
		

	
	
	Texture[1][0][0] = (char*)"　　/\\_/\\";
	Texture[1][0][1] = (char*)"(↘(ご,.こ)/)";
	Texture[1][0][2] = (char*)"　(↘:::/) ";
	Texture[1][0][3] = (char*)"    w-w";

	Texture[1][1][0] = (char*)"　　/\\_/\\";
	Texture[1][1][1] = (char*)"　 (ご,.こ)";
	Texture[1][1][2] = (char*)"　↙(:::) ↘";
	Texture[1][1][3] = (char*)"↙_/ w-w ↘_↘";




	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen(" /\\_/\\ "), 4.0f);
	
	//Change = 0;
	Speed = 0.5f;

	Color = 10;
	Active = false;

	Time = (ULONG)GetTickCount64();
	MotionTime = 500;
	Damage = 1;
	Check = 0;
	HP = 10;
}

int Enemy::Update()
{
	TransInfo.Position.x -= Speed;

	//몸에서 출력되기때문에 수정을 좀 해줘야됨..↓ 이렇게,......내가 이해 못하던거 그거..
	if ((TransInfo.Position.x - (TransInfo.Scale.x/2)) <= ((Change != 0) ? 4.5f : 3.5f))
	{
		Active = false;
		return -1;
	}


	if (Time + MotionTime < GetTickCount64())
	{
		Time = (ULONG)GetTickCount64();
		Motion = !Motion;
	}

	if (HP <= 9)
	{
		Speed = 1.2f;
		Color = 12;
		Check = 1;
		MotionTime = 80;
	}
	 
	if (HP <= 0)
	{
		Active = false;

		ObjectManager::GetInstance()->AddScore(10);
		
		return 1;
	}

	return 0;
}

void Enemy::Render()
{
	for (int i = 0; i < 4; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
			Texture[Check][Motion][i], Color);
	}

}

void Enemy::Release()
{

}


